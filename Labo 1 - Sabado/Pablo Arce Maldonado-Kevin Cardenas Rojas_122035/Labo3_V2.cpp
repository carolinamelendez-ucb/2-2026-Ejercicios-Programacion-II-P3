#include <iostream>
#include <string>
#include "ListaGenerica.h"
#include "Cliente.h"
#include "Envio.h"
#include "exception.h"
#include"SistemaEnvios.h"
using namespace std;
int main()
{ 

    SistemaEnvios* sistema = new SistemaEnvios("Sistema Principal", 3);

 
    sistema->registrar(new Cliente(9534449, "Kevin", 712472,"quillacollo"));
    sistema->registrarEnvio(new Envio(1111, "mayo", 67.67, new Cliente(9534449, "Kevin", 712472, "quillacollo")));
  
    sistema->buscarYMostrar(9534449);
 
    delete sistema;
}