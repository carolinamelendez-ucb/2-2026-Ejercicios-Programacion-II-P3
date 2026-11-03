#include "SistemaEnvios.h"

SistemaEnvios::SistemaEnvios(string nombreEmpresa) {
	this->nombreEmpresa = nombreEmpresa;
	this->listaClientes = new ListaGenerica<Cliente>(50);
	this->listaEnvios = new ListaGenerica<Envio>(50);
}

void SistemaEnvios::registrarCliente(Cliente* nuevoCliente) {
	if (listaClientes->buscarElementos(nuevoCliente->getIdentificador()) == true) {
		ClienteDuplicadoException();
	}
	else {
		listaClientes->agregarElemento(nuevoCliente);
	}
}

void SistemaEnvios::registrarEnvio(Envio* nuevoEnvio) {
	listaEnvios->agregarElemento(nuevoEnvio);
}

void SistemaEnvios::registrarPaquete(Envio* envio,PaqueteNormal* nuevoPaquete) {
	envio->registrarPaquete(nuevoPaquete);
}

void SistemaEnvios::BuscarCliente(string buscarIdentificador) {
	listaEnvios->mostrarElementoBuscado(buscarIdentificador);
}