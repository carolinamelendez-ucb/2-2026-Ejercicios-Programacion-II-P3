#pragma once
#include "Perro.h"
#include "Servicio.h"

class Atencion
{
private :
	Perro* perro;
	Servicios* servicio;
	int codigo;
	double costoFinal;
public:
	Atencion(Perro* perro, Servicios* servicio, int codigo, double costoFinal)
	{
		this->perro = perro;
		this->servicio = servicio;
		this->codigo = codigo;
		this->costoFinal = costoFinal;
	}

	~Atencion(){}
};