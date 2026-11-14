#pragma once
#include"Perro.h"
class Servicio {
protected:
	string codigoS;
	string nombre;

public:
	Servicio(string codigo, string nombre) {
		this->codigoS = codigo;
		this->nombre = nombre;
	}
	string getCodigo() {
		return codigoS;
	}
	virtual float Costototal() = 0;
	static bool Comparar(string codigoS, Servicio* servicio) {
		if (codigoS == servicio->getCodigo()) {
			return true;
		}
		else {
			return false;
		}
	}
	virtual void Mostrar() {
		cout << "El codigo del Servicio es: " << codigoS << endl;
		cout << "El nombre del Servicio es: " << nombre << endl;
	}
};