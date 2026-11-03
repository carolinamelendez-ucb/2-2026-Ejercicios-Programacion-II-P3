#pragma once
#include "ListaGenerica.h"
#include "Cliente.h"
#include "ClienteDuplicadoException.h"
#include "Envio.h"
#include "ClienteNoencontradoException.h"
#include "EnvioDuplicado.h"
#include "PaqueteDuplicado.h"
#include "EnvioNoencontrado.h"
class SistemaDeEnvios
{
private:
	ListaGenerica<Cliente>* clientes;
	ListaGenerica<Envio>* envios;
	ListaGenerica<Paquete>* paquetes;

public:
	SistemaDeEnvios(int cantMaxCliente,int cantMaxenvio,int cantmaxpaquetes) {
		this->clientes = new ListaGenerica<Cliente>(cantMaxCliente);
		this->envios = new ListaGenerica<Envio>(cantMaxenvio);
		this->paquetes = new ListaGenerica<Paquete>(cantmaxpaquetes);
	}
	~SistemaDeEnvios(){}
	void RegistrarClientes(Cliente* nuevoCliente) {
		string ciDuplicado = nuevoCliente->getci();
		try {
			
			Cliente* clienteCiDuplicado = clientes->Buscar(ciDuplicado, Cliente::getciStatic);

			if (clienteCiDuplicado != nullptr) {
				throw ClienteDuplicadoException();
			}
			else {
				clientes->Registrar(nuevoCliente);
			}
		}
		catch (Exception err) {
			cout << "Error: " << err.getrror();
			cout << endl;
		}
	}
	void MostrarClientes() {
		clientes->Mostrar();
	}
	void RegistrarclienteEnvio(Cliente* NuevoCliente, Envio* nuevoEnvio) {
		string idaBusacar = nuevoEnvio->getnumenvio();
		string idcliente = NuevoCliente->getci();
		try {
			Envio* envioDuplicado = envios->Buscar(idaBusacar, Envio::getnumestatico);
			Cliente* clientebuscar = clientes->Buscar(idcliente, Cliente::getciStatic);
			if (envioDuplicado != nullptr && clientebuscar != nullptr) {
				throw EnvioDuplicado();
				throw ClienteNoencontradoException();
			}
			else {
				envios->Registrar(nuevoEnvio);
				nuevoEnvio->Registrarcliente(clientebuscar);
			}
		}
		catch (Exception err) {
			cout << "Error: " << err.getrror();
			cout << endl;
		}
		
	}
	void MostrarEnvios() {
		envios->Mostrar();
	}
	/*void RegistrarPaqueteAenvio(Paquete* nuevopaquete, Envio* nuevoEnvio) {
		string idaBusacar = nuevoEnvio->getnumenvio();
		string idpaquete = nuevopaquete->getcodigo();
		try {
			Paquete* idpaqueteduplicado = paquetes->Buscar(idpaquete, Paquete::getCodigoestatico);
			Envio* envioDuplicado = envios->Buscar(idaBusacar, Envio::getnumestatico);
			if (idpaqueteduplicado != nullptr && idpaqueteduplicado != nullptr) {
				throw EnvioNoencontrado();
				throw PaqueteDuplicado();
			}
			else {
				//paquetes->Registrar(nuevopaquete);
			}
		}
	}*/


};