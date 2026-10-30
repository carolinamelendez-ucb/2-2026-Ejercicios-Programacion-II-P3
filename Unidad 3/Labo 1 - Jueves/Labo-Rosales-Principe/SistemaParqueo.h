#pragma once

#include "Espacio.h"
#include "Vehiculo.h"
#include "ListaGenerica.h"
#include "CodigoEspacioDuplicadoException.h"
#include "PlacaDuplicadaException.h"
#include "VehiculoNoEncontradoException.h"
#include "VehiculoYaAsignadoException.h"
#include "NoHayEspaciosDisponiblesException.h"

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

	void registrarEspacio(Espacio* nuevoEspacio) {
		try {
			string codigoNuevo = nuevoEspacio->getCodigoEspacio();
			Espacio* espacioDuplicado = this->listaEspacios->buscar(codigoNuevo, Espacio::getterCodigo);

			if (espacioDuplicado != nullptr) {
				delete nuevoEspacio;
				throw CodigoEspacioDuplicadoException(codigoNuevo);
			}
			else {
				this->listaEspacios->agregar(nuevoEspacio);
			}
		}
		catch (Exception err) {
			cout << "Error: " << err.getMensaje() << endl;
		}
	}

	void registrarVehiculo(Vehiculo* nuevoVehiculo) {
		try {
			string placaNueva = nuevoVehiculo->getPlaca();
			Vehiculo* vehiculoDuplicado = this->listaVehiculos->buscar(placaNueva, Vehiculo::getterPlaca);

			if (vehiculoDuplicado != nullptr) {
				delete nuevoVehiculo;
				throw PlacaDuplicadaException(placaNueva);
			}
			else {
				this->listaVehiculos->agregar(nuevoVehiculo);
			}
		}
		catch (Exception err) {
			cout << "Error: " << err.getMensaje() << endl;
		}
	}

	void asignarEspacioAutomatico(string placa) {
		try {
			Vehiculo* vehiculoEncontrado = this->listaVehiculos->buscar(placa, Vehiculo::getterPlaca);

			if (vehiculoEncontrado == nullptr) {
				throw VehiculoNoEncontradoException(placa);
			}

			if (vehiculoEncontrado->getEspacioAsignado() != nullptr) {
				throw VehiculoYaAsignadoException(placa);
			}

			Espacio* espacioDisponible = nullptr;
			for (int i = 0; i < this->listaEspacios->getCantidad(); i++) {
				Espacio* esp = this->listaEspacios->getElementoEn(i);
				if (esp->getEstado() == "disponible") {
					espacioDisponible = esp;
					break;
				}
			}

			if (espacioDisponible == nullptr) {
				throw NoHayEspaciosDisponiblesException();
			}

			espacioDisponible->setEstado("ocupado");
			vehiculoEncontrado->setEspacioAsignado(espacioDisponible);
		}
		catch (Exception err) {
			cout << "Error: " << err.getMensaje() << endl;
		}
	}

	void buscarVehiculoPorPlaca(string placa) {
		Vehiculo* v = this->listaVehiculos->buscar(placa, Vehiculo::getterPlaca);
		if (v != nullptr) {
			cout << "\n=== INFORMACION DEL VEHICULO ===" << endl;
			v->mostrar();
		}
		else {
			cout << "Vehiculo con placa " << placa << " no encontrado." << endl;
		}
	}

	void mostrarVehiculosEstacionados() {
		cout << "\n=== VEHICULOS ESTACIONADOS ===" << endl;
		for (int i = 0; i < this->listaVehiculos->getCantidad(); i++) {
			Vehiculo* v = this->listaVehiculos->getElementoEn(i);
			if (v->getEspacioAsignado() != nullptr) {
				v->mostrar();
				cout << "-----------------------------------" << endl;
			}
		}
	}

	void buscarEspacioPorEstado() {
		for (int i = 0; i < this->listaEspacios->getCantidad(); i++) {
			Espacio* e = this->listaEspacios->getElementoEn(i);
			if (e->getEstado() == "disponible") {
				cout << "\n=== ESPACIOS DISPONIBLES ===" << endl;
				e->mostrar();
			}
		}
	}

	/*
	void buscarEspacioPorEstado( ) {
		Espacio* e = this->listaEspacios->buscar("disponible", Espacio::getterEstado);
		if (e != nullptr) {
			cout << "\n=== ESPACIOS DISPONIBLES ===" << endl;
			e->mostrar();
		}
		else {
			cout << "no hay espacios disponibles" << endl;
		}
	}
	*/
};