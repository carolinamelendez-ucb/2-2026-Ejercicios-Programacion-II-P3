#pragma once
#include <iostream>
#include <string>
#include "Cliente.h"
#include "Paquete.h"
#include "ListaGenerica.h"
using namespace std;
class Envio
{
private:
	string Numenvio;
	string Fecha;
	float PesoMax;
	Cliente* cliente;
	ListaGenerica<Paquete>* paquetes;
public:
	Envio(string numenvio, string fecha, float pesomax) {
		this->Numenvio = numenvio;
		this->Fecha = fecha;
		this->PesoMax = pesomax;
		this->cliente = nullptr;
		this->paquetes = new ListaGenerica<Paquete>(10);
	}
	~Envio();
	string getnumenvio() {
		return Numenvio;
	}
	void Registrarcliente(Cliente* cli) {
		this->cliente = cli;
	}
	static string getnumestatico(Envio* en) {
		return en->Numenvio;
	}
	void Mostrar() {
		cout << "num envio: " << Numenvio << endl;
		cout << "peso max" << endl;
		cliente->Mostrar();
		paquetes->Mostrar();
	}
};