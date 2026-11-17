#pragma once
#include <iostream>
#include <string>
#include "Servicios.h"
#include "Perro.h"
using namespace std;

class ServiciosCorte :public Servicios {

private:

public:
	ServiciosCorte() :Servicios(codigo, nombre, CostoMaterial) {
		this->codigo = codigo;
		this->nombre = nombre;
		this->CostoMaterial = CostoMaterial;
	}
	
	void mostrar() override {
		Servicios::mostrar();
		cout << " Tipo de Servicio: Servicio de Corte "<< endl;
	}
	double calcularCostoTotal() {
		cout << "Costo total: " << endl;
		return CostoMaterial * 15;
	}
};

