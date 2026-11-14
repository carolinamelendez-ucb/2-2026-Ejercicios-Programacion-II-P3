#pragma once
#include "Servicio.h"
class ServicioCorte : public Servicio
{
private:

public:
	ServicioCorte(string codigo, string nombre, float costocorte) :Servicio(codigo, nombre,costocorte) {
	}
	~ServicioCorte(){}
	void Mostrar() {
		Servicio::Mostrar();

	}

};