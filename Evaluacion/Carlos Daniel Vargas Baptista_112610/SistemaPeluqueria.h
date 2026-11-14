#pragma once
#include<iostream>
#include<string>
#include"ListaGenerica.h"
#include"Perro.h"
#include"Servicio.h"
#include"Atencion.h"
#include"Exception.h"
using namespace std;

class SistemaPeluqueria{
private:
	string nombre;
	ListaGenerica <Perro>* listaPerros;
	ListaGenerica<Servicio>* listaServicios;
	ListaGenerica<Atencion>* listaAtenciones;
public:
	SistemaPeluqueria(string nombre, int cap) {
		this->nombre = nombre;
		this->listaPerros = new ListaGenerica<Perro>(cap);
		this->listaServicios = new ListaGenerica<Servicio>(cap);
		this->listaAtenciones = new ListaGenerica<Atencion>(cap);
	}
    void RegistrarPerro(Perro* nuevo) {
        try {
            Perro* duplicada = this->listaPerros->buscar(nuevo->getCodigo(), Perro::getterCodigo);
            if (duplicada != nullptr) {
                throw PerroDuplicadoException(nuevo->getCodigo());
            }
            this->listaPerros->agregar(nuevo);
            cout << "Perro " << nuevo->getCodigo() << " registrado" << endl;
        }
        catch (Exception& err) {
            cout << "Error: " << err.getMensaje() << endl;
            delete nuevo;
        }
    }
    void RegistrarServicio(Servicio* nuevo) {
        try {
            Servicio* duplicada = this->listaServicios->buscar(nuevo->getCodigoServicio(), Servicio::getterCodigoServicio);
            if (duplicada != nullptr) {
                throw ServicioDuplicadoException(nuevo->getCodigoServicio());
            }
            this->listaServicios->agregar(nuevo);
            cout << "Servicio " << nuevo->getCodigoServicio() << " registrado" << endl;
        }
        catch (Exception& err) {
            cout << "Error: " << err.getMensaje() << endl;
            delete nuevo;
        }
    }
    
};

