#include <iostream>
#include "Biblioteca.h"

using namespace std;


int main() {


    Autor* a1 = new Autor("Gabriel Garcia Marquez", "Colombia", 20);

    Autor* a2 = new Autor("Mario Vargas Llosa", "Peru", 15);

    Autor* a3 = new Autor("Juan Perez", "Bolivia", 2);

    Autor* a4 = new Autor("Ana Lopez", "Bolivia", 4);




    Libro* libros[4];



    libros[0] = new Libro("Cien anos de soledad", 80, a1);

    libros[1] = new Libro("La ciudad y los perros", 70, a2);

    libros[2] = new Libro("Historia nueva", 40, a3);

    libros[3] = new Libro("Mi primer libro", 30, a4);





    Biblioteca biblioteca(libros, 4);





    cout << endl;

    cout << "1. Promedio precio libros autores con mas de N publicaciones" << endl;

    cout << biblioteca.promedioAutores(5) << endl;


    cout << endl;

    cout << "2. Promedio precio libros Best Seller" << endl;

    cout << biblioteca.promedioBestSeller() << endl;




    cout << endl;

    cout << "3. Libro mas caro cuyo autor es reconocido" << endl;

    biblioteca.libroMasCaro();


    cout << endl;

    cout << "4. Cantidad de libros de autores novatos" << endl;

    cout << biblioteca.cantidadNovatos() << endl;

    cout << endl;

    cout << "5. Total recaudado por libros de autores productivos" << endl;

    cout << biblioteca.totalProductivos() << endl;


    delete libros[0];
    delete libros[1];
    delete libros[2];
    delete libros[3];


    delete a1;
    delete a2;
    delete a3;
    delete a4;


    return 0;

}