#pragma once
#include <iostream>
#include <string>
using namespace std;

class Servicio {
protected: 
	string codigo;
	float costo;
	string nom;
public:
	Servicio(string codigo, string nom, float costo) {
		this->codigo = codigo;
		this->nom= nom;
		this->costo = costo;
	}

	float getCosto()
	{
		return costo;
	}
	void mostrar() {
		cout << "Nombre" << nom << endl;
		cout << "Codigo: " << codigo << endl;
		cout << "Costo: " << costo << endl;
	}
};