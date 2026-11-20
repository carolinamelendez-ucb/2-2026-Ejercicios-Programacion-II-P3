#pragma once
#include <iostream>
#include <string>
using namespace std;

class Servicio {
protected:
	string codigo;
	string nombre;
public:
	Servicio(const string& codigo, const string& nombre)
	{
		this->codigo = codigo;
		this->nombre = nombre;
	}
	string getCodigo() {
		return codigo;
	}
	static bool comparar(string cod, Servicio* servic) {
		return cod == servic->getCodigo();
	}
	virtual void mostrar() {
		cout << "---------------------------------------------------" << endl;
		cout << "codigo: " << codigo << endl;
		cout << "nombre: " << nombre << endl;
	}
};