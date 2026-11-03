#pragma once
#include "Envio.h"

class SistemaEnvios
{
private:
	string nombreEmpresa;
	ListaGenerica<Cliente>* listaClientes;
	ListaGenerica<Envio>* listaEnvios;
public:
	SistemaEnvios(string nombreEmpresa);
	void registrarCliente(Cliente* nuevoCliente);
	void registrarEnvio(Envio* nuevoEnvio);
	void registrarPaquete(Envio* envio, PaqueteNormal* nuevoPaquete);
	void BuscarCliente(string buscarIdentificador);
};

