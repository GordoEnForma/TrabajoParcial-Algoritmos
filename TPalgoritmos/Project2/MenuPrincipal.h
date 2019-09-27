#pragma once
#include"CyGPuntaje.h"
#include"MyForm.h"
namespace Project2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MenuPrincipal
	/// </summary>
	public ref class MenuPrincipal : public System::Windows::Forms::Form
	{
	public:
		MenuPrincipal()
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
	private: System::Windows::Forms::Timer^  timer1;
	public:
	private:
		Puntaje*objPuntaje;
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MenuPrincipal()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	protected:
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::ComponentModel::IContainer^  components;

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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(91, 28);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(95, 47);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Nuevo Juego";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MenuPrincipal::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(91, 99);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(95, 47);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Cargar Juego";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MenuPrincipal::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(91, 165);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(95, 47);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Guardar Juego";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MenuPrincipal::button3_Click);
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MenuPrincipal::timer1_Tick);
			// 
			// MenuPrincipal
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"MenuPrincipal";
			this->Text = L"MenuPrincipal";
			this->Load += gcnew System::EventHandler(this, &MenuPrincipal::MenuPrincipal_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MenuPrincipal_Load(System::Object^  sender, System::EventArgs^  e) {
		objPuntaje = new Puntaje(0);
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		Form^ f = gcnew Project2::MyForm(objPuntaje);
		this->Visible = false;
		f->ShowDialog();
		delete f;
		this->Visible = true;
	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		objPuntaje->cargarPuntaje();
	}
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
		objPuntaje->guardarPuntaje();
	}
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		this->Text = objPuntaje->getpuntaje().ToString();
	}
};
}
