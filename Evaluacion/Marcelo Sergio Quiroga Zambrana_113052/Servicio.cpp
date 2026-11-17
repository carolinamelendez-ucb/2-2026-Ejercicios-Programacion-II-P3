#include "Servicio.h"

Servicio::Servicio(string codigo,string nombre) {
	this->codigo = codigo;
	this->nombre = nombre;
	this->costo = 0;
}

string Servicio::getCodigo() {
	return codigo;
}

double Servicio::getCosto() {
	return costo;
}

void Servicio::mostrarDatos() {
	cout << "Codigo Servcio: " << codigo << endl;
	cout << "Nombre Servicio" << nombre << endl;
}