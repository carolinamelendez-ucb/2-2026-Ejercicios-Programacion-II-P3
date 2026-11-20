#pragma once

#include<iostream>
#include<string>
#include "Servicio.h"

using namespace std;

class Atencion {
private:
	string codigo;
	Perro* perro;
	Servicio* servicio;
	int costoFinal;


	Atencion(string codigo,int costoFinal) {
		this->codigo = codigo;
	}







};