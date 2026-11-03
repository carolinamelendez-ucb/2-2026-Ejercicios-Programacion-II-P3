#pragma once
#include <iostream>
#include <string>

using namespace std;
class Paquete
{
protected:
	int codigoPaquete;
	string descripcion;
	int peso;
	int costoPorKg;
public:
	Paquete(int codigoPaquete, string descripcion, int  peso, int costoPorKg)
	{
		this->codigoPaquete = codigoPaquete;
		this->descripcion = descripcion;
		this->peso = peso;
		this->costoPorKg = costoPorKg;
	}
	int getCodigoPaquete() {
		return codigoPaquete;
	}
	int getPeso() {
		return peso;
	}
	int getCostoPorKg() {
		return costoPorKg;
	}
	virtual void obtenerCosto() {
		int costoTotal;
		costoTotal = peso * costoPorKg;
	}
	void mostrar() {
		cout << "Codigo del paqueton:" << codigoPaquete << endl;
		cout << "descripcion" << descripcion << endl;
		cout << "Peso" << peso << endl;
		cout <<" Costo por kilo" << costoPorKg << endl;
	}
};

