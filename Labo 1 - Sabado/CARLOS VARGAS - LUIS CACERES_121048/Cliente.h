#pragma once
#include<iostream>
#include<string>
using namespace std;

class Cliente{
private:
	string ci;
	string nombre;
	string telefono;
	string direccion;
public:
	Cliente(string ci,string nombre, string telefono,string direccion) {
		this->ci = ci;
		this->direccion = direccion;
		this->nombre = nombre;
		this->telefono = telefono;

	}
	string getNombre() {
		return this->nombre;
	}
	string getCi() {
		return this->ci;
	}
	void mostrar() {
		cout << "Ci: " << this->ci << endl;
		cout << "Nombre: " << this->nombre << endl;
		cout << "Telefono: " << this->telefono<<endl;
		cout << "Direccion: " << this->direccion << endl;
	}
	static string getterCi(Cliente* c) {
		return c->ci;
	}
};

