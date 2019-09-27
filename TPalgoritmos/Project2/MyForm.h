#pragma once
#include"CyGPuntaje.h"
#include"Controlador.h"
namespace Project2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	private:
		Controlador* objControlador;
		Puntaje* objPuntaje;
	public:
		MyForm(Puntaje* objPuntaje)
		{
			this->objPuntaje = objPuntaje;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Timer^ timer1;

	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 30;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::Timer1_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(604, 690);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyUp);
			this->ResumeLayout(false);

		}
#pragma endregion
	public: int contador = 0;
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		objControlador = new Controlador(this->ClientRectangle);
		
		objControlador->setcontador(objPuntaje->getpuntaje());
	}
	private: System::Void Timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		
		Graphics^ g;
		BufferedGraphicsContext^ context = BufferedGraphicsManager::Current;
		BufferedGraphics^ buffer;
		g = this->CreateGraphics();
		buffer = context->Allocate(g, this->ClientRectangle);
		buffer->Graphics->Clear(Color::White);

		objControlador->timer(contador, buffer->Graphics);
		//SolidBrush^ lapiz = gcnew SolidBrush(Color::FromArgb(200, 200, 200));
		//buffer->Graphics->FillRectangle(lapiz, 100, 100, 250, 250);

		buffer->Render(g);
		delete buffer;
		delete context;
		delete g;
		contador++;
		if (contador == 20)contador = 1;
		this->Text ="Puntaje: " + objControlador->getcontador().ToString();
	}
	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyData != Keys::Escape)
			objControlador->cambiardir(e->KeyData);
		else {
			objPuntaje->setpuntaje(objControlador->getcontador());
			this->Close();
		}
	}
	private: System::Void MyForm_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		objControlador->cambiardir(Keys::None);
	}
	};
}
