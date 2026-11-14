#pragma once
#include <iostream>
#include <string.h>
#include "Perro.h"
#include "Servicio.h"
using namespace std;
class Atencion
{
private:
	string Codigo;
	Perro* Perr;
	Servicio* Serv;
	float Costofinal;
public:
	Atencion(string codigo, Perro* perro, Servicio* servicio, float  costofinal) {
		this->Codigo = codigo;
		this->Perr = perro;
		this->Serv = servicio;
		this->Costofinal = costofinal;
	}
	~Atencion() {
	}
	static string getperroidstatic(Atencion* atencion) {
		return atencion->Perr->getcodigo();
	}

	void Mostrar() {
		cout << "Datos atencion" << endl;
		cout << "Codigo: " << Codigo << endl;
		Perr->Mostrar();
		Serv->Mostrar();
		cout << "Costo final: " << Costofinal << endl;
	}
};
