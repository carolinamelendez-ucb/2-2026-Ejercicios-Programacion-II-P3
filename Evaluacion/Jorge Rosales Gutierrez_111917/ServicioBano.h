#pragma once
#include "Servicio.h"

class ServicioBano : public Servicio {
private:
	float costoProductos;
public:
	ServicioBano(string codigo, string nombre, float costoProductos)
		: Servicio(codigo, nombre) {
		this->costoProductos = costoProductos;
	}

	int calcularCosto(Perro* perro) override {
		return costoProductos;
	}
	void mostrar() override {
		cout << "Servicio Bano: ";
		Servicio::mostrar();
		cout << "Incluye baño y secado" << endl;
		cout << " Costo final de productos utilizados: " << costoProductos << " Bs." << endl;
	}
};