
#include "SistemaPeluqueria.h"
#include "Atencion.h"
#include "ServicioBano.h"
#include "ServicioCorte.h"

#include "Perro.h"


int main() {
	SistemaPeluqueria* peluqueria = new SistemaPeluqueria("Patitas Felices", 10,10,10);

	cout << "--- 1. REGISTRO DE PERROS ---" << endl;
	peluqueria->registrarPerro(new Perro("P1", "Max","caniche", "grande"));
	peluqueria->registrarPerro(new Perro("P2", "Jose", "Labrador", "mediano"));
	peluqueria->registrarPerro(new Perro("P3", "Nacho", "golden", "pequeño"));
	//Excepcion
	peluqueria->registrarPerro(new Perro("P3", "fran", "Husky", "mediano"));


	cout << "\n--- 2. REGISTRO DE SERVICIOS---" << endl;
	peluqueria->registrarServicio(new ServicioBano("S1", "Servicio Bano", 10));
	peluqueria->registrarServicio(new ServicioCorte("S2", "Servicio Corte", 20));
	//Excepcion
	peluqueria->registrarServicio(new ServicioCorte("S2", "Servicio Corte", 15));


	cout << "\n--- 3. REGISTAR ATENCION ---" << endl;
	peluqueria->registrarAtencion("P1", "S1");
	peluqueria->registrarAtencion("P2", "S2");
	peluqueria->registrarAtencion("P1", "S2");

	//Excepcion
	peluqueria->registrarAtencion("P5", "S2");
	peluqueria->registrarAtencion("P2", "S5");


	cout << "\n--- 4. MOSTRAR ATENCION DE UN PERRO---" << endl;
	peluqueria->mostrarAtencionPerro("P1");
	//Exception
	peluqueria->mostrarAtencionPerro("P4");


	

	delete peluqueria;
	return 0;
}



