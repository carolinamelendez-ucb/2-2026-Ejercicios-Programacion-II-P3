#pragma once
#include <iostream>
#include <string>
using namespace std;

class Perro {
private:
	string codigo;
	string nombre;
	string raza;
	string tamanio;
public:
	Perro(const string& codigo, const string& nombre, const string& raza, string tamanio)
	{
		this->codigo = codigo;
		this->nombre = nombre;
		this->raza = raza;
		this->tamanio = tamanio;
	}
	string getCodigo() {
		return codigo;
	}
	string getTamanio() {
		return tamanio;
	}
	static bool comparar(string cod, Perro* perr) {
		return cod == perr->getCodigo();
	}
	void mostrar() {
		cout << "---------------------------------------------------" << endl;
		cout << "codigo: " << codigo << endl;
		cout << "nombre: " << nombre << endl;
		cout << "raza: " << raza << endl;
		cout << "tamanio: " << tamanio << endl;
		cout << "---------------------------------------------------" << endl;
	}
};