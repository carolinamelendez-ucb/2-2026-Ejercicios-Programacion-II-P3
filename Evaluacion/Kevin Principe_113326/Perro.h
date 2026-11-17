#pragma once
#include <iostream>
#include <string>
using namespace std;

class Perro
{
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

	~Perro(){}

	string getRaza() {
		return raza;
	}

	string getTamanio() {
		return tamanio;
	}

	string getCodigo() {
		return codigo;
	}

	void mostrar() {
		cout << "Codigo Perro: " << codigo << endl;
		cout << "Nombre: " << nombre << endl;
		cout << "Raza: " << raza << endl;
		cout << "Tamanio: " << tamanio << endl;
	}
};

