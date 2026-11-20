#pragma once

#include<iostream>
#include<string>
#include "Servicio.h"

using namespace std;


class ServicioCorte :public Servicio {
private:
	int costoCorte;
public:
	ServicioCorte(string codigo, string nombre) :Servicio(codigo, nombre)
	{
		this->costoCorte = costoCorte;
	}
	int getcostoCorte() {
		return this->costoCorte;
	}
	void mostrar() override {
		Servicio::mostrar();
		cout << "costo de corte: " << this->getcostoCorte() << endl;
	}












};