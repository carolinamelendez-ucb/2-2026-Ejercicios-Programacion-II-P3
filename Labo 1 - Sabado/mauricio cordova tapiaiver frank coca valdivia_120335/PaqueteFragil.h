#pragma once
#include <string>
#include <iostream>
#include "Paquete.h"
using namespace std;

class PaqueteFragil :public Paquete {
private:
	string nivelFragilidad;
	int costoEnvalage;
public:
	PaqueteFragil(string nivelFragilidad, string codigo, string descrip, int peso) :Paquete(codigo, descrip, peso, 15) {
		this->nivelFragilidad = nivelFragilidad;
		this->costoEnvalage = 0;
	}

	string getCod() override { return codPaquete; }
	float costoFinal()override {

		if (this->nivelFragilidad == "BAJO") {
			costoEnvalage = 5;
		}
		if (this->nivelFragilidad == "MEDIO") {
			costoEnvalage = 10;
		}
		if (this->nivelFragilidad == "ALTO") {
			costoEnvalage = 20;
		}
		return costoEnvalage+(peso * costoKilo);
	}
	int getPeso() override {
		return peso;
	}
	int getCostoKilo() override {
		return costoKilo;
	}
	void mostrar() override {
		cout << "Codigo: " << codPaquete << endl;
		cout << "Descripcion: " << descripcion << endl;
		cout << "Peso: " << peso << endl;
		cout << "Costo Kilo: " << costoKilo << endl;
		cout << "Nivel gragilidad: " << nivelFragilidad << endl;
		cout << "Costo Envalage: " << costoEnvalage << endl;
		cout << "Precio Final: " << costoFinal() << endl;
	}
};