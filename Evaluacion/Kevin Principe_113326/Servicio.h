#pragma once
#include <iostream>
#include <string>
using namespace std;

class Servicio
{
protected:
	string codigo;
	string nombre;
	double costoBase;
public:
	Servicio(string codigo) {
		this->codigo = codigo;
		this->nombre = "Clase padre";
		this->costoBase = 0;
	}

	string getNombre() {
		return nombre;
	}

	string getCodigo() {
		return codigo;
	}

	double getCosto() {
		return costoBase;
	}

	~Servicio(){}

	virtual void mostrar() = 0;
};

