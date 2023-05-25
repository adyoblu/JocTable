#undef UNICODE

#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#include "User.h"
#include <json/json.h>
#include <msclr/marshal_cppstd.h>
#include <msclr/marshal.h>
#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <vector>

int ConnectedClients = 0;
int ReadyToGame = 0;
int PlayerTurn = 0;

std::vector<SOCKET> Clienti_Conectati;

using namespace System::Runtime::InteropServices;
using namespace System;
using namespace System::Net;
using namespace System::Net::Sockets;
using namespace System::Windows::Forms;
using namespace System::Data::SqlClient;
using namespace System::Text;

#pragma comment (lib, "Ws2_32.lib")


#define DEFAULT_BUFLEN 512
#define DEFAULT_PORT "27015"

int Verify(User^% user, std::string mail, std::string password);

DWORD WINAPI ProcessClient(LPVOID lpParameter)
{
    SOCKET AcceptSocket = (SOCKET)lpParameter;

    // Send and receive data.
    int bytesSent;
    int bytesRecv = SOCKET_ERROR;
    char sendbuf[2000] = "";
    char recvbuf[2000] = "";

    char timebuf[128];

   
    do {

        ZeroMemory(recvbuf, sizeof(recvbuf));
        int bytesReceived = recv(AcceptSocket, recvbuf, DEFAULT_BUFLEN, 0);
        if (bytesReceived == SOCKET_ERROR)
        {
            printf("recv failed with error: %d\n", WSAGetLastError());
            ConnectedClients--;
            ReadyToGame--;

            WSACleanup();
            return 0;
        }
        array<Byte>^ byteData = gcnew array<Byte>(bytesReceived);
        Marshal::Copy(IntPtr((void*)recvbuf), byteData, 0, bytesReceived);
        String^ receivedData = Encoding::ASCII->GetString(byteData);

        Json::Value jsonData;
        Json::Reader jsonReader;
        if (!jsonReader.parse(msclr::interop::marshal_as<std::string>(receivedData), jsonData))
        {
            printf("Failed to parse JSON data\n");
            // Handle the parsing error
            return 0;
        }
        std::string operatiune = jsonData["operatiune"].asString();
        if (operatiune == "login")
        {
            std::string email = jsonData["mail"].asString();
            std::string password = jsonData["password"].asString();

            //verificare cont in baza de date

            User^ user = gcnew User;
            int verificare = Verify(user, email, password);



            if (send(AcceptSocket, reinterpret_cast<char*>(&verificare), sizeof(verificare), 0) == SOCKET_ERROR) {
                std::cerr << "Failed to send data" << std::endl;
            }
            else {
                std::cout << "Data sent successfully: " << verificare << std::endl;
            }
        }
        else if (operatiune == "register")
        {
            std::string email = jsonData["mail"].asString();
            System::String^ mail = gcnew System::String(email.c_str());

            std::string password = jsonData["password"].asString();
            System::String^ parola = gcnew System::String(password.c_str());

            std::string phone = jsonData["phone"].asString();
            System::String^ telefon = gcnew System::String(phone.c_str());

            std::string address = jsonData["address"].asString();
            System::String^ adresa = gcnew System::String(address.c_str());

            std::string name = jsonData["name"].asString();
            System::String^ nume = gcnew System::String(name.c_str());



            String^ connString = "Data Source=DESKTOP-OIGQPEQ;Initial Catalog=BDPOO;Integrated Security=True";
            SqlConnection sqlConn(connString);
            sqlConn.Open();


            String^ sqlQuery = "INSERT INTO users " +
                "(name, email, phone, address, password) VALUES " +
                "(@name, @email, @phone, @address, @password);";

            SqlCommand command(sqlQuery, % sqlConn);
            command.Parameters->AddWithValue("@name", nume);
            command.Parameters->AddWithValue("@email", mail);
            command.Parameters->AddWithValue("@phone", telefon);
            command.Parameters->AddWithValue("@address", adresa);
            command.Parameters->AddWithValue("@password", parola); // Pass the hashed password

            command.ExecuteNonQuery();
            int inregistrare = 1;
            if (send(AcceptSocket, reinterpret_cast<char*>(&inregistrare), sizeof(inregistrare), 0) == SOCKET_ERROR) {
                std::cerr << "Failed to send data" << std::endl;
            }
            else {
                std::cout << "Register successful!\n Data sent successfully: " << inregistrare << std::endl;
            }


        }
        if (operatiune == "rtg")
        {
            ReadyToGame++;
        }

        if (ReadyToGame == 2 && operatiune != "joc")
        {
            for (int i = 0; i < Clienti_Conectati.size(); i++)
                if (send(Clienti_Conectati[i], reinterpret_cast<char*>(&ReadyToGame), sizeof(ReadyToGame), 0) == SOCKET_ERROR) {
                    std::cerr << "Failed to send data" << std::endl;
                }
                else {
                    std::cout << "Ambii jucatori sunt pregatitit de joc!\nCodJoc: " << ReadyToGame << std::endl;
                }
        }

        if (operatiune == "joc")
        {

            int currentPlayer = jsonData["player"].asInt();




            int** serverMatrix = new int* [8];
            for (int i = 0; i < 8; ++i)
            {
                serverMatrix[i] = new int[8];
            }

            for (int i = 0; i < 8; ++i)
            {
                for (int j = 0; j < 8; ++j)
                {
                    serverMatrix[i][j] = jsonData["matrix"][i][j].asInt();
                }

            }
            std::cout << "\n";
            for (int i = 0; i < 8; ++i, std::cout << std::endl)
                for (int j = 0; j < 8; j++)
                    std::cout << serverMatrix[i][j];

        
        array<Byte>^ dataBytes = Encoding::ASCII->GetBytes(msclr::interop::marshal_as<String^>(jsonData.toStyledString()));
        pin_ptr<unsigned char> pinnedData = &dataBytes[0];
        int dataLength = dataBytes->Length;
        for (int i = 0; i < Clienti_Conectati.size(); i++)
            send(Clienti_Conectati[i], reinterpret_cast<char*>(pinnedData), dataLength, 0);

        }

    
                 
    } while (1);
        
fin:
    printf("Client processed\n");

    closesocket(AcceptSocket);
    return 0;
}

int __cdecl main(void)
{
    WSADATA wsaData;
    int iResult;

    SOCKET ListenSocket = INVALID_SOCKET;
    SOCKET AcceptSocket = INVALID_SOCKET;

    struct addrinfo* result = NULL;
    struct addrinfo hints;

    int iSendResult;
    char recvbuf[DEFAULT_BUFLEN];
    int recvbuflen = DEFAULT_BUFLEN;

    // Initialize Winsock
    iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0) {
        printf("WSAStartup failed with error: %d\n", iResult);
        return 1;
    }

    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;
    hints.ai_flags = AI_PASSIVE;

    // Resolve the server address and port
    iResult = getaddrinfo(NULL, DEFAULT_PORT, &hints, &result);
    if (iResult != 0) {
        printf("getaddrinfo failed with error: %d\n", iResult);
        WSACleanup();
        return 1;
    }

    // Create a SOCKET for the server to listen for client connections.
    ListenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (ListenSocket == INVALID_SOCKET) {
        printf("socket failed with error: %ld\n", WSAGetLastError());
        freeaddrinfo(result);
        WSACleanup();
        return 1;
    }

    // Setup the TCP listening socket
    iResult = bind(ListenSocket, result->ai_addr, (int)result->ai_addrlen);
    if (iResult == SOCKET_ERROR) {
        printf("bind failed with error: %d\n", WSAGetLastError());
        freeaddrinfo(result);
        closesocket(ListenSocket);
        WSACleanup();
        return 1;
    }

    freeaddrinfo(result);

    iResult = listen(ListenSocket, SOMAXCONN);
    if (iResult == SOCKET_ERROR) {
        printf("listen failed with error: %d\n", WSAGetLastError());
        closesocket(ListenSocket);
        WSACleanup();
        return 1;
    }

    // Accept a client socket
    while (1)
    {
        AcceptSocket = SOCKET_ERROR;

        while (AcceptSocket == SOCKET_ERROR)
        {
            AcceptSocket = accept(ListenSocket, NULL, NULL);
            Clienti_Conectati.push_back(AcceptSocket);
        }
        ConnectedClients++;
        printf("Client Connected.\n");

        DWORD dwThreadId;
        CreateThread(NULL, 0, ProcessClient, (LPVOID)AcceptSocket, 0, &dwThreadId);
    }
   
    

    // shutdown the connection since we're done
    iResult = shutdown(AcceptSocket, SD_SEND);
    if (iResult == SOCKET_ERROR) {
        printf("shutdown failed with error: %d\n", WSAGetLastError());
        //closesocket(AcceptSocket);
        WSACleanup();
        //return 1;
    }

    WSACleanup();

    return 0;
}


int Verify(User^% user, std::string mail, std::string password) {
    if (mail.empty() || password.empty()) {
        return -1;
    }
    try {
        String^ connString = "Data Source=DESKTOP-OIGQPEQ;Initial Catalog=BDPOO;Integrated Security=True";
        SqlConnection sqlConn(gcnew String(connString));
        sqlConn.Open();

        // Retrieve the hashed password from the database for the given email
        String^ sqlQuery = "SELECT * FROM users WHERE email=@mail AND password=@pwd;";
        SqlCommand command(sqlQuery, % sqlConn);

        command.Parameters->AddWithValue("@mail", gcnew String(mail.c_str()));
        command.Parameters->AddWithValue("@pwd", gcnew String(password.c_str()));
        SqlDataReader^ reader = command.ExecuteReader();
        if (reader->Read()) {
            user->id = reader->GetInt32(0);
            user->name = reader->GetString(1);
            user->email = reader->GetString(2);
            user->phone = reader->GetString(3);
            user->address = reader->GetString(4);
            user->password = reader->GetString(5);
            Console::WriteLine("Utilizator gasit in baza de date!");
            reader->Close(); // Close the SqlDataReader
            sqlConn.Close(); // Close the SqlConnection
            return 1;
        }
        else {
            // Email not found in the database
            // MessageBox::Show("Email or password is incorrect",
            //     "Email or Password Error", MessageBoxButtons::OK);
            Console::WriteLine("Email or password is incorrect!");
            reader->Close(); // Close the SqlDataReader
            sqlConn.Close(); // Close the SqlConnection
            return 0;
        }
    }
    catch (Exception^ e) {
        Console::WriteLine("Exceptie!");
        return 0;
    }
}