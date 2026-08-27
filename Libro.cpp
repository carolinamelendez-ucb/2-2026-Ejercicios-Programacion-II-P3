#include "Libro.h"
#include <iostream>

using namespace std;

Libro::Libro()
    : autor("", "", 0)
{
    titulo = "";
    precio = 0;
}

Libro::Libro(
    string titulo,
    double precio,
    Autor autor
) {

    this->titulo = titulo;
    this->precio = precio;
    this->autor = autor;
}

string Libro::getTitulo() {
    return titulo;
}


double Libro::getPrecio() {
    return precio;
}


Autor Libro::getAutor() {
    return autor;
}

void Libro::setPrecio(double nuevoPrecio) {

    if (nuevoPrecio > 0) {

        precio = nuevoPrecio;

    }
    else {

        cout << "El precio debe ser mayor que 0."
            << endl;
    }
}

bool Libro::esBestSeller() {

    if (autor.getCantidadLibrosPublicados() > 5) {

        return true;
    }

    return false;
}

void Libro::mostrarInformacion() {

    cout << "--------------------------------"
        << endl;

    cout << "Titulo: "
        << titulo
        << endl;

    cout << "Precio: $"
        << precio
        << endl;

    cout << "Autor:"
        << endl;

    autor.mostrarInformacion();

    cout << "Best Seller: ";

    if (esBestSeller()) {

        cout << "SI" << endl;

    }
    else {

        cout << "NO" << endl;
    }

    cout << "--------------------------------"
        << endl;
}