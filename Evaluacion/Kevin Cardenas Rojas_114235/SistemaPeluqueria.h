#pragma once

#include<iostream>
#include<string>
#include "Perro.h"
#include"Atencion.h"
#include"Exception.h"
#include"ListaGenerica.h"
#include"ServicioBano.h"
#include"ServicioCorte.h"


class SistemaPeluqueria {
private:
	string nombre;
	ListaGenerica<Perro>* listaPerros;
	ListaGenerica<Servicio>* listaServicios;
	ListaGenerica<Atencion>* listaAtenciones;
public:
	SistemaPeluqueria(string nombre, int max) {
		this->nombre = nombre;
		this->listaPerros = new ListaGenerica<Perro>(max);
		this->listaServicios = new ListaGenerica<Servicio>(max);
		this->listaAtenciones = new ListaGenerica<Atencion>(max);


	}



	void RegistrarPerro(Perro* nuevoPerro) {
		string codigo = nuevoPerro->getCodigo();
		try {
			Perro* duplicado = this->listaPerros->buscar(codigo,Perro::getterCodigo);

			if (duplicado != nullptr) {
				delete nuevoPerro;
				throw PerroDuplicadoException();
			}
			this->listaPerros->registrar(nuevoPerro);
			cout << "Registrado" << endl;
		}
		catch(Exception err){

			cout << "Error: " << err.getMensaje()<<endl;

		}
	}

	void RegistrarServicio(Servicio* nuevoServicio) {
		string codigo = nuevoServicio->getCodigo();
		try {
			Servicio* duplicado = this->listaServicios->buscar(codigo, Servicio::getterCodigo);
			if (duplicado != nullptr) {
				delete nuevoServicio;
				throw ServicioDuplicadoException();
			}
			this->listaServicios->registrar(nuevoServicio);
			cout << "Registrado" << endl;
		}
		catch (Exception err) {

			cout << "Error: " << err.getMensaje() << endl;

		}


	}

	void RegistrarAtencion() {



	}




	void mostrarAtenciones() {
		for (int i = 0;i < this->listaAtenciones->getCantidad();i++)
		{
		}




	}






};
