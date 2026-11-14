#pragma once
#include <iostream>
#include <string>
#include "Perro.h"
#include "ListaGenerica.h"
using namespace std;

class Servicio {
protected:
	string codigo;
	string nombre;
	

public:
	Servicio(string codigo, string nombre) {
		this->codigo = codigo;
		this->nombre = nombre;
	}

	virtual ~Servicio() {}

	string getCodigo() {
		return codigo;
	}



	virtual bool esCompatible(string tamanioPerro) {
		if (tamanioPerro == "grande") {
			return true;
		}
	}
	

	virtual int calcularCosto(Perro* perro) = 0;

	virtual void mostrar() {
		cout << "Codigo: " << codigo
			<< " | Nombre: " << nombre << endl;
	}

	static string getterCodigo(Servicio* servicio) {
		return servicio->codigo;
	}
};
