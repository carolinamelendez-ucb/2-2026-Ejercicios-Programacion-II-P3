#pragma once
#include <iostream>
#include <string>
#include "ListaGenerica.h"
#include "Perro.h"
using namespace std;
//Atencion(atributos: codigo, perro, servicio, costoFinal).
//○ Almacena la información de una atención realizada.
class Atencion {

private:
	string codigoAtencion;
	ListaGenerica<Perro>* perros;
	float costofinal;
public:

	Atencion(string codigoAtencion,int cantmaxPerros) {
		this->codigoAtencion = codigoAtencion;
		this->perros = new ListaGenerica<Perro>(cantmaxPerros);
	}
	~Atencion() {

	}
	string getcodigoatencion() {
		return codigoAtencion;
	}
	static string gettercodigo(Atencion *a) {
		return a->getcodigoatencion();
	}
	void agregar(Perro* p) {
		perros->registrar(p);
	}


	void mostrar() {
		cout << "codigo de atencion " << codigoAtencion<<endl;
		cout << "costo final" << costofinal;

	}


};