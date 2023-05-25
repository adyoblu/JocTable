#pragma once
#include "User.h"
#include <Windows.h>
#include <json/json.h>
#include <msclr/marshal_cppstd.h>
#include <winsock2.h>
#include <stdio.h>
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
	#define DEFAULT_BUFLEN 1024

	/// <summary>
	/// Summary for RegisterForm
	/// </summary>
	public ref class RegisterForm : public System::Windows::Forms::Form
	{
	public:
		SOCKET connectSocket;
		RegisterForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			this->CenterToScreen();
		}
		RegisterForm(SOCKET socket)
		{
			InitializeComponent();
			connectSocket = socket;
			this->CenterToScreen();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~RegisterForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ labelName;
	private: System::Windows::Forms::TextBox^ textBoxName;

	private: System::Windows::Forms::Label^ labelEmail;
	private: System::Windows::Forms::TextBox^ textBoxEmail;

	private: System::Windows::Forms::Label^ labelPhone;
	private: System::Windows::Forms::TextBox^ textBoxPhone;

	private: System::Windows::Forms::Label^ labelAddress;
	private: System::Windows::Forms::TextBox^ textBoxAddress;

	private: System::Windows::Forms::Label^ labelPassword;
	private: System::Windows::Forms::TextBox^ textBoxPassword;


	private: System::Windows::Forms::Label^ labelCPassword;
	private: System::Windows::Forms::TextBox^ textBoxCPassword;

	private: System::Windows::Forms::Button^ buttonConfirm;

	private: System::Windows::Forms::Button^ buttonBack;

	protected:

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(RegisterForm::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->labelName = (gcnew System::Windows::Forms::Label());
			this->textBoxName = (gcnew System::Windows::Forms::TextBox());
			this->labelEmail = (gcnew System::Windows::Forms::Label());
			this->textBoxEmail = (gcnew System::Windows::Forms::TextBox());
			this->labelPhone = (gcnew System::Windows::Forms::Label());
			this->textBoxPhone = (gcnew System::Windows::Forms::TextBox());
			this->labelAddress = (gcnew System::Windows::Forms::Label());
			this->textBoxAddress = (gcnew System::Windows::Forms::TextBox());
			this->labelPassword = (gcnew System::Windows::Forms::Label());
			this->textBoxPassword = (gcnew System::Windows::Forms::TextBox());
			this->labelCPassword = (gcnew System::Windows::Forms::Label());
			this->textBoxCPassword = (gcnew System::Windows::Forms::TextBox());
			this->buttonConfirm = (gcnew System::Windows::Forms::Button());
			this->buttonBack = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(221, 9);
			this->label1->Margin = System::Windows::Forms::Padding(7, 0, 7, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(281, 55);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Register";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// labelName
			// 
			this->labelName->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->labelName->AutoSize = true;
			this->labelName->BackColor = System::Drawing::Color::Transparent;
			this->labelName->Location = System::Drawing::Point(145, 90);
			this->labelName->Name = L"labelName";
			this->labelName->Size = System::Drawing::Size(90, 25);
			this->labelName->TabIndex = 1;
			this->labelName->Text = L"Name(*)";
			// 
			// textBoxName
			// 
			this->textBoxName->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->textBoxName->Location = System::Drawing::Point(236, 90);
			this->textBoxName->Name = L"textBoxName";
			this->textBoxName->Size = System::Drawing::Size(371, 31);
			this->textBoxName->TabIndex = 2;
			// 
			// labelEmail
			// 
			this->labelEmail->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->labelEmail->AutoSize = true;
			this->labelEmail->BackColor = System::Drawing::Color::Transparent;
			this->labelEmail->Location = System::Drawing::Point(145, 145);
			this->labelEmail->Name = L"labelEmail";
			this->labelEmail->Size = System::Drawing::Size(87, 25);
			this->labelEmail->TabIndex = 1;
			this->labelEmail->Text = L"Email(*)";
			// 
			// textBoxEmail
			// 
			this->textBoxEmail->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->textBoxEmail->Location = System::Drawing::Point(236, 145);
			this->textBoxEmail->Name = L"textBoxEmail";
			this->textBoxEmail->Size = System::Drawing::Size(371, 31);
			this->textBoxEmail->TabIndex = 2;
			// 
			// labelPhone
			// 
			this->labelPhone->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->labelPhone->AutoSize = true;
			this->labelPhone->BackColor = System::Drawing::Color::Transparent;
			this->labelPhone->Location = System::Drawing::Point(145, 204);
			this->labelPhone->Name = L"labelPhone";
			this->labelPhone->Size = System::Drawing::Size(74, 25);
			this->labelPhone->TabIndex = 1;
			this->labelPhone->Text = L"Phone";
			// 
			// textBoxPhone
			// 
			this->textBoxPhone->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->textBoxPhone->Location = System::Drawing::Point(236, 204);
			this->textBoxPhone->Name = L"textBoxPhone";
			this->textBoxPhone->Size = System::Drawing::Size(371, 31);
			this->textBoxPhone->TabIndex = 2;
			// 
			// labelAddress
			// 
			this->labelAddress->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->labelAddress->AutoSize = true;
			this->labelAddress->BackColor = System::Drawing::Color::Transparent;
			this->labelAddress->Location = System::Drawing::Point(128, 259);
			this->labelAddress->Name = L"labelAddress";
			this->labelAddress->Size = System::Drawing::Size(91, 25);
			this->labelAddress->TabIndex = 1;
			this->labelAddress->Text = L"Address";
			// 
			// textBoxAddress
			// 
			this->textBoxAddress->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->textBoxAddress->Location = System::Drawing::Point(236, 255);
			this->textBoxAddress->Name = L"textBoxAddress";
			this->textBoxAddress->Size = System::Drawing::Size(371, 31);
			this->textBoxAddress->TabIndex = 2;
			// 
			// labelPassword
			// 
			this->labelPassword->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->labelPassword->AutoSize = true;
			this->labelPassword->BackColor = System::Drawing::Color::Transparent;
			this->labelPassword->Location = System::Drawing::Point(91, 309);
			this->labelPassword->Name = L"labelPassword";
			this->labelPassword->Size = System::Drawing::Size(128, 25);
			this->labelPassword->TabIndex = 1;
			this->labelPassword->Text = L"Password(*)";
			// 
			// textBoxPassword
			// 
			this->textBoxPassword->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->textBoxPassword->Location = System::Drawing::Point(236, 309);
			this->textBoxPassword->Name = L"textBoxPassword";
			this->textBoxPassword->PasswordChar = '*';
			this->textBoxPassword->Size = System::Drawing::Size(371, 31);
			this->textBoxPassword->TabIndex = 2;
			// 
			// labelCPassword
			// 
			this->labelCPassword->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->labelCPassword->AutoSize = true;
			this->labelCPassword->BackColor = System::Drawing::Color::Transparent;
			this->labelCPassword->Location = System::Drawing::Point(12, 364);
			this->labelCPassword->Name = L"labelCPassword";
			this->labelCPassword->Size = System::Drawing::Size(208, 25);
			this->labelCPassword->TabIndex = 1;
			this->labelCPassword->Text = L"Confirm Password(*)";
			// 
			// textBoxCPassword
			// 
			this->textBoxCPassword->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->textBoxCPassword->Location = System::Drawing::Point(236, 364);
			this->textBoxCPassword->Name = L"textBoxCPassword";
			this->textBoxCPassword->PasswordChar = '*';
			this->textBoxCPassword->Size = System::Drawing::Size(371, 31);
			this->textBoxCPassword->TabIndex = 2;
			// 
			// buttonConfirm
			// 
			this->buttonConfirm->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->buttonConfirm->Location = System::Drawing::Point(236, 425);
			this->buttonConfirm->Name = L"buttonConfirm";
			this->buttonConfirm->Size = System::Drawing::Size(153, 33);
			this->buttonConfirm->TabIndex = 3;
			this->buttonConfirm->Text = L"Confirm";
			this->buttonConfirm->UseVisualStyleBackColor = true;
			this->buttonConfirm->Click += gcnew System::EventHandler(this, &RegisterForm::buttonConfirm_Click);
			// 
			// buttonBack
			// 
			this->buttonBack->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->buttonBack->Location = System::Drawing::Point(439, 425);
			this->buttonBack->Name = L"buttonBack";
			this->buttonBack->Size = System::Drawing::Size(153, 33);
			this->buttonBack->TabIndex = 4;
			this->buttonBack->Text = L"Back";
			this->buttonBack->UseVisualStyleBackColor = true;
			this->buttonBack->Click += gcnew System::EventHandler(this, &RegisterForm::buttonBack_Click);
			// 
			// RegisterForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(689, 478);
			this->Controls->Add(this->buttonBack);
			this->Controls->Add(this->buttonConfirm);
			this->Controls->Add(this->textBoxCPassword);
			this->Controls->Add(this->textBoxPassword);
			this->Controls->Add(this->textBoxAddress);
			this->Controls->Add(this->textBoxPhone);
			this->Controls->Add(this->textBoxEmail);
			this->Controls->Add(this->textBoxName);
			this->Controls->Add(this->labelCPassword);
			this->Controls->Add(this->labelPassword);
			this->Controls->Add(this->labelAddress);
			this->Controls->Add(this->labelPhone);
			this->Controls->Add(this->labelEmail);
			this->Controls->Add(this->labelName);
			this->Controls->Add(this->label1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(7);
			this->Name = L"RegisterForm";
			this->Text = L"Register";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		public: bool switchToMain = false;
			  bool switchToLogin = false;
private: System::Void buttonBack_Click(System::Object^ sender, System::EventArgs^ e) {
	this->switchToLogin = true;
	this->Close();
}
	public: User^ user;
private: System::Void buttonConfirm_Click(System::Object^ sender, System::EventArgs^ e) {
	try
	{
		String^ name = this->textBoxName->Text;
		String^ operatiune = "register";
		String^ email = this->textBoxEmail->Text;
		String^ address = this->textBoxAddress->Text;
		String^ phone = this->textBoxPhone->Text;
		String^ password = this->textBoxPassword->Text;
		String^ cpassword = this->textBoxCPassword->Text;
		if (password != cpassword) {
			MessageBox::Show("Confirmation password is not equal with password",
				"Password do not match", MessageBoxButtons::OK);
			return;
		}
		//aici trimit catre server email si password
		Json::Value jsonData;
		//clientSocket->Connect(serverEndPoint);

		jsonData["operatiune"] = msclr::interop::marshal_as<std::string>(operatiune);
		jsonData["name"] = msclr::interop::marshal_as<std::string>(name);
		jsonData["mail"] = msclr::interop::marshal_as<std::string>(email);
		jsonData["address"] = msclr::interop::marshal_as<std::string>(address);
		jsonData["phone"] = msclr::interop::marshal_as<std::string>(phone);
		jsonData["password"] = msclr::interop::marshal_as<std::string>(GetSHA256Hash(password));

		user = gcnew User();
		user->email = email;
		std::string jsonString = jsonData.toStyledString();


		// Convert the string to bytes
		array<Byte>^ dataBytes = Encoding::ASCII->GetBytes(msclr::interop::marshal_as<String^>(jsonString));
		pin_ptr<unsigned char> pinnedData = &dataBytes[0];
		int dataLength = dataBytes->Length;

		int bytesSent = send(connectSocket, reinterpret_cast<char*>(pinnedData), dataLength, 0);
		if (bytesSent == SOCKET_ERROR)
		{
			closesocket(connectSocket);
			WSACleanup();
			return;
		}
		else
		{
			// Receive the response from the server
			array<Byte>^ recvBuffer = gcnew array<Byte>(sizeof(int));
			pin_ptr<Byte> pinnedRecvBuffer = &recvBuffer[0];
			int bytesReceived = recv(connectSocket, reinterpret_cast<char*>(pinnedRecvBuffer), sizeof(int), 0);
			if (bytesReceived == sizeof(int))
			{
				// Convert the received byte array to an integer
				int receivedValue = BitConverter::ToInt32(recvBuffer, 0);

				// Process the received integer
				if (receivedValue == 1) {
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
		}
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
};
}
