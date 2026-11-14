#pragma once
#include "Perro.h"
#include"Servicio.h"


class Atencion
{
private:
	string codigo;
	Perro* perro;
	Servicio *servicio;
	int costoFinal;
public:
	Atencion();
	Atencion(string codigo, Perro* perro, Servicio* servicio) {
		this->codigo = codigo;
		this->perro = perro;
		this->servicio = servicio;
		this->costoFinal = 0;
	}
	~Atencion() {
		delete perro;
		delete servicio;
	}
	void calcularCostoFinal() {
		costoFinal = servicio->getCostoAdicional();
		string tamanioPerro = perro->getTamanio();
		if (tamanioPerro=="GRANDE"){
			costoFinal = costoFinal + 15;
		}
		
	}
	void mostrar() {
		calcularCostoFinal();
		cout << "Atencion: " << endl;
		cout << "Codigo Atencion: " << codigo << endl;
		perro->mostrar();
		cout << endl;
		servicio->mostrar();
		cout << "Costo Final: " <<costoFinal<< endl;
	}
	string getCodigoPerroAtendido() {
		return perro->getCodigo();
	}
	static bool comparador(Atencion* atencion, string codbuscado) {
		return atencion->getCodigoPerroAtendido() == codbuscado;
	}
	int getter() {
		return costoFinal;
	}
};



