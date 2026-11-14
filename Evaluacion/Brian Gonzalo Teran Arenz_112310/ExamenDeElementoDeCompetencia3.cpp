// ExamenDeElementoDeCompetencia3.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include<string>
#include"SistemaPeluqueria.h"
using namespace std;

int main()
{
	SistemaPeluqueria* Barnie = new SistemaPeluqueria("Barnie");
	Barnie->AgregarPerro(new Perro("125agy","Bongo","Canes","Mediano"));
	Barnie->AgregarPerro(new Perro("245flp", "Pablo", "Lobradero", "Grande"));
	Barnie->AgregarPerro(new Perro("481ekl", "Broly", "Pomerania", "pequenio"));
	Barnie->AgregarServicio(new ServicioBano("13886sga","Relax",75));
	Barnie->AgregarServicio(new ServicioBano("13886sga", "Relax", 75));
	Barnie->AgregarServicio(new ServicioBano("13586sga", "Formax", 85));
	Barnie->AgregarServicio(new ServicioCorte("85664aqg", "Floarl", 85));
	Barnie->AgregarAtencion(new Atencion("98avgca"));
	Barnie->AgregarAtencion(new Atencion("12njbsa"));
	Barnie->AgregarAtencion(new Atencion("11dbyay"));
	Barnie->AsignarServicioyPerroaAtencion("13886sga", "125agy", "98avgca");
	Barnie->AsignarServicioyPerroaAtencion("13586sga", "245flp", "11dbyay");
	Barnie->AsignarServicioyPerroaAtencion("85664aqg", "125agy", "12njbsa");
		//Barnie->Mostar();
	Barnie->MostrarAtencion();
	cout << endl;
	Barnie->BuscarInformacionDeUnSoloPerro("481ekl");
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
