#include <iostream>
#include "Envio.h"
using namespace std;

int main() {
    cout << "EJERCICIO 5 - ENVIO DE PAQUETE" << endl;
    Remitente* remitente = new Remitente("1234567", "Juan Perez");
    cout << endl << "REMITENTE" << endl;
    remitente->mostrar();

    cout << endl << "TIPO DE REMITENTE INCORRECTO" << endl;
    remitente->setTipoRemitente("CLIENTE");

    cout << endl << "CAMBIAR A EMPRESA" << endl;
    remitente->setTipoRemitente("EMPRESA");
    remitente->mostrar();

    Paquete* paquete = new Paquete("P001", 12, "NORMAL");

    cout << endl << "PESO INCORRECTO" << endl;
    paquete->setPeso(-5);

    cout << endl << "CAMBIAR PESO" << endl;
    paquete->setPeso(12);

    cout << endl << "PAQUETE" << endl;
    paquete->mostrar();

    cout << endl << "TIPO DE ENVIO INCORRECTO" << endl;
    paquete->setTipoEnvio("RAPIDO");

    Envio* envio = new Envio("E001", "La Paz", remitente, paquete, 100);

    cout << endl << "ENVIO" << endl;
    envio->mostrar();

    cout << endl << "Costo base: " << envio->calcularCostoBase() << endl;

    cout << "Costo final: " << envio->calcularCostoFinal() << endl;

    cout << endl << "DISTANCIA INCORRECTA" << endl;
    envio->setDistancia(-20);

    cout << endl << "CAMBIAR DISTANCIA" << endl;
    envio->setDistancia(150);
    cout << "Nuevo costo: " << envio->calcularCostoFinal() << endl;

    cout << endl << "CAMBIAR TIPO DE ENVIO A EXPRESS" << endl;
    paquete->setTipoEnvio("EXPRESS");
    cout << "Nuevo costo: " << envio->calcularCostoFinal() << endl;

    cout << endl << "INFORMACION FINAL" << endl;
    envio->mostrar();

    delete envio;
    delete paquete;
    delete remitente;

    return 0;
}
