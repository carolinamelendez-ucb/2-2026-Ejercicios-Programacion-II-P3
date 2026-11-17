#pragma once
#include "Perro.h"
#include "Servicio.h"

class Atencion
{
private:
	string codigo;
	Perro* perro;
	Servicio* servicio;
	double costoFinal;
public:
	Atencion(string codigo, Perro* perro, Servicio* servicio) {
		this->codigo = codigo;
		this->perro = perro;
		this->servicio = servicio;
		this->costoFinal = servicio->getCosto();
	}

	~Atencion(){}

	string getCodigo() {
		return codigo;
	}

	double calcularCostoAtencion() {
		if ((perro->getTamanio() == "Grande") && servicio->getNombre() == "ServicioCorte") {
			costoFinal = costoFinal + 15;
		}
		return costoFinal;
	}

	void mostrar() {
		cout << "Codigo Atencion: " << codigo << endl;
		perro->mostrar();
		servicio->mostrar();
		cout << "CostoFinal: " << calcularCostoAtencion() << endl;
	}
};

