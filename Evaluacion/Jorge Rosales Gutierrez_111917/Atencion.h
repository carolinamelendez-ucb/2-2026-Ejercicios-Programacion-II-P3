#pragma once
#include "Perro.h"
#include "Servicio.h"

class Atencion {
private:
	//string codigo;
	Perro* perro;
	Servicio* servicio;
	int costoFinal;

public:
	Atencion(Perro* perro, Servicio* servicio, int costoFinal) {
		
		//this->codigo = codigo;
		this->perro = perro;
		this->servicio = servicio;
		this->costoFinal = costoFinal;
	}

	Perro* getPerro() {
		return perro;
	}

	Servicio* getServicio() {
		return servicio;
	}

	int getCostoFinal() {
		return costoFinal;
	}

	void mostrar() {
		cout << "Perro atendido: " << perro->getCodigo()
			<< " | Servicio: " << servicio->getCodigo() << endl;
	}

	static string getterPerroCodigo(Atencion* atencion) {
		return atencion->perro->getCodigo();
	}
};
