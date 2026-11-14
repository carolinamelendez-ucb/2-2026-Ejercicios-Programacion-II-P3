#pragma once
#include <iostream>
#include <string>
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

	string getCodigo() {
		return codigo;
	}

	string getTamanio() {
		return tamanio;
	}

	void mostrar() {
		cout << "Perro: " << codigo
			<< " | Nombre: " << nombre
			<< " | Raza: " << raza
			<< " | tamanio: " << tamanio << endl;
	}

	static string getterCodigo(Perro* perro) {
		return perro->codigo;
	}
};

