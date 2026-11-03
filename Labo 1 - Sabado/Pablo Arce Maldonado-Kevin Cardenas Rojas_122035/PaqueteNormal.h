#pragma once
#include <iostream>
#include <string>
#include "Cliente.h"

using namespace std;


class PaqueteNormal{
protected:
	int codigoPaquete;
	string descripcion;
	float peso;
	float costoPorKg;
public:
	PaqueteNormal(int codigoPaquete,string descripcion,float peso,float costoPorKg){
		this->codigoPaquete = codigoPaquete;
		this->descripcion = descripcion;
		this->peso = peso;
		this->costoPorKg = costoPorKg;
	}

	virtual float Costo() {
		return this->peso * this->costoPorKg;
	}
};