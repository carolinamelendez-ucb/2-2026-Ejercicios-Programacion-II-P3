#pragma once
#include "ListaGenerica.h"
#include "Envio.h"
#include "Cliente.h"
#include "Paquete.h"
#include "PaqueteExpress.h"
#include "PaqueteFragil.h"
#include "PaqueteNormal.h"
class SistemaEnvios
{
private:
    string NombreEmpresa;
    ListaGenerica<int> listaClientes;
    ListaGenerica<int> listaEnvios;

public:
    SistemaEnvios(string NombreEmpresa) {
        this->NombreEmpresa = NombreEmpresa;
        this->listaClientes = listaClientes;
        this->listaEnvios = listaEnvios;
    }
    int buscarCliente(const ListaGenerica<Cliente> clientes,  int ci) {
        for (int i = 0; i < clientes.tamanio(); i++) {
            if (clientes[i].getCodigo() == ci) {
                return i;
            }
        }
        return -1;
    }

    int buscarPaquete(const ListaGenerica<Paquete> paquetes, const int& codigo) {
        for (int i = 0; i < paquetes.tamanio(); i++) {
            if (paquetes[i].getCodigoPaquete() == codigo) {
                return i;
            }
        }
        return -1;
    }

    void registrarCliente(ListaGenerica<Cliente>& cliente) {
        int ci;
        string  nombre;
        int telefono;
        string direccion;
        cout << "CI: ";
        cin >> ci;

        if (buscarCliente(cliente, ci) != -1) {
            cout << "Ya existe un Cliente con ese CI.\n";
            return;
        }

        cout << "Nombre: ";
        (cin >> ws, nombre);
        cout << "Telefono: ";
        (cin, telefono);
        cliente.agregar(ci , nombre, telefono, direccion);
        cout << "Socio registrado.\n";
    }

    void mostrarEnviosOrdenados(const ListaGenerica<Envio>& envios) {
        ListaGenerica<Envio> ordenados = envios;
        for (int i = 0; i < ordenados.tamanio() - 1; i++) {
            for (int j = i + 1; j < ordenados.tamanio(); j++) {
                if (ordenados[j].getPesoMax() < ordenados[i].getPesoMax()) {
                    envios  = ordenados[i];
                    ordenados[i] = ordenados[j];
                    ordenados[j] = temporal;
                }
            }
        }

        if (ordenados.tamanio() == 0) {
            cout << "No hay Clientes registrados.\n";
            return;
        }

        for (int i = 0; i < ordenados.tamanio(); i++) {
            cout << "CI: " << ordenados[i].ci
                << " | Nombre: " << ordenados[i].nombre
                << " | Telefono: " << ordenados[i].telefono << '\n';
        }
    }


};