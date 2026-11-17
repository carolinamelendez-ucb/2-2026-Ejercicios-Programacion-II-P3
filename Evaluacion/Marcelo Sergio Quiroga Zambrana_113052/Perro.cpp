#include "Perro.h"

Perro::Perro(string codigo, string nombre, string raza, string tamanio) {
	this->codigo = codigo;
	this->nombre = nombre;
	this->raza = raza;
	if ((this->tamanio != "pequenio") || (this->tamanio != "mediano") || (this->tamanio != "grande")) {
		TamanioNoValidoException();
	}
	else {
		this->tamanio = tamanio;
	}
}

string Perro::getCodigo() {
	return codigo;
}

string Perro::getTamanio() {
	return tamanio;
}

void Perro::mostrarDatos() {
	cout << "Nombre Perro: " << nombre << endl;
	cout << "Codigo: " << codigo << endl;
	cout << "Raza: " << raza << endl;
	cout << "Tamanio: " << tamanio << endl;
}