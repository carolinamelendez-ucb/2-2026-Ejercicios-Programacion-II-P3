#pragma once
#include <iostream>
#include <string>
#include "Autor.h"
using namespace std;

class Libro
{
private:
	string titulo;
	float precio;
	Autor autor;
public:
	Libro()
	{
		titulo = "";
		precio = 0;
		autor = Autor();
	}

	Libro(string titulo, double precio, Autor* autor) 
	{
		this->titulo = titulo;
		this->precio = precio;
		this->autor = autor;
	}


	string getTitulo()
	{
		return titulo;
	}

	float getPrecio()
	{
		return precio;
	}

	Autor getAutor()
	{
		return autor;
	}

	bool esBestSeller()
	{
		return autor.getCantidadLibros() > 5;
	}	
};