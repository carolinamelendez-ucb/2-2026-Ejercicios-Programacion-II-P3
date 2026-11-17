#pragma once
#include <iostream>
#include <string>
#include "TamanioNoValidoException.h"

using namespace std;

class Perro
{
private:
	string codigo;
	string nombre;
	string raza;
	string tamanio;
public:
	Perro(string codigo,string nombre,string raza,string tamanio);
	string getCodigo();
	string getTamanio();
	void mostrarDatos();
};

