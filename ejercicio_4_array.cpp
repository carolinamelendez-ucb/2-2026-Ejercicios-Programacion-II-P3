// ejercicio_4_array.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>

using namespace std;

const int TAM = 10;

class Autor {
private:
    string nombre;
    string nacionalidad;
    int cantidadLibrosPublicados;
public:
    Autor(const string& nombre, const string& nacionalidad, int cantidadLibrosPublicados)
        : nombre(nombre), nacionalidad(nacionalidad), cantidadLibrosPublicados(cantidadLibrosPublicados)
    {
    }
    void mostrar() {
        cout << "nombre: " << nombre << endl;
        cout << "nacionalidad: " << nacionalidad << endl;
        cout << "cantidad de libros publicados: " << cantidadLibrosPublicados << endl;
    }
    string getNombre() {
        return nombre;
    }
    string getNacionalidad() {
        return nacionalidad;
    }
    int getCantidadLibrosPublicados() {
        return cantidadLibrosPublicados;
    }
};
class Libro {
private:
    string titulo;
    double precio;
    Autor* autor;
public:
    Libro(const string& titulo, double precio, Autor* autor)
        : titulo(titulo), precio(precio), autor(autor)
    {
    }
    bool esBestSeller() {
        if (autor->getCantidadLibrosPublicados() > 5) {
            return true;
        }
        return false;
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
    void mostrar() {
        cout << "titulo: " << titulo << endl;
        cout << "precio: " << precio << endl;

        cout << "autor:" << endl;
        autor->mostrar();

        cout << "------------------------" << endl;
    }
};
class Libreria {
private:
    Libro** listaLibros;
    int indice;
public:
    Libreria() {
        this->listaLibros = new Libro * [TAM];
        this->indice = 0;
    }
    void agregarLibro(Libro* nuevoLibro) {
        listaLibros[indice] = nuevoLibro;
        indice++;
    }
    // 1. Precio promedio de libros cuyos autores
    // tengan mas de N libros publicados
    double precioPromedioMasDeN(int N) {
        double suma = 0;
        int cantidad = 0;
        for (int i = 0; i < indice; i++) {
            if (listaLibros[i]->getAutor()->getCantidadLibrosPublicados() > N) {
                suma += listaLibros[i]->getPrecio();
                cantidad++;
            }
        }
        if (cantidad == 0) {
            return 0;
        }
        return suma / cantidad;
    }
    // 2. Precio promedio de libros considerados best seller
    double precioPromedioBestSeller() {
        double suma = 0;
        int cantidad = 0;
        for (int i = 0; i < indice; i++) {
            if (listaLibros[i]->esBestSeller()) {
                suma += listaLibros[i]->getPrecio();
                cantidad++;
            }
        }
        if (cantidad == 0) {
            return 0;
        }
        return suma / cantidad;
    }
    // 3. Libro mas caro cuyo autor sea reconocido
    // Autor reconocido: mas de 10 libros publicados
    Libro* libroMasCaroAutorReconocido() {
        Libro* mayor = nullptr;
        for (int i = 0; i < indice; i++) {
            if (listaLibros[i]->getAutor()->getCantidadLibrosPublicados() > 10) {
                if (mayor == nullptr ||
                    listaLibros[i]->getPrecio() > mayor->getPrecio()) {
                    mayor = listaLibros[i];
                }
            }
        }
        return mayor;
    }
    // 4. Cantidad de libros que pertenecen
    // a autores novatos
    // Autor novato: hasta 2 libros publicados
    int cantidadLibrosAutoresNovatos() {
        int cantidad = 0;
        for (int i = 0; i < indice; i++) {
            if (listaLibros[i]->getAutor()->getCantidadLibrosPublicados() <= 2) {
                cantidad++;
            }
        }
        return cantidad;
    }
    // 5. Total recaudado por libros
    // de autores productivos
    // Autor productivo: mas de 5 libros publicados
    double totalRecaudadoAutoresProductivos() {
        double total = 0;
        for (int i = 0; i < indice; i++) {
            if (listaLibros[i]->getAutor()->getCantidadLibrosPublicados() > 5) {
                total += listaLibros[i]->getPrecio();
            }
        }
        return total;
    }
    void mostrar() {
        for (int i = 0; i < indice; i++) {
            listaLibros[i]->mostrar();
        }
    }
};
int main()
{
    Libreria libreria;

    // CREAR AUTORES

    Autor* autorGabriel =
        new Autor("Gabriel Garcia Marquez", "Colombiana", 15);

    Autor* autorMario =
        new Autor("Mario Vargas Llosa", "Peruana", 12);

    Autor* autorJuan =
        new Autor("Juan Perez", "Boliviana", 2);

    Autor* autorAna =
        new Autor("Ana Torres", "Argentina", 5);

    // CREAR LIBROS

    Libro* libro1 =
        new Libro("Cien anos de soledad", 120, autorGabriel);

    libreria.agregarLibro(libro1);


    Libro* libro2 =
        new Libro("El amor en los tiempos del colera", 100, autorGabriel);

    libreria.agregarLibro(libro2);


    Libro* libro3 =
        new Libro("La ciudad y los perros", 90, autorMario);

    libreria.agregarLibro(libro3);


    Libro* libro4 =
        new Libro("Conversacion en La Catedral", 110, autorMario);

    libreria.agregarLibro(libro4);


    Libro* libro5 =
        new Libro("Mi primer libro", 50, autorJuan);

    libreria.agregarLibro(libro5);


    Libro* libro6 =
        new Libro("Historias de mi pueblo", 70, autorAna);

    libreria.agregarLibro(libro6);


    // MOSTRAR LIBROS

    cout << "===== LIBROS =====" << endl;

    libreria.mostrar();


    // 1

    int N = 5;

    cout << endl;

    cout << "1. Precio promedio de libros de autores " << "con mas de " << N << " libros publicados: " << libreria.precioPromedioMasDeN(N) << endl;


    // 2

    cout << "2. Precio promedio de libros best seller: " << libreria.precioPromedioBestSeller() << endl;


    // 3

    Libro* mayor =
        libreria.libroMasCaroAutorReconocido();

    cout << "3. Libro mas caro cuyo autor sea reconocido:" << endl;

    if (mayor != nullptr) {
        mayor->mostrar();
    }


    // 4

    cout << "4. Cantidad de libros de autores novatos: " << libreria.cantidadLibrosAutoresNovatos() << endl;


    // 5

    cout << "5. Total recaudado por libros de autores productivos: " << libreria.totalRecaudadoAutoresProductivos() << endl;


    return 0;
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
