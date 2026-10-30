#pragma once
#include"Espacio.h"
class Vehiculo {
private:
	string placa;
	string marca;
	string modelo;
	string tipoVehiculo;
	Espacio* espacioAsignado;
public:
	Vehiculo(const string& placa, const string& marca, const string& modelo, const string& tipoVehiculo)
		  
	{
		this->placa = placa;
		this->marca = marca;
		this->modelo = modelo;
		this->tipoVehiculo = tipoVehiculo;
		this->espacioAsignado = nullptr;
	}
	string getplaca() {
		return placa;
	}
	Espacio* getEspacio() {
		return espacioAsignado;
	}
	static bool getterEspacio(string placa, Vehiculo* vehiculo) {
		return placa == vehiculo->placa;
	}
	void AsignarEspacio(Espacio* espacioDisponible) {
		espacioAsignado = espacioDisponible;
	}
	void mostrar() {
		cout << "============ Vehiculo ============" << endl;
		cout << "La placa del vehiculo es: " << placa << endl;
		cout << "La marca del vehiculo es: " << marca << endl;
		cout << "La modelo del vehiculo es: " << modelo << endl;
		cout << "La tipoVehiculo del vehiculo es: " << tipoVehiculo << endl;
		if (espacioAsignado != nullptr) {
			espacioAsignado->mostrar();
		}
		else {
			cout << "No posee un espacio de estacionamiento" << endl;
		}
	}
};