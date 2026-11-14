#pragma once
#include <iostream>
#include <string.h>
using namespace std;
class Servicio
{
protected:
	string Codigo;
	string Nombre;
	float CostoAd;
public:
	Servicio(string codigo, string nombre,float costoad) {
		this->Codigo = codigo;
		this->Nombre = nombre;
		this->CostoAd = costoad;
	}
	virtual ~Servicio(){}
	string getcodigo() {
		return Codigo;
	}
	float getcosto() {
		return CostoAd;
	}
	static string getcodigoStatic(Servicio* servicio) {
		return servicio->Codigo;
	}
	virtual void Mostrar() {
		cout << "Datos del servicio" << endl;
		cout << "Codigo: " << Codigo << endl;
		cout << "Nombre: " << Nombre << endl;
		cout << "Costo: " << CostoAd << endl;
	}
};