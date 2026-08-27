#pragma once
#include <iostream>
#include <string>
#include "Libro.h"
using namespace std;


class ArregloLibros
{
private:
	Libro* libro;
	int cantidadActual;
	int capacidad;
public:
	ArregloLibros(int capacidadMax)
	{
		capacidad = capacidadMax;
		cantidadActual = 0;
		libro = new Libro[capacidad];
	}

	~ArregloLibros()
	{
		delete[]libro;
	}

	void agregarLibro(Libro& agLibro)
	{
		if (cantidadActual < capacidad)
		{
			libro[cantidadActual] = agLibro;
			cantidadActual++;
		}
		else
		{
			cout << "cantidad maxima alcanzada" << endl;
		}
	}

	float precioProm(int n)
	{
		float suma = 0;
		int cont = 0;
		float prom = 0;
		for (int i = 0; i < cantidadActual; i++)
		{
			if (libro[i].getAutor().getCantidadLibros() > n)
			{
				suma = libro[i].getPrecio();
				cont++;
			}
		}
		return prom = suma / cont;
	}

	float promedioBestSeller()
	{
		float suma = 0;
		float cont = 0;
		float prom = 0;
		for (int i = 0; i < cantidadActual; i++)
		{
			if (libro[i].esBestSeller())
			{
				suma = libro[i].getPrecio();
				cont++;
			}
		}
		return suma = suma / cont;
	}

	void LibroMasCaro() //tome en cuenta 3 para autor reconocido >=
	{
		float max = -1;
		int cont = -1;
		for (int i = 0; i < cantidadActual; i++)
		{
			if (libro[i].getAutor().getCantidadLibros() >= 3)
			{
				if (libro[i].getPrecio() > max)
				{
					max = libro[i].getPrecio();
					cont = i;
				}
			}
		}
		if (cont != -1)
		{
			cout << "el libro mas caro es " << libro[cont].getTitulo() << "que cuesta " << libro[cont].getPrecio() << endl;
		}
		else
		{
			cout << "no hay libro caro de autor reconocido" << endl;
		}
	}


	void librosNovatos()//tome en cuenta 1 libro <=
	{
		int cont = 0;
		for (int i = 0; i < cantidadActual; i++)
		{
			if (libro[i].getAutor().getCantidadLibros() <= 1)
			{
				cont++;
			}
		}
		cout << "la cantidad de libros de novatos es" << cont << endl;
	}

	float autoresProd()//asumimos 10
	{
		float total = 0;
		for (int i = 0; i < cantidadActual; i++)
		{
			if (libro[i].getAutor().getCantidadLibros() >= 10)
			{
				total += libro[i].getPrecio();
			}
		}
		return total;
	}
};