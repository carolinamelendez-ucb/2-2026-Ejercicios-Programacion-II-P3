#pragma once
#include <iostream>
#include <string>
#include "ListaGenerica.h"
#include "Perro.h"
#include "Servicios.h"
#include "ServicioNoEncontrado.h"
#include "ServicioDuplicadoException.h"
#include "PerroNoEncontrado.h"
using namespace std;


class SistemaPeluqueria {
private:
    string nombre;
    ListaGenerica<Perro>* listaPerros;
    ListaGenerica<Servicios>* listaServicios;

public:
    SistemaPeluqueria(string nombrePeluqueria, int maxPerros, int maxServicios) {
        this->nombre = nombrePeluqueria;
        this->listaPerros = new ListaGenerica<Perro>(maxPerros);
        this->listaServicios = new ListaGenerica<Servicios>(maxServicios);
    }

    ~SistemaPeluqueria() {
        delete listaPerros;
        delete listaServicios;
    }

    void registrarServicios(Servicios* nuevaServicios) {
        if (listaServicios->buscar(nuevaServicios->getCodigo(), Servicios::compararCodigo) != nullptr) {
            throw ServicioDuplicadoException(nuevaServicios->getCodigo());
        }
        listaServicios->agregar(nuevaServicios);
    }

    void registrarPerro(Perro* nuevoPerro) {
        Servicios* Servicios = listaServicios->buscar(nuevoPerro->getcodigo(), Servicios::estaPerroRegistrado);
        if (listaPerros->buscar(nuevoPerro->getcodigo(), Perro::compararCodigo) != nullptr) {
            throw PerroDuplicadoException();
        }

        listaPerros->agregar(nuevoPerro);
    }

    void mostrarPerrosDeServicios(string codigoServicios) {
        Servicios* Servicios = listaServicios->buscar(codigoServicios, Servicios::compararCodigo);
        if (Servicios == nullptr) throw ServicioNoEncontradoException();
        cout << "Perros registrados en Servicios " << codigoServicios << endl;
        Servicios->mostrarPerros();
    }

    void mostrarInformacionPerro(string codigo) {
        Perro* Perro = listaPerros->buscar(codigo, Perro::compararCodigo);
        if (Perro == nullptr) throw PerroNoEncontradoException();
        Perro->mostrar();
        Servicios* ServicioRegistrado = listaServicios->buscar(codigo, Servicios::compararCodigoPerro);
        if (ServicioRegistrado != nullptr) {
            cout << "Asignado: " << ServicioRegistrado->getCodigo() << endl;
        }
    }

};
