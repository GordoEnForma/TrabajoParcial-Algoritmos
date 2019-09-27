#pragma once
#include <sstream>
#include <fstream>
using namespace std;

class Puntaje

{
public:
	Puntaje(long long puntaje) {
		this->puntaje = puntaje;
	}
	~Puntaje(){}
	void cargarPuntaje() {//FALTA CARGA DE PUNTAJE
		ifstream ArchPuntaje("Puntaje.txt");//En este archivo además de guardar el pj guardamos nivel y vidas
		string cadena, tmp;
		stringstream archtmp(cadena);

		//archtmp.str(std::string()); //limpiamos archtmp
		while (getline(ArchPuntaje, cadena))
			//for (size_t i = 1; i <= CantidadEnemigos; i++)
		{
			long long puntajeAux;
			archtmp.str(cadena);
			getline(archtmp, tmp);
			//archtmp >> dy;
			puntajeAux = stoll(tmp);
			archtmp.clear();
			this->puntaje = puntajeAux;
		}
		ArchPuntaje.close();
	}
	void guardarPuntaje() {//
		ofstream ArchPuntaje("Puntaje.txt");
		ArchPuntaje << puntaje << endl;
		ArchPuntaje.close();
	}
	void setpuntaje(long long puntaje) {
		this->puntaje = puntaje;
	}
	long long getpuntaje() {
		return puntaje;
	}
private:
	long long puntaje;
};
