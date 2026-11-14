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
	Perro(string codigo, string nombre, string tamanio) {
		this->codigo = codigo;
		this->nombre = nombre;
		this->tamanio= tamanio;
	}
	void mostrar() {
		cout << endl;
		cout << "codigo: " << codigo << endl;
		cout << "nombre: " << nombre << endl;
		cout << "tamanio: " << tamanio<< endl;
	}
	string getCodigo() {
		return this->codigo;
	}
	string getTamanio() {
		return this->tamanio;
	}
	string getNombre() {
		return this->nombre;
	}
	static bool compararCodigo(Perro* perro, string codigo) {
		return perro->getCodigo() == codigo;
	}
	static bool mostrarNombreOrdenado(Perro* p1, Perro* p2) {
		return p1->getNombre() < p2->getNombre();
	}
};

