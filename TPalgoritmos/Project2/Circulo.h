#pragma once
#include<cstdlib>
#include<ctime>
#include<cmath>
using namespace System::Drawing;
class CCirculo
{
public:
	CCirculo(int x, int y);
	~CCirculo();
	void dibujar(Graphics^ g);
	bool HayColision(int px, int py, int ancho, int largo);
	void mover();
	bool getPY();
	bool llegoborde() { return llegobordeV; }
private:
	int crad, r, g, b, x, y;
	int dy;
	int alto;
	int velocidad;
	bool llegobordeV;
};

CCirculo::CCirculo(int x, int y)
{
	crad = x * 0.05;
	r = rand() % 255;
	g = rand() % 255;
	b = rand() % 255;
	this->x = rand() % int(x);
	this->y = rand() % int(y*0.15f)+crad;
	velocidad = rand() % 20 + 10;
	dy = 1*velocidad;
	alto = y;
	llegobordeV = false;
}
CCirculo::~CCirculo() {}
bool CCirculo::HayColision(int px, int py, int ancho, int largo)
{
	auto funcion = [px, py, ancho, largo](int x, int y, int crad)->bool {return bool(Rectangle(x, y, crad, crad).IntersectsWith(Rectangle(px, py, ancho, largo)) && (y) < py); };
	bool colision = false;
	
	if (funcion(x, y, crad)) {
		colision = true;
	}
	return colision;
}
void CCirculo::dibujar(Graphics^ g) {
	//(Color::FromArgb(r,g,b), grosor);
	Pen^ lapiz = gcnew Pen(Color::FromArgb(r, this->g, b), 8);
	//g->DrawRectangle(lapiz, x, y, crad, crad);
	g->DrawEllipse(lapiz, x, y, crad, crad);
}
void CCirculo::mover() {//px del jugador
		if (y < alto - crad)
			y += dy;
		else
			llegobordeV = true;
}
bool CCirculo::getPY() {
	return y+crad;
}