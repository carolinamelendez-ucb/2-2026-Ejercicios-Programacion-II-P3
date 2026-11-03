#pragma once
#include <iostream>
#include <string>
#include "Cliente.h"
#include "Paquete.h"
#include "ListaGenerica.h"
#include "Exception.h"
using namespace std;
class Envio {
private:
	int numeroEnvio;
	string fechaEnvio;
	float pesoMax;
	Cliente* clientes;
	ListaGenerica<Paquete*>* listapaquetes;

public:
	Envio(int numeroEnvio, string fechaEnvio, float pesoMax, Cliente* cliente) {
		this->numeroEnvio= numeroEnvio;
		this->fechaEnvio= fechaEnvio;
		this->pesoMax= pesoMax;
		this->clientes=cliente;
		this->listapaquetes=new  ListaGenerica <Paquete*>();

	}
	~Envio() {
		for (int i = 0;i < listapaquetes->getCantidad();i++) {
			delete listapaquetes->obtener (i);
		}
		delete this->listapaquetes;
	}
	void mostrar() {
		cout << "codigo Paquete" << numeroEnvio << endl;
	}
	int getNumeroEnvio() {
		return numeroEnvio;
	}
	Cliente* getcliente() {
		return clientes;
	}
	float getpesoactual() {
		float total = 0;
		for (int i = 0;i < listapaquetes->getCantidad();i++) {
			total += listapaquetes->obtener(i)->getPeso();

		}
		return total;
	}
};