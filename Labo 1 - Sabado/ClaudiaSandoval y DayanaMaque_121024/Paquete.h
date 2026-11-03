#pragma once
#include <iostream>
#include <string>

using namespace std;
class Paquete{
protected:
	string codigoPaquete;
	string descripcion;
	float peso;
	float costoKilo;

public:
	Paquete(string codigoPaquete, string descripcion, float peso) {
		this->codigoPaquete = codigoPaquete;
		this->descripcion = descripcion;
		this ->peso = peso;
		this->costoKilo = costoKilo;
		

	}
	virtual void mostrar() {
		cout << "codigo Paquete"<< codigoPaquete << endl;
		cout << "descripcion " << descripcion << endl;
		cout << "peso " << peso << endl;

	}
	float getPeso() {
		return peso;
	}
};