#pragma once
#include "Autor.h"


class Libro {


private:

    string titulo;
    double precio;
    Autor* autor;



public:


    Libro() {


        titulo = "";
        precio = 0;
        autor = nullptr;


    }




    Libro(string titulo, double precio, Autor* autor) {


        this->titulo = titulo;
        this->precio = precio;
        this->autor = autor;


    }





    string getTitulo() {

        return titulo;

    }



    double getPrecio() {

        return precio;

    }



    Autor* getAutor() {

        return autor;

    }





    bool esBestSeller() {


        return autor->getCantidadLibros() > 5;

    }





    void mostrar() {


        cout << "Titulo: " << titulo << endl;

        cout << "Precio: " << precio << endl;

        autor->mostrar();

    }



};