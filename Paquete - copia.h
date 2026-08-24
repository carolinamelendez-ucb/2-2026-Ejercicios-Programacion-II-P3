#ifndef PAQUETE_H
#define PAQUETE_H

#include <string>

using namespace std;

enum TipoEnvio {
    NORMAL,
    EXPRESS
};

class Paquete {

private:
    string codigo;
    double peso;
    TipoEnvio tipoEnvio;

public:

    Paquete(string codigo, double peso, TipoEnvio tipoEnvio);

    void setPeso(double nuevoPeso);
    void setTipoEnvio(TipoEnvio nuevoTipo);

    string getCodigo();
    double getPeso();
    TipoEnvio getTipoEnvio();

    void mostrarInformacion();
};

string mostrarTipoEnvio(TipoEnvio tipo);

#endif