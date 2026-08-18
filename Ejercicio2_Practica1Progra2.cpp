// Ejercicio2_Practica1Progra2.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string> 
using namespace std;

class Cliente
{
private:
    string nombre;
    int CI;
    int aniosAntiguedad;
public:
    Cliente()
    {
        nombre = "";
        CI = 0;
        aniosAntiguedad = 0;
    }

    Cliente(const string& nombre, int CI, int aniosAntiguedad)
        : nombre(nombre), CI(CI), aniosAntiguedad(aniosAntiguedad)
    {
        this->nombre = nombre;
        this->CI = CI;
        this->aniosAntiguedad = aniosAntiguedad;
    }
};

class Vehiculo
{
    string placa;
    string modelo;
    int tarifaDia;
    Vehiculo()
    {
        placa = "";
        modelo = "";
        tarifaDia = 0;
    }
public:

    Vehiculo(const string& placa, const string& modelo, int tarifaDia)
        : placa(placa), modelo(modelo), tarifaDia(tarifaDia)
    {
        this->placa = placa;
        this->modelo = modelo;
        this->tarifaDia = tarifaDia;
    }
};

class Reserva
{
private:
    string fechaInicio;
    int cantidadDias;
    Cliente* cliente;
    Vehiculo* vehiculo;
    int costoBase;
public:

    Reserva(const string& fechaInicio, int cantidadDias, Cliente* cliente, Vehiculo* vehiculo, int costoBase)
        : fechaInicio(fechaInicio), cantidadDias(cantidadDias), cliente(cliente), vehiculo(vehiculo), costoBase(costoBase)
    {
    }
};

int main()
{
    
}

