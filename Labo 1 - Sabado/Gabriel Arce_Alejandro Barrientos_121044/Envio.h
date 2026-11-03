#pragma once
#include "Cliente.h"
#include"VectorGenerico.h"
#include"Paquete.h"
#include"Excepcion.h"
#include"PaqueteDuplicadoException.h"

class Envio
{
private:
	string numero;
	int fecha;
	double pesoMaximo;
	Cliente* cliente;
	VectorGenerico<Paquete>* paquetes;
public:
	Envio() = default;
	Envio(string numero, int fecha, double pesoMaximo,int cantidadPaquetes) {
		this->numero = numero;
		this->fecha = fecha;
		this->pesoMaximo = pesoMaximo;
		this->cliente = nullptr;
		this->paquetes = new VectorGenerico<Paquete>(cantidadPaquetes);
	}
	string getNumero() {
		return numero;
	}
	~Envio();
	void agregarClienteAEnvio(Cliente* cliente) {
		this->cliente = cliente;
	}
	void agregarPaquetesAEnvio(Paquete* paquete) {
		try {
			if (paquetes->buscar(paquete->getCodigo(), Paquete::comparador) == nullptr)
			{
				paquetes->agregarElemento(paquete);
			}
			else {
				throw PaqueteDuplicadoExcepcion();
			}
		}
		catch (Excepcion err) {
			cout << err.getMensaje() << endl;
		}

		
	}
	void mostrar() {
		cout << "Numero envio: " << numero << endl;
		cout << "Feha : " << fecha << endl;
		cout << "Peso Maximo : " << numero << endl;
		if (cliente == nullptr) {
			cout << "No se asigno cliente aun. " << endl;
		}else {
			cout << "Cliente : " << endl;
			cliente->mostrar();
		}
		
		cout << "Paquetes: " << endl;
		paquetes->mostrar();
	}
	
	static bool comparador(Envio* envio, string numero) {
		return envio->numero == numero;
	}

};

