#pragma once
#include<iostream>
#include<string>
using namespace std;

class Perro{
private:
	string codigo;
	string nombre;
	string raza;
	float tamanio;
public:
	Perro(const string& codigo, const string& nombre, const string& raza, float tamanio) {
		this->codigo = codigo;
		this->nombre = nombre;
		this->raza = raza;
		this->tamanio = tamanio;
	}
	string getCodigo() {
		return this->codigo;
	}
	string getNombre() {
		return this->nombre;
	}
	string getRaza() {
		return this->raza;
	}
	float getTamanio() {
		return this->tamanio;
	}
	
	void mostrar() {
		cout << "Codigo: " << this->codigo << endl;
		cout << "Nombre: " << this->nombre << endl;
		cout << "Raza: " << this->raza << endl;
		cout << "Tamanio: " << this->tamanio << endl;
	}
	static string getterCodigo(Perro* p) {
		return p->codigo;
	}
};

