#pragma once
#include <iostream>
#include <string>
#include "Paquete.h"
using namespace std;
enum NivelFragilidad {
	BAJO,MEDIO,ALTO
};
class PaqueteFragil : Paquete {
private:
	float nivelFragilidad;
	float costoEmbalaje;
public:
	PaqueteFragil(string codigoPaquete, string descripcion, float peso) :Paquete(codigoPaquete, descripcion, peso) {

	}


	float calcularEmbalaje() {
		if (nivelFragilidad == BAJO) {
			return costoEmbalaje = 5;
		}
		if (nivelFragilidad == MEDIO) {
			return costoEmbalaje = 10;
		}
		if (nivelFragilidad == ALTO) {
			return costoEmbalaje = 20;
		}
	}
	 
	float  calcularCosto() {
		return (peso * costoKilo) + costoEmbalaje;

	}

	void mostrar() {
		cout << "Paquete Fragil" << endl;
		Paquete::mostrar();
		cout << "nivel de fragilidad" << nivelFragilidad << endl;
		cout << "costo de Embalaje" << calcularCosto() << endl;

	}

};

