#pragma once
#include<iostream>
#include<string>
using namespace std;



class Servicio {
protected:
	string codigo;
	string nombre;
public:
	Servicio(string codigo,string nombre)
	{
		this->codigo = codigo;
		this->nombre = nombre;
	}
	virtual ~Servicio(){}

	string getCodigo() {

		return this->codigo;
	}
	string getNombre() {
		return this->nombre;
	}

	static string getterCodigo(Servicio* s) {
		return s->codigo;
	}


	virtual void mostrar() {
		cout << "Codigo: " << this->getCodigo() << endl;
		cout << "Nombre: " << this->getNombre() << endl;

	}




};
