#pragma once
#include <string>
#include <iostream>
#include "Cliente.h"
#include "Paquete.h"
#include "ListaGenerica.h"
#include "Exception.h"
#include "PaqueteDuplicadoException.h"
#include "PesoMaximoExedido.h"
using namespace std;

class Envio {
private:
	string numeroEnvio;
	string fechaEnvio;
	int pesoMax;
	Cliente* cliente;
	ListaGenerica<Paquete>* listaPaquete;
public:
	Envio(string numEnvio, string fecha, int pesoMax,int capEnvios) {
		this->numeroEnvio = numEnvio;
		this->fechaEnvio = fecha;
		this->pesoMax = pesoMax;
		this->listaPaquete = new ListaGenerica<Paquete>(capEnvios);
		this->cliente = nullptr;

	}
	string getNumEnvio() { return numeroEnvio; }
	void agregarCliete(Cliente* nuevoCliente) {
		this->cliente = nuevoCliente;
	}
	static bool getterEnvio(Envio* envio, string cod) {
		return envio->numeroEnvio == cod;
	}

	static bool getterCliente(Envio* envio,string ci) {
		return envio->cliente->getCI()==ci;
	}

	void agregarPaquete(Paquete* nuevoPaquete) {
		try {
			if (nuevoPaquete->getPeso() < pesoMax) {
				Paquete* paquete = this->listaPaquete->buscar(nuevoPaquete->getCod(), Paquete::getterCod);
				if (paquete != nullptr) {
					throw PaqueteDuplicado(nuevoPaquete->getCod());
				}
				else {
					this->listaPaquete->agregar(nuevoPaquete);
				}
			}
			else {
				throw PesoExedido(nuevoPaquete->getPeso());
			}
		}
		catch (Exception err) {
			cout << "Error: " << err.getMensaje() << endl;
		}

	}
	void mostrar() {
		cout << "Envios de cliente: " << endl;
		cliente->mostrar();
		listaPaquete->mostrar();
		cout << "Costo final de los paquetes: " << listaPaquete->total() << endl;
	}

};