#pragma once
#include <string>
#include <iostream>
#include "Servicio.h"
using namespace std;

class ServicioBano: public Servicio {
public:


	ServicioBano( string codigo):Servicio(codigo,"Bano", 20)
	{

	}
	string getNombre() override { return nombre; }
	string getCodigo() override { return codigo; }
	int getCosto() override { return costo; }

	void mostrar() override {
		cout << "Nombre: " << nombre << endl;
		cout << "Codigo: " << codigo << endl;
		cout << "Costo Producto: " << costo<< endl;
	}
};