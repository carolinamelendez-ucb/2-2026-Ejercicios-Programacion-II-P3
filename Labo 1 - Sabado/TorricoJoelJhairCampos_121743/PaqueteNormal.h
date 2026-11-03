#pragma once
#include <iostream>
#include <string>
using namespace std;
class PaqueteNormal
{
protected:
	string codigo;
	string descripcion;
	float peso;
	float costoPorKilogramo;


public:
	PaqueteNormal(string codigo,string descripcion,float peso,float costoPorKilogramo) {
		this->codigo = codigo;
		this->descripcion = descripcion;
		this->peso = peso;
		this->costoPorKilogramo = costoPorKilogramo;
	}
	virtual void mostrar() {
		cout << "--------------------------------------------------" << endl;
		cout << "el codigo es: " << codigo << endl;
		cout << "descripcion: " << descripcion << endl;
		cout << "peso: " << peso << endl;
		cout << "costoPorKilogramo: " << costoPorKilogramo << endl;
		cout << "costo si fuera paquete normal: " << total() << endl;
		
	}
	string getCodigo() {
		return this->codigo;
	}
	static bool compararCodigo(PaqueteNormal* paquete, string codigo) {
		return paquete->getCodigo() == codigo;
	}
	float total() {
		return this->peso* this->costoPorKilogramo;
	}
	virtual float calcularCosto() {
		return total();
	}
	
	static bool nombreCostoMenor(PaqueteNormal* primero, PaqueteNormal* segundo) {
		return primero->calcularCosto() < segundo->calcularCosto();
	}

};

