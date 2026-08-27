// practicaEjercicio4.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>

using namespace std;
class Autor {
private:
    string nombre;
    string nacionalidad;
    int cantlibros;
public:
    Autor(string nombre, string nacionalidad, int cantlibros)
    {
        this->nombre = nombre;
        this->nacionalidad = nacionalidad;
        
        this->cantlibros = cantlibros;
    }
    string getnombre() {
        return nombre;
    }
    string getNacionalidad() { 
        return nacionalidad; 
    }
    
    int gatcantlibros()
    {
        return cantlibros;
   }
    bool EsNovato() {
        return cantlibros < 3;

    }
    bool EsReconocido() {
        return cantlibros >= 10;
    }
    bool Productivo() {
        return cantlibros > 5;
    }
 
    void mostrar()
    {
        cout << "El nombre del autor es:" << nombre << endl;
        cout << "La nacionalidad del autor es:" << nacionalidad << endl;
        cout << "la cant de libros del autor es:" << cantlibros << endl;
    }



};
class libro
{
private:
    string titulo;
    double precio;
    Autor* autor;
public:
    libro(string titulo, double precio, Autor* autor)
    {
        this->autor = autor;
        this->titulo = titulo;
        this->precio = precio; 

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

    bool esBestSeller() {
        return autor->gatcantlibros() > 5;
    }

};
int main()
{
    Autor a1 ("gabriel garcia", "Colombiano", 2);
    a1.mostrar();
    if (a1.EsNovato())
    {
        cout << "El autor es un pavo aun";
    }

}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
