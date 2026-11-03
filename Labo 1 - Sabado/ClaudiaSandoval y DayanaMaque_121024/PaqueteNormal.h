#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "Paquete.h"
using namespace std;
class PaqueteNormal : Paquete {
private:
	//float horasEntrega;
	//float costoPrioridad;
public:
	PaqueteNormal(string codigoPaquete, string descripcion, float peso) :Paquete(codigoPaquete, descripcion, peso) {

	}
	float  calcularCosto() {
		return (peso * costoKilo);

	}
	void mostrar() {
		cout << "Paquete normal" << endl;
		Paquete::mostrar();
		
	}
};