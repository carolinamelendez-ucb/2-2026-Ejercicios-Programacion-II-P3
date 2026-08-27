#include "Autor.h"
#include <iostream>

using namespace std;

#include "Autor.h"
#include <iostream>

using namespace std;


Autor::Autor() {

    nombre = "";
    nacionalidad = "";
    cantidadLibrosPublicados = 0;
}


Autor::Autor(
    string nombre,
    string nacionalidad,
    int cantidadLibrosPublicados
) {

    this->nombre = nombre;
    this->nacionalidad = nacionalidad;
    this->cantidadLibrosPublicados = cantidadLibrosPublicados;
}

string Autor::getNombre() {
    return nombre;
}


string Autor::getNacionalidad() {
    return nacionalidad;
}


int Autor::getCantidadLibrosPublicados() {
    return cantidadLibrosPublicados;
}


void Autor::setCantidadLibrosPublicados(int cantidad) {

    if (cantidad >= 0) {
        cantidadLibrosPublicados = cantidad;
    }
    else {
        cout << "La cantidad de libros no puede ser negativa."
            << endl;
    }
}


void Autor::mostrarInformacion() {

    cout << "Nombre: "
        << nombre
        << endl;

    cout << "Nacionalidad: "
        << nacionalidad
        << endl;

    cout << "Libros publicados: "
        << cantidadLibrosPublicados
        << endl;
}