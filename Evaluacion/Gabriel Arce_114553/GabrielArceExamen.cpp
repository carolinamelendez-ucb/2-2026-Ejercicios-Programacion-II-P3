
#include"SistemaPeluqueria.h"
#include"ServicioBano.h"
#include"ServicioCorte.h"




int main()
{
	Perro* p1 = new Perro("01", "Max", "Golde", "GRANDE");
	Perro* p2 = new Perro("01", "Lui", "Golde", "MEDIANO");
	Servicio* s1 = new ServicioBano("02", "BanioDU", 15);
	Servicio* s2 = new ServicioCorte("02", "Cortesito", 20);
	SistemaPeluqueria* sistema = new SistemaPeluqueria("PelitosPet", 5);

	//1 Perro duplicado
	sistema->agregarPerro(p1);
	sistema->agregarPerro(p2);
	cout << endl;
	sistema->mostrarPerros();

	//2 servicio duplicado
	sistema->agregarServicio(s1);
	sistema->mostrarSercicios();
	sistema->agregarServicio(s2);
	sistema->mostrarSercicios();
	cout << endl;
	//3 Atencion
	sistema->agregarAtencion("01", "01", "02");
	sistema->agregarAtencion("02", "02", "02");
	sistema->agregarAtencion("03", "01", "03");
	sistema->agregarAtencion("04", "01", "02");
	sistema->mostrarAtenciones();

	//4 BuscarPerro
	/*sistema->buscarAtencionesPerro("01");
	sistema->buscarAtencionesPerro("04");*/
	sistema->mostrarDatosUnperro("01");
}

