#pragma once
#include <iostream>
#include <string>
#include "Cliente.h"
using namespace std;



class Envio{
private:
	int numeroEnvio;
	string fechaEnvio;
	float pesoMax;
	Cliente* cliente;
	string listaPaquetes;
public:
	Envio(int numeroEnvio, string fechaEnvio, float pesoMax, Cliente* cliente) {
		this->numeroEnvio = numeroEnvio;
		this->fechaEnvio = fechaEnvio;
		this->pesoMax = pesoMax;
		this->cliente = cliente;
		this->listaPaquetes = listaPaquetes;
	}
	int getid() {
		return this->numeroEnvio;
	}


	static bool compararNombre(Envio* a, Envio* b) {
		return a->numeroEnvio > b->numeroEnvio;
	}


	static int getterId(Envio* e) {
		return e->numeroEnvio;
	}

	void mostrar() {
		cout << 
			" | Id: "<< numeroEnvio << " | fecha: "<< fechaEnvio << " | pesoMax: "<< pesoMax << " | pesoMax: " <<endl;
	}





};