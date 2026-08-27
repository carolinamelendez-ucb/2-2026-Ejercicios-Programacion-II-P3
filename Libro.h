#pragma once
#include <iostream>
#include <string>
#include "Autor.h"

using namespace std;

class Libro
{
private:
    string titulo;
    double precio;
    Autor autor;

public:
    Libro()
    {
        titulo = "";
        precio = 0;
        autor = Autor();
    }

    Libro(string titulo, double precio, Autor autor)
    {
        this->titulo = titulo;
        this->precio = precio;
        this->autor = autor;
    }

    string getTitulo()
    {
        return titulo;
    }

    double getPrecio()
    {
        return precio;
    }

    Autor getAutor()
    {
        return autor;
    }

   
    bool esBestSeller()
    {
        if (autor.getCantidadLibrosPublicados() > 5)
        {
            return true;
        }

        return false;
    }

    
    static double precioPromedio(Libro libros[], int cantidad, int N)
    {
        double suma = 0;
        int contador = 0;

        for (int i = 0; i < cantidad; i++)
        {
            if (libros[i].getAutor().getCantidadLibrosPublicados() > N)
            {
                suma = suma + libros[i].getPrecio();
                contador++;
            }
        }

        if (contador > 0)
        {
            return suma / contador;
        }

        return 0;
    }

   double precioPromedioBestSeller(Libro libros[], int cantidad)
    {
        double suma = 0;
        int contador = 0;

        for (int i = 0; i < cantidad; i++)
        {
            if (libros[i].esBestSeller())
            {
                suma = suma + libros[i].getPrecio();
                contador++;
            }
        }

        if (contador > 0)
        {
            return suma / contador;
        }

        return 0;
    }

Libro libroMasCaro(Libro libros[], int cantidad)
    {
        Libro mayor;
        double precioMayor = 0;

        for (int i = 0; i < cantidad; i++)
        {
            if (libros[i].getAutor().getCantidadLibrosPublicados() > 5)
            {
                if (libros[i].getPrecio() > precioMayor)
                {
                    precioMayor = libros[i].getPrecio();
                    mayor = libros[i];
                }
            }
        }

        return mayor;
    }

   int cantidadNovatos(Libro libros[], int cantidad)
    {
        int contador = 0;

        for (int i = 0; i < cantidad; i++)
        {
            if (libros[i].getAutor().getCantidadLibrosPublicados() <= 5)
            {
                contador++;
            }
        }

        return contador;
    }
     double totalRecaudado(Libro libros[], int cantidad)
    {
        double total = 0;

        for (int i = 0; i < cantidad; i++)
        {
            if (libros[i].getAutor().getCantidadLibrosPublicados() > 5)
            {
                total = total + libros[i].getPrecio();
            }
        }

        return total;
    }
};
