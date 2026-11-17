#pragma once
#include <iostream>
#include <string>
#include "ListaGenerica.h"
#include "Perro.h"
#include "SistemaPeluqueria.h"

using namespace std;

class Servicios {
protected:
	string codigo;
	string nombre;
	int CostoMaterial;
    int capacidad;
    ListaGenerica<Perro>* listaPerros;
public:
	Servicios(string codigo, string nombre, int CostoMaterial) : codigo(codigo), nombre(nombre), capacidad(capacidad){
		this->codigo = codigo;
		this->nombre = nombre;
		this->CostoMaterial = CostoMaterial;
        this->listaPerros = new ListaGenerica<Perro>(capacidad);
       
	}

    virtual ~Servicios() {
        delete listaPerros;
    }

  

    string getCodigo() 
    { return codigo; 
    }
    int getCantidadPerros() { 
        return listaPerros->getCantidad(); 
    }
    int getEspaciosDisponibles() { 
        return capacidad - listaPerros->getCantidad(); 
    }

   
    void agregarPerro(Perro* Perro) {
        listaPerros->agregar(Perro);
    }

    static bool estaPerroRegistrado(string codigoPerro, Servicios* Servicios) {
        return listaPerros->buscar(codigoPerro, Perro::compararCodigo) != nullptr;
    }

    virtual void mostrar() {
        cout << "Codigo: " << codigo <<"Nombre: " << nombre << capacidad << " Registrados: " << listaPerros->getCantidad() << endl;
    }

    void mostrarPerros() {
        listaPerros->mostrar();
    }

    static bool compararCodigo(string codigo, Servicios* Servicios) {
        return codigo == Servicios->codigo;
    }

    static bool compararCodigoPerro(string codigoPerro, Servicios* Servicios) {
        return Servicios->estaPerroRegistrado(codigoPerro);
    }

    static bool compararCantidadPerros(Servicios* a1, Servicios* a2) {
        return a1->getCantidadPerros() < a2->getCantidadPerros();
    }
};