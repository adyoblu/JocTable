#pragma once
#include <list>
#include <json/json.h>
#include <msclr\marshal_cppstd.h>
#include <iostream>

namespace Client {

	using namespace System;
	using namespace System::Net;
	using namespace System::Net::Sockets;
	using namespace System::Text;
	using namespace msclr::interop;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	const int dimensiuneHarta  = 8;
	const int dimensiuneCelula = 60;

	int** matrix;

	bool toShowSteps;

	public ref class GameForm : public System::Windows::Forms::Form
	{
	protected:
		~GameForm()
		{
			if (components)
			{
				delete components;
			}
		}

		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(GameForm::typeid));
			this->SuspendLayout();
			// 
			// GameForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(279, 261);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"GameForm";
			this->Text = L"GameForm";
			this->ResumeLayout(false);

		}
	private:
		System::ComponentModel::Container^ components;

		Image^ figuraAlba;
		Image^ figuraNeagra;
		Image^ damaAlba;
		Image^ damaNeagra;

		Button^ butonApasat;
		Button^ butonInapoi;

		array<Button^, 2>^ butoane = gcnew array<Button^, 2>(dimensiuneHarta , dimensiuneHarta );
		Generic::List<Button^>^ pasi = gcnew Generic::List<Button^>;

		int jucatorAcum;
		int nrMancate = 0;

		bool seMisca;
		bool continua;

	public:
		SOCKET connectSocket;

		GameForm(SOCKET socket)
		{
			InitializeComponent();
			this->Text = "Dame";
			this->BackColor = Color::Black;
			this->Width = dimensiuneHarta  * dimensiuneCelula + 20;
			this->Height = dimensiuneHarta  * dimensiuneCelula + 70;
			this->CenterToScreen();
			connectSocket = socket;
			Init();
		}

		void Init() {

			figuraAlba = gcnew Bitmap(gcnew Bitmap(L"image\\w.png"), dimensiuneCelula - 11, dimensiuneCelula - 11);
			figuraNeagra = gcnew Bitmap(gcnew Bitmap(L"image\\b.png"), dimensiuneCelula - 11, dimensiuneCelula - 11);
			damaAlba = gcnew Bitmap(gcnew Bitmap(L"image\\wd.png"), dimensiuneCelula - 11, dimensiuneCelula - 11);
			damaNeagra = gcnew Bitmap(gcnew Bitmap(L"image\\bd.png"), dimensiuneCelula - 11, dimensiuneCelula - 11);

			jucatorAcum = 1;
			seMisca = false;
			butonApasat = nullptr;
			toShowSteps = false;

			MenuStrip^ menuStrip = gcnew MenuStrip();
			ToolStripButton^ reset = gcnew ToolStripButton("Un joc nou");
			ToolStripButton^ showMe = gcnew ToolStripButton("Arata miscarile");
			ToolStripButton^ wtf = gcnew ToolStripButton("Despre program...");
			menuStrip->Dock = DockStyle::Top;
			this->Controls->Add(menuStrip);
			menuStrip->Items->Add(reset);
			menuStrip->Items->Add(showMe);
			menuStrip->Items->Add(wtf);
			reset->Click += gcnew EventHandler(this, &GameForm::reseteazaJoc);
			showMe->Click += gcnew EventHandler(this, &GameForm::Hint);
			wtf->Click += gcnew EventHandler(this, &GameForm::Info);

			matrix = new int* [dimensiuneHarta ];
			for (size_t i = 0; i < dimensiuneHarta ; i++)
			{
				matrix[i] = new int[dimensiuneHarta ];
			}
			for (size_t i = 0; i < dimensiuneHarta ; i++)
			{
				for (size_t j = 0; j < dimensiuneHarta ; j++)
				{
					if (i == 0 && j % 2 == 0) matrix[i][j] = 2;
					else if (i == 1 && j % 2 != 0) matrix[i][j] = 2;
					else if (i == 2 && j % 2 == 0) matrix[i][j] = 2;
					else if (i == 5 && j % 2 != 0) matrix[i][j] = 1;
					else if (i == 6 && j % 2 == 0) matrix[i][j] = 1;
					else if (i == 7 && j % 2 != 0) matrix[i][j] = 1;
					else matrix[i][j] = 0;
				}
			}
			FormeazaMapa();
		}

		System::Void reseteazaJoc(System::Object^ sender, System::EventArgs^ e) {
			reset();
		}
		System::Void Hint(System::Object^ sender, System::EventArgs^ e) {
			toShowSteps = toShowSteps == true ? false : true;
		}
		System::Void Info(System::Object^ sender, System::EventArgs^ e) {
			MessageBox::Show("Joc creeat in c++", "Succes!");
		}

		void FormeazaMapa() {
			for (int i = 0; i < dimensiuneHarta ; i++)
			{
				for (int j = 0; j < dimensiuneHarta ; j++)
				{
					Button^ button = gcnew Button();
					button->Location = System::Drawing::Point(j * dimensiuneCelula, i * dimensiuneCelula + 25);
					button->Size = System::Drawing::Size(dimensiuneCelula, dimensiuneCelula);
					button->Visible = true;
					button->FlatStyle = FlatStyle::Flat;
					button->Click += gcnew EventHandler(this, &GameForm::Apasare);

					if (matrix[i][j] == 1) {
						button->Image = figuraAlba;
					}
					else if (matrix[i][j] == 2) {
						button->Image = figuraNeagra;
					}

					this->Controls->Add(button);
					butoane[i, j] = button;

					button->BackColor = Culoare(button);
				}
			}
		}


		void update() {
			this->Controls->Clear();
			figuraAlba = gcnew Bitmap(gcnew Bitmap(L"image\\w.png"), dimensiuneCelula - 11, dimensiuneCelula - 11);
			figuraNeagra = gcnew Bitmap(gcnew Bitmap(L"image\\b.png"), dimensiuneCelula - 11, dimensiuneCelula - 11);
			damaAlba = gcnew Bitmap(gcnew Bitmap(L"image\\wd.png"), dimensiuneCelula - 11, dimensiuneCelula - 11);
			damaNeagra = gcnew Bitmap(gcnew Bitmap(L"image\\bd.png"), dimensiuneCelula - 11, dimensiuneCelula - 11);


			MenuStrip^ menuStrip = gcnew MenuStrip();
			ToolStripButton^ reset = gcnew ToolStripButton("Un joc nou");
			ToolStripButton^ showMe = gcnew ToolStripButton("Arata miscarile");
			ToolStripButton^ wtf = gcnew ToolStripButton("Despre program...");
			menuStrip->Dock = DockStyle::Top;
			this->Controls->Add(menuStrip);
			menuStrip->Items->Add(reset);
			menuStrip->Items->Add(showMe);
			menuStrip->Items->Add(wtf);
			reset->Click += gcnew EventHandler(this, &GameForm::reseteazaJoc);
			showMe->Click += gcnew EventHandler(this, &GameForm::Hint);
			wtf->Click += gcnew EventHandler(this, &GameForm::Info);

			Json::Value jsonData;
			jsonData["operatiune"] = Json::Value("joc");
			jsonData["player"] = Json::Value(jucatorAcum);
			jsonData["matrix"] = Json::Value(Json::arrayValue);

			Json::Value matrixJson(Json::arrayValue);
			for (int i = 0; i < 8; ++i) {
				Json::Value rowJson(Json::arrayValue);
				for (int j = 0; j < 8; ++j) {
					rowJson.append(matrix[i][j]);
				}
				matrixJson.append(rowJson);
			}
			jsonData["matrix"] = matrixJson;

			std::string jsonString = jsonData.toStyledString();
			array<Byte>^ dataBytes = Encoding::ASCII->GetBytes(msclr::interop::marshal_as<String^>(jsonString));
			pin_ptr<unsigned char> pinnedData = &dataBytes[0];
			int dataLength = dataBytes->Length;
			send(connectSocket, reinterpret_cast<char*>(pinnedData), dataLength, 0);

			array<Byte>^ recvBuffer = gcnew array<Byte>(sizeof(int));
			pin_ptr<Byte> pinnedRecvBuffer = &recvBuffer[0];
			std::cout << jucatorAcum << std::endl;
			for (int i = 0; i < 8; ++i, std::cout << std::endl)
				for (int j = 0; j < 8; j++)
					std::cout << matrix[i][j];

			recv(connectSocket, reinterpret_cast<char*>(pinnedRecvBuffer), sizeof(int), 0);


			int jucatorAcum = jsonData["player"].asInt();

			for (int i = 0; i < 8; ++i)
			{
				for (int j = 0; j < 8; ++j)
				{
					matrix[i][j] = jsonData["matrix"][i][j].asInt();
				}

			}
			std::cout << jucatorAcum << std::endl;
			for (int i = 0; i < 8; ++i, std::cout << std::endl)
				for (int j = 0; j < 8; j++)
					std::cout << matrix[i][j];

			
			FormeazaMapa();
		}

		Color Culoare(Button^ button) {  
			if (button->Location.Y / dimensiuneCelula % 2 != 0 && button->Location.X / dimensiuneCelula % 2 == 0) {
				return Color::DarkGray;
			}
			else if (button->Location.Y / dimensiuneCelula % 2 == 0 && button->Location.X / dimensiuneCelula % 2 != 0) {
				return Color::DarkGray;
			}
			else {
				return Color::White;
			}
		}

		System::Void Apasare(System::Object^ sender, System::EventArgs^ e) {
			Update();
			if (butonInapoi != nullptr) {
				butonInapoi->BackColor = Culoare(butonInapoi);
			}

			butonApasat = safe_cast<Button^> (sender);

			if (matrix[butonApasat->Location.Y / dimensiuneCelula][butonApasat->Location.X / dimensiuneCelula] != 0 && matrix[butonApasat->Location.Y / dimensiuneCelula][butonApasat->Location.X / dimensiuneCelula] == jucatorAcum) {
				closeSteps();
				if (toShowSteps) butonApasat->BackColor = Color::DarkRed;
				dezactiveazaTot();
				butonApasat->Enabled = true;
				nrMancate = 0;
				//if (butonApasat->Text == "D") arataPasi(butonApasat->Location.Y / dimensiuneCelula, butonApasat->Location.X / dimensiuneCelula, true);
				if (butonApasat->Image == damaAlba || butonApasat->Image == damaNeagra) arataPasi(butonApasat->Location.Y / dimensiuneCelula, butonApasat->Location.X / dimensiuneCelula, true);
				else arataPasi(butonApasat->Location.Y / dimensiuneCelula, butonApasat->Location.X / dimensiuneCelula, false);

				if (seMisca) {
					closeSteps();
					butonApasat->BackColor = Culoare(butonApasat);
					//showPossibleSteps();
					seMisca = false;
				}
				else seMisca = true;
			}
			else {
				if (seMisca) {
					continua = false;
					if (Math::Abs(butonApasat->Location.X / dimensiuneCelula - butonInapoi->Location.X / dimensiuneCelula) > 1) {
						continua = true;
						stergeMancat(butonApasat, butonInapoi);
					}
					int temp = matrix[butonApasat->Location.Y / dimensiuneCelula][butonApasat->Location.X / dimensiuneCelula];
					matrix[butonApasat->Location.Y / dimensiuneCelula][butonApasat->Location.X / dimensiuneCelula] = matrix[butonInapoi->Location.Y / dimensiuneCelula][butonInapoi->Location.X / dimensiuneCelula];
					matrix[butonInapoi->Location.Y / dimensiuneCelula][butonInapoi->Location.X / dimensiuneCelula] = temp;
					butonApasat->Image = butonInapoi->Image;
					butonInapoi->Image = nullptr;
					butonApasat->Text = butonInapoi->Text;
					butonInapoi->Text = "";
					//schimbaDama(butonApasat);
					nrMancate = 0;
					seMisca = false;
					closeSteps();
					dezactiveazaTot();
					//if (butonApasat->Text == "D") arataPasi(butonApasat->Location.Y / dimensiuneCelula, butonApasat->Location.X / dimensiuneCelula, true);
					if (butonApasat->Image == damaAlba || butonApasat->Image == damaNeagra) arataPasi(butonApasat->Location.Y / dimensiuneCelula, butonApasat->Location.X / dimensiuneCelula, true);
					else arataPasi(butonApasat->Location.Y / dimensiuneCelula, butonApasat->Location.X / dimensiuneCelula, false);
					if (nrMancate == 0 || !continua) {
						closeSteps();
						schimbaJucator();
						update();
						//showPossibleSteps();
						continua = false;
						

					}
					else if (continua) {
						if (toShowSteps) butonApasat->BackColor = Color::DarkRed;
						butonApasat->Enabled = true;
						seMisca = true;
					}
				}
			}
			//FormeazaMapa();
			butonInapoi = butonApasat; 


		}

		void reset() {
			this->Controls->Clear();
			Init();
		}

		void schimbaJucator() {
			jucatorAcum = jucatorAcum == 1 ? 2 : 1;
		}

		bool inHarta(int i, int j) {
			if (i >= dimensiuneHarta  || j >= dimensiuneHarta  || i < 0 || j < 0)
				return false;
			return true;
		}

		void activeazaTot() {
			for (int i = 0; i < dimensiuneHarta ; i++)
			{
				for (int j = 0; j < dimensiuneHarta ; j++)
				{
					butoane[i, j]->Enabled = true;
				}
			}
		}

		void dezactiveazaTot() {
			for (int i = 0; i < dimensiuneHarta ; i++)
			{
				for (int j = 0; j < dimensiuneHarta ; j++)
				{
					butoane[i, j]->Enabled = false;
				}
			}
		}

		void closeSteps() { 
			for (int i = 0; i < dimensiuneHarta ; i++)
			{
				for (int j = 0; j < dimensiuneHarta ; j++)
				{
					butoane[i, j]->BackColor = Culoare(butoane[i, j]);
				}
			}
		}

		void showPossibleSteps() {
			bool isRege = false;
			bool isEatStep = false;
			dezactiveazaTot();
			for (size_t i = 0; i < dimensiuneHarta ; i++)
			{
				for (size_t j = 0; j < dimensiuneHarta ; j++)
				{
					if (matrix[i][j] == jucatorAcum) {
						//if (butoane[i, j]->Text == "D") isRege = true;
						if (butonApasat->Image == damaAlba || butonApasat->Image == damaNeagra) isRege = true;
						else isRege = false;
						if (isAbleToEat(i, j, isRege, new int[2] { 0, 0 })) {
							isEatStep = true;
							butoane[i, j]->Enabled = true;
						}
					}
				}
			}
			if (!isEatStep) activeazaTot();
		}

		void schimbaDama(Button^ button) {
			if (matrix[button->Location.Y / dimensiuneCelula][button->Location.X / dimensiuneCelula] == 2 && button->Location.Y / dimensiuneCelula == dimensiuneHarta  - 1) {
				//button->Text = "D";
				//button->BackgroundImage = nullptr;
				button->Image = damaNeagra;
			}
			if (matrix[button->Location.Y / dimensiuneCelula][button->Location.X / dimensiuneCelula] == 1 && button->Location.Y / dimensiuneCelula == 0) {
				//button->Text = "D";
				//button->BackgroundImage = nullptr;
				button->Image = damaAlba;
			}
		}

		void stergeMancat(Button^ endButton, Button^ startButton) {
			int count = Math::Abs(endButton->Location.Y / dimensiuneCelula - startButton->Location.Y / dimensiuneCelula);
			int startIndexX = endButton->Location.Y / dimensiuneCelula - startButton->Location.Y / dimensiuneCelula;
			int startIndexY = endButton->Location.X / dimensiuneCelula - startButton->Location.X / dimensiuneCelula;
			startIndexX = startIndexX < 0 ? -1 : 1;
			startIndexY = startIndexY < 0 ? -1 : 1;
			int currCount = 0;
			int i = startButton->Location.Y / dimensiuneCelula + startIndexX;
			int j = startButton->Location.X / dimensiuneCelula + startIndexY;
			while (currCount < count - 1) {
				matrix[i][j] = 0;
				butoane[i, j]->Image = nullptr;
				butoane[i, j]->Text = "";
				i += startIndexX;
				j += startIndexY;
				currCount++;
			}
		}

		void arataPasi(int currentI, int currentJ, bool isRege) {
			pasi->Clear();
			arataDiagonala(currentI, currentJ, isRege);
			if (nrMancate > 0) inchidePasi(pasi);
		}

		void arataDiagonala(int currentI, int currentJ, bool isRege) {
			int j = currentJ + 1;
			for (int i = currentI - 1; i >= 0; i--) {
				if (jucatorAcum == 2 && !isRege && !continua) break;
				if (inHarta(i, j)) {
					if (!determinaDrum(i, j)) break;
				}
				if (j < 7) j++;
				else break;
				if (!isRege) break;
			}

			j = currentJ - 1;
			for (int i = currentI - 1; i >= 0; i--) {
				if (jucatorAcum == 2 && !isRege && !continua) break;
				if (inHarta(i, j)) {
					if (!determinaDrum(i, j)) break;
				}
				if (j > 0) j--;
				else break;
				if (!isRege) break;
			}

			j = currentJ - 1;
			for (int i = currentI + 1; i < 8; i++) {
				if (jucatorAcum == 1 && !isRege && !continua) break;
				if (inHarta(i, j)) {
					if (!determinaDrum(i, j)) break;
				}
				if (j > 0) j--;
				else break;
				if (!isRege) break;
			}

			j = currentJ + 1;
			for (int i = currentI + 1; i < 8; i++) {
				if (jucatorAcum == 1 && !isRege && !continua) break;
				if (inHarta(i, j)) {
					if (!determinaDrum(i, j)) break;
				}
				if (j < 7) j++;
				else break;
				if (!isRege) break;
			}
		}

		bool determinaDrum(int i, int j) {
			if (matrix[i][j] == 0 && !continua) {
				if (toShowSteps) butoane[i, j]->BackColor = Color::Yellow;
				butoane[i, j]->Enabled = true;
				pasi->Add(butoane[i, j]);
			}
			else {
				if (matrix[i][j] != jucatorAcum) {
					//if (butonApasat->Text == "D") arataProcedura(i, j, true);
					if (butonApasat->Image == damaAlba || butonApasat->Image == damaNeagra) arataProcedura(i, j, true);
					else arataProcedura(i, j, false);
				}
				return false;
			}
			return true;
		}

		void inchidePasi(Generic::List<Button^>^ pasi) {
			if (pasi->Count > 0) {
				for (size_t i = 0; i < pasi->Count; i++)
				{
					pasi[i]->BackColor = Culoare(pasi[i]);
					pasi[i]->Enabled = false;
				}
			}
		}

		void arataProcedura(int i, int j, bool isRege) {
			int dirX = i - butonApasat->Location.Y / dimensiuneCelula;
			int dirY = j - butonApasat->Location.X / dimensiuneCelula;
			dirX = dirX < 0 ? -1 : 1;
			dirY = dirY < 0 ? -1 : 1;
			int il = i;
			int jl = j;
			bool isEmpty = true;
			while (inHarta(il, jl)) {
				if (matrix[il][jl] != 0 && matrix[il][jl] != jucatorAcum) {
					isEmpty = false;
					break;
				}
				il += dirX;
				jl += dirY;
				if (!isRege) break;
			}
			if (isEmpty) return;

			Generic::List<Button^>^ toClose = gcnew Generic::List<Button^>;
			bool closeSimple = false;

			int ik = il + dirX;
			int jk = jl + dirY;
			while (inHarta(ik, jk)) {
				if (matrix[ik][jk] == 0) {
					if (isAbleToEat(ik, jk, isRege, new int[2] { dirX, dirY })) {
						closeSimple = true;
					}
					else {
						toClose->Add(butoane[ik, jk]);
					}
					if (toShowSteps) butoane[ik, jk]->BackColor = Color::Yellow;
					butoane[ik, jk]->Enabled = true;
					nrMancate++;
				}
				else break;
				if (!isRege) break;
				ik += dirX;
				jk += dirY;
			}
			if (closeSimple && toClose->Count > 0) {
				inchidePasi(toClose);
			}
		}

		bool isAbleToEat(int currentI, int currentJ, bool isRege, int direction[]) {
			bool eatStep = false;

			int j = currentJ + 1;
			for (int i = currentI - 1; i >= 0; i--)
			{
				if (jucatorAcum == 2 && !isRege && !continua) break; 
				if (direction[0] == 1 && direction[1] == -1 && isRege) break; 
				if (inHarta(i, j)) {
					if (matrix[i][j] != 0 && matrix[i][j] != jucatorAcum) {
						eatStep = true;
						if (!inHarta(i - 1, j + 1)) eatStep = false;
						else if (matrix[i - 1][j + 1] != 0) eatStep = false; 
						else return eatStep;
					}
				}
				if (j < 7) j++;
				else break;
				if (!isRege) break;
			}

			j = currentJ - 1;
			for (int i = currentI - 1; i >= 0; i--) 
			{
				if (jucatorAcum == 2 && !isRege && !continua) break; 
				if (direction[0] == 1 && direction[1] == 1 && isRege) break;
				if (inHarta(i, j)) {
					if (matrix[i][j] != 0 && matrix[i][j] != jucatorAcum) {
						eatStep = true;
						if (!inHarta(i - 1, j - 1)) eatStep = false;
						else if (matrix[i - 1][j - 1] != 0) eatStep = false;
						else return eatStep;
					}
				}
				if (j > 0) j--;
				else break;
				if (!isRege) break;
			}

			j = currentJ - 1;
			for (int i = currentI + 1; i >= 0; i--)
			{
				if (jucatorAcum == 1 && !isRege && !continua) break; 
				if (direction[0] == -1 && direction[1] == 1 && isRege) break;
				if (inHarta(i, j)) {
					if (matrix[i][j] != 0 && matrix[i][j] != jucatorAcum) {
						eatStep = true;
						if (!inHarta(i + 1, j - 1)) eatStep = false;
						else if (matrix[i + 1][j - 1] != 0) eatStep = false; 
						else return eatStep;
					}
				}
				if (j > 0) j--;
				else break;
				if (!isRege) break;
			}

			j = currentJ + 1;
			for (int i = currentI + 1; i >= 0; i--) 
			{
				if (jucatorAcum == 1 && !isRege && !continua) break;
				if (direction[0] == -1 && direction[1] == -1 && isRege) break;
				if (inHarta(i, j)) {
					if (matrix[i][j] != 0 && matrix[i][j] != jucatorAcum) {
						eatStep = true;
						if (!inHarta(i + 1, j + 1)) eatStep = false; 
						else if (matrix[i + 1][j + 1] != 0) eatStep = false;
						else return eatStep;
					}
				}
				if (j < 7) j++;
				else break;
				if (!isRege) break;
			}
			return eatStep;
		}
#pragma endregion
	};
}