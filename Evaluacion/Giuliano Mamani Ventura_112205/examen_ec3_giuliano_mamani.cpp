#include "SistemaPeluqueria.h"

int main() {
	SistemaPeluqueria* krico = new SistemaPeluqueria("Krico");
	//------------------------------------------------1------------------------------------------------
	//agregando perros
	krico->agregarPerro(new Perro("501", "max", "golden", "grande"));
	krico->agregarPerro(new Perro("502", "bolt", "pastor aleman", "mediano"));
	krico->agregarPerro(new Perro("503", "evo", "ciberiano", "mediano"));
	krico->agregarPerro(new Perro("504", "cholo", "chiwaw", "pequenio"));

	//perro dupicado
	krico->agregarPerro(new Perro("501", "max", "golden", "grande"));

	//------------------------------------------------2------------------------------------------------
	//agregando servicios
	krico->agregarServicio(new ServicioCorte("301", "servicio corte", 20));
	krico->agregarServicio(new ServicioBano("201", "servicio bano", 14));

	//duplicado de servicio de corte
	krico->agregarServicio(new ServicioCorte("301", "servicio corte", 20));

	//------------------------------------------------3------------------------------------------------
	//agregando atenciones
	krico->agregarAtencion("501", "301", new Atencion("901"));
	krico->agregarAtencion("502", "301", new Atencion("902"));
	krico->agregarAtencion("501", "201", new Atencion("903"));

	//Perro no existe
	krico->agregarAtencion("001", "301", new Atencion("901"));

	//servicio no existe
	krico->agregarAtencion("501", "001", new Atencion("901"));

	//------------------------------------------------4------------------------------------------------
	//mostrar dtos de perro que existe
	krico->mostrarPerro("501");

	//mostrar dtos de perro que no existe
	krico->mostrarPerro("001");

	//------------------------------------------------6------------------------------------------------
	//mostrar todos los perros alfabeticamente
	krico->mostrarTodosPerros();

	delete krico;
	return 0;
}