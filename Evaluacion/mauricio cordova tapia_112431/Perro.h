#pragma once
#include <string>
#include <iostream>
using namespace std;

class Perro {
private:
	string codigo;
	string nombre;
	string raza;
	string tamanio;
public:


	Perro( string codigo, string nombre,  string raza,  string tamanio)
		: codigo(codigo), nombre(nombre), raza(raza), tamanio(tamanio)
	{
	}

	static bool getter(Perro* perro, string codigo) {
		return perro->codigo == codigo;
	}
	string getTamanio() { return tamanio; }
	string getRaza() { return raza; }
	string getCodigo() { return codigo; }
	void mostrar(){
		cout << "Nombre: " << nombre << endl;
		cout << "Codigo: " << codigo << endl;
		cout << "Raza: " << raza << endl;
		cout << "Tamanio: " << tamanio << endl;

	
	
	}
};