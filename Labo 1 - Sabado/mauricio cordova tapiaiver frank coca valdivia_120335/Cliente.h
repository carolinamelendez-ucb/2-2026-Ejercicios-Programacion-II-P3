#pragma once
#include <string>
#include <iostream>
using namespace std;

class Cliente {
private:
	string ci;
	string nombre;
	int telefono;
	string direccion;
public:


	Cliente( string ci, string nombre, int telefono,string direccion)
		: ci(ci), nombre(nombre), telefono(telefono), direccion(direccion)
	{
	}
	string getCI() { return ci; }
	static bool getterCI(Cliente* cliente, string dato) {
		return cliente->ci == dato;
	}

	void mostrar() {
		cout << "CI: " << ci << endl;
		cout << "Nombre: " << nombre << endl;
		cout << "Telefono: " << telefono << endl;
		cout << "Direccion: " << direccion << endl;
	}

};