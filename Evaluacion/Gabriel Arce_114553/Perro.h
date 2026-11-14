#pragma once
#include <string>
#include <iostream>
using namespace std;

class Perro
{
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
	~Perro();
	void mostrar() {
		cout << "Perro: " << endl; 
		cout << "Codigo: " <<codigo<< endl; 
		cout << "Nombre: " <<nombre<< endl; 
		cout << "raza: " <<raza<< endl; 
		cout << "tamanio: " <<tamanio<< endl; 
	}
	string getTamanio() {
		return tamanio;
	}
	string getCodigo() {
		return codigo;
	}
	static bool comparador(Perro* perro, string codbuscado) {
		return perro->codigo == codbuscado;
	}
};
