#pragma once
#include <iostream>
#include <string>
#include "Servicio.h"
using namespace std;

enum ServiciosBanio { BANIO, SECADO};

class ServicioBanio : public Servicio
{

private:
	float costoProducto;

public:
	ServicioBanio(string codigo, string nombre, float costoProducto)
		: Servicio(codigo, nombre) {
		this->costoProducto = costoProducto;
	}
	~ServicioBanio();

	float getCostoProducto() {
		return this->costoProducto;
	}


	//float calcularCostoProducto() {}

	//string getCodigo();

};
