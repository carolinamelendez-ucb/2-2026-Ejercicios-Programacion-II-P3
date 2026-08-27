#ifndef LIBRO_H
#define LIBRO_H

#include <string>
#include "Autor.h"

using namespace std;

class Libro {

private:

    string titulo;
    double precio;
    Autor autor;

public:

    Libro();

    Libro(string titulo, double precio, Autor autor);

    string getTitulo();
    double getPrecio();
    Autor getAutor();

    void setPrecio(double nuevoPrecio);

    bool esBestSeller();

    void mostrarInformacion();
};

#endif