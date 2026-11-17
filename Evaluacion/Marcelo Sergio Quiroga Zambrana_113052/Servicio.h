#pragma once
#include <iostream>
#include<string>

using namespace std;

class Servicio
{
protected:
	string codigo;
	string nombre;
	double costo;
public:
	Servicio(string codigo,string nombre);
	virtual string getCodigo();
	virtual double getCosto();
	virtual void mostrarDatos();
};

