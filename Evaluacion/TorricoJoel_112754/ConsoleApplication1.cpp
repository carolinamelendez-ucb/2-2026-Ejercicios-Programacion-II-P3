// ConsoleApplication1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include"SistemaPeluqueria.h"
#include"ServicioBano.h"
#include"ServicioCorte.h"
int main()
{
    SistemaPeluqueria* s1 = new SistemaPeluqueria("Patitas", 30, 20, 5);
    s1->registrarPerro(new Perro("123", "Romeo", "PEQUENIO"));
    s1->registrarPerro(new Perro("124", "Perla", "GRANDE"));
    s1->registrarPerro(new Perro("125", "Lola", "MEDIANO"));
    s1->registrarPerro(new Perro("126", "A", "MEDIANO"));//para el ordenamiento
    s1->registrarPerro(new Perro("127", "Z", "MEDIANO"));//para el ordenamiento
    s1->registrarPerro(new Perro("123", "romeo", "pequenio"));//perro duplicado

    s1->registrarServicio(new ServicioBano("SB1", "Servicio Banio", 20));
    s1->registrarServicio(new ServicioCorte("SC1", "Servicio Corte", 30));
    s1->registrarServicio(new ServicioBano("SB1", "Servicio Banio", 20)); // servicio banio duplicado
    s1->registrarServicio(new ServicioBano("SC1", "Servicio Banio", 20)); //servicio corte duplicado

    s1->registrarAtencion("123", "SB1", new Atencion("Atencion1"));
    s1->registrarAtencion("124", "SC1", new Atencion("Atencion2"));
    s1->registrarAtencion("125", "SB1", new Atencion("Atencion3"));
    s1->registrarAtencion("123", "SB1", new Atencion("Atencion1"));// atencion duplicado
    s1->registrarAtencion("125", "SB1", new Atencion("Atencion2"));//el perro no existe
    s1->registrarAtencion("123", "SB5", new Atencion("Atencion2"));// el servicio no existe

    cout << "*************ATENCIONES POR CODIGO DE PERRO*********************" << endl;
    s1->mostrarAtencionesDeUnPerro("123");
    s1->mostrarAtencionesDeUnPerro("124");
    s1->mostrarAtencionesDeUnPerro("125");

    cout << "---------------PERROS ORDENADOS POR EL NOMBRE----------------" << endl;
    s1->mostrarPerrosOrdenados();


}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
