#pragma once
#include <iostream>
#include <string>
using namespace std;
class Servicio
{
protected:
	string codigo;
	string nombre;
	float costo;
public:
	Servicio(string codigo,string nombre,float costo) {
		this->codigo = codigo;
		this->nombre = nombre;
		this->costo = costo;
	}
	virtual void mostrar() {
		cout << "codigo del servicio: " << codigo << endl;
		cout << "nombre del servicio: " << nombre << endl;
		cout << "costo base del servicio: " << costo << endl;
	}
	string getCodigo() {
		return this->codigo;
	}
	static bool compararCodigoServicio(Servicio* servicio, string codigo) {
		return servicio->getCodigo() == codigo;
	}
	virtual float totalServicio() {
		return this->costo;
	}
};

