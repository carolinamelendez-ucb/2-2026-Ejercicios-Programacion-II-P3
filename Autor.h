#pragma once
#include <iostream>

using namespace std;


class Autor {


private:

    string nombre;
    string nacionalidad;
    int cantidadLibrosPublicados;



public:


    Autor() {

        nombre = "";
        nacionalidad = "";
        cantidadLibrosPublicados = 0;
    }



    Autor(string nombre, string nacionalidad, int cantidad) {

        this->nombre = nombre;
        this->nacionalidad = nacionalidad;
        this->cantidadLibrosPublicados = cantidad;
    }




    string getNombre() {

        return nombre;
    }




    int getCantidadLibros() {

        return cantidadLibrosPublicados;
    }


    void mostrar() {


        cout << "Nombre: " << nombre << endl;
        cout << "Nacionalidad: " << nacionalidad << endl;
        cout << "Cantidad libros publicados: " << cantidadLibrosPublicados << endl;


    }


};