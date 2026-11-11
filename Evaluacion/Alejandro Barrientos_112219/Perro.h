#pragma once
#include <iostream>
#include <string>

using namespace std;

class Perro
{
private:
	int codigo;
	string nombre;
	string raza;
	string tamanio;
public:
	Perro(int codigo, string nombre, string raza , string tamanio)
	{
		this->codigo = codigo;
		this->nombre = nombre;
		this->raza = raza;
		this->tamanio = tamanio;
	}

	int getcodigo()
	{
		return codigo;
	}

	string getnombre()
	{
		return nombre;
	}
	string getraza()
	{
		return raza;
	}
	string gettamanio()
	{
		return tamanio;
	}



	~Perro(){}
};