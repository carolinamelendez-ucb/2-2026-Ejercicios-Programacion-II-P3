// practicando2.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include<string>
using namespace std;
class Cliente {
private:
    int ci;
    string nombre;
    int aniosAntiguedad;
public:
    Cliente(int ci, const string& nombre)
        : ci(ci), nombre(nombre)
    {
        this->aniosAntiguedad = 0;
    }
    void setAniosAntiguedad(int aniosNuevos) {
        if (aniosNuevos < 0) {
            cout << "el cliente no se puede tener antiguedad negativa" << endl;
        }
        else {
            aniosAntiguedad = aniosNuevos;
        }
    }
    void mostrar() {
        cout << "El ci del Cliente es: " << ci << endl;
        cout << "El nombre de cliente es: " << nombre << endl;
        cout << "Los anios de Antiguedad es: " << aniosAntiguedad << endl;
    }
};
class Vehiculo {
private:
    int placa;
    string modelo;
    int tarifaDia;
public:
   
    Vehiculo(int placa, const string& modelo, int tarifaDia)
        : placa(placa), modelo(modelo), tarifaDia(tarifaDia)
    {
    }
    void mostrar() {
        cout << "La placa del Auto es: " << placa << endl;
        cout << "El modelo de Auto es: " << modelo << endl;
        cout << "La tarifa es: " << endl;
        indicarTarifa();
    }
    void indicarTarifa() {
        if (tarifaDia < 0) {
            cout << "no pude tener una tarifamenor a 0" << endl;
        }
        else {
           tarifaDia = tarifaDia;
        }
    }
    int getTarifa() {
        return tarifaDia;
    }
};
class Reserva {
private:
    string fechaInicio;
    int cantidadDias;
    Cliente cliente;
    Vehiculo vehiculo;
    int costoBase;
public:
    Reserva(string& fechaInicio, int cantidadDias, const Cliente& cliente, const Vehiculo& vehiculo)
        : fechaInicio(fechaInicio), cantidadDias(cantidadDias), cliente(cliente), vehiculo(vehiculo)
    {
        this->costoBase = 0;
    }
    void setcostobase() {
        if (cantidadDias < 0) {
            cout << "No puede haber la cantidad de dias en negativo" << endl;
        }
        else {
            costoBase = cantidadDias * vehiculo.getTarifa();
        }
    }
    void mostrar() {
        cout << "La fecha indicada es: " << fechaInicio << endl;
        cout << "la cantidad de dias reservado es : " << cantidadDias << endl;
        cout << "el costo es: " << costoBase << endl;
        cout << "Datos del cliente: " << endl;
        cliente.mostrar();
        cout << "Datos del Vehiculo: " << endl;
        vehiculo.mostrar();
    }
};
int main()
{
    Cliente Rodolfo = Cliente(1, "Rodolfo");
    Vehiculo Caros = Vehiculo(123, "Toyota", 5);
    Reserva reserva1 = Reserva("12/07/2027", 6, Rodolfo, Caros);
    reserva1.mostrar();
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
