
#include"SistemaParqueo.h"
#include <iostream>

int main()
{
	SistemaParqueo* nuevoParqueo = new SistemaParqueo("Aranjuez", "America", 2);
	nuevoParqueo->registrarEstacionamiento(new Espacio("1023", 3, "a12"));


	nuevoParqueo->registrarVehiculo(new Vehiculo("1023", "mazda", "2013", "Gwagon"));


	nuevoParqueo->mostrarVehiulos();
}
