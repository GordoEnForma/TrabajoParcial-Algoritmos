
#pragma once
#include "Nodo.h"
template <class T>

class CLista
{
private:
	CNodo<T>* Inicio;
	size_t Cantidad;

public:
	CLista()
	{
		Inicio = nullptr;
		Cantidad = 0;
	}
	~CLista() {}
	//////////////////////////
	void InsercionInicio(T* Elemento)
	{
		CNodo<T>* Nuevo = new CNodo<T>(Elemento);
		if (Inicio != nullptr)
			Nuevo->Set_Siguiente(Inicio);
		Inicio = Nuevo;
		Cantidad++;
	}
	T* Recuperar(size_t Posicion)
	{
		if (Posicion > 0 && Posicion <= Cantidad)
		{
			CNodo<T>* Aux = Inicio;
			for (size_t i = 0; i < Posicion - 1; i++)
			{
				Aux = Aux->Get_Siguiente();
			}
			return Aux->Get_Elemento();
		}
		return nullptr;
	}
	void Eliminar(size_t Posicion)
	{
		if (Posicion > 1 && Posicion <= Cantidad)
		{
			CNodo<T>* Aux = Inicio;
			for (size_t i = 0; i < Posicion - 2; i++)
			{
				Aux = Aux->Get_Siguiente();
			}
			Aux->Set_Siguiente(Aux->Get_Siguiente()->Get_Siguiente());
			Cantidad--;
		}
		else if (Posicion == 1 && Cantidad > 1)
		{
			Inicio = Inicio->Get_Siguiente();
			Cantidad--;
		}
		else if (Posicion == 1 && Cantidad == 1)
		{
			Inicio = nullptr;
			Cantidad--;
		}
	}
	/////////////////////
	size_t Get_Cantidad()
	{
		return Cantidad;
	}
};
