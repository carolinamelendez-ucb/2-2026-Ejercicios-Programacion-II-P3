#pragma once
#include "Libro.h"

class ArrayLibro
{
private:
    int tamanio;
    Libro** libros;
    int indice;

public:
    ArrayLibro(int tamanio)
    {
        this->tamanio = tamanio;
        libros = new Libro * [indice];
        indice = 0;
    }

    void agregar(Libro* libro)
    {
        if (indice < tamanio)
        {
            libros[indice] = libro;
            indice++;
        }
    }

    int getCantidad()
    {
        return indice;
    }
};
