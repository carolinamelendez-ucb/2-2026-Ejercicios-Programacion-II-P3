#pragma once
#include <string>
#include <iostream>
#include "Servicio.h"
#include "Perro.h"
using namespace std;

class Atencion {
private:
	string codigo;
	Perro* perro;
	Servicio* servicio;
	float costoFinal;
public:
	Atencion(string codigo) {
		this->codigo = codigo;
		this->perro = nullptr;
		this->servicio = nullptr;
		this->costoFinal = 0;
	}
	float CostoTotal() {
		costoFinal = servicio->getCosto();
		if (servicio->getNombre() == "Corte") {
			if (perro->getTamanio() == "Grande") {
				costoFinal = costoFinal + 15;
			}
		}
		return costoFinal;
	}
	static bool getterPerro(Perro* perro,string codigo) {
		return perro->getCodigo() == codigo;
	}
	float getCotoTotal() {
		return costoFinal;
	}
	static bool getter(Atencion* atencion, string codigo) {
		return atencion->codigo == codigo;
	}
	void agregarPerro(Perro* nuevoPerro) {
		this->perro = nuevoPerro;
	}
	void agregarServicio(Servicio* nuevoServicio) {
		this->servicio = nuevoServicio;
	}
	string getCodigo() { return codigo; }
	void mostrar() {
		cout << "-------------------------------------" << endl;
		cout << "Informacion de perro: " << endl;
		perro->mostrar();
		cout << "Informacion de servicio: " << endl;
		servicio->mostrar();
		cout << "Total: " << CostoTotal() << endl;

	}


};