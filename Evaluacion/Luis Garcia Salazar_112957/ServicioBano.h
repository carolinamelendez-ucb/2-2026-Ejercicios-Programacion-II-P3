#pragma once
#include "Servicio.h"
class ServicioBano: public Servicio
{
private:
	int costoProductos;

public:
	ServicioBano() : Servicio() {
		this->cogidoS = "";
		this->nombre = "";
		this->costoServicio = costoProductos;
	}

	void mostrar() {
		cout << "Codigo: " << cogidoS << endl;
		cout << "Nombre: " << nombre << endl;
		cout << "Costo del servicio:" << costoServicio << endl;
	}


};


