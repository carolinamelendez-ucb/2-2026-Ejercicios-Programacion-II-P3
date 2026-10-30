#pragma once
#include <iostream>
#include <string>
using namespace std;

class Espacio {
private:
	string codigoEspacio;
	int nivel;
	string sector;
	string estado;

public:
	Espacio(string codigoEspacio, int nivel, string sector) {
		this->codigoEspacio = codigoEspacio;
		this->nivel = nivel;
		this->sector = sector;
		this->estado = "disponible";
	}

	string getCodigoEspacio() {
		return codigoEspacio;
	}
	void setEstado(string estado) {
		this->estado = estado;
	}
	string getEstado() {
		return estado;
	}

	
	void mostrar() {
		cout << "espacio: " << codigoEspacio
			<< " | nivel: " << nivel
			<< " | sector: " << sector
			<< " | estado: " << estado << endl;
	}

	static string getterCodigo(Espacio* espacio) {
		return espacio->codigoEspacio;
	}
	static string getterEstado(Espacio* estado) {
		return estado->estado;
	}
};
