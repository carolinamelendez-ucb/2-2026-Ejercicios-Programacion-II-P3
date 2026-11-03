#include "PaqueteFragil.h"

PaqueteFragil::PaqueteFragil(string codigo, string descripcion, float peso, float costoPorKilo, int nivelFragilidad) :PaqueteNormal(codigo, descripcion, peso, costoPorKilo) {
	this->codigo = codigo;
	this->descripcion = descripcion;
	this->peso = peso;
	this->costoPorkilo = costoPorkilo;
	if ((this->nivelFragilidad = 1)||(this->nivelFragilidad = 2)||(this->nivelFragilidad = 3)) {
		if (this->nivelFragilidad = 1) {
			this->costoEmbalaje = 5;
		}
		else if (this->nivelFragilidad = 2) {
			this->costoEmbalaje = 10;
		}
		else if (this->nivelFragilidad = 3) {
			this->costoEmbalaje = 20;
		}
	}
	else {
		//exception
	}
}

float PaqueteFragil::calcularCosto() {
	return (costoPorkilo + costoEmbalaje) * peso;
}

void PaqueteFragil::mostrarDatos() {
	cout << "Tipo Paquete: Fragil" << endl;
	cout << "Codigo: " << codigo << endl;
	cout << "Descripcion: " << descripcion << endl;
	cout << "Peso: " << peso << endl;
	cout << "Nivel Fragilidad: " << nivelFragilidad << endl;
	cout << "Costo Embalaje: " << costoEmbalaje << endl;
	cout << "Costo Paquete: " << calcularCosto() << endl;
}