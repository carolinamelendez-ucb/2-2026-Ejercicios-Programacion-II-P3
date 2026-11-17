#include "ServicioCorte.h"

ServicioCorte::ServicioCorte(string codigo, string nombre, double costoCorte) :Servicio(codigo, nombre) {
	this->codigo = codigo;
	this->nombre = nombre;
	this->costoCorte = costoCorte;
}

double ServicioCorte::getCosto() {
	return costoCorte;
}

void ServicioCorte::mostrarDatos() {
	cout << "Codigo Servcio: " << codigo << endl;
	cout << "Nombre Servicio" << nombre << endl;
	cout << "Tipo Servicio: Servicio Corte" << endl;
	cout << "Costo Productos: " << getCosto() << endl;
}