#include "ServicioBanio.h"

ServicioBanio::ServicioBanio(string codigo, string nombre, double costoProductos) :Servicio(codigo, nombre) {
	this->codigo = codigo;
	this->nombre = nombre;
	this->costoProductos = costoProductos;
}

double ServicioBanio::getCosto() {
	return costoProductos;
}

void ServicioBanio::mostrarDatos() {
	cout << "Codigo Servcio: " << codigo << endl;
	cout << "Nombre Servicio" << nombre << endl;
	cout << "Tipo Servicio: Servicio Banio" << endl;
	cout << "Costo Productos: " << getCosto() << endl;
}