#pragma once
#include "User.h"
#include <vcclr.h>
#include <msclr/marshal_cppstd.h>
#include <winsock2.h>
#include <stdio.h>
#include <Windows.h>
#include <json/json.h>
#define DEFAULT_BUFLEN 1024

namespace Client {

	using namespace System;
	using namespace System::Net;
	using namespace System::Net::Sockets;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Text;
	/// <summary>
	/// Summary for LoginForm
	/// </summary>
	public ref class LoginForm : public System::Windows::Forms::Form
	{
	private:
		// Private copy constructor and assignment operator to prevent copying
	public:
		SOCKET connectSocket;
		LoginForm()
		{
			InitializeComponent();
		}
		LoginForm(SOCKET socket)
		{
			InitializeComponent();
			connectSocket = socket;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~LoginForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	protected:
	private: System::Windows::Forms::LinkLabel^ linkLabelSignUp;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox2;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(LoginForm::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->linkLabelSignUp = (gcnew System::Windows::Forms::LinkLabel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::Transparent;
			this->panel1->Controls->Add(this->linkLabelSignUp);
			this->panel1->Controls->Add(this->button1);
			this->panel1->Controls->Add(this->textBox1);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->textBox2);
			this->panel1->Location = System::Drawing::Point(116, 60);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(305, 291);
			this->panel1->TabIndex = 11;
			// 
			// linkLabelSignUp
			// 
			this->linkLabelSignUp->AutoSize = true;
			this->linkLabelSignUp->BackColor = System::Drawing::Color::Transparent;
			this->linkLabelSignUp->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->linkLabelSignUp->Location = System::Drawing::Point(125, 228);
			this->linkLabelSignUp->Name = L"linkLabelSignUp";
			this->linkLabelSignUp->Size = System::Drawing::Size(75, 24);
			this->linkLabelSignUp->TabIndex = 13;
			this->linkLabelSignUp->TabStop = true;
			this->linkLabelSignUp->Text = L"SignUp";
			this->linkLabelSignUp->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &LoginForm::linkLabelSignUp_LinkClicked);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(125, 187);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 11;
			this->button1->Text = L"Login";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &LoginForm::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(76, 138);
			this->textBox1->Name = L"textBox1";
			this->textBox1->PasswordChar = '*';
			this->textBox1->Size = System::Drawing::Size(175, 26);
			this->textBox1->TabIndex = 10;
			this->textBox1->Text = L"Password";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(121, 33);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(62, 24);
			this->label1->TabIndex = 9;
			this->label1->Text = L"Login";
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox2->Location = System::Drawing::Point(76, 95);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(175, 26);
			this->textBox2->TabIndex = 3;
			this->textBox2->Text = L"Email";
			// 
			// LoginForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(537, 410);
			this->Controls->Add(this->panel1);
			this->Name = L"LoginForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Auth";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	public: User^ user = nullptr;
	public: bool switchToMain = false;
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		try
		{
			String^ email = this->textBox2->Text;
			String^ password = this->textBox1->Text;
			if (email->Length == 0 || password->Length == 0) {
				MessageBox::Show("Please enter username and password",
					"Username or Password Empty", MessageBoxButtons::OK);
				return;
			}
			user = gcnew User();
			user->email = email;
			//aici trimit catre server email si password
			Json::Value jsonData;
			//clientSocket->Connect(serverEndPoint);
			String^ operatiune = "login";
			jsonData["operatiune"] = msclr::interop::marshal_as<std::string>(operatiune);
			jsonData["mail"] = msclr::interop::marshal_as<std::string>(email);
			jsonData["password"] = msclr::interop::marshal_as<std::string>(GetSHA256Hash(password));
			std::string jsonString = jsonData.toStyledString();


			// Convert the string to bytes
			array<Byte>^ dataBytes = Encoding::ASCII->GetBytes(msclr::interop::marshal_as<String^>(jsonString));
			pin_ptr<unsigned char> pinnedData = &dataBytes[0];
			int dataLength = dataBytes->Length;

			int bytesSent = send(connectSocket, reinterpret_cast<char*>(pinnedData), dataLength, 0);
			if (bytesSent == SOCKET_ERROR)
			{
				printf("send failed with error: %d\n", WSAGetLastError());
				closesocket(connectSocket);
				WSACleanup();
				return;
			}
			else
			{
				printf("Bytes sent: %d\n", bytesSent);
			}
	
			// Receive the response from the server
			array<Byte>^ recvBuffer = gcnew array<Byte>(sizeof(int));
			pin_ptr<Byte> pinnedRecvBuffer = &recvBuffer[0];
			int bytesReceived = recv(connectSocket, reinterpret_cast<char*>(pinnedRecvBuffer), sizeof(int), 0);
			if (bytesReceived == sizeof(int))
			{
				// Convert the received byte array to an integer
				int receivedValue = BitConverter::ToInt32(recvBuffer, 0);

				// Process the received integer
				if(receivedValue == -1)
					MessageBox::Show("Please enter username and password",
							    "Username or Password Empty", MessageBoxButtons::OK);
				else if (receivedValue == 0) {
					MessageBox::Show("Email or password is incorrect",
						"Email or Password Error", MessageBoxButtons::OK);
				}
				else if (receivedValue == 1){
					//user->email = email;
					//user->password = password;
					this->switchToMain = true;
					this->Close();
				}
			}
			else if (bytesReceived == 0)
			{
				// Connection closed by the server
				printf("Connection closed by the server.\n");
			}
			else
			{
				// Error occurred while receiving
				printf("recv failed with error: %d\n", WSAGetLastError());
			}

			// Clean up
			//clientSocket->Shutdown(SocketShutdown::Both);
			//clientSocket->Close();
		}
		catch (Exception^ ex)
		{
			// Handle the exception
			MessageBox::Show("An error occurred: " + ex->Message,
				"Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	String^ GetSHA256Hash(String^ input) {
		array<Byte>^ hashBytes;
		pin_ptr<const wchar_t> str = PtrToStringChars(input);

		// Hash the input password
		System::Security::Cryptography::SHA256Managed^ sha256 = gcnew System::Security::Cryptography::SHA256Managed();
		hashBytes = sha256->ComputeHash(Encoding::UTF8->GetBytes(input));

		// Convert the hashed bytes to a hexadecimal string
		StringBuilder^ sb = gcnew StringBuilder();
		for each (Byte b in hashBytes) {
			sb->Append(b.ToString("x2"));
		}
		return sb->ToString();
	}
	public: bool switchToRegister = false;
	private: System::Void linkLabelSignUp_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
		this->switchToRegister = true;
		this->Close();
	}

};
}
