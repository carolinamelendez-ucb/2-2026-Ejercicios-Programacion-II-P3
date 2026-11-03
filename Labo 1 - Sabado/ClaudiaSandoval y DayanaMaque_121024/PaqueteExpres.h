#pragma once
#include <iostream>
#include <string>
#include "Paquete.h"
using namespace std;
class PaqueteExpress: Paquete{
private:
	float horasEntrega;
	float costoPrioridad;
public:
	PaqueteExpress(string codigoPaquete, string descripcion, float peso) :Paquete(codigoPaquete, descripcion, peso) {
		this->horasEntrega = horasEntrega;
		this->costoPrioridad = costoPrioridad;
	}
	
	float calcularHora() {
		if (horasEntrega <= 24) {
			return costoPrioridad = 30;

		}
		else 
			if (horasEntrega <= 48 && horasEntrega > 24) {
				return costoPrioridad = 20;
			}
			else if (horasEntrega>48 ) {
				return costoPrioridad = 10;
			}
	}

	float  calcularCosto() {
		return (peso * costoKilo) + costoPrioridad;

	}
	void mostrar() {
		cout << "Paquete Express" << endl;
		Paquete::mostrar();
		cout << "horas de entrega" << horasEntrega << endl;
		cout << "costo prioridad" << calcularCosto() << endl;

	}
};