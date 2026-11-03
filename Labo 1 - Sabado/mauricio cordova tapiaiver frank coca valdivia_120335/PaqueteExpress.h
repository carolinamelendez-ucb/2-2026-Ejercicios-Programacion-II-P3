#pragma once
#include <string>
#include <iostream>
#include "Paquete.h"
using namespace std;

class PaqueteExpress :public Paquete {
private:
	int horasDeEntrega;
	int costoPrioridad;
public:
	PaqueteExpress(int horasDeEntre, string codigo, string descrp, int peso) :Paquete(codigo, descrp, peso,15) {
		this->horasDeEntrega = horasDeEntre;
		this->costoPrioridad = 0;
	}
	string getCod() override { return codPaquete; }

	float costoFinal() override {
		if (horasDeEntrega < 24) {
			costoPrioridad = 30;
	   }
		if (horasDeEntrega >= 24 && horasDeEntrega <= 48) {
			costoPrioridad = 20;
		}
		if (horasDeEntrega > 48) {
			costoPrioridad = 10;
		}
		return costoPrioridad + (peso * costoKilo);
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
		cout << "Horas Entrega: " << horasDeEntrega << endl;
		cout << "Costo Prioridad: " << costoPrioridad << endl;
		cout << "Precio Final: " << costoFinal() << endl;
	}

};