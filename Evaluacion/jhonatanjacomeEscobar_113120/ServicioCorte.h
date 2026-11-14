#pragma once
#pragma once
#include "Servicio.h"
#include "Perro.h"
class ServicioCorte : public Servicio {
private:
	float costoCorte;
	string tamanio;
public:
	ServicioCorte(string nombre, string codigo, float costoCorte, string tamanio) : Servicio(nombre, codigo) {
		this->costoCorte = costoCorte;
		this->tamanio = tamanio;
	}

	int calcularosto(string tamanio) {

		if (tamanio == "grande") {
			return costoCorte + 15;
		}
	}


	void mostrar() override {
		Servicio::mostrar();
		cout << " costo corte : " << costoCorte << endl;
		cout << " costo corte : " << calcularosto(tamanio) << endl;

	}
};