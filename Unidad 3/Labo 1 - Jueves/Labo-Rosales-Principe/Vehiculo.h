#pragma once
#include <iostream>
#include <string>
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
	Vehiculo(string placa, string marca, string modelo, string tipoVehiculo) {
		this->placa = placa;
		this->marca = marca;
		this->modelo = modelo;
		this->tipoVehiculo = tipoVehiculo;
		this->espacioAsignado = nullptr;
	}

	string getPlaca() {
		return placa;
	}

	Espacio* getEspacioAsignado() {
		return espacioAsignado;
	}

	void setEspacioAsignado(Espacio* espacio) {
		this->espacioAsignado = espacio;
	}

	void mostrar() {
		cout << "Placa: " << placa
			<< " | Marca: " << marca
			<< " | Modelo: " << modelo
			<< " | Tipo: " << tipoVehiculo << endl;
		if (espacioAsignado != nullptr) {
			cout << " Espacio Asignado: " << espacioAsignado->getCodigoEspacio() << endl;
		}
		else {
			cout << " Espacio Asignado: Ninguno" << endl;
		}
	}

	static string getterPlaca(Vehiculo* vehiculo) {
		return vehiculo->placa;
	}
};