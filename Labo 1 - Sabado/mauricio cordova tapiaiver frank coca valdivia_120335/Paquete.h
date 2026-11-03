#pragma once
#include <string>
#include <iostream>
using namespace std;

class Paquete {
protected:
	string codPaquete;
	string descripcion;
	int peso;
	int costoKilo;
public:


	Paquete(string codPaquete,string descripcion, int peso, int costoKilo)
		: codPaquete(codPaquete), descripcion(descripcion), peso(peso), costoKilo(costoKilo)
	{
	}
	virtual float costoFinal() = 0;
	virtual int getPeso() = 0;
	virtual string getCod() = 0;
	virtual int getCostoKilo() = 0;
	static bool getterCod(Paquete* paquete, string codigo) {
		return paquete->codPaquete == codigo;
	}
	virtual void mostrar() = 0;

};