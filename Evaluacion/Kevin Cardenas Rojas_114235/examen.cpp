
#include <iostream>
#include<string>
#include "SistemaPeluqueria.h"

int main()
{
	SistemaPeluqueria* sistema = new SistemaPeluqueria("Patitas felices", 6);


	sistema->RegistrarPerro(new Perro("1", "max", "pastor", "grande"));
	sistema->RegistrarServicio(new Servicio("1", "Bano"));
	

	//duplicado
	sistema->RegistrarPerro(new Perro("1", "max", "xd", "pequenio"));
	//servicio duplicado
	sistema->RegistrarServicio(new Servicio("1", "xd"));

   
}

