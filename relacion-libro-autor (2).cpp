#include <iostream>
#include <string>
#include "Autor.h"
#include "Libro.h"
#include "ArregloLibros.h"
using namespace std;

int main() 
{
    Autor* a1 = new Autor("juan", "Colombia", 20);

    Autor* a2 = new Autor("marcelo", "Peru", 15);

    Autor* a3 = new Autor("dowy", "argentina", 1);

    Autor* a4 = new Autor("ana", "Bolivia", 4);

    Autor* a5 = new Autor("fercho", "brasil", 4);

    Libro* gestor[5];

    // Carga de libros
    gestor[0] = new Libro ("el resplandor", 25.50, a1);
    gestor[1] = new Libro ("Harry Potter", 30.00, a2);
    gestor[2] = new Libro ("Libro Random", 15.00, a3);
    gestor[3] = new Libro ("Primeros Pasos", 10.00, a4);
    gestor[4] = new Libro ("It", 28.00, a5);

    ArregloLibros arreglolibros(5);


    int N = 5;
    cout << "1. Precio promedio" << endl;
    cout << arreglolibros.precioProm(N) << endl;

    cout << "2. Precio promedio (Best Sellers)" << endl;
    cout << arreglolibros.promedioBestSeller()<< endl;

    cout << "3. " << endl;
    arreglolibros.LibroMasCaro();

    cout << "4. Libros de autores novatos: " << endl;
    arreglolibros.librosNovatos();

    cout << "5. Total recaudado por autores productivos " << endl;
    cout << arreglolibros.autoresProd() << endl;

    return 0;
}