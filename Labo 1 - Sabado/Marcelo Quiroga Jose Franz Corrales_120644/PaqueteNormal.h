#pragma once
#include <iostream>
#include <string>
#include "Exception.h"
#include "ClienteDuplicadoException.h"

using namespace std;

class PaqueteNormal
{
protected:
	string codigo;
	string descripcion;
	float peso;
	float costoPorkilo;
public:
	PaqueteNormal(string codigo,string descripcion,float peso,float costoPorKilo);
	virtual float calcularCosto();
	virtual string getIdentificador();
	virtual void mostrarDatos();
};

