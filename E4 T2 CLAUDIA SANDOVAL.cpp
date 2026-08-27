#include <iostream>
#include <string>

using namespace std;

class Autor {
private:
    string nombre;
    string nacionalidad;
    int cantidadLibrosPublicados;

public:
    Autor() {
        nombre = "Desconocido";
        nacionalidad = "Desconocida";
        cantidadLibrosPublicados = 0;
    }

    Autor(string nombre, string nacionalidad, int cantidadLibrosPublicados) {
        this->nombre = nombre;
        this->nacionalidad = nacionalidad;
        this->cantidadLibrosPublicados = cantidadLibrosPublicados;
    }

    string getNombre() const { 
        return nombre; 
    }
    int getCantidadLibrosPublicados() const { 
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
        titulo = "Sin titulo";
        precio = 0.0;
    }

    Libro(string titulo, double precio, Autor autor) {
        this->titulo = titulo;
        if (precio < 0) {
            this->precio = 0.0;
        }
        else {
            this->precio = precio;
        }
        this->autor = autor;
    }

    bool esBestSeller() const {
        return autor.getCantidadLibrosPublicados() > 5;
    }

    double getPrecio() const { 
        return precio; 
    }
    Autor getAutor() const { 
        return autor; 
    }
    string getTitulo() const { 
        return titulo; 
    }
};

void calcularPromedioPrecioMayorAN(Libro arr[], int tam, int n) {
    double suma = 0.0;
    int contador = 0;

    for (int i = 0; i < tam; i++) {
        if (arr[i].getAutor().getCantidadLibrosPublicados() > n) {
            suma += arr[i].getPrecio();
            contador++;
        }
    }

    if (contador > 0) {
        cout << "1. Precio promedio autores con mas de " << n << " libros: " << (suma / contador) << endl;
    }
    else {
        cout << "1. No hay libros que cumplan esta condicion." << endl;
    }
}

void calcularPromedioBestSeller(Libro arr[], int tam) {
    double suma = 0.0;
    int contador = 0;

    for (int i = 0; i < tam; i++) {
        if (arr[i].esBestSeller()) {
            suma += arr[i].getPrecio();
            contador++;
        }
    }

    if (contador > 0) {
        cout << "2. Precio promedio de los Best Sellers: " << (suma / contador) << endl;
    }
    else {
        cout << "2. No hay libros Best Seller en el arreglo." << endl;
    }
}

void mostrarLibroMasCaroReconocido(Libro arr[], int tam) {
    double precioMax = -1.0;
    string tituloMax = "";
    string autorMax = "";

    for (int i = 0; i < tam; i++) {
        if (arr[i].esBestSeller()) {
            if (arr[i].getPrecio() > precioMax) {
                precioMax = arr[i].getPrecio();
                tituloMax = arr[i].getTitulo();
                autorMax = arr[i].getAutor().getNombre();
            }
        }
    }

    if (precioMax != -1.0) {
        cout << "3. Libro mas caro de autor reconocido: '" << tituloMax
            << "' de " << autorMax << " (Bs. " << precioMax << ")" << endl;
    }
    else {
        cout << "3. No se encontraron libros de autores reconocidos." << endl;
    }
}

void contarLibrosNovatos(Libro arr[], int tam) {
    int contador = 0;
    for (int i = 0; i < tam; i++) {
        if (arr[i].getAutor().getCantidadLibrosPublicados() <= 2) {
            contador++;
        }
    }
    cout << "4. Cantidad de libros de autores novatos: " << contador << endl;
}

void calcularTotalProductivos(Libro arr[], int tam) {
    double suma = 0.0;
    for (int i = 0; i < tam; i++) {
        if (arr[i].getAutor().getCantidadLibrosPublicados() >= 10) {
            suma += arr[i].getPrecio();
        }
    }
    cout << "5. Total recaudado por autores productivos: Bs. " << suma << endl;
}

int main() {
    Autor a1("Hola", "Bolivia", 15);
    Autor a2("l2", "peru", 7);      
    Autor a3("l4 ", "usa", 1);       
    Autor a4("jrr", "britanico", 65);       
    const int TAM = 5;
    Libro arregloLibros[TAM];
    arregloLibros[0] = Libro("soledad", 150.50, a1);
    arregloLibros[1] = Libro("TLOTR", 200.0, a2);
    arregloLibros[2] = Libro("king kong", 35.0, a3);
    arregloLibros[3] = Libro("cancion", 180.0, a4);
    arregloLibros[4] = Libro("silmarillion", 220.0, a4);
    calcularPromedioPrecioMayorAN(arregloLibros, TAM, 5);
    calcularPromedioBestSeller(arregloLibros, TAM);
    mostrarLibroMasCaroReconocido(arregloLibros, TAM);
    contarLibrosNovatos(arregloLibros, TAM);
    calcularTotalProductivos(arregloLibros, TAM);

    return 0;
}