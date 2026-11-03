#include "PaqueteNormal.h"

PaqueteNormal::PaqueteNormal(string codigo,string descripcion,float peso,float costoPorkilo) {
	this->codigo = codigo;
	this->descripcion = descripcion;
	this->peso = peso;
	this->costoPorkilo = costoPorkilo;
}

float PaqueteNormal::calcularCosto() {
	return peso * costoPorkilo;
}

string PaqueteNormal::getIdentificador() {
	return codigo;
}

void PaqueteNormal::mostrarDatos() {
	cout << "Tipo Paquete: Normal" << endl;
	cout << "Codigo: " << codigo << endl;
	cout << "Descripcion: " << descripcion << endl;
	cout << "Peso: " << peso << endl;
	cout << "Costo Paquete: " << calcularCosto() << endl;
}