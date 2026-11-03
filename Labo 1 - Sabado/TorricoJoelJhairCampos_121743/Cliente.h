#pragma once
#include <iostream>
#include <string>
using namespace std;
class Cliente
{
private:
	string ci;
	string nombre;
	double telefono;
	string direccion;
public:
	Cliente(string ci, string nombre, double telefono, string direccion) {
		this->ci = ci;
		this->nombre = nombre;
		this->telefono = telefono;
		this->direccion = direccion;
	}
	void mostrar() {
		cout << "ci: " << ci << endl;
		cout << "nombre: " << nombre << endl;
		cout << "telefono: " << telefono << endl;
		cout << "direccion: " << direccion << endl;
	}
	string getCi() {
		return this->ci;
	}
	static bool compararCi(Cliente* cliente, string ci) {
		return cliente->getCi() == ci;
	}

};

