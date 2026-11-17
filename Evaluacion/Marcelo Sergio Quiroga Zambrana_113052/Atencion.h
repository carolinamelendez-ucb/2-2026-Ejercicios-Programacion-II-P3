#pragma once
#include "Perro.h"
#include "Servicio.h"
#include "ServicioBanio.h"
#include "ServicioCorte.h"

class Atencion
{
private:
	string codigo;
	Perro* perro;
	Servicio* servicio;
	double costoFinal;
public:
	Atencion(Perro* perro, Servicio* servicio);
	double calcularCostoFinal();
	string getCodigo();
	void mostrarDatos();
};

