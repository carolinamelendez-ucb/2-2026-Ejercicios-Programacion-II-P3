#pragma once
#include <iostream>
#include<string>
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
	string getTamanio() {
		return tamanio;
	}
	string getCodigo() {
		return codigo;
	}
	static bool Comparar(string ci,Perro* perro) {
		if (ci == perro->getCodigo()) {
			return true;
		}
		else {
			return false;
		}
	}
	void Mostrar() {
		cout << "=======DATOS DEL PERRO ============" << endl;
		cout << "El codigo del Perro: " << codigo << endl;
		cout << "El nombre del Perro: " << nombre << endl;
		cout << "El raza del Perro: " << raza << endl;
		cout << "El tamanio del Perro: " << tamanio << endl;
	}

};