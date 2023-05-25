#pragma once

#include <winsock2.h>
#include <ws2tcpip.h>
#include <msclr/marshal.h>
#include "User.h"
#include "RegisterForm.h"
#include "MainForm.h"
#include "LoginForm.h"
#include "GameForm.h"

using namespace System;
using namespace System::Net;
using namespace System::Text;
using namespace System::Windows::Forms;
using namespace System::Runtime::InteropServices;

#pragma comment(lib, "Ws2_32.lib")

#define DEFAULT_BUFLEN 512
#define DEFAULT_PORT "27015"

int main(array<String^>^ args)
{
    WSADATA wsaData;
    SOCKET ConnectSocket = INVALID_SOCKET;
    addrinfo* result = nullptr;
    addrinfo* ptr = nullptr;
    addrinfo hints{};
    const char* sendbuf = "this is a test";
    char recvbuf[DEFAULT_BUFLEN];
    int iResult;
    int recvbuflen = DEFAULT_BUFLEN;

    // Validate the parameters
    if (args->Length != 2) {
        Console::WriteLine("usage: {0} server-name", args[0]);
        return 1;
    }

    // Initialize Winsock
    iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0) {
        Console::WriteLine("WSAStartup failed with error: {0}", iResult);
        return 1;
    }

    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    // Resolve the server address and port
    IntPtr ptrHostname = Marshal::StringToHGlobalAnsi(args[1]);
    iResult = getaddrinfo(static_cast<const char*>(ptrHostname.ToPointer()), DEFAULT_PORT, &hints, &result);
    Marshal::FreeHGlobal(ptrHostname);

    if (iResult != 0) {
        Console::WriteLine("getaddrinfo failed with error: {0}", iResult);
        WSACleanup();
        return 1;
    }

    // Attempt to connect to an address until one succeeds
    for (ptr = result; ptr != nullptr; ptr = ptr->ai_next) {

        // Create a SOCKET for connecting to the server
        ConnectSocket = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);
        if (ConnectSocket == INVALID_SOCKET) {
            Console::WriteLine("socket failed with error: {0}", WSAGetLastError());
            WSACleanup();
            return 1;
        }

        // Connect to the server
        iResult = connect(ConnectSocket, ptr->ai_addr, static_cast<int>(ptr->ai_addrlen));
        if (iResult == SOCKET_ERROR) {
            closesocket(ConnectSocket);
            ConnectSocket = INVALID_SOCKET;
            continue;
        }
        break;
    }

    freeaddrinfo(result);

    if (ConnectSocket == INVALID_SOCKET) {
        Console::WriteLine("Unable to connect to the server!");
        WSACleanup();
        return 1;
    }
    //aici s-a conectat la server
    // Send an initial buffer

    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    User^ user = gcnew User();
    while (1) {
        Client::LoginForm^ loginF = gcnew Client::LoginForm(ConnectSocket);
        loginF->ShowDialog();
    
        if (loginF->switchToMain == 1) {
            user = loginF->user;
            Client::MainForm^ mainForm = gcnew Client::MainForm(user, ConnectSocket);
            mainForm->ShowDialog();
            if (mainForm->switchToGame) {
                Client::GameForm^ gamef = gcnew Client::GameForm(ConnectSocket);
                gamef->ShowDialog();
            }
        }
        if (loginF->switchToRegister == 1) {
            Client::RegisterForm^ registerF = gcnew Client::RegisterForm(ConnectSocket);;
            registerF->ShowDialog();
    
            if (registerF->switchToMain) {
                user = registerF->user;
                //Client::MainForm mainForm(user, ConnectSocket);
                //Application::Run(% mainForm);
                Client::MainForm^ mainForm = gcnew Client::MainForm(user, ConnectSocket);
                mainForm->ShowDialog();
                if (mainForm->switchToGame) {
                    Client::GameForm^ gamef = gcnew Client::GameForm(ConnectSocket);
                    gamef->ShowDialog();
                }

            }
                
            if (registerF->switchToLogin)
                continue;
            else {
                user = registerF->user;
                break;
            }
        }
        else {
            user = loginF->user;
            break;
        }
    }

    //String^ managedSendBuf = Marshal::PtrToStringAnsi(static_cast<IntPtr>(const_cast<char*>(sendbuf)));

    //array<Byte>^ sendBytes = Encoding::ASCII->GetBytes(managedSendBuf);
    //pin_ptr<Byte> pinnedSendBytes = &sendBytes[0];
    //iResult = send(ConnectSocket, reinterpret_cast<char*>(static_cast<void*>(pinnedSendBytes)), sendBytes->Length, 0);

    if (iResult == SOCKET_ERROR) {
        Console::WriteLine("send failed with error: {0}", WSAGetLastError());
        closesocket(ConnectSocket);
        WSACleanup();
        return 1;
    }

    Console::WriteLine("Bytes Sent: {0}", iResult);

    // Shutdown the connection for sending
    iResult = shutdown(ConnectSocket, SD_SEND);
    if (iResult == SOCKET_ERROR) {
        Console::WriteLine("shutdown failed with error: {0}", WSAGetLastError());
        closesocket(ConnectSocket);
        WSACleanup();
        return 1;
    }

    // Receive until the peer closes the connection
    do {
        iResult = recv(ConnectSocket, recvbuf, recvbuflen, 0);
    } while (iResult > 0);

    // Cleanup
    closesocket(ConnectSocket);
    WSACleanup();

    return 0;
}

