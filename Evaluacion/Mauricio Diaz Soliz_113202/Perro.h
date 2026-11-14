#pragma once
#include <iostream>
#include <string.h>
using namespace std;
class Perro
{
private:
	string Codigo;
	string Nombre;
	string Raza;
	float Tamanio;
public:
	Perro(string codigo, string nombre, string raza, float tamanio) {
		this->Codigo = codigo;
		this->Nombre = nombre;
		this->Raza = raza;
		this->Tamanio = tamanio;
	}
	~Perro(){}
	string getcodigo() {
		return Codigo;
	}
	static string getCodigostatico(Perro* perro) {
		return perro->Codigo;
	}
	void Mostrar() {
		cout << "Datos del perro" << endl;
		cout << "Codigo: " << Codigo << endl;
		cout << "Raza: " << Raza << endl;
		cout << "Raza: " << Raza << endl;
		cout << "Tamanio: " << Tamanio << endl;
	}
};