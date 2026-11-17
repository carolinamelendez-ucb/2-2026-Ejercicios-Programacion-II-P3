#pragma once
#include <iostream>
#include <string>
#include "Perro.h"
using namespace std;

class Perro {
private:
	string codigo;
	string nombre;
	string raza;
	string tamanio;
public:
	Perro(string codigo, string nombre, string raza, string tamanio) {
		this->codigo = codigo;
		this->nombre = nombre;
		this->raza = raza;
		this->tamanio = tamanio;
	}


	string getcodigo() { 
		return codigo; 
	}
	string getRaza() { 
		return raza; 
	}

	void mostrar() {
		cout << "Perro: " << nombre << " Codigo: " << codigo << "  Tamaño: " << tamanio << endl;
	}

	static bool compararCodigo(string codigoBusqueda, Perro* n) {
		return codigoBusqueda == n->codigo;
	}
};