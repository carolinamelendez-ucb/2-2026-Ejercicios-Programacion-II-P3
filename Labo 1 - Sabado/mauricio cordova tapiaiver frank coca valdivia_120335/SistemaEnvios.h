#pragma once
#include <string>
#include <iostream>
#include "Cliente.h"
#include "Paquete.h"
#include "ListaGenerica.h"
#include "Exception.h"
#include "PaqueteDuplicadoException.h"
#include "ClienteDuplicadoException.h"
#include "EnvioDuplicadoException.h"
#include "Envio.h"
#include "ClienteNoEncontradoException.h"
#include "EnvioNoEncontradoException.h"
using namespace std;

class SistemaEnvio {
private:
	string nombreEmpresa;
	ListaGenerica<Cliente>* listaCliente;
	ListaGenerica<Envio>* listaEnvio;
public:
	SistemaEnvio(string nombreEmpresa, int capacidad) {
		this->nombreEmpresa = nombreEmpresa;
		this->listaCliente = new ListaGenerica<Cliente>(capacidad);
		this->listaEnvio = new ListaGenerica<Envio>(capacidad);
	}
	void agregarEnvios(Envio* nuevoEnvio) {
		try {
			Envio* numEnvioDuplicado = this->listaEnvio->buscar(nuevoEnvio->getNumEnvio(), Envio::getterEnvio);
			if (numEnvioDuplicado != nullptr) {
				throw EnvioDuplicado(nuevoEnvio->getNumEnvio());
			}
			else {
				this->listaEnvio->agregar(nuevoEnvio);
			}
		}
		catch(Exception err){
			cout << "Error: " << err.getMensaje() << endl;
		}
	}
	void agregarClienteAEnvio(string ci,string numEnvio) {
		try {
			Cliente* clienteBuscado = this->listaCliente->buscar(ci, Cliente::getterCI);
			if (clienteBuscado != nullptr) {
				Envio* numEnvioBuscado = this->listaEnvio->buscar(numEnvio, Envio::getterEnvio);
				if (numEnvioBuscado != nullptr) {
					numEnvioBuscado->agregarCliete(clienteBuscado);
				}
				else {
					throw EnvioNoEncontrado(numEnvio);
				}
			}
			else {
				throw ClienteNoEncontrado(ci);
			}
		}
		catch (Exception err) {
			cout << "Error: " << err.getMensaje() << endl;
		}
	}

	void registrarPaquetesAEnvio(string numEnvio,Paquete* nuevoPaquete) {
		try {
			Envio* buscarEnvio = this->listaEnvio->buscar(numEnvio, Envio::getterEnvio);
			if (buscarEnvio != nullptr) {
				buscarEnvio->agregarPaquete(nuevoPaquete);
			}
			else {
				throw EnvioNoEncontrado(numEnvio);
			}
		}
		catch (Exception err) {
			cout << "Error " << err.getMensaje() << endl;
		}
	}


	void agregarCliente(Cliente* newCliente) {
		try {
			Cliente* clienteCiDuplicado = this->listaCliente->buscar(newCliente->getCI(), Cliente::getterCI);
			if (clienteCiDuplicado != nullptr) {
				throw ClienteDuplicado(newCliente->getCI());
			}
			else {
				this->listaCliente->agregar(newCliente);
			}
		}
		catch (Exception err) {
			cout << "Error: " << err.getMensaje() << endl;
		}
	}

	void mostrarClientes() {
		this->listaCliente->mostrar();
	}

	void mostrarClienteEspecifico(string ci) {
		try {
			Envio* envio = this->listaEnvio->buscar(ci,Envio::getterCliente);
			if (envio != nullptr) {
				envio->mostrar();
			}
			else {
				throw ClienteNoEncontrado(ci);
			}
		}
		catch (Exception err) {
			cout << "Error: " << err.getMensaje() << endl;
		}
	}


	void mostrarEnvios() {
		cout << "--------------------------------Lista de envios-----------------------------" << endl;
		listaEnvio->mostrar();
	}


};