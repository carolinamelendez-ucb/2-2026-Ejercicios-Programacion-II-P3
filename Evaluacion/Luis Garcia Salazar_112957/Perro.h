#pragma once
#include <iostream>
#include <string>

using namespace std;

class Perro

{
protected:
	string codigo; 
	string nombre;
	string raza;
	string tamanio;
public:
	Perro() {
		this->codigo = "";
		this->nombre = "";
		this->raza = "";
		this->tamanio = "";

	}
	
	string getCodigo() {
		return codigo;
	}

	void mostrar() {
		cout << "Codigo: "<<codigo<<endl;
		cout << "Nombre: "<< nombre<<endl;
		cout << "Raza: "<< raza<<endl;
		cout << "Tamaño: "<<tamanio<<endl;

	}
    static bool compararCodigo(string codigo, Perro* perro) {
        return codigo == perro->codigo;
    }

	static bool compararPerroRegistrado(string codigo, Perro* perro) {
		return codigo == perro->codigo;
	}
};


