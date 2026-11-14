#pragma once
#include <iostream>
#include <string>
#include "ListaGenerica.h"
using namespace std;
class Servicio {
protected:
	string codigoSer;
	string nombre;


public:
	Servicio(string nombre, string codigo) {
		this->nombre=nombre;
		this->codigoSer=codigo;
	}
	~Servicio() {

	}
	string getcodigoSer()
	{
		return codigoSer;
	}
	static string getterServicio(Servicio *ser) {
		return ser->getcodigoSer();

	}

	virtual void mostrar() {
		cout << "nombre servicio:  " << nombre << endl;
		cout << " codigo servicio : " << codigoSer << endl;
	}
};