#pragma once
#pragma once
#include <iostream>
#include <string>
#include "Perro.h"

using namespace std;

class Servicios
{
protected:
	int codigo;
	string nombre;
public:
	Servicios(int codigo, string nombre)
	{
		this->codigo = codigo;
		this->nombre = nombre;
	}

	virtual double CalcularCosto(Perro* perro) = 0;

	virtual int RecibirCodigoPerro(Perro* perro) = 0;

	virtual string MostrarPerro(Perro* perro, Servicios* servicios) = 0;

	string getNombreServicio()
	{
		return nombre;
	}

	virtual double CalcularCostoFinal(Perro* perro) = 0;

	~Servicios(){}

};