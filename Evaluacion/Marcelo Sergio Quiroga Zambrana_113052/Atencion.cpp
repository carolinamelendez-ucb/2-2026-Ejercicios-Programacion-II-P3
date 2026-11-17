#include "Atencion.h"

Atencion::Atencion(Perro* perro,Servicio* servicio) {
	this->codigo = "111";
	this->perro = perro;
	this->servicio = servicio;
	this->costoFinal = 0;
}

double Atencion::calcularCostoFinal() {
	costoFinal = servicio->getCosto();
	return costoFinal;
}

string Atencion::getCodigo() {
	return codigo;
}

void Atencion::mostrarDatos() {
	cout << "Codigo Atencion: " << codigo << endl;
	cout << "Datos Perro: " << endl;
	perro->mostrarDatos();
	cout << endl;
	cout << "Datos Servicio: " << endl;
	servicio->mostrarDatos();
	cout << endl;
	cout << "COSTO FINAL: " << calcularCostoFinal() << endl;
}