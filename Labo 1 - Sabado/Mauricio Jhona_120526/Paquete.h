#pragma once
#include <iostream>
#include <string.h>
using namespace std;
class Paquete
{
protected:
	string Codigo;
	string Descripcion;
	float Peso;
	float Costo;
public:
	Paquete(string codigo, string descripcion, float peso, float costo) {
		this->Codigo = codigo;
		this->Descripcion = descripcion;
		this->Peso = peso;
		this->Costo = costo;
	}
	virtual ~Paquete() {}
	string getcodigo() {
		return Codigo;

	}
	static string getCodigoestatico(Paquete* paq) {
		return paq->Codigo;
	}
	virtual void Mostrar() {
		cout << "Codigo: " << Codigo << endl;
		cout << "descripcion: " << Descripcion << endl;
		cout << "peso: " << Peso << endl;
		cout << "costo: " << Costo << endl;
	}
};