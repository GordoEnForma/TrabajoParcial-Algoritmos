#pragma once
#include<cmath>
using namespace System::Drawing;
using namespace System::Windows::Forms;
class Personaje
{
public:
	Personaje(Rectangle RecForm);
	~Personaje();
	void dibujar(Graphics^ g);
	void mover();
	float getx() { return x; }
	void cambiardireccion(Keys tecla);
	float gety() { return y; }
	float getancho() { return ancho; }
	float getlargo() { return largo; }
private:
	float x, y, dx, ancho, largo;
	float anchof;
	int velocidad;
};

Personaje::Personaje(Rectangle RecForm)
{
	anchof = RecForm.Width;
	ancho = RecForm.Width * 0.25f;
	largo = RecForm.Height*0.05;
	x = RecForm.Width / 2.0f;
	y = RecForm.Height - largo*2;
	dx = 0;
	velocidad = 30;
}

Personaje::~Personaje()
{
}
void Personaje::dibujar(Graphics^ g) {
	SolidBrush^ lapiz = gcnew SolidBrush(Color::BlueViolet);
	g->FillRectangle(lapiz, x, y, ancho, largo);
}
void Personaje::mover() {
	if (x+dx < 0 || x + ancho+dx > anchof) {
		dx = 0;
	}
	else
	{
		x += dx;
	}
}
void Personaje::cambiardireccion(Keys tecla) {
	switch (tecla)
	{
	case System::Windows::Forms::Keys::A:
		dx = (-1)*velocidad;
		break;
	case System::Windows::Forms::Keys::D:
		dx = 1*velocidad;
		break;
	case System::Windows::Forms::Keys::Left:
		dx = (-1) * velocidad;
		break;
	case System::Windows::Forms::Keys::Right:
		dx = 1 * velocidad;
		break;
	case System::Windows::Forms::Keys::None:
		dx = 0;
		break;
	}
}