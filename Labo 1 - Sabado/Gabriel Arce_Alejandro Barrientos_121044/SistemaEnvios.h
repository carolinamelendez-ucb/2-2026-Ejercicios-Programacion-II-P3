#pragma once
#include"Envio.h"
#include"ExcepcionClienteDupicado.h"
#include"EnvioDuplicadoExcepcion.h"
#include"ClienteNoEncontrado.h"
#include"EnvioNoEncontradoExcapcion.h"
class SistemaEnvios
{
private:
	string nombre;
	VectorGenerico<Cliente>* clientes;
	VectorGenerico<Envio>* envios;

public:
	SistemaEnvios(string nombre, int capacidadClientes, int capacidadEnvios) {
		this->nombre = nombre;
		this->clientes = new VectorGenerico<Cliente>(capacidadClientes);
		this->envios = new VectorGenerico<Envio>(capacidadEnvios);
	}
	~SistemaEnvios();

	void mostrarClientes() {
		clientes->mostrar();
	}
	void mostrarEnvios() {
		envios->mostrar();
	}
	void registrarCliente(Cliente* nuevoCliente) {
		try {
			if (clientes->buscar(nuevoCliente->getCi(), Cliente::comparador) == nullptr)
			{
				clientes->agregarElemento(nuevoCliente);
			}
			else {
				throw ExcepcionClienteDupicado();
			}
		}catch (Excepcion err) {
			cout << err.getMensaje() << endl;
		}
		
	}
		
	void registrarEnvios(Envio* nuevoEnvio) {
		try {
			if (envios->buscar(nuevoEnvio->getNumero(), Envio::comparador) == nullptr)
			{
			envios->agregarElemento(nuevoEnvio);
			}
			else {
				throw EnvioDuplicadoExcepcion();
			}
		}
		catch (Excepcion err) {
			cout << err.getMensaje() << endl;
		}
		
	}
	void registrarEnvioACliente(string CiBuscado, Envio* nuevoEnvio) {
		try {
			if (clientes->buscar(CiBuscado, Cliente::comparador) != nullptr)
			{
				Cliente* clienteBuscado = clientes->buscar(CiBuscado, Cliente::comparador);
				nuevoEnvio->agregarClienteAEnvio(clienteBuscado);
			}
			else {
				throw ClienteNoEncontrado();
			}
		
		}
		catch (Excepcion err) {
			cout << err.getMensaje() << endl;
		}
	}
	void registrarPaqueteAEnvio(Paquete* paquete,string numero) {
		try {
			if (envios->buscar(numero, Envio::comparador) == nullptr)
			{
				throw EnvioNoEnconradoExcapcion();
				
			}
			else {
				Envio* encontrado = envios->buscar(numero, Envio::comparador);
				encontrado->agregarPaquetesAEnvio(paquete);
			}
		}
		catch (Excepcion err) {
			cout << err.getMensaje() << endl;
		}
	}

	void BuscarCliente(Cliente* clienteBuscado) {
		Cliente* clienteEncontrado=	clientes->buscar(clienteBuscado->getCi(), Cliente::comparador);
		clienteBuscado->mostrar();
	}
};
