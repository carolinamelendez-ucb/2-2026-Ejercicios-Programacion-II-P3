#pragma once
#include <iostream>
#include <string>

using namespace std;

class Servicio
{
protected:
	string cogidoS;
	string nombre;
	int costoServicio;
public:
	Servicio() {
		this->cogidoS = "";
		this->nombre = "";
		this->costoServicio = 0;

	}
	string getCodigo() {
		return cogidoS;
	}

	void mostrar() {
		cout << "Codigo: " << cogidoS << endl;
		cout << "Nombre: " << nombre << endl;
		cout << "Costo del servicio:" << costoServicio << endl;
	}
	
	static bool compararCodigo(string codigoS, Servicio* servicio) {
		return codigoS == servicio->cogidoS;
	}
	

};

