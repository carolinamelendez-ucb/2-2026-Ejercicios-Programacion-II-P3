#pragma once
#include <iostream>
#include <string>
#include "ListaGenerica.h"

using namespace std;

class Perro
{

private:
	string codigo;
	string nombre;
	string raza;
	string tamanio;

public:
	Perro(string codigo) {
		this->codigo = codigo;
		this->nombre = nombre;
		this->raza = raza;
		this->tamanio = tamanio;

	}

	~Perro() {
	}

	void mostrar() {
		cout << "codigo" << codigo;
		cout << "nombre" << nombre;
		cout << "raza" << raza;
		cout << "tamanio" << tamanio;

	}

	string getCodigo() {
		return this->codigo;
	}

	static string getCi(Perro* perro) {
		return perro->codigo;
	}

	void agregarPerro() {
	ListaGenerica:agregarPerro();
	}
		

};
