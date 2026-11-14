#pragma once
#include <iostream>
#include <string>
#include "ListaGenerica.h"

using namespace std;

class Servicio
{

protected:
	string codigo;
	string nombre;

public:
	Servicio(string codigo, string nombre) {
		this->codigo = codigo;
		this->nombre = nombre;
	}

	~Servicio();

	string getCodigo() {
		return this->codigo;

	}

	string getNombre() {
		return this->nombre;
	}

	void mostrar() {
		cout << "codigo" << codigo;
		cout << "nombre" << nombre;
	}

	string getCodigo() {
		return this->codigo;
	}

	static string getCi(Servicio* servicio) {
		return servicio->codigo;
	}


	void agregarServicio() {
	ListaGenerica:agregarServicio();
	}

};
