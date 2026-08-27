#include <iostream>
#include <iomanip>

#include "Autor.h"
#include "Libro.h"

using namespace std;


int main() {

    cout << fixed << setprecision(2);

    Autor autor1(
        "Gabriel Garcia Marquez",
        "Colombiana",
        10
    );

    Autor autor2(
        "Mario Vargas Llosa",
        "Peruana",
        8
    );

    Autor autor3(
        "Juan Perez",
        "Boliviana",
        3
    );

    Autor autor4(
        "Maria Lopez",
        "Argentina",
        2
    );

    Autor autor5(
        "Carlos Gomez",
        "Chilena",
        6
    );

    Libro libros[5] = {

        Libro(
            "Cien anos de soledad",
            50,
            autor1
        ),

        Libro(
            "La ciudad y los perros",
            45,
            autor2
        ),

        Libro(
            "Mi primer libro",
            20,
            autor3
        ),

        Libro(
            "Historias de amor",
            30,
            autor4
        ),

        Libro(
            "El camino",
            60,
            autor5
        )
    };


    int cantidad = 5;

    cout << endl;
    cout << "========================================"
        << endl;

    cout << "          LISTA DE LIBROS"
        << endl;

    cout << "========================================"
        << endl;

    for (int i = 0; i < cantidad; i++) {

        libros[i].mostrarInformacion();
    }

    int N;

    cout << endl;

    cout << "Ingrese N: ";
    cin >> N;

    double suma = 0;
    int contador = 0;

    for (int i = 0; i < cantidad; i++) {

        if (
            libros[i]
            .getAutor()
            .getCantidadLibrosPublicados() > N
            ) {

            suma += libros[i].getPrecio();

            contador++;
        }
    }


    cout << endl;

    if (contador > 0) {

        double promedio = suma / contador;

        cout << "1. Precio promedio de libros cuyos autores "
            << "tienen mas de "
            << N
            << " libros publicados: $"
            << promedio
            << endl;
    }
    else {

        cout << "1. No existen libros que cumplan la condicion."
            << endl;
    }

    suma = 0;
    contador = 0;

    for (int i = 0; i < cantidad; i++) {

        if (libros[i].esBestSeller()) {

            suma += libros[i].getPrecio();

            contador++;
        }
    }


    cout << endl;

    if (contador > 0) {

        double promedio = suma / contador;

        cout << "2. Precio promedio de los Best Seller: $"
            << promedio
            << endl;
    }
    else {

        cout << "2. No existen libros Best Seller."
            << endl;
    }

    int posicionMasCaro = -1;

    for (int i = 0; i < cantidad; i++) {

        if (libros[i].esBestSeller()) {

            if (posicionMasCaro == -1 ||
                libros[i].getPrecio() >
                libros[posicionMasCaro].getPrecio()) {

                posicionMasCaro = i;
            }
        }
    }


    cout << endl;

    if (posicionMasCaro != -1) {

        cout << "3. Libro mas caro cuyo autor es reconocido:"
            << endl;

        libros[posicionMasCaro].mostrarInformacion();
    }
    else {

        cout << "3. No existe un libro cuyo autor sea reconocido."
            << endl;
    }

    int cantidadNovatos = 0;

    for (int i = 0; i < cantidad; i++) {

        if (
            libros[i]
            .getAutor()
            .getCantidadLibrosPublicados() <= 5
            ) {

            cantidadNovatos++;
        }
    }


    cout << endl;

    cout << "4. Cantidad de libros pertenecientes a "
        << "autores novatos: "
        << cantidadNovatos
        << endl;

    double totalRecaudado = 0;

    for (int i = 0; i < cantidad; i++) {

        if (
            libros[i]
            .getAutor()
            .getCantidadLibrosPublicados() > N
            ) {

            totalRecaudado += libros[i].getPrecio();
        }
    }


    cout << endl;

    cout << "5. Total recaudado por libros de autores "
        << "productivos: $"
        << totalRecaudado
        << endl;


    return 0;
}