#ifndef REMITENTE_H
#define REMITENTE_H

#include <string>

using namespace std;

enum TipoRemitente {
    PARTICULAR,
    EMPRESA
};

class Remitente {

private:
    string ci;
    string nombre;
    TipoRemitente tipoRemitente;

public:

    Remitente(string ci, string nombre);

    void setTipoRemitente(TipoRemitente nuevoTipo);

    string getCi();
    string getNombre();
    TipoRemitente getTipoRemitente();

    void mostrarInformacion();
};

string mostrarTipoRemitente(TipoRemitente tipo);

#endif