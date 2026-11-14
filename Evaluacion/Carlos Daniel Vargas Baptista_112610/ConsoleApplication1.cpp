#include<string>
#include <iostream>
#include"SistemaPeluqueria.h"
#include"Atencion.h"
#include"Perro.h"
#include"Servicio.h"
#include"ListaGenerica.h"
using namespace std;

int main(){
	SistemaPeluqueria* P1= new SistemaPeluqueria("Nombre", 20);
	//1
	P1->RegistrarPerro(new Perro("11", "Tyson", "Pastor Aleman", 60));
	P1->RegistrarPerro(new Perro("12", "Perla", "Golden", 50));
	P1->RegistrarPerro(new Perro("11", "Clon", "Pastor", 60));
	//2
	P1->RegistrarServicio(new Servicio("21", "Servicio1", "Banio"));
	P1->RegistrarServicio(new Servicio("22", "Servicio2", "Corte"));
	P1->RegistrarServicio(new Servicio("21", "ServicioClon", "Banio"));
	//3

	
	delete P1;
}

