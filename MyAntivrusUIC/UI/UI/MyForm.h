#pragma once
#include <Windows.h>

namespace UI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(55, 63);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(111, 52);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Начать сканирование";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(55, 121);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(111, 52);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Остановить сканирование";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(55, 179);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(111, 52);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Переместить в карантин";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(55, 237);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(111, 46);
			this->button4->TabIndex = 3;
			this->button4->Text = L"Удалить ";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(711, 395);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
HANDLE hMailslotServer;
LPDWORD msgSize, msgQuantity, written;
BOOL returnCode;


void connectToMailslot() {
	hMailslotServer = CreateFile(L"\\\\.\\Mailslot\\mailServer", GENERIC_WRITE, FILE_SHARE_READ, NULL, OPEN_EXISTING, 0, NULL);
	if (hMailslotServer == INVALID_HANDLE_VALUE) {
		MessageBox::Show("Не удалось подключиться к серверу.");
	}
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	connectToMailslot();
	LPCSTR message = "001";
	WriteFile(hMailslotServer, message, strlen(message) + 1, written, NULL);
}
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	connectToMailslot();
	LPCSTR message = "002";
	WriteFile(hMailslotServer, message, strlen(message) + 1, written, NULL);
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	connectToMailslot();
	LPCSTR message = "003";
	WriteFile(hMailslotServer, message, strlen(message) + 1, written, NULL);
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	connectToMailslot();
	LPCSTR message = "004";
	WriteFile(hMailslotServer, message, strlen(message) + 1, written, NULL);
}
};
}
