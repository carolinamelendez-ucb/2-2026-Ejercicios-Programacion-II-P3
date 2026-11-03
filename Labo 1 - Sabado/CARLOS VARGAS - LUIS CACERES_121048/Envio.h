#pragma once
#include<iostream>
#include<string>
#include"Cliente.h"
using namespace std;

class Envio{
private:
	string numeroEnvio;
	string fecha;
	float pesoMax;
	Cliente* cliente;
public:
	Envio(string numeroEnvio, string  fecha, float pesoMax,Cliente* cliente) {
		this->cliente = cliente;
		this->fecha = fecha;
		this->numeroEnvio = numeroEnvio;
		this->pesoMax = pesoMax;
	}
	string getNumeroEnvio() {
		return this->numeroEnvio;
	}
	Cliente* getCliente() {
		return this->cliente;
	}
	void mostrar() {
		cout << "Numero de Envio: " << this->numeroEnvio << endl;
		cout << "Fecha: " << this->fecha << endl;
		cout << "Peso Maximo: " << this->pesoMax << endl;
		cout << "Cliente ";
		this->cliente->mostrar();
	}
	static string getterNumero(Envio* e) {
		return e->numeroEnvio;
	}
};

