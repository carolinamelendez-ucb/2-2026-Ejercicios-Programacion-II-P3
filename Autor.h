#pragma once
#include <iostream>
#include <string>
using namespace std;

class Autor
{
private:
	string nombre;
	string nacionalidad;
	int cantidadLibros;
public:
	Autor()
	{
		nombre = "";
		nacionalidad = "";
		cantidadLibros = 0;
	}

	Autor(const string& nombre, const string& nacionalidad, int cantidadLibros)
		: nombre(nombre), nacionalidad(nacionalidad), cantidadLibros(cantidadLibros)
	{
	}

	string getNombre()
	{
		return nombre;
	}

	string getNacionalidad()
	{
		return nacionalidad;
	}

	int getCantidadLibros()
	{
		return cantidadLibros;
	}

	

	
};

