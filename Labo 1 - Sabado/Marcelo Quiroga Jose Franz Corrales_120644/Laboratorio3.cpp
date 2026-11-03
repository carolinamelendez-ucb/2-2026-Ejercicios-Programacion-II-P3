#include <iostream>
#include "SistemaEnvios.h"

int main()
{
	Cliente* cliente1 = new Cliente("123", "cliente 1", 555, "direccion 1");
	Cliente* cliente2 = new Cliente("456", "cliente 2", 666, "direccion 2");
	Cliente* cliente3 = new Cliente("789", "cliente 3", 777, "direccion 3");

	PaqueteNormal* paquete1 = new PaqueteNormal("8989", "descripcion 1", 10, 3);
	PaqueteNormal* paquete2 = new PaqueteExpress("8989", "descripcion 1", 20, 2,25);
	PaqueteNormal* paquete3 = new PaqueteFragil("8989", "descripcion 1", 30, 1,2);

	Envio* envio1 = new Envio("787878", "01/01/01", 100, cliente1);
	Envio* envio2 = new Envio("898989", "01/01/01", 100, cliente2);
	Envio* envio3 = new Envio("101010", "01/01/01", 100, cliente3);

	SistemaEnvios* sistema1 = new SistemaEnvios("Empresa 1");

	try {
		sistema1->registrarCliente(cliente1);
		sistema1->registrarCliente(cliente2);
	}
	catch (ClienteDuplicadoException()) {
		sistema1->registrarCliente(cliente1);
	}

	sistema1->registrarEnvio(envio1);
	sistema1->registrarEnvio(envio2);
	sistema1->registrarEnvio(envio3);

	sistema1->registrarPaquete(envio1, paquete1);
	sistema1->registrarPaquete(envio1, paquete2);

	
	sistema1->BuscarCliente("123");
}
