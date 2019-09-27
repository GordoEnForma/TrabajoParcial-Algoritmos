#pragma once
template<class T>

class CNodo
{
private:
	CNodo<T>* Siguiente;
	T* Elemento;

public:
	CNodo()
	{
		Siguiente = nullptr;
	}
	CNodo(T* Elemento)
	{
		this->Elemento = Elemento;
		Siguiente = nullptr;
	}
	~CNodo() {}
	//////////////////////////
	CNodo<T>* Get_Siguiente()
	{
		return this->Siguiente;
	}
	void Set_Siguiente(CNodo<T>* Siguiente)
	{
		this->Siguiente = Siguiente;
	}
	T* Get_Elemento()
	{
		return this->Elemento;
	}
};


