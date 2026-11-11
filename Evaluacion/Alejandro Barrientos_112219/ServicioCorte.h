#pragma once
#pragma once
#include "Servicio.h"

class ServicioCorte : public Servicios
{
private:
	double costoCorte;

public:
	ServicioCorte(double costoCorte, int codigo, string nombre) : Servicios(codigo, nombre)
	{
		this->costoCorte = costoCorte;

	}

	double CalcularCosto(Perro* perro) override
	{
		string tamanio = perro->gettamanio();
		if (tamanio == "grande")
		{
			return costoCorte + 15;
		}
		else
		{
			return costoCorte;
		}
	}
};