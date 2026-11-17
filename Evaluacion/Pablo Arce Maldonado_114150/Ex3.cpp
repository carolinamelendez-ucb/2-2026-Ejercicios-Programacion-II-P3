#include <iostream>
#include <string>
#include "ListaGenerica.h"
#include "Exception.h"
#include "PerroDuplicadoException.h"
#include "Perro.h"
#include "ServicioDuplicadoException.h"
#include "ServicioBano.h"
#include "ServicioCorte.h"
#include "Servicios.h"
#include "SistemaPeluqueria.h"
#include"ServicioNoEncontrado.h"
#include "PerroNoEncontrado.h"

using namespace std;

int main()
{
    SistemaPeluqueria* sistema = new SistemaPeluqueria("Cachuchin Dog Barber", 50, 2);

    try {
        sistema->registrarServicios(new ServiciosCorte());
    } catch (Exception& err) { cout << ">> Error: " << err.getMensaje() << endl; }

    try {
        sistema->registrarPerro(new Perro("123", "Doggo", "delmer", "pequeño"));
    } catch (Exception& err) { cout << ">> Error: " << err.getMensaje() << endl; }

    try {
        sistema->registrarPerro(new Perro("123","Doggi", "SinRaza", "pequeño"));
    } catch (Exception& err) { cout << ">> Error: " << err.getMensaje() << endl; }

    try { sistema->mostrarInformacionPerro("123"); } catch (Exception& err) { cout << ">> Error: " << err.getMensaje() << endl; }

    delete sistema;
    return 0;
}

