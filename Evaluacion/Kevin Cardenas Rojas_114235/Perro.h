#pragma once
#include<iostream>
#include<string>

using namespace std;



class Perro {
private:
	string codigo;
	string nombre;
	string raza;
	string tamanio;
public:
	Perro(string codigo,string nombre,string raza,string tamanio) {
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
	string getTamanio() {
		return this->tamanio;
	}
static string getterCodigo(Perro* p) {
	    
		return p->codigo;
	}

};