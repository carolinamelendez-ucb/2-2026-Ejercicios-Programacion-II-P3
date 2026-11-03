#pragma once
#include "Paquete.h"
class PaqueteNormal :
    public Paquete
{

public:
	PaqueteNormal() : Paquete(codigoPaquete, descripcion, peso, costoPorKg) {
		this->codigoPaquete = codigoPaquete;
		this->descripcion = descripcion;
		this->peso = peso;
		this->costoPorKg = costoPorKg;
	}
	void obtenerCosto() {
		int costoTotal;
		costoTotal = peso * costoPorKg;

	}

};

