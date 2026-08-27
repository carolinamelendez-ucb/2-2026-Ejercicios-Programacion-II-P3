#ifndef AUTOR_H
#define AUTOR_H

#include <string>

using namespace std;

class Autor {

private:

    string nombre;
    string nacionalidad;
    int cantidadLibrosPublicados;

public:

    Autor();

    Autor(string nombre, string nacionalidad, int cantidadLibrosPublicados);

    string getNombre();
    string getNacionalidad();
    int getCantidadLibrosPublicados();

    void setCantidadLibrosPublicados(int cantidad);

    void mostrarInformacion();
};

#endif