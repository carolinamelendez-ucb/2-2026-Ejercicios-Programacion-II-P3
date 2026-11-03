#pragma once
#include <string>
#include <iostream>
#include "Paquete.h"
using namespace std;


class PaqueteNormal :public Paquete {
public:
	PaqueteNormal(string codigo, string descrip, int peso) :Paquete(codigo, descrip, peso, 10) {

	}
	string getCod() override { return codPaquete; }
	float costoFinal() override{
		return peso * costoKilo;
	}
	int getPeso() override {
		return peso;
	}
	int getCostoKilo() override {
		return costoKilo;
	}

	void mostrar() override{
		cout << "Codigo: " << codPaquete << endl;
		cout << "Descripcion: " << descripcion << endl;
		cout << "Peso: " << peso << endl;
		cout << "Costo Kilo: " << costoKilo<< endl;
		cout << "Precio Final: " << costoFinal() << endl;
	}
};