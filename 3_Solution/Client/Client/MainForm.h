#pragma once
#include "User.h"
#include <Windows.h>
#include <json/json.h>
#include <msclr/marshal_cppstd.h>
#include <winsock2.h>
#include <stdio.h>
namespace Client {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		SOCKET connectSocket;
		MainForm(void)
		{
			InitializeComponent();
			this->CenterToScreen();
		}
		MainForm(User^ user, SOCKET socket)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			UserInfo->Text = "Welcome " + user->email+ " ! ";
			this->CenterToScreen();
			connectSocket = socket;
		}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Label^ UserInfo;
	private: System::Windows::Forms::Button^ playButton;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::ComponentModel::IContainer^ components;
	protected:
	protected:
	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->UserInfo = (gcnew System::Windows::Forms::Label());
			this->playButton = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(491, 30);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Welcome to Dashboard";
			this->label1->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// UserInfo
			// 
			this->UserInfo->AutoSize = true;
			this->UserInfo->BackColor = System::Drawing::Color::Transparent;
			this->UserInfo->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->UserInfo->Location = System::Drawing::Point(29, 60);
			this->UserInfo->Name = L"UserInfo";
			this->UserInfo->Size = System::Drawing::Size(49, 19);
			this->UserInfo->TabIndex = 1;
			this->UserInfo->Text = L"label2";
			// 
			// playButton
			// 
			this->playButton->BackColor = System::Drawing::Color::Transparent;
			this->playButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"playButton.BackgroundImage")));
			this->playButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->playButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->playButton->Location = System::Drawing::Point(173, 130);
			this->playButton->Name = L"playButton";
			this->playButton->Size = System::Drawing::Size(173, 128);
			this->playButton->TabIndex = 2;
			this->playButton->Text = L"Play Game";
			this->playButton->UseVisualStyleBackColor = false;
			this->playButton->Click += gcnew System::EventHandler(this, &MainForm::playButton_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(235, 95);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(44, 20);
			this->label2->TabIndex = 3;
			this->label2->Text = L"0:00";
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 1000;
			this->timer1->Tick += gcnew System::EventHandler(this, &MainForm::timer1_Tick);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(536, 407);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->playButton);
			this->Controls->Add(this->UserInfo);
			this->Controls->Add(this->label1);
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Dashboard";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public: bool switchToGame = false;
	private: System::Void playButton_Click(System::Object^ sender, System::EventArgs^ e) {
		// Disable the button
		playButton->Enabled = false;

		// Start the timer
		timer1->Start();
		Json::Value jsonData;
		String^ operatiune = "rtg";
		jsonData["operatiune"] = msclr::interop::marshal_as<std::string>(operatiune);
		std::string jsonString = jsonData.toStyledString();


		// Convert the string to bytes
		array<Byte>^ dataBytes = Encoding::ASCII->GetBytes(msclr::interop::marshal_as<String^>(jsonString));
		pin_ptr<unsigned char> pinnedData = &dataBytes[0];
		int dataLength = dataBytes->Length;
		int bytesSent = send(connectSocket, reinterpret_cast<char*>(pinnedData), dataLength, 0);

		array<Byte>^ recvBuffer = gcnew array<Byte>(sizeof(int));
		pin_ptr<Byte> pinnedRecvBuffer = &recvBuffer[0];
		int bytesReceived = recv(connectSocket, reinterpret_cast<char*>(pinnedRecvBuffer), sizeof(int), 0);
		if (bytesReceived == sizeof(int))
		{
			// Convert the received byte array to an integer
			int receivedValue = BitConverter::ToInt32(recvBuffer, 0);

			// Process the received integer
			if (receivedValue == 2) {
				this->switchToGame = true;
				this->Close();

			}
		}


	}

	public: static int Second = 0;
	static int Minute = 0;
	String^ Sec;
	String^ Min;
	System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		Second++;
		if (Second == 60) {
			Second = 0;
			Minute++;
		}
		Sec = Convert::ToString(Second);
		Min = Convert::ToString(Minute);
		label2->Text = Min + ":" + Sec;
		// Timer tick event handler
		// Update your timer display or perform other actions here
	}
};
}
