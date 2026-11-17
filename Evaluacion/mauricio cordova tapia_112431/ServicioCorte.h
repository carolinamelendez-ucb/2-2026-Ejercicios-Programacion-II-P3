#pragma once
#include <string>
#include <iostream>
#include "Servicio.h"
#include "Perro.h"
using namespace std;

class ServicioCorte:public Servicio {

public:


	ServicioCorte( string codigo):Servicio(codigo,"Corte", 30)
	{
	}
	string getNombre() override { return nombre; }

	string getCodigo() override { return codigo; }
	int getCosto() override{ 
		return costo; }
	void mostrar() override {
		cout << "Nombre: " << nombre << endl;
		cout << "Codigo: " << codigo << endl;
		cout << "Costo Corte: " << costo << endl;
	}
};