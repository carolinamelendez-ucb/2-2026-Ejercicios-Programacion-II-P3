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

    void mostrarInformacion()
    {
        cout << "Autor: " << nombre << endl;
        cout << "Nacionalidad: " << nacionalidad << endl;
        cout << "Libros publicados: " << cantidadLibrosPublicados << endl;
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
        : autor(autor)
    {
        this->titulo = titulo;
        this->precio = precio;
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
        return autor.getCantidadLibrosPublicados() > 5;
    }

    void mostrarInformacion()
    {
        cout << "Titulo: " << titulo << endl;
        cout << "Precio: " << precio << endl;
        autor.mostrarInformacion();
    }
};


class Biblioteca
{
private:
    Libro* libros;
    int cantidad;

public:
    Biblioteca()
    {
        libros = nullptr;
        cantidad = 0;
    }

    void cargarLibros()
    {
        cout << "Cantidad de libros: ";
        cin >> cantidad;

        libros = new Libro[cantidad];

        for (int i = 0; i < cantidad; i++)
        {
            string titulo;
            double precio;
            string nombreAutor;
            string nacionalidad;
            int cantidadPublicados;

            cout << endl;
            cout << "Libro " << i + 1 << endl;

            cout << "Titulo: ";
            cin >> titulo;

            cout << "Precio: ";
            cin >> precio;

            cout << "Nombre del autor: ";
            cin >> nombreAutor;

            cout << "Nacionalidad: ";
            cin >> nacionalidad;

            cout << "Cantidad de libros publicados: ";
            cin >> cantidadPublicados;

            Autor autor(nombreAutor, nacionalidad, cantidadPublicados);

            libros[i] = Libro(titulo, precio, autor);
        }
    }

    void mostrarLibros()
    {
        for (int i = 0; i < cantidad; i++)
        {
            cout << endl;
            cout << "Libro " << i + 1 << endl;
            libros[i].mostrarInformacion();
        }
    }

    void promedioAutoresMasDeN()
    {
        int n;
        double suma = 0;
        int contador = 0;

        cout << "Ingrese N: ";
        cin >> n;

        for (int i = 0; i < cantidad; i++)
        {
            if (libros[i].getAutor().getCantidadLibrosPublicados() > n)
            {
                suma += libros[i].getPrecio();
                contador++;
            }
        }

        if (contador > 0)
        {
            cout << "Precio promedio: " << suma / contador << endl;
        }
        else
        {
            cout << "No existen libros que cumplan la condicion" << endl;
        }
    }

    void promedioBestSeller()
    {
        double suma = 0;
        int contador = 0;

        for (int i = 0; i < cantidad; i++)
        {
            if (libros[i].esBestSeller())
            {
                suma += libros[i].getPrecio();
                contador++;
            }
        }

        if (contador > 0)
        {
            cout << "Promedio de Best Seller: "
                << suma / contador << endl;
        }
        else
        {
            cout << "No existen libros Best Seller" << endl;
        }
    }

    void libroMasCaroAutorReconocido()
    {
        int minimoLibros;
        int posicion = -1;

        cout << "Cantidad minima para autor reconocido: ";
        cin >> minimoLibros;

        for (int i = 0; i < cantidad; i++)
        {
            if (libros[i].getAutor().getCantidadLibrosPublicados() >= minimoLibros)
            {
                if (posicion == -1 ||
                    libros[i].getPrecio() > libros[posicion].getPrecio())
                {
                    posicion = i;
                }
            }
        }

        if (posicion != -1)
        {
            cout << "Libro mas caro de autor reconocido:" << endl;
            libros[posicion].mostrarInformacion();
        }
        else
        {
            cout << "No existe un libro que cumpla la condicion" << endl;
        }
    }

    void contarLibrosAutoresNovatos()
    {
        int maximoLibros;
        int contador = 0;

        cout << "Cantidad maxima para considerar autor novato: ";
        cin >> maximoLibros;

        for (int i = 0; i < cantidad; i++)
        {
            if (libros[i].getAutor().getCantidadLibrosPublicados() <= maximoLibros)
            {
                contador++;
            }
        }

        cout << "Cantidad de libros de autores novatos: "
            << contador << endl;
    }

    void totalRecaudadoAutoresProductivos()
    {
        int minimoLibros;
        double total = 0;

        cout << "Cantidad minima para considerar autor productivo: ";
        cin >> minimoLibros;

        for (int i = 0; i < cantidad; i++)
        {
            if (libros[i].getAutor().getCantidadLibrosPublicados() >= minimoLibros)
            {
                total += libros[i].getPrecio();
            }
        }

        cout << "Total recaudado: " << total << endl;
    }

    ~Biblioteca()
    {
        delete[] libros;
    }
};


int main()
{
    Biblioteca biblioteca;

    biblioteca.cargarLibros();
    biblioteca.mostrarLibros();
    biblioteca.promedioAutoresMasDeN();
    biblioteca.promedioBestSeller();
    biblioteca.libroMasCaroAutorReconocido();
    biblioteca.contarLibrosAutoresNovatos();
    biblioteca.totalRecaudadoAutoresProductivos();

    return 0;
}