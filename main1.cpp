#include <iostream>
#include "Autor.h"
#include "Libro.h"
#include "ArrayLibro.h"

using namespace std;

int main()
{
    Autor a1("Gabriel Garcia Marquez", "Colombiana", 10);
    Autor a2("Rowling", "Britanica", 7);
    Autor a3("Juan Perez", "Boliviana", 3);
    Autor a4("Mario Vargas Llosa", "Peruana", 12);

    Libro l1("Cien anos de soledad", 120, a1);
    Libro l2("Harry Potter", 150, a2);
    Libro l3("Mi primer libro", 80, a3);
    Libro l4("La ciudad y los perros", 130, a4);

    ArrayLibro libros;

    libros.agregar(l1);
    libros.agregar(l2);
    libros.agregar(l3);
    libros.agregar(l4);


    // Probar esBestSeller()

    cout << "L1 Best Seller: " << l1.esBestSeller() << endl;
    cout << "L3 Best Seller: " << l3.esBestSeller() << endl;


    // Ejercicio 1

    cout << "Precio promedio autores con mas de 5 libros: "
        << Libro::precioPromedio(libros.getLibros(), libros.getCantidad(), 5)
        << endl;


    // Ejercicio 2

    cout << "Precio promedio Best Seller: "
        << Libro::precioPromedioBestSeller(libros.getLibros(), libros.getCantidad())
        << endl;


    // Ejercicio 3

    Libro mayor = Libro::libroMasCaro(libros.getLibros(), libros.getCantidad());

    cout << "Libro mas caro de autor reconocido: "
        << mayor.getTitulo() << endl;

    cout << "Precio: "
        << mayor.getPrecio() << endl;

    cout << "Cantidad de libros de autores novatos: "
        << Libro::cantidadNovatos(libros.getLibros(), libros.getCantidad())
        << endl;

    cout << "Total recaudado por autores productivos: "
        << Libro::totalRecaudado(libros.getLibros(), libros.getCantidad())
        << endl;


    return 0;
}
