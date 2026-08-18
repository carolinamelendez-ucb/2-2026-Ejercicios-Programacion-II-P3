// ejercicio_2.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
using namespace std;

class Cliente {
private:
    int ci;
    string nombre;
    int aniosAntiguedad;

public:

    Cliente() {
        ci = 0;
        nombre = "";
        aniosAntiguedad = 0;
    }
    Cliente(int ci, const string& nombre, int aniosAntiguedad)
        : ci(ci), nombre(nombre)
    {
        if (aniosAntiguedad == 0) {
            cout << "error en el registro, el valor debe ser mayor o igual a cero" << endl;
        }
        else this->aniosAntiguedad = aniosAntiguedad;
    }
    void setAniosAntiguedad(int nuevoAniosAntiguedad) {
        this->aniosAntiguedad = nuevoAniosAntiguedad;
    }
    void mostrar() {
        cout << "ci: " << ci << endl;
        cout << "nombre: " << nombre << endl;
        cout << "aniosAntiguedad: " << aniosAntiguedad << endl;
    }
};
class Vehiculo {
    int placa;
    string modelo;
    int tarifaDia;
public:
    Vehiculo() {
        placa = 0;
        modelo = "";
        tarifaDia = 0;
    }
    Vehiculo(int placa, const string& modelo, int tarifaDia)
        : placa(placa), modelo(modelo), tarifaDia(tarifaDia)
    {
    }
};
class Reserva {
    string fechaInicio;
    int cantidadDias;

    Cliente* cliente;
    Vehiculo* vehiculo;
public:

    Reserva(const string& fechaInicio, int cantidadDias, Cliente* cliente, Vehiculo* vehiculo)
    {
        this->fechaInicio = fechaInicio;
        this->cantidadDias = cantidadDias;
        this->cliente = cliente;
        this->vehiculo = vehiculo;
    }
};


int main()
{
    Cliente clienteGiuliano = Cliente(123, "Giuliano", 0);
    clienteGiuliano.mostrar();

    Vehiculo vehiculotoyota = Vehiculo(98, "toyota", 45);

}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
