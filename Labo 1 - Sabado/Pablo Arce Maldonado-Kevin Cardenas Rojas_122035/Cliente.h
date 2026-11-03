#pragma once
#include <iostream>
#include <string>

using namespace std;


class Cliente {
private:
	int ci;
	string nombre;
	int telefono;
	string direccion;
public:
	Cliente(int ci, string nombre, int telefono, string direccion) {
		this->ci = ci;
		this->nombre = nombre;
		this->telefono = telefono;
		this->direccion = direccion;
	}

	int getCi(){
		return this->ci;
	}

	string getNombre() {
		return this->nombre;
	}

	int getTelefono() {
		return this->telefono;
	}

	string getDireccion() {
		return this->direccion;
	}

	static bool compararNombre(Cliente* a, Cliente* b) {
		return a->nombre > b->nombre;
	}


	static int getterCi(Cliente* e) {
		return e->ci;
	}

	void mostrar() {
		cout << "ID: " << ci << " | Nombre: "
			<< nombre << " | telefono: "
			<<telefono<<" | direccion: " 
			<< direccion << endl;
	}
};