#pragma once
#include<iostream>
#include<string>
#include"Servicio.h"

using namespace std;


class ServicioBano: Servicio{
private:
	int costoProductos;
public:
	ServicioBano(string codigo, string nombre,int costoProducto) :Servicio(codigo,nombre)
	{
		this->costoProductos = costoProductos;
	}
	int getcostoProductos() {
		return this->costoProductos;
	}





	void mostrar() override {
		Servicio::mostrar();
		cout << "costo de productos: " << this->getcostoProductos()<<endl;
	}




};