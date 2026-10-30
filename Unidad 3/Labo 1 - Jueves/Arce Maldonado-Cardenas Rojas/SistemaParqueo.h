#pragma once
/*#include<iostream>
#include<string>
#include"Espacio.h"
#include"ListaGenerica.h"
#include"Vehiculo.h"

using namespace std;





class SistemaParqueo {
private:
    string nombreEmpresa;
    string direccion;
    int capacidadMaxima;
    ListaGenerica<Espacio>* listaEspacios;
    ListaGenerica<Vehiculo>* listaVehiculos;

public:
    SistemaParqueo(string nombreEmpresa, string direccion, int capacidadMaxima) {
        this->nombreEmpresa = nombreEmpresa;
        this->direccion = direccion;
        this->capacidadMaxima = capacidadMaxima;
        this->listaEspacios = new ListaGenerica<Espacio>(capacidadMaxima);
        this->listaVehiculos = new ListaGenerica<Vehiculo>(capacidadMaxima);
    }

    ~SistemaParqueo() {
        delete listaEspacios;
        delete listaVehiculos;
    }

    void registrarEspacio(string codigo, int nivel, string sector) {
        if (listaEspacios->estaLlena()) {
            throw CapacidadMaximaEspaciosException(capacidadMaxima);
        }
        if (listaEspacios->buscar(codigo, Espacio::getCodigo) != nullptr) {
            throw CodigoEspacioDuplicadoException(codigo);
        }
        listaEspacios->agregar(new Espacio(codigo, nivel, sector));
    }

    void registrarVehiculo(string placa, string marca, string modelo, string tipo) {
        if (listaVehiculos->estaLlena()) {
            throw CapacidadMaximaVehiculosException(capacidadMaxima);
        }
        if (listaVehiculos->buscar(placa, Vehiculo::getPlaca) != nullptr) {
            throw PlacaDuplicadaException(placa);
        }
        listaVehiculos->agregar(new Vehiculo(placa, marca, modelo, tipo));
    }

    void asignarEspacioAutomatico(string placa) {
        Vehiculo* vehiculo = listaVehiculos->buscar(placa, Vehiculo::getPlaca);
        if (vehiculo == nullptr) {
            throw VehiculoNoEncontradoException(placa);
        }
        if (vehiculo->estaEstacionado()) {
            throw VehiculoYaAsignadoException(placa);
        }

        for (int i = 0; i < listaEspacios->getCantidad(); i++) {
            Espacio* actual = listaEspacios->obtener(i);
            if (actual->estaDisponible()) {
                vehiculo->asignarEspacio(actual);
                return;
            }
        }
        throw NoHayEspaciosDisponiblesException();
    }

    void mostrarVehiculosEstacionados() {
        cout << "vehiculos estacionados (" << nombreEmpresa << direccion << ")" << endl;
        bool hay = false;
        for (int i = 0; i < listaVehiculos->getCantidad(); i++) {
            Vehiculo* v = listaVehiculos->obtener(i);
            if (v->estaEstacionado()) {
                v->mostrar();
                hay = true;
            }
        }
        if (!hay) cout << "Ninguno" << endl;
    }
};