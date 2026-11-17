#pragma once
#include <string>
#include <iostream>
using namespace std;

class Servicio {
protected:
	string codigo;
	string nombre;
	int costo;
public:



	Servicio( string codigo, string nombre, int costo)
		: codigo(codigo), nombre(nombre), costo(costo)
	{
	}
	static bool getter(Servicio* servicio, string codigo) {
		return servicio->codigo == codigo;
	}
	virtual string getNombre() = 0;
	virtual string getCodigo() = 0;
	virtual int getCosto() = 0;
	virtual void mostrar() = 0;
};

