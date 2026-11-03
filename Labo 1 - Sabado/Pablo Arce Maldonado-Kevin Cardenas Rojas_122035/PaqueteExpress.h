#pragma once
#include <iostream>
#include <string>
#include "PaqueteNormal.h"

using namespace std;


class PaqueteExpress:public PaqueteNormal {
protected:
	int horasEntrega;
	float costoPrioridad;
public:
	PaqueteExpress(int horasEntrega, float costoPrioridad):PaqueteNormal(codigoPaquete, descripcion, peso, costoPorKg) {
		this->codigoPaquete = codigoPaquete;
		this->descripcion = descripcion;
		this->peso = peso;
		this->costoPorKg = costoPorKg;
		this->horasEntrega = horasEntrega;
		this->costoPrioridad = costoPrioridad;
	}

	float Costo() override {
		if (this->horasEntrega < 24) {
			this->costoPrioridad = 30;

			return this->peso * this->costoPorKg * this->costoPrioridad;
		}
		else {
			if (this->horasEntrega >= 24 && this->horasEntrega <= 48) {
				this->costoPrioridad = 20;
				return this->peso * this->costoPorKg * this->costoPrioridad;

			}
			else {
				if (this->horasEntrega > 48) {
					this->costoPrioridad = 10;
					return this->peso * this->costoPorKg * this->costoPrioridad;
				}

			}

		}	
	
	}

};