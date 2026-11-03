// ConsoleApplication1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include"SistemaEnvios.h"
#include"PaqueteExpress.h"
#include"PaqueteFragil.h"

int main()
{
	SistemaEnvios* s1 = new SistemaEnvios("UCB", 20, 30, 30);
	s1->registrarPaquetes(new PaqueteFragil("PF1", "MEDIO", 10, 10));
	s1->registrarPaquetes(new PaqueteExpress("PE2", "Express", 20, 10, 10));
	s1->registrarPaquetes(new PaqueteExpress("PE2", "Express", 20, 10, 24));
	s1->registrarPaquetes(new PaqueteExpress("PE4", "Express", 20, 10, 50));
	s1->registrarPaquetes(new PaqueteNormal("PE5", "Paquete normal", 20, 10));

	s1->registrarClientes(new Cliente("123", "JHAIR", 2030, "Circu"));
	s1->registrarClientes(new Cliente("123", "JHAIR", 2030, "Circu"));

	s1->registrarEnvio(new Envio("E1", "10-26", 30, 30));
	s1->registrarEnvio(new Envio("E1", "10-26", 30, 30));
	s1->registrarClienteAEnvio("E1", "123");
	s1->registrarClienteAEnvio("E2", "123");
	s1->registrarClienteAEnvio("E1", "124");
	s1->mostrarClientes();
	s1->mostrarPaquetes();


	s1->costoTotal();

	s1->mostrarOrdenado();
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
