#pragma once
#include <iostream>
#include <string>
using namespace std;
class Espacio {
private:
	string codigoEspacio;
	int nivel;
	string sector;
	bool estado;
public:
	Espacio(const string& codigoEspacio, int nivel, const string& sector)
		
	{
		this->codigoEspacio = codigoEspacio;
		this->nivel = nivel;
		this->sector = sector;
		this->estado = true;
	}
	bool getEstado() {
		return estado;
	}
	string getEspacio() {
		return codigoEspacio;
	}
	void mostrar() {
		cout << "============ Espacio ============" << endl;
		cout << "El codigoEspacio del Espacio es: " << codigoEspacio << endl;
		cout << "El nivel del Espacio es: " << nivel << endl;
		cout << "El sector del Espacio es: " << sector << endl;
		cout << "El estado del Espacio es: " << estado << endl;
	}
	static bool getterEspacio(string codigo, Espacio* espacio) {
		return codigo==espacio->codigoEspacio;
	}
};