#pragma once
#include "Servicio.h"
class ServicioCorte : public Servicio
{
private:
	int costoCorte;

public:
	ServicioCorte() : Servicio() {
		this->cogidoS = "";
		this->nombre = "";
		this->costoServicio = costoCorte;
	}

	void mostrar() {
		cout << "Codigo: " << cogidoS << endl;
		cout << "Nombre: " << nombre << endl;
		cout << "Costo del servicio:" << costoServicio << endl;
	}
};




