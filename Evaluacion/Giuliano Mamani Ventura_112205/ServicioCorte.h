#pragma once
#include "Servicio.h"

class ServicioCorte : public Servicio {
private:
	double costoCorte;
public:
	ServicioCorte(const string& codigo, const string& nombre, double costoCorte) : Servicio(codigo, nombre) {
		this->costoCorte = costoCorte;
	}
	double getCostoCorte() {
		return costoCorte;
	}
	void mostrar() {
		Servicio::mostrar();
		cout << "costoCorte: " << costoCorte << endl;
		cout << "---------------------------------------------------" << endl;
	}
};