#pragma once
#include <iostream>
#include <string>

using namespace std;
class Cliente
{
private:
	int Ci;
	string nombre;
	int telefono;
	string direccion;
public:
	Cliente() {
		this->Ci = 0;
		this->nombre = "";
		this->telefono = 0;
		this->direccion = "";
	}

	int getCodigo() {
		return Ci;
	}
	int getTelefono() {
		return telefono;
	}
	string getNombre() {
		return nombre;

	}
	string getDireccion() {
		return direccion;
	}
	void mostrar() {
		cout << "Ci:"<< Ci <<endl;
		cout << "nombre"<< nombre<<endl;
		cout << "telefono"<< telefono<<endl;
		cout << "direccion"<< direccion<<endl;
	}

};

