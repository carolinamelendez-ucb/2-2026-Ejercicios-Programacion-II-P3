#include <string>
#include <iostream>
#include "Cliente.h"
#include "Paquete.h"
#include "PaqueteExpress.h"
#include "PaqueteFragil.h"
#include "PaqueteNormal.h"
#include "ListaGenerica.h"
#include "Exception.h"
#include "PaqueteDuplicadoException.h"
#include "ClienteDuplicadoException.h"
#include "Envio.h"
#include "SistemaEnvios.h"
using namespace std;

int main()
{
    Cliente* C1 = new Cliente("4444", "messi", 63899664, "el abra");
    Cliente* C2 = new Cliente("5555", "turan", 32323233, "Sacaba");
    Cliente* C3 = new Cliente("4444", "pepe", 63232323, "America");

    Paquete* P1 = new PaqueteNormal("PPPP", "MANDO", 4);
    Paquete* P2 = new PaqueteExpress(20,"yyyy", "MANDO", 12);
    Paquete* P3 = new PaqueteFragil("ALTO","PPPP", "MANDO", 4);
    Paquete* P4 = new PaqueteFragil("ALTO", "RRRR", "MANDO", 4);


    Envio* E1 = new Envio("22", "martes", 10, 10);

    SistemaEnvio sistema = SistemaEnvio("QuickExpress", 20);

    sistema.agregarCliente(C1);
    sistema.agregarCliente(C2);
    sistema.agregarCliente(C3);
    sistema.agregarEnvios(E1);
    sistema.agregarEnvios(E1);
    sistema.mostrarClientes();

    cout << "---------------------------------------------------------------------------------------" << endl;
    sistema.agregarClienteAEnvio("9899", "22");
    sistema.agregarClienteAEnvio("4444", "22");
    sistema.agregarClienteAEnvio("4444", "222");
    sistema.registrarPaquetesAEnvio("22", P1);
    sistema.registrarPaquetesAEnvio("22", P1);
    sistema.registrarPaquetesAEnvio("22", P2);
    sistema.registrarPaquetesAEnvio("22", P3);
    sistema.registrarPaquetesAEnvio("22", P4);
    sistema.mostrarEnvios();
    cout << "--------------------------------------------------------------------------" << endl;

    sistema.mostrarClienteEspecifico("4444");
















}


