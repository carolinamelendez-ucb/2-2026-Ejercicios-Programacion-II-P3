#pragma once
#include "Perro.h"
#include "ServicioBano.h"
#include "ServicioCorte.h"

class Atencion {
private:
	string codigo;
	Perro* perro;
	Servicio* servicio;
	double costoFinal;
public:
	Atencion(const string& codigo)
	{
		this->codigo = codigo;
		this->perro = nullptr;
		this->servicio = nullptr;
		this->costoFinal = 0;
	}
	string getCodigo() {
		return codigo;
	}
	void asignarPerro(Perro* nuevoPerro) {
		this->perro = nuevoPerro;
	}
	void asignarServicio(Servicio* nuevoServicio) {
		this->servicio = nuevoServicio;
	}
	double calculoCostoFinal() {
		double aux = 0;
		string perroTamanio = perro->getTamanio();
		if (perroTamanio == "grande") {
			aux += 15;
		}
		return aux;
	}
	void mostrar() {
		cout << "---------------------------------------------------" << endl;
		cout << "codigo: " << codigo << endl;
		perro->mostrar();
		servicio->mostrar();
		cout << "costoFinal: " << calculoCostoFinal() << endl;
		cout << "---------------------------------------------------" << endl;
	}
};