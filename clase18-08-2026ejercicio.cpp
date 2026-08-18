// clase18-08-2026ejercicio.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
using namespace std;
class Cliente {
private:
    string attr;
    int ci;
    string nombre;
    string aniosAntiguedad;
public:
    Cliente(const string& attr, int ci, const string& nombre, const string& aniosAntiguedad)
        : attr(attr), ci(ci), nombre(nombre), aniosAntiguedad(aniosAntiguedad)
    {
    }
};
class Vehiculo {
private:
    string attr;
    string placa;
    string modelo;
    string tarifaDia;
public:

    Vehiculo(const string& attr, const string& placa, const string& modelo, const string& tarifaDia)
        : attr(attr), placa(placa), modelo(modelo), tarifaDia(tarifaDia)
    {
    }
};
class Reserva {
private:
    string attr;
    string fechaInicio;
    int cantidadDias;
    Cliente cliente;
    Vehiculo vehiculo;
    int costoBase;
public:

    Reserva(const string& attr, const string& fechaInicio, int cantidadDias, const Cliente& cliente, const Vehiculo& vehiculo, int costoBase)
        : attr(attr), fechaInicio(fechaInicio), cantidadDias(cantidadDias), cliente(cliente), vehiculo(vehiculo), costoBase(costoBase)
    {
    }
};


int main()
{
    std::cout << "Hello World!\n";
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
