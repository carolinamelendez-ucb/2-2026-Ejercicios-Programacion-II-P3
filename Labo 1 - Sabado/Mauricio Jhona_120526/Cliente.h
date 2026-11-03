#pragma once
#include <iostream>
#include <string.h>
using namespace std;
class Cliente
{
private:
	string Ci;
	string Nombre;
	int Telefono;
	string Direccion;
public:
	Cliente(string ci, string nombre, int telefono, string direccion) {
		this->Ci = ci;
		this->Nombre = nombre;
		this->Telefono = telefono;
		this->Direccion = direccion;
	}
	~Cliente(){}
	static string getciStatic(Cliente* cliente) {
		return cliente->Ci;
	}
	string getci() {
		return Ci;
	}
	void Mostrar() {
		cout << "Ci: " << Ci << endl;
		cout << "Nombre: " << Nombre << endl;
		cout << "Telefono: " << Telefono << endl;
		cout << "Direccion: " << Direccion << endl;
	}
};