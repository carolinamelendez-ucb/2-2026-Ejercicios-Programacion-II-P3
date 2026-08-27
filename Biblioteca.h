#pragma once
#include "Libro.h"


class Biblioteca {


private:

    Libro** libros;
    int cantidad;

public:


    Biblioteca() {

        libros = nullptr;
        cantidad = 0;

    }



    Biblioteca(Libro* lista[], int cantidad) {


        this->cantidad = cantidad;

        libros = new Libro * [cantidad];


        for (int i = 0;i < cantidad;i++) {

            libros[i] = lista[i];

        }


    }

    ~Biblioteca() {

        delete[] libros;

    }


    double promedioAutores(int N) {


        double suma = 0;
        int contador = 0;


        for (int i = 0;i < cantidad;i++) {


            if (libros[i]->getAutor()->getCantidadLibros() > N) {


                suma += libros[i]->getPrecio();

                contador++;


            }


        }


        if (contador == 0)

            return 0;


        return suma / contador;


    }






    double promedioBestSeller() {
        double suma = 0;
        int contador = 0;

        for (int i = 0;i < cantidad;i++) {


            if (libros[i]->esBestSeller()) {


                suma += libros[i]->getPrecio();

                contador++;


            }
        }



        if (contador == 0)

            return 0;
        return suma / contador;


    }







    void libroMasCaro() {


        Libro* mayor = NULL;



        for (int i = 0;i < cantidad;i++) {


            if (libros[i]->getAutor()->getCantidadLibros() > 5) {



                if (mayor == NULL || libros[i]->getPrecio() > mayor->getPrecio()) {


                    mayor = libros[i];


                }


            }


        }




        if (mayor != NULL) {


            mayor->mostrar();


        }



    }







    int cantidadNovatos() {


        int contador = 0;



        for (int i = 0;i < cantidad;i++) {


            if (libros[i]->getAutor()->getCantidadLibros() <= 5) {


                contador++;


            }


        }



        return contador;


    }








    double totalProductivos() {


        double total = 0;



        for (int i = 0;i < cantidad;i++) {


            if (libros[i]->getAutor()->getCantidadLibros() > 5) {


                total += libros[i]->getPrecio();


            }


        }



        return total;


    }



};