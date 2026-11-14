#pragma once
#include"tipoServicio.h"
class Atencion {
private:
	string codigoA;
	Perro* perro;
	Servicio* servicio;
	float costoFinal;
public:
	Atencion(const string& codigoA)
	{
		this->codigoA = codigoA;
		this->perro = nullptr;
		this->servicio = nullptr;
		this->costoFinal = 0;
	}
	string getCodigo() {
		return codigoA;
	}
	bool CodigoPerro(string ci) {
		if (perro->getCodigo() == ci) {
			return true;
		}
		else {
			return false;
		}
	}
	static bool Comparar(string codigoA, Atencion* atencion) {
		if (codigoA == atencion->getCodigo()) {
			return true;
		}
		else {
			return false;
		}
	}
	
	void AgregarServicioyPerroaAtencion(Servicio* nuevoServicio, Perro* nuevoPerro) {
		this->servicio = nuevoServicio;
		this->perro = nuevoPerro;
		if (nuevoPerro->getTamanio() == "Grande") {
			this->costoFinal = nuevoServicio->Costototal()+ 15;
		}
		else {
			this->costoFinal = nuevoServicio->Costototal();
		}
		
	}
	void Mostrar() {
		cout << "============ INFORMACION DEL SERVICIO ============" << endl;
		cout << "El codigo del servicio es: " << codigoA << endl;
		if (perro != nullptr) {
			perro->Mostrar();
		}
		else {
			cout << "todavia no se a asignado a un perro" << endl;
		}
		if (servicio != nullptr) {
			servicio->Mostrar();
		}
		else {
			cout << "todavia no se a asignado a un servicio" << endl;
		}
		cout << "El costo total  del servicio es: " << costoFinal << endl;
	}
};