#pragma once
#include "Servicio.h"


class ServicioBano: public Servicio {
private:
	float costoProd;
public:
	ServicioBano(float costoProd, string nom, string cod, float precio) : Servicio(codigo, "ServicioBano", costo) {
		this->costoProd = 5;
	}

	float getCosto()
	{
		return costo;
	}
	void mostrar() {
		cout << "Nombre" << nom << endl;
		cout << "Codigo: " << codigo << endl;
		cout << "Costo: " << costo << endl;
	}

};