#pragma once
#include"ListaGenerica.h"
#include"Cliente.h"
#include"PaqueteNormal.h"
class Envio
{
private:
	string numeroEnvio;
	string fechaEnvio;
	float pesoMax;
	Cliente* cliente;
	ListaGenerica<PaqueteNormal>* paquetes;
public:
	Envio(string numeroEnvio,string fechaEnvio,float pesoMax,int capMaxPaquetes) {
		this->numeroEnvio = numeroEnvio;
		this->fechaEnvio = fechaEnvio;
		this->pesoMax = pesoMax;
		this->paquetes = new ListaGenerica< PaqueteNormal>(capMaxPaquetes);
		this->cliente = nullptr;
		
	}


	void regisrarCliente(Cliente* nuevoCliente)
	{
		this->cliente = nuevoCliente;
	
	}

	string getNumero() {
		return numeroEnvio;
	}
	static bool compararNumero(Envio* envio, string numero) {
		return envio->getNumero() == numero;
	}
		
	
};

