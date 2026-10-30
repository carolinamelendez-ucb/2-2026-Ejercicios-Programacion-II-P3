#include "SistemaParqueo.h"

int main()
{
	SistemaParqueo* parqueo = new SistemaParqueo(" Las Torres", "Av. Principal", 10);

	parqueo->registrarEspacio(new Espacio("01", 1, "Norte"));
	parqueo->registrarEspacio(new Espacio("02", 1, "Norte"));
	parqueo->registrarEspacio(new Espacio("03", 1, "Norte"));
	parqueo->registrarEspacio(new Espacio("04", 1, "Norte"));

	parqueo->registrarVehiculo(new Vehiculo("111", "Toyota", "Corolla", "Auto"));
	parqueo->registrarVehiculo(new Vehiculo("222", "Suzuki", "Swift", "Auto"));

	parqueo->registrarVehiculo(new Vehiculo("111", "Nissan", "Sentra", "Auto"));

	parqueo->asignarEspacioAutomatico("111");
	parqueo->asignarEspacioAutomatico("222");
	parqueo->asignarEspacioAutomatico("000");


	parqueo->buscarVehiculoPorPlaca("111");
	parqueo->mostrarVehiculosEstacionados();
	//parqueo->mostrarEspaciosDisponibles();

	parqueo->buscarEspacioPorEstado();

	delete parqueo;
	return 0;
}