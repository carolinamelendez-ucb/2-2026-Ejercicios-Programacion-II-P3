#pragma once
#include <iostream>
#include <string.h>
using namespace std;

class Espacio
{
private:
	string codigoEspacio;
	int nivel;
	string sector;
	bool estado;//true  libre, false ocupado
public:
	Espacio();
	Espacio(string codigoEspacio, int nivel, string sector) {
		this->codigoEspacio = codigoEspacio;
		this->nivel = nivel;
		this->sector = sector;
		this->estado = true;
	}
	~Espacio();
	void mostrar() {
		cout << "Codigo Espacio: " << codigoEspacio << endl;
		cout << "Nivel: " << nivel << endl;
		cout << "Sector: " << sector << endl;
		cout << " Estado: ";
		if (estado)
		{
			cout << " disponible " << endl;
		}else {
			cout << " ocupado " << endl;
		}
	}
	string getCodigoEspacio() {
		return codigoEspacio;
	}
	static bool comparador(Espacio* elemento, string codigoBuscado) {
		return elemento->getCodigoEspacio() == codigoBuscado;
	}
};
