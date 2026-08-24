#include <iostream>
#include <iomanip>

#include "Remitente.h"
#include "Paquete.h"
#include "Envio.h"

using namespace std;

int main() {

    cout << fixed << setprecision(2);


    // ==========================================
    // CREAR REMITENTE
    // ==========================================

    Remitente remitente1(
        "12345678",
        "Juan Perez"
    );

    remitente1.mostrarInformacion();


    // ==========================================
    // CAMBIAR REMITENTE A EMPRESA
    // ==========================================

    cout << endl;

    remitente1.setTipoRemitente(EMPRESA);

    remitente1.mostrarInformacion();


    // ==========================================
    // CREAR PAQUETE
    // ==========================================

    cout << endl;

    Paquete paquete1(
        "PKG-001",
        12,
        NORMAL
    );

    paquete1.mostrarInformacion();


    // ==========================================
    // MODIFICAR PESO
    // ==========================================

    cout << endl;

    paquete1.setPeso(15);

    paquete1.mostrarInformacion();


    // ==========================================
    // CREAR ENVIO
    // ==========================================

    cout << endl;

    Envio envio1(
        1001,
        "Cochabamba",
        &remitente1,
        &paquete1,
        200
    );


    // ==========================================
    // MOSTRAR ENVIO
    // ==========================================

    envio1.mostrarInformacion();


    // ==========================================
    // CAMBIAR A EXPRESS
    // ==========================================

    cout << endl;

    cout << "Cambiando a envio EXPRESS..."
        << endl;

    envio1.setTipoEnvio(EXPRESS);

    cout << "Nuevo costo: $"
        << envio1.getCosto()
        << endl;


    // ==========================================
    // CAMBIAR DISTANCIA
    // ==========================================

    cout << endl;

    cout << "Cambiando distancia a 300 km..."
        << endl;

    envio1.setDistancia(300);

    cout << "Nuevo costo: $"
        << envio1.getCosto()
        << endl;


    // ==========================================
    // CAMBIAR REMITENTE
    // ==========================================

    cout << endl;

    cout << "Cambiando remitente a PARTICULAR..."
        << endl;

    envio1.setTipoRemitente(PARTICULAR);

    cout << "Nuevo costo: $"
        << envio1.getCosto()
        << endl;


    // ==========================================
    // INFORMACION FINAL
    // ==========================================

    cout << endl;

    envio1.mostrarInformacion();


    return 0;
}