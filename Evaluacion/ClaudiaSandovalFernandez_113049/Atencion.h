#pragma once
#include <iostream>
#include <string>

#include "Perro.h"
#include "Servicio.h"
#include "ListaGenerica.h"

using namespace std;

class Atencion
{

private:
	string codigo;
	float costoFinal;
	Perro* perros;
	Servicio* servicios;

public:
	Atencion(string codigo) {
		this->codigo = codigo;
		this->costoFinal = costoFinal;
	}
	~Atencion();

	void agregarAtencion() {
	ListaGenerica:agregarAtencion();
	}

};
