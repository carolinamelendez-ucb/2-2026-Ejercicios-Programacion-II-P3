#pragma once
#include <iostream>
#include <string>
using namespace std;
class Cliente {
protected:
	string ci;
	string nombre;
	string telefono;
	string direccion;
public:
	Cliente(string ci, string nombre, string telefono, string direccion) {
		this->ci = ci;
		this->nombre = nombre;
		this->telefono = telefono;
		this->direccion = direccion;
	}
	string getCi() {
		return ci;
	}

	string getNombre() {
		return nombre;
	}

	void mostrar() {
		cout<< "ci" << ci;
		cout << "nombre" << nombre<<endl;
		cout << "telefono" << telefono << endl;
		cout << "direccion" << direccion << endl;
	}
};