#pragma once
#include<iostream>
#include<string>
#include"Cliente.h"
#include"Envio.h"
#include"Exception.h"
#include"ClienteDuplicadoException.h"
#include"ListaGenerica.h"
#include "EnvioDuplicadoException.h"
using namespace std;

class SistemaEnvios{
private:
	string nombreEmpresa;
	ListaGenerica<Cliente>* listaClientes;
	ListaGenerica<Envio>* listaEnvios;
public:
	SistemaEnvios(string nomEmpresa,int cap,int capE) {
		this->nombreEmpresa = nombreEmpresa;
		this->listaClientes = new ListaGenerica<Cliente>(cap);
		this->listaEnvios = new ListaGenerica<Envio>(capE);
	}
	void registrarCliente(Cliente* nuevo) {
		try {
			Cliente* duplicado = this->listaClientes->buscar(nuevo->getCi(), Cliente::getterCi);
			if (duplicado != nullptr) {
				throw ClienteDuplicadoException(nuevo->getCi());
			}
			this->listaClientes->agregar(nuevo);
			cout << "Cliente Registrado" << endl;
		}
		catch (Exception err) {
			cout << "ERROR " << err.getMensaje() << endl;
			delete nuevo;
		}
	}
	void registrarEnvio(Envio* nuevoE) {
		try {
			Envio* duplicado = this->listaEnvios->buscar(nuevoE->getNumeroEnvio(), Envio::getterNumero);
			if (duplicado != nullptr) {
				throw EnvioDuplicadoException(nuevoE->getNumeroEnvio());
			}
			this->listaEnvios->agregar(nuevoE);
			cout << "Envio registrado" << endl;
		}
		catch (Exception err) {
			cout << "ERROR " << err.getMensaje() << endl;
			delete nuevoE;
		}
	}

	~SistemaEnvios() {
		delete listaClientes;
		delete listaEnvios;
	}
};


