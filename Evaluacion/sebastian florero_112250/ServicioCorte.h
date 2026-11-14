#pragma once
#include "Servicio.h"

class ServicioCorte: public Servicio {
private:
	float costoAdi;
public:
	ServicioCorte(string codigo, string nom, float costo) : Servicio(codigo, "ServicioCorte", costo) {
		this->costoAdi = 15;
	}

	
	
	void mostrar() {
		cout << "Codigo: " << codigo << endl;
		cout << "Nombre" << nom << endl;
		cout << "Costo: " <<costo<< endl;
	}

};