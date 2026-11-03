#include "Envio.h"

Envio::Envio(string numeroEnvio, string fechaEnvio, int pesoMax, Cliente* cliente) {
	this->numeroEnvio = numeroEnvio;
	this->fechaEnvio = fechaEnvio;
	this->pesoMax = pesoMax;
	this->cliente = cliente;
	this->listaPaquetes = new ListaGenerica<PaqueteNormal>(10);
}

void Envio::registrarPaquete(PaqueteNormal* nuevoPaquete) {
	listaPaquetes->agregarElemento(nuevoPaquete);
}

string Envio::getIdentificador() {
	return cliente->getIdentificador();
}

void Envio::mostrarDatos() {
	cout << "Numero Envio: " << numeroEnvio << endl;
	cout << "Fecha Envio: " << fechaEnvio << endl;
	cout << "Peso Max: " << endl;
	cliente->mostrarDatos();
	cout << endl;
	listaPaquetes->mostrarElementos();
	cout << endl;
}
