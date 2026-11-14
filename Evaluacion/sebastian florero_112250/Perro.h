#pragma once
#include <iostream>
#include <string>
using namespace std;


class Perro {
private:
	string codigo;
	string nom;
	string raza;
	string tam;
public:
	Perro(string codigo, string nom, string raza, string tam) {
		this->codigo = codigo;
		this->nom = nom;
		this->raza = raza;
		this->tam = tam;
	}

	string getCodigo(){
		return this->codigo;
	}
	string getRaza() {
		return this->raza;
	}
	string getTam() {
		return this->tam;

	}

	void mostrar() {
		cout << "Nombre:" << nom << endl;
		cout << "Codigo" << codigo << endl;
		cout << "Raza" << raza << endl;
		cout << "Tamanio" << tam << endl;
	}
};