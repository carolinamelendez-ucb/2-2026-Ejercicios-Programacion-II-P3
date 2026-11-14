#pragma once
#include <string>
#include <iostream>
using namespace std;
class Perro
{
private:
	int codigo;
	string nombre;
	string raza;
	int tamanio;
public:
	Perro(int codigo, string nombre, string raza, int tamanio);
 	~Perro();
void 	TamanioPerro();
};

