#pragma once
#include "Cliente.h"
#include "ListaGenerica.h"
#include "PaqueteExpress.h"
#include "PaqueteFragil.h"
#include "PaqueteNormal.h"

class Envio
{
private:
	string numeroEnvio;
	string fechaEnvio;
	int pesoMax;
	Cliente* cliente;
	ListaGenerica<PaqueteNormal>* listaPaquetes;
public:
	Envio(string numeroEnvio,string fechaEnvio,int pesoMax,Cliente* cliente);
	void registrarPaquete(PaqueteNormal* paquete);
	string getIdentificador();
	void mostrarDatos();
};

