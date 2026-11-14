#pragma once
#include <iostream>
#include <string>
#include "Servicio.h"
using namespace std;


enum TamanioPerro { PEQUENIO, MEDIANO, GRANDE };

class ServicioCorte : public Servicio
{

private:
	float costoCorte;

public:
	ServicioCorte(string codigo, string nombre, float costoCorte)
		: Servicio(codigo, nombre) {
		this->costoCorte = costoCorte;
	}
	~ServicioCorte();

	float calcularCostoCorte();
	
	float getCostoCorte() {
		return this->costoCorte;
	}
	

	//string getCodigo();

};
