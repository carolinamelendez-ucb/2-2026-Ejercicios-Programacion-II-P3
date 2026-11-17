#include <iostream>
#include "SistemaPeluqueria.h"


int main()
{
    try {
        SistemaPeluqueria* nuevoSistema = new SistemaPeluqueria("Peluqueria 1");

        Perro* perro1 = new Perro("123", "Perro 1", "Raza 1", "pequeno");
        Perro* perro2 = new Perro("456", "Perro 2", "Raza 2", "pequeno");
        Perro* perro3 = new Perro("789", "Perro 3", "Raza 3", "mediano");
        Perro* perro4 = new Perro("321", "Perro 4", "Raza 4", "mediano");
        Perro* perro5 = new Perro("654", "Perro 5", "Raza 5", "grande");
        Perro* perro6 = new Perro("987", "Perro 6", "Raza 6", "grande");

        Servicio* servicio1 = new ServicioBanio("11", "Servicio 1", 150);
        Servicio* servicio2 = new ServicioBanio("22", "Servicio 2", 250);

        Servicio* servicio3 = new ServicioCorte("33", "Servicio 3", 100);
        Servicio* servicio4 = new ServicioCorte("44", "Servicio 4", 120);

        nuevoSistema->registrarPerro(perro1);
        nuevoSistema->registrarPerro(perro2);
        nuevoSistema->registrarPerro(perro3);
        nuevoSistema->registrarPerro(perro4);
        nuevoSistema->registrarPerro(perro5);
        nuevoSistema->registrarPerro(perro6);

        nuevoSistema->registrarServicio(servicio1);
        nuevoSistema->registrarServicio(servicio2);
        nuevoSistema->registrarServicio(servicio3);
        nuevoSistema->registrarServicio(servicio4);

        nuevoSistema->registrarAtencion("123", "11");
        nuevoSistema->registrarAtencion("456", "22");

        nuevoSistema->mostrarAtencionesPerro("123");
    }
    catch (Exception& e)
    {
        cout << e.getMensaje() << endl;
    }
}
