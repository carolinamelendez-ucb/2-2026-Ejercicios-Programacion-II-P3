#include <string>
#include <iostream>
#include "Servicio.h"
#include "Perro.h"
#include "ListaGenerica.h"
#include "Atencion.h"
#include "Exception.h"
#include "ServicioBano.h"
#include "ServicioCorte.h"
#include "SistemaPeluqueria.h"
#include "ExceptionCodigoPerroDuplicado.h"
using namespace std;

int main()
{
	SistemaPeluqueria sistema = SistemaPeluqueria(20);
	Perro* P1 = new Perro("4434", "toni", "salchicha", "Pequenio");
	Perro* P2 = new Perro("2324", "thor", "golden", "Grande");
	Perro* P3 = new Perro("4434", "picaron", "lobo", "Grande");
	Servicio* S1 = new ServicioBano("888");
	Servicio* S2 = new ServicioCorte("5555");
	Servicio* S3 = new ServicioBano("888");
	Atencion* A1 = new Atencion("65464");
	Atencion* A2 = new Atencion("3232");
	Atencion* A3 = new Atencion("3030");
	sistema.agregarPerro(P1);
	sistema.agregarPerro(P2);
	sistema.agregarPerro(P3);
	sistema.agregarServicio(S1);
	sistema.agregarServicio(S2);
	sistema.agregarServicio(S3);
	sistema.mostrarPerro();


	cout << "*************************************************" << endl;
	cout << "*************************************************" << endl;
	cout << "*************************************************" << endl;

	sistema.registrarAtencion(A1, "2324", "5555");
	sistema.registrarAtencion(A2, "2324", "5555");
	sistema.registrarAtencion(A1, "233", "343243");
	sistema.registrarAtencion(A2, "233", "3433");
	sistema.registrarAtencion(A3, "4434", "867");
	sistema.registrarAtencion(A3, "4434", "888");
	sistema.mostrarAtenciones();

}


