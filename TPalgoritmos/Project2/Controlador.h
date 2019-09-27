#pragma once
#include"Personaje.h"
#include"Circulo.h"
#include"Lista.h"
class Controlador
{
public:
	Controlador(Rectangle recform) {
		this->recform = recform;
		listaCirculos = new CLista<CCirculo>();
		listaCirculos->InsercionInicio(new CCirculo(recform.Width,recform.Height));
		objPersonaje = new Personaje(recform);
		contador = new long long;
		*contador = 0;
	}
	~Controlador() {}
	void timer(int ins, Graphics^g) {
		if (ins == 1) {
			listaCirculos->InsercionInicio(new CCirculo(recform.Width, recform.Height));
		}
		if (listaCirculos->Get_Cantidad() > 0) {
			for (int i = 1; i <= listaCirculos->Get_Cantidad(); i++)
			{
				//insercion
				
				listaCirculos->Recuperar(i)->dibujar(g);
				
				//colision:
				
				if (listaCirculos->Recuperar(i)->getPY() < objPersonaje->gety()-200) {
					if (listaCirculos->Recuperar(i)->HayColision(objPersonaje->getx(), objPersonaje->gety(), objPersonaje->getancho(),objPersonaje->getlargo())) {
						listaCirculos->Eliminar(i);
						(*contador)++;
					}
					//else if (listaCirculos->Recuperar(i)->llegoborde()) { //esto es para eliminar de la lista en caso llegue al borde
						//listaCirculos->Eliminar(i);
					//}
				}
			}
		}
		//movimiento:
		for (int i = 1; i <= listaCirculos->Get_Cantidad(); i++)
		{
			listaCirculos->Recuperar(i)->mover();
		}
		objPersonaje->dibujar(g);
		objPersonaje->mover();
	}
	void cambiardir(Keys tecla) {
		objPersonaje->cambiardireccion(tecla);
	}
	long long getcontador() {
		return *contador;
	}
	void setcontador(long long contador) {
		*(this->contador) = contador;
	}
private:

	CLista<CCirculo>*listaCirculos;
	Personaje* objPersonaje;
	Rectangle recform;
	long long *contador;
};
