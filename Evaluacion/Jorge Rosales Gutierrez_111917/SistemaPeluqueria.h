#pragma once
#include "ListaGenerica.h"
#include "Perro.h"
#include "Servicio.h"
#include "Atencion.h"

#include "PerroDuplicadoException.h"
#include "ServicioDuplicadoException.h"
#include "PerroNoEncontradoException.h"
#include "ServicioNoEncontradoException.h" 

class SistemaPeluqueria {
private:
	string nombrePeluqueria;
	ListaGenerica<Perro>* listaPerros;
	ListaGenerica<Servicio>* listaServicios;
	ListaGenerica<Atencion>* listaAtencion;

public:
	SistemaPeluqueria(string nombrePeluqueria, int maxPerros, int maxServicios, int maxAencion) {
		this->nombrePeluqueria = nombrePeluqueria;
		this->listaPerros = new ListaGenerica<Perro>(maxPerros);
		this->listaServicios = new ListaGenerica<Servicio>(maxServicios);
		this->listaAtencion = new ListaGenerica<Atencion>(maxAencion);
	}

	~SistemaPeluqueria() {
		delete listaPerros;
		delete listaServicios;
		delete listaAtencion;
	}
	//1 
	void registrarPerro(Perro* nuevoPerro) {
		try {
			string codigo = nuevoPerro->getCodigo();
			Perro* duplicado = this->listaPerros->buscar(codigo, Perro::getterCodigo);
			if (duplicado != nullptr) {
				delete nuevoPerro;
				throw PerroDuplicadoException(codigo);
			}
			this->listaPerros->agregar(nuevoPerro);
			cout << " Perro registrado correctamente: " << codigo << endl;
		}
		catch (Exception err) {
			cout << "Error: " << err.getMensaje() << endl;
		}
	}
	//2
	void registrarServicio(Servicio* nuevoServicio) {
		try {
			string codigo = nuevoServicio->getCodigo();
			Servicio* duplicado = this->listaServicios->buscar(codigo, Servicio::getterCodigo);
			if (duplicado != nullptr) {
				delete nuevoServicio;
				throw ServicioDuplicadoException(codigo);
			}
			this->listaServicios->agregar(nuevoServicio);
			cout << " Servicio registrado correctamente: " << codigo << endl;
		}
		catch (Exception err) {
			cout << "Error: " << err.getMensaje() << endl;
		}
	}
	//3
	void registrarAtencion(string cPerro, string cServicio) {
		try {
			Perro* perro = this->listaPerros->buscar(cPerro, Perro::getterCodigo);
			if (perro == nullptr) {
				throw PerroNoEncontradoException(cPerro);
			}
			Servicio* servicio = this->listaServicios->buscar(cServicio, Servicio::getterCodigo);
			if (servicio == nullptr) {
				throw ServicioNoEncontradoException(cServicio);
			}

			int costoCalculado = servicio->calcularCosto(perro);

			
			Atencion* nuevoAtencion = new Atencion(perro, servicio, costoCalculado);
			this->listaAtencion->agregar(nuevoAtencion);

			cout << " Atencion realizada. El costo final es: " << costoCalculado << "Bs." << endl;
		}
		catch (Exception err) {
			cout << "Error: " << err.getMensaje() << endl;
		}
	}
	//4
	void mostrarAtencionPerro(string cPerro) {
		try {
			Perro* perro = this->listaPerros->buscar(cPerro, Perro::getterCodigo);
			if (perro == nullptr) {
				throw PerroNoEncontradoException(cPerro);
			}

			cout << "\n===DATOS Y SERVICIOS DEL PERRO ===" << endl;
			perro->mostrar();
			int costoFinal = 0;
			for (int i = 0; i < this->listaAtencion->getCantidad(); i++) {
				Atencion* atencion = this->listaAtencion->getElementoEn(i);
				if (atencion->getPerro()->getCodigo() == cPerro) {
					atencion->mostrar();
					costoFinal= costoFinal+atencion->getCostoFinal();

				}

			}
			cout << "\nTotal Gastado: " << costoFinal <<"Bs" << endl;


		}
		catch (Exception err) {
			cout << "Error: " << err.getMensaje() << endl;
		}
	}

	void mostrarTodosLosPerros() {
		cout << "\n=== PERROS REGISTRADOS ===" << endl;
		for (int i = 0; i < this->listaPerros->getCantidad(); i++) {
			Perro* perro = this->listaPerros->getElementoEn(i);
			perro->mostrar();
			cout << "-----------------------------------" << endl;
		}
	}
};