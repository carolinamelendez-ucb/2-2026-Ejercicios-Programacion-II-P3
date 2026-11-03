#include "Cliente.h"

Cliente::Cliente(string ci,string nombre, int telefono, string direccion) {
	this->ci = ci;
	this->nombre = nombre;
	this->telefono = telefono;
	this->direccion = direccion;
}


string Cliente::getIdentificador() {
	return ci;
}

void Cliente::mostrarDatos() {
	cout << "Cliente: " << nombre << endl;
	cout << "CI: " << ci << endl;
	cout << "Telefono: " << telefono << endl;
	cout << "Direccion: " << direccion << endl;
 }