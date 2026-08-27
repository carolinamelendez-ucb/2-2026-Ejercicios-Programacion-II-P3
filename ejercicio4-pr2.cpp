#include <iostream>
#include <string>
using namespace std;

const int NUM_LIBROS = 6;

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

    Autor(string nombre, string nacionalidad, int cantidadLibrosPublicados) {
        this->nombre = nombre;
        this->nacionalidad = nacionalidad;
        this->cantidadLibrosPublicados = cantidadLibrosPublicados;
    }

    string getNombre()  {
        return nombre;
    }

    string getNacionalidad() {
        return nacionalidad;
    }

    int getCantidadLibrosPublicados()  {
        return cantidadLibrosPublicados;
    }
};

class Libro {
private:
    string titulo;
    double precio;
    Autor autor;

public:
    Libro() {
        titulo = "";
        precio = 0.0;
    }

    Libro(string titulo, double precio, Autor autor) {
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

    Autor getAutor() {
        return autor;
    }

    bool esBestSeller()  {
        return autor.getCantidadLibrosPublicados() > 5;
    }

    // 1. Precio promedio de los libros cuyos autores tengan mas de N libros publicados
    void calcularPrecioPromedioAutoresConMasDeNLibros(Libro libros[], int numLibros, int N) {
        double sumaN = 0.0;
        int contadorN = 0;
        for (int i = 0; i < NUM_LIBROS; i++) {
            if (libros[i].getAutor().getCantidadLibrosPublicados() > N) {
                sumaN += libros[i].getPrecio();
                contadorN++;
            }
        }
        cout << "\n1. Precio promedio (autores con mas de " << N << " libros publicados): ";
        if (contadorN > 0)
            cout << sumaN / contadorN << endl;
        else
            cout << "No hay libros que cumplan la condicion." << endl;

    }

    // 2. Precio promedio de los libros considerados best seller
    void calcularPrecioPromedioBestSeller(Libro libros[], int numLibros) {
        double sumaBS = 0.0;
        int contadorBS = 0;
        for (int i = 0; i < NUM_LIBROS; i++) {
            if (libros[i].esBestSeller()) {
                sumaBS += libros[i].getPrecio();
                contadorBS++;
            }
        }
        cout << "2. Precio promedio de libros best seller: ";
        if (contadorBS > 0)
            cout << sumaBS / contadorBS << endl;
        else
            cout << "No hay libros best seller." << endl;
    }
    // 3. Libro mas caro cuyo autor sea reconocido 
    void libroMasCaroAutorReconocido(Libro libros[], int numLibros) {
        int Reconocido = -1;
        for (int i = 0; i < NUM_LIBROS; i++) {
            if (libros[i].esBestSeller()) {
                if (Reconocido == -1 || libros[i].getPrecio() > libros[Reconocido].getPrecio())
                    Reconocido = i;
            }
        }
        cout << "3. Libro mas caro de autor reconocido: ";
        if (Reconocido != -1)
            cout << libros[Reconocido].getTitulo() << " ($" << libros[Reconocido].getPrecio() << ")" << endl;
        else
            cout << "No hay libros de autores reconocidos." << endl;
    }

    // 4. Cantidad de libros que pertenecen a autores novatos
    void cantidadLibrosAutoresNovatos(Libro libros[], int numLibros, int UMBRAL_NOVATO) {
        int contadorNovatos = 0;
        int UMBRAL_NOVATO = 2;
        for (int i = 0; i < NUM_LIBROS; i++) {
            if (libros[i].getAutor().getCantidadLibrosPublicados() <= UMBRAL_NOVATO)
                contadorNovatos++;
        }
        cout << "4. Cantidad de libros de autores novatos: " << contadorNovatos << endl;
    }
    // 5. Total recaudado por los libros de autores productivos 
    void totalRecaudadoAutoresProductivos(Libro libros[], int numLibros) {
        double totalProductivos = 0.0;
        for (int i = 0; i < NUM_LIBROS; i++) {
            if (libros[i].esBestSeller())
                totalProductivos += libros[i].getPrecio();
        }
        cout << "5. Total recaudado por libros de autores productivos: " << totalProductivos << endl;
    }

};



int main() {

    Libro libros[NUM_LIBROS] = {
        Libro("l1", 45.0, Autor("a1", "Argentina", 12)),
        Libro("l2", 60.0, Autor("a2", "Colombia", 15)),
        Libro("l3", 55.0, Autor("a3", "Argentina", 8)),
        Libro("l4", 30.0, Autor("a4", "Bolivia", 1)),
        Libro("l5", 35.0, Autor("a5", "Peru", 2)),
        Libro("l6", 40.0, Autor("a6", "Chile", 4))
    };
    return 0;
}