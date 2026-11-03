#pragma once
#include <iostream>
#include <string>
#include "ListaGenerica.h"
#include "Cliente.h"
using namespace std;
class Envio
{
private:
	int nuevoEnvio;
	string fechaEnvio;
	int pesoMax;
	Cliente* cliente;
	ListaGenerica<int> listaPaquetes;

public:
	Envio(int nuevoEnvio, string fechaEnvio, int pesoMax,) {
		this->nuevoEnvio = nuevoEnvio;
		this->fechaEnvio = fechaEnvio;
		this->pesoMax = pesoMax;
		this->cliente = new Cliente();
	}
	int getPesoMax() {
		return pesoMax;

	}
	string getFechaEnvio() {
		return fechaEnvio;

	}
	int getNuevoEnvio() {
		return nuevoEnvio;
	}

	void anidarEnvioACliente( Cliente cliente) {
		
	}
};

