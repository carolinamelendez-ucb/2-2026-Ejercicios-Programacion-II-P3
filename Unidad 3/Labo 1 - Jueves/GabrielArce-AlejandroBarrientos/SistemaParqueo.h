#pragma once
#include"Espacio.h"
#include"Excepcion.h"
#include"Vehiculo.h"
#include"VectorGenerico.h"
#include"ExcepcionCapacidadMaximaEspacios.h"
#include"ExcepcionEspacioDuplicado.h"
#include"ExcepcionCapacidadMaximaVehiculos.h"
#include"ExcepcionVehiculoDuplicado.h"

class SistemaParqueo
{
private:
	string nombreEmpresa;
	string direccion;
	int capacidadMaxima;
	VectorGenerico<Espacio>* listaEspacios;
	VectorGenerico<Vehiculo>* listaVehiculos;
public:
	SistemaParqueo(string nombre, string direccion, int capacidadMaxima) {
		this->nombreEmpresa = nombre;
		this->direccion = direccion;
		this->capacidadMaxima = capacidadMaxima;
		this->listaEspacios = new VectorGenerico<Espacio>(capacidadMaxima);
		this->listaVehiculos = new VectorGenerico<Vehiculo>(capacidadMaxima);
	}
	~SistemaParqueo();

	void registrarEstacionamiento(Espacio* nuevoEspacio) {
		int cantidadEspacios= listaEspacios->getCantidad();
		try {
			if (cantidadEspacios < capacidadMaxima)
			{
				if (listaEspacios->buscar(nuevoEspacio->getCodigoEspacio(), Espacio::comparador) != nullptr)
				{
					listaEspacios->agregar(nuevoEspacio);
				}else {
					throw ExcepcionEspacioDuplicado();
				}
				
			}
			else {
				throw ExcepcionCapacidadMaximaEspacios();
			}
		}
		catch (Excepcion err) {
			cout << err.getMensaje();
		}
	}
	void registrarVehiculo(Vehiculo* nuevoVehiculo) {
		int cantidadVhiculos = listaVehiculos->getCantidad();
		try {
			if (cantidadVhiculos < capacidadMaxima)
			{
				if (listaVehiculos->buscar(nuevoVehiculo->getPlaca(), Vehiculo::comparador)!= nullptr)
				{
					listaVehiculos->agregar(nuevoVehiculo);
				}
				else {
					throw ExcepcionVehiculoDuplicado();
				}

			}
			else {
				throw ExcepcionCapacidadMaximaVehiculos();
			}
		}
		catch (Excepcion err) {
			cout << err.getMensaje();
		}
	}
	void mostrarVehiulos() {
		listaVehiculos->mostrar();
	}

};
