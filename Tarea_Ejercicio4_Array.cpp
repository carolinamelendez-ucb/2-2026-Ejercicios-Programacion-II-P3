// Tarea_Ejercicio4_Array.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include <iostream> 
#include <string> 

using namespace std;


class Autor
{
private:
    string nombre;
    string nacionalidad;
    int cantidadLibrosPublicados;

public:

    Autor()
    {
        nombre = "";
        nacionalidad = "";
        cantidadLibrosPublicados = 0;
    }

    Autor(string nombre, string nacionalidad, int cantidadLibrosPublicados)
    {
        this->nombre = nombre;
        this->nacionalidad = nacionalidad;
        this->cantidadLibrosPublicados = cantidadLibrosPublicados;
    }

    string getNombre()
    {
        return nombre;
    }

    string getNacionalidad()
    {
        return nacionalidad;
    }

    int getCantidadLibrosPublicados()
    {
        return cantidadLibrosPublicados;
    }

    bool esNovato()
    {
        if (cantidadLibrosPublicados <= 2)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool esReconocido()
    {
        if (cantidadLibrosPublicados > 10)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool esProductivo()
    {
        if (cantidadLibrosPublicados > 15)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void mostrarAutor()
    {
        cout << "Nombre: " << nombre << endl;
        cout << "Nacionalidad: " << nacionalidad << endl;
        cout << "Cantidad de libros publicados: "<< cantidadLibrosPublicados << endl;
    }
};

class Libro
{
private:
    string titulo;
    double precio;
    Autor autor;

public:
    Libro()
    {
        titulo = "";
        precio = 0;
    }

    Libro(string titulo, double precio, Autor autor)
    {
        this->titulo = titulo;
        this->precio = precio;
        this->autor = autor;
    }

    string getTitulo()
    {
        return titulo;
    }

    double getPrecio()
    {
        return precio;
    }

    Autor getAutor()
    {
        return autor;
    }

    bool esBestSeller()
    {
        if (autor.getCantidadLibrosPublicados() > 5)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void mostrarLibro()
    {
        cout << "Titulo: " << titulo << endl;
        cout << "Precio: " << precio << endl;

        cout << "AUTOR:" << endl;
        autor.mostrarAutor();
    }
};

double calcularPromedioMasDeN(Libro libros[], int cantidad, int N)
{
    double suma = 0;
    int contador = 0;

    for (int i = 0; i < cantidad; i++)
    {
        if (libros[i].getAutor().getCantidadLibrosPublicados() > N)
        {
            suma = suma + libros[i].getPrecio();
            contador++;
        }
    }

    if (contador > 0)
    {
        return suma / contador;
    }
    else
    {
        return 0;
    }
}

double calcularPromedioBestSeller(Libro libros[], int cantidad)
{
    double suma = 0;
    int contador = 0;

    for (int i = 0; i < cantidad; i++)
    {
        if (libros[i].esBestSeller())
        {
            suma = suma + libros[i].getPrecio();
            contador++;
        }
    }

    if (contador > 0)
    {
        return suma / contador;
    }
    else
    {
        return 0;
    }
}

void mostrarLibroMasCaroReconocido(Libro libros[], int cantidad)
{
    double mayorPrecio = -1;
    int posicion = -1;

    for (int i = 0; i < cantidad; i++)
    {
        if (libros[i].getAutor().esReconocido())
        {
            if (libros[i].getPrecio() > mayorPrecio)
            {
                mayorPrecio = libros[i].getPrecio();
                posicion = i;
            }
        }
    }

    if (posicion != -1)
    {
        cout << "LIBRO MAS CARO DE AUTOR RECONOCIDO" << endl;

        libros[posicion].mostrarLibro();
    }
    else
    {
        cout << "No existen libros de autores reconocidos." << endl;
    }
}

int contarLibrosAutoresNovatos(Libro libros[], int cantidad)
{
    int contador = 0;

    for (int i = 0; i < cantidad; i++)
    {
        if (libros[i].getAutor().esNovato())
        {
            contador++;
        }
    }

    return contador;
}

double calcularTotalAutoresProductivos(Libro libros[], int cantidad)
{
    double total = 0;

    for (int i = 0; i < cantidad; i++)
    {
        if (libros[i].getAutor().esProductivo())
        {
            total = total + libros[i].getPrecio();
        }
    }

    return total;
}

int main()
{
    Autor autor1("Gabriel Garcia Marquez", "Colombiana", 20);

    Autor autor2("J.K. Rowling", "Britanica", 15);

    Autor autor3("Juan Perez", "Boliviano", 2);

    Autor autor4("Carlos Rodriguez", "Boliviana", 8);

    Libro libros[20] =
    {
        Libro("Cien Anos de Soledad", 120.50, autor1),
        Libro("El Amor en los Tiempos del Colera", 100.00, autor1),
        Libro("Harry Potter y la Piedra Filosofal", 150, autor2),
        Libro("Harry Potter y la Camara Secreta", 180, autor2),
        Libro("El Resplandor", 200, autor3),
        Libro("La Primera Aventura", 50, autor4),
    };

    int cantidad = 6;

    for (int i = 0; i < cantidad; i++)
    {
        cout << "LIBRO " << i + 1 << endl;

        libros[i].mostrarLibro();
    }

    int N;

    cout << "Ingrese la cantidad N de libros publicados: " << endl;
    cin >> N;

    double promedioN;

    promedioN = calcularPromedioMasDeN(libros,cantidad,N);
    cout << "Precio promedio de los libros cuyos autores tienen mas de " << N << " libros publicados: "<< promedioN << endl;

    double promedioBestSeller;

    promedioBestSeller = calcularPromedioBestSeller(libros,cantidad);

    cout << "Precio promedio de los libros Best Seller: "<< promedioBestSeller << endl;

    mostrarLibroMasCaroReconocido(libros,cantidad);

    int cantidadNovatos;

    cantidadNovatos = contarLibrosAutoresNovatos(libros,cantidad);

    cout << "Cantidad de libros que pertenecen a autores novatos: "<< cantidadNovatos << endl;

    double totalProductivos;

    totalProductivos = calcularTotalAutoresProductivos(libros,cantidad);

    cout << "Total recaudado por los libros de autores productivos: " << totalProductivos << endl;
}