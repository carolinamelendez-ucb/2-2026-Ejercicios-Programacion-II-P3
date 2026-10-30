#pragma once
#include"Vehiculo.h"
#include"ListaGenerica.h"
#include"Excepciones.h"
class SistemaParqueo {
private:
	string nombreDelaEmpresa;
	string dirrecion;
	int capacidadMax;
	ListaGenerica<Espacio>* ListaE;
	ListaGenerica<Vehiculo>* ListaV;
public:
	SistemaParqueo(const string& nombreDelaEmpresa, const string& dirrecion, int capacidadMax)
	{
		this->nombreDelaEmpresa = nombreDelaEmpresa;
		this->dirrecion = dirrecion;
		this->capacidadMax = capacidadMax;
		this->ListaE = new ListaGenerica<Espacio>(capacidadMax);
		this->ListaV = new ListaGenerica<Vehiculo>(capacidadMax);
	}
	void AgregarVehiculo(Vehiculo* nuevoVehiculo) {
		string codigoEspacio = nuevoVehiculo->getplaca();
		try {
			if (ListaV->getCantidad() > ListaV->getTamanio()) {
				throw CapacidadMaximaVehiculosException();
			}
			if (ListaV->Buscar(codigoEspacio, Vehiculo::getterEspacio)) {
				throw PlacaDuplicadaException();
			}
			ListaV->agregar(nuevoVehiculo);
		}
		catch (Excepciones error) {
			cout << error.getMensaje() << endl;
		}

	}
	void AgregarEspacio(Espacio* nuevoEspacio) {
		string codigoEspacio = nuevoEspacio->getEspacio();
		try{
			if(ListaE->getCantidad() > ListaE->getTamanio()){
				throw CapacidadMaximaEspaciosException();
			}
			if (ListaE->Buscar(codigoEspacio,Espacio::getterEspacio) ) {
				throw CodigoEspacioDuplicadoException();
			}
			ListaE->agregar(nuevoEspacio);
		}
		catch (Excepciones error) {
			cout << error.getMensaje() << endl;
		}
		
	}
	void AsignarVehiculoAEspacio(string placa,string CodigoDeEspacio) {
		Espacio* Aux= ListaE->Buscar(CodigoDeEspacio, Espacio::getterEspacio);
		Vehiculo* Aux2 = ListaV->Buscar(placa, Vehiculo::getterEspacio);
		try {
			if (Aux2 == nullptr) {
				throw VehiculoNoEncontradoException();
			}
			if (Aux->getEstado() == false) {
				throw NoHayEspaciosDisponiblesException();
			}
			if(Aux2->getEspacio() != nullptr){
				throw VehiculoYaAsignadoException();
			}
			Aux2->AsignarEspacio(Aux);
		}
		catch (Excepciones error) {
			cout << error.getMensaje() << endl;
		}
	}
	void MostrarVehiculos() {
		ListaV->Mostar();
	}
	void MostrarEspacios() {
		ListaE->Mostar();
	}
};