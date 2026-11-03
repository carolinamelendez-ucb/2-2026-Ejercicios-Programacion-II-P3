#pragma once
#include"ListaGenerica.h"
#include"PaqueteNormal.h"
#include"Cliente.h"
#include"Envio.h"
class SistemaEnvios
{
private:
	ListaGenerica<PaqueteNormal>* paquetes;
	ListaGenerica<Cliente>* clientes;
	ListaGenerica<Envio>* envios;
	string nombre;
public:
	SistemaEnvios(string nombre, int capMaxPaquetes,int capMaxCliente,int capMaxEnvios) {
		this->paquetes = new ListaGenerica<PaqueteNormal>(capMaxPaquetes);
		this->clientes = new ListaGenerica<Cliente>(capMaxCliente);
		this->envios = new ListaGenerica<Envio>(capMaxEnvios);
		this->nombre = nombre;
	}
	void registrarPaquetes(PaqueteNormal* nuevoPaquete) {
		string codigo = nuevoPaquete->getCodigo();
		try {
			PaqueteNormal* duplicado = paquetes->buscar(codigo, PaqueteNormal::compararCodigo);
			if (duplicado != nullptr) {
				throw runtime_error("El codigo ya esta registrado");
			}
			paquetes->agregar(nuevoPaquete);
		}
		catch (const exception& e) {
			cout << "Error: " << e.what() << endl;
		}
		paquetes->agregar(nuevoPaquete);
	}
	void mostrarPaquetes() {
		paquetes->mostrar();
	}

	void registrarClientes(Cliente* nuevoCliente) {
		string ci = nuevoCliente->getCi();
		try {
			Cliente* duplicado = clientes->buscar(ci, Cliente::compararCi);
			if (duplicado != nullptr) {
				throw runtime_error("El CI ya esta registrado");
			}
			clientes->agregar(nuevoCliente);
		}
		catch (const exception& e) {
			cout << "Error: " << e.what() << endl;
		}
		clientes->agregar(nuevoCliente);
	}

	void mostrarClientes() {
		clientes->mostrar();
	}
	void registrarEnvio(Envio* nuevoEnvio) {
		string numero = nuevoEnvio->getNumero();
		try {
			Envio* duplicado = envios->buscar(numero, Envio::compararNumero);
			if (duplicado != nullptr) {
				throw runtime_error("El envio con ese numero ya esta registrado");
			}
			envios->agregar(nuevoEnvio);
		}
		catch (const exception& e) {
			cout << "Error: " << e.what() << endl;
		}
		envios->agregar(nuevoEnvio);
	}
	void registrarClienteAEnvio(string numeroEnvio,string ci) {
		Envio* envio= envios->buscar(numeroEnvio, Envio::compararNumero);
		Cliente* cliente= clientes->buscar(ci, Cliente::compararCi);
		try {
			if (envio == nullptr) {
				throw runtime_error("El envio no existe");
			}
			if (cliente == nullptr) {
				throw runtime_error("El cliente no existe");
			}
			envio->regisrarCliente(cliente);

		}
		catch (const exception& e) {
			cout << "Error: " << e.what() << endl;
		}

	}
	void costoTotal() {
		double total = paquetes->calcularTotal();
		cout << "el costo total es: " << total<<endl;
	}
	void mostrarOrdenado() {
		cout << endl;
		cout << "ORDENADO DE FORMA DESCENDENTE: " << endl;
		cout << "************************************************" << endl;
		paquetes->ordenar(PaqueteNormal::nombreCostoMenor);
		paquetes->mostrar();
	}

};

