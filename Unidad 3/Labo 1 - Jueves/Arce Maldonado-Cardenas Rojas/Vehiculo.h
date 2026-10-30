#pragma once
/*#include<iostream>
#include<string>
#include"Espacio.h"
#include"ListaGenerica.h"
using namespace std;


class Vehiculo 
{
private:
    string placa;
    string marca;
    string modelo;
    string tipoVehiculo;
    Espacio* espacioAsignado;

public:
    Vehiculo(string placa, string marca, string modelo, string tipoVehiculo) {
        this->placa = placa;
        this->marca = marca;
        this->modelo = modelo;
        this->tipoVehiculo = tipoVehiculo;
        this->espacioAsignado = nullptr;
    }

    bool estaEstacionado() 
    { return this->espacioAsignado != nullptr; }

    void asignarEspacio(Espacio* espacio) {
        this->espacioAsignado = espacio;
        espacio->ocupar();
    }

    void mostrar() {
        cout << "Placa: " << placa << "Marca: " << marca
            << "Modelo: " << modelo << "Tipo: " << tipoVehiculo << endl;
        if (this->espacioAsignado != nullptr) {
            this->espacioAsignado->mostrar();
        }
        else {
            cout << "Sin espacio asignado" << endl;
        }
    }

    static string getPlaca(Vehiculo* v) 
    { return v->placa; }
    static bool marcaMayorQue(Vehiculo* a, Vehiculo* b) { return a->marca > b->marca; }
};

