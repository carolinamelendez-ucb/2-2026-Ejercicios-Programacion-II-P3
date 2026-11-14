#pragma once
#include <iostream>
#include <string>
using namespace std; 

class Servicio
{
protected:
	string codigo;
	string nombre;
public:
	Servicio(string codigo, string nombre) {
		this->codigo = codigo;
		this->nombre = nombre;
	}
	~Servicio() {};
	virtual void mostrar() {
		cout << "Servicio: "<<endl;
	}
	virtual int getCostoAdicional()=0;
	string getCodigo() {
		return codigo;
	}
	static bool comparador(Servicio* servicio, string codbuscado) {
		return servicio->codigo == codbuscado;
	}
};
