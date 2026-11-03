#pragma once
#include <iostream>
#include <string>
#include "ListaGenerica.h"
#include "Cliente.h"
#include "Envio.h"
#include "exception.h"
using namespace std;


class SistemaEnvios {
private:
    string nombreEmpresa;
    int capacidadMaxima;
    ListaGenerica<Cliente>* listaClientes;
    ListaGenerica<Envio>* listaEnvios;
public:
    SistemaEnvios(string nombreSistema, int capacidadMaxima) {
        this->nombreEmpresa = nombreEmpresa;
        this->capacidadMaxima = capacidadMaxima;
        this->listaClientes = new ListaGenerica<Cliente>(capacidadMaxima);
        this->listaEnvios = new ListaGenerica<Envio>(capacidadMaxima);
    }

    ~SistemaEnvios() {
        delete listaClientes;
        delete listaEnvios;
    }


    
    void registrar(Cliente* nuevo) {
        try {
            int clienteCI = nuevo->getCi();
            Cliente* duplicado = this->listaClientes->buscar(clienteCI, Cliente::getterCi);
            if (duplicado != nullptr) {
                throw ClientDuplicadoException();
            }
            this->listaClientes->agregar(nuevo);
        }
        catch (Exception err) {
            cout << "Error: " << err.getMensaje() << endl;
            delete nuevo; 
        }
    }
    void buscarYMostrar(int id) {
        try {
             Cliente* e = this->listaClientes->buscar(id, Cliente::getterCi);
            if (e == nullptr) {
                throw ClienteNoEncontradoException();
            }
            e->mostrar();
        }
        catch (Exception err) {
            cout << "Error: " << err.getMensaje() << endl;
        }
    }


    void registrarEnvio(Envio* nuevo) {
        try {
            int numeroEnvio = nuevo->getid();
            Envio* duplicado = this->listaEnvios->buscar(numeroEnvio, Envio::getterId);
            if (duplicado != nullptr) {
                throw PaqueteDuplicadoException();
            }
            this->listaEnvios->agregar(nuevo);
        }
        catch (Exception err) {
            cout << "Error: " << err.getMensaje() << endl;
            delete nuevo;
        }
    }
    

   /* void mostrarOrdenados() {
        cout << "\nReporte Ordenado del Sistema [" << nombreEmpresa<< "]:" << endl;
        this->listaClientes->ordenar(Cliente::compararNombre);
        this->listaClientes->mostrar();
    }
    */




};