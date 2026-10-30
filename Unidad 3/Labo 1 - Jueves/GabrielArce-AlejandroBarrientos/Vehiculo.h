#pragma once
#include <iostream>
#include <string.h>
#include "Espacio.h"
using namespace std;

class Vehiculo {
private:
	string placa;
	string marca;
	string modelo;
	string tipoVehiculo;
	Espacio* espacioAsignado;
public:
	Vehiculo();
	Vehiculo(string placa, string marca, string modelo, string tipoVehiculo) {
		this->placa = placa;
		this->marca = marca;
		this->modelo = modelo;
		this->tipoVehiculo = tipoVehiculo;
		this->espacioAsignado = nullptr;
	}
	void mostrar() {
		cout << "PLaca: " << placa << endl;
		cout << "Marca: " << marca << endl;
		cout << "Modelo: " << modelo << endl;
		cout << "Tipo vehiculo: " << tipoVehiculo << endl;
		cout << "Espacio asignado: " << endl;
		espacioAsignado->mostrar();
	}
	string getPlaca() {
		return placa;
	}
	static bool comparador(Vehiculo* elemento, string placa) {
		return elemento->getPlaca() == placa;
	}
};

