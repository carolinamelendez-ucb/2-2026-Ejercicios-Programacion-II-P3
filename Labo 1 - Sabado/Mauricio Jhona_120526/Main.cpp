// MauriJhona.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "SistemaDeEnvios.h"
#include "Cliente.h"

int main()
{
    Cliente* cli1 = new Cliente("123", "pedro", 67646123, "America");
    Cliente* cli2 = new Cliente("123", "jose", 654246123, "dorbigni");
    Cliente* cli3 = new Cliente("2421", "manuel", 3512351253, "dorbigni");

    Envio* envio1 = new Envio("1342", "12/23/26", 30);
    Envio* envio2 = new Envio("1342", "12/23/26", 40);

    SistemaDeEnvios* SisEnv = new SistemaDeEnvios(10,10,10);
    SisEnv->RegistrarClientes(cli1);
    SisEnv->MostrarClientes();

    SisEnv->RegistrarClientes(cli2);


    SisEnv->RegistrarclienteEnvio(cli1, envio1);

    SisEnv->RegistrarclienteEnvio(cli2, envio2);


    SisEnv->MostrarEnvios();
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
