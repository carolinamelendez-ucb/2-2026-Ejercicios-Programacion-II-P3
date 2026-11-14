// Examen.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "Perro.h"
#include "PatitasFelices.h"
#include "ServicioBano.h"
#include "ServicioCorte.h"

int main()
{
    
    PatitasFelices patfel(5,5,5);
    Perro* perr1 = new Perro("a24", "Dwight", "Pomerania", 4);
    Perro* perr2 = new Perro("a24", "Gym", "Pomerania", 5);
    cout << "------------Ejercicio 1--------------" << endl;
    patfel.RegistrarPerros(perr1);
   patfel.RegistrarPerros(perr2); //perro duplicado
    patfel.Mostrarperro();
    cout << "-------------------Ejercicio 2------------" << endl;
    ServicioBano* serba = new ServicioBano("123as", "Banio Floral", 90);
    ServicioBano* serba2 = new ServicioBano("123as", "Banio termal", 100);
    ServicioCorte* serba3 = new ServicioCorte("43as", "corte Honguito", 100);
    patfel.Registrarservicios(serba);
    patfel.Registrarservicios(serba3);
    patfel.Registrarservicios(serba2); //servicio duplicado
    patfel.MostrarServicios();
    cout << "-------------------Ejercico 3----------------" << endl;
    patfel.RegistraraTENCION("a24","123as");
    patfel.RegistraraTENCION("a42", "342f");
    patfel.RegistraraTENCION("a24", "43as");
    patfel.MostrarAtencion();
    cout << "----------------------ejercicio 4-----------------" << endl;
    patfel.mostraratencionesDeUnperro("a24");
    patfel.mostraratencionesDeUnperro("asd2");//perro no existente
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
