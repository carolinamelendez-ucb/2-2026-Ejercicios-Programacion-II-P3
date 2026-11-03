#pragma once
#include <iostream>
#include <string>
#include "Exception.h"
#include "Cliente.h"
#include "Paquete.h"
#include "Envio.h"
#include "ListaGenerica.h"
using namespace std;
class SistemaEnvios {
private:
	string nombre;
	ListaGenerica<Cliente*>* listaClientes;
	ListaGenerica<Envio*>* listaEnvios;
public:
	SistemaEnvios(string nombre) {
		this->nombre = nombre;
		this->listaClientes = new  ListaGenerica <Cliente*>();
		this->listaEnvios = new  ListaGenerica <Envio*>();
	}
	static string obtenerCi(Cliente* cliente) {
		return cliente->getCi();

	}
	static int obtenerNumeroEnvio(Envio* envio) {
		return envio->getNumeroEnvio();

	}

	void registrarCliente(Cliente* nuevoCliente) {
		for (int i = 0; i < listaClientes->getCantidad();i++) {
			//if ( SistemaEnvios::obtenerCi(listaClientes->obtener(i) == nuevoCliente.getCi()) ) 
			throw{
				cout << "ci iguales" << endl;

		}
		}
	}
};