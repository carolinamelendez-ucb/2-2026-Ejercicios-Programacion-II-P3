#pragma once
#include <iostream>
#include <string>
#include "ListaGenerica.h"
#include "PerroDuplicadoException.h";
#include "Perro.h"
#include "Servicio.h"
#include "ServicioDuplicadoException.h"
#include "PerroNoEncontradoException.h"
#include "ServicioNoEncontradoException.h"
#include "Atencion.h"

using namespace std;
class Sistema {
private:

	string nombre; 
	ListaGenerica<Perro>* perros;
	ListaGenerica<Servicio>*servicios;
	ListaGenerica<Atencion>* atenciones;
public:
	Sistema(string nombre, int cantmaxPerros, int cantmaxServi, int cantmaxAtenciones) {
		this->nombre = nombre;
		this->perros = new ListaGenerica<Perro>(cantmaxPerros);
		this->servicios = new ListaGenerica<Servicio>(cantmaxServi);
		this->atenciones = new ListaGenerica<Atencion>(cantmaxAtenciones);

	}
	~Sistema() {

	}

	void agregarperro(Perro *nuevo) {
		string codigo = nuevo->getCodigo();
		try {
			Perro* perronuevo = perros->buscar(codigo,Perro::gettercodigo);
			if (perronuevo!=nullptr) {
				throw PerroDuplicadoException();
			}
			perros->registrar(nuevo);
		}
		catch(Exception& e){
			cout << "ERROR: " << e.getmensaje();
			cout << endl;


		}
	}

	void mostrar() {
		perros->mostrar();
	}



	void registrarservicio(Servicio * nuevoservi) {
		string  codigoser = nuevoservi->getcodigoSer();
		try {
			Servicio* servicionuevo = servicios->buscar(codigoser,Servicio::getterServicio );
			if (servicionuevo!= nullptr) {
				throw ServicioDuplicadoException();
			}
			servicios->registrar(nuevoservi);
		}
		catch (Exception& e) {
			cout << "ERROR: " << e.getmensaje();
			cout << endl;


		}

	}
	void mostrarservico() {
		servicios->mostrar();
	}

	void registraratencio(Atencion* nuevaatencion,string codigoPerro, string codigoservicio) {
		string codigoatencion = nuevaatencion->getcodigoatencion();
		try {
			Perro* perroexiste = perros->buscar(codigoPerro, Perro::gettercodigo);
			if (perroexiste==nullptr) {
				throw PerroNoEncontradoException();
			}
			Servicio* servioexcistente = servicios->buscar(codigoservicio,Servicio::getterServicio);
			if (servioexcistente==nullptr) {
				throw ServicioNoEncontradoException();
			}
			atenciones->registrar(nuevaatencion);
		}
		catch (Exception& e) {
			cout << "ERROR: " << e.getmensaje();
			cout << endl;


		}
	}

	void mostraratencionesDEperro(string codigo,Atencion* nuevaatencion) {
		string codigoatencion = nuevaatencion->getcodigoatencion();
		try {
			Perro* perroexiste = perros->buscar(codigo, Perro::gettercodigo);
			if (perroexiste == nullptr) {
				throw PerroNoEncontradoException();
			}

			perroexiste->mostrar();
		}
		catch (Exception& e) {
			cout << "ERROR: " << e.getmensaje();
			cout << endl;


		}
	}
	 
};