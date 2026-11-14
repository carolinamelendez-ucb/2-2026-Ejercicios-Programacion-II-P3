#pragma once
#include <iostream>
#include <string>
using namespace std;

//Perro(atributos: codigo, nombre, raza, tamanio).
//○ El tamaño puede ser pequeño, mediano o grande.
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

	~Perro() {

	}
	string getCodigo() {
		return codigo;
	}
	static string gettercodigo(Perro *p) {
		return p->getCodigo();

	}
	void mostrar() {
		cout << "codigo : " << codigo << endl;
		cout << "nombre : " << nombre << endl;
		cout << " raza:  " << raza << endl;
		cout << " tamanio" << endl;
	}


};