#pragma once
#include "Servicio.h"
class ServicioBano : public Servicio {
private:
	float costoProductos;

public:
	ServicioBano(string nombre , string codigo,float costoProductos): Servicio(nombre,codigo) {
		this -> costoProductos = costoProductos;
	}
	void mostrar() override {
		Servicio::mostrar();
		cout << " costo de los productos: " << costoProductos << endl;

	}
};