#pragma once
#include "Servicio.h"

class ServicioCorte : public Servicio {
private:
	int costoCorte;

public:
	ServicioCorte(string codigo, string nombre, int costoCorte)
		: Servicio(codigo, nombre) {
		this->costoCorte = costoCorte;
	}


	int calcularCosto(Perro* perro)  {
		string tamanio = perro->getTamanio();
		if (tamanio == "grande" ) {
			costoCorte = costoCorte+15;
		}
		return costoCorte;
	}


	void mostrar() override {
		cout << "Servicio Corte: Incluye corte de pelo ";
		Servicio::mostrar();
		cout << "Costo del Corte: " << costoCorte << endl;
	}
};