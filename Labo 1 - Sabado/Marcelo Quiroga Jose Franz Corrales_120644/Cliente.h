#pragma once
#include <iostream>
#include <string>

using namespace std;

class Cliente
{
private:
	string ci;
	string nombre;
	int telefono;
	string direccion;
public:
	Cliente(string ci,string nombre,int telefono,string direccion);
	string getIdentificador();
	void mostrarDatos();
};

