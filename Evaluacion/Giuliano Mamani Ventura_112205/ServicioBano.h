#pragma once
#include "Servicio.h"

class ServicioBano : public Servicio {
private:
	double costoProductos;
public:
	ServicioBano(const string& codigo, const string& nombre, double costoProductos) : Servicio(codigo, nombre) {
		this->costoProductos = costoProductos;
	}
	double getCostoProductos() {
		return costoProductos;
	}
	void mostrar() {
		Servicio::mostrar();
		cout << "costoProductos: " << costoProductos << endl;
		cout << "---------------------------------------------------" << endl;
	}
};