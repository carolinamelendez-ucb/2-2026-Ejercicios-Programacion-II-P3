#include "SistemaPeluqueria.h"
#include "ServicioBano.h"
#include "ServicioCorte.h"

int main()
{
    Perro* perro1 = new Perro("1", "Max", "Rottwailer", "Grande");
    Perro* perro2 = new Perro("2", "Scott", "Beagle", "Pequeno");
    Perro* perro21 = new Perro("2", "Maderito", "Bulldog", "Mediano");
    Perro* perro3 = new Perro("3", "Jhon", "Caniche", "Pequeno");
    Perro* perro4 = new Perro("4", "Firulais", "Perro Peruano", "Mediano");

    Servicio* servicio1 = new ServicioBano("01");
    Servicio* servicio2 = new ServicioCorte("02");
    Servicio* servicio21 = new ServicioBano("01");

    Atencion* atencion1 = new Atencion("a", perro1, servicio1);
    Atencion* atencion2 = new Atencion("b", perro2, servicio2);

    SistemaPeluqueria* peluqueria = new SistemaPeluqueria("Perlas");

    peluqueria->agregarPerroAlSistema(perro1);
    peluqueria->agregarPerroAlSistema(perro2);
    peluqueria->agregarPerroAlSistema(perro21);
    peluqueria->agregarPerroAlSistema(perro3);
    peluqueria->agregarPerroAlSistema(perro4);

    peluqueria->agregarServicioAlSistema(servicio1);
    peluqueria->agregarServicioAlSistema(servicio2);
    peluqueria->agregarServicioAlSistema(servicio21);

    peluqueria->agregarAtencionAlSistema(atencion1);
    peluqueria->agregarAtencionAlSistema(atencion2);

    peluqueria->mostrarSistema();
}