#pragma once
#include "Servicio.h"

class ServicioBano : public Servicios
{
private:
	double costoProductos;
	double costoBano;
public :
	ServicioBano(double costoProductos, double costoBano, int codigo, string nombre) : Servicios( codigo, nombre)
	{
		this->costoProductos = costoProductos;
		this->costoBano = costoBano;

	}

	double CalcularCosto(Perro* perro) override
	{
		return costoBano + costoProductos;
	}
};