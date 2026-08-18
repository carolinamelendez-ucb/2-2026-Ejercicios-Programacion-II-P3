#include <string>
#include <iostream>
using namespace std;
class Cliente {
private:
    int CI;
    string nombre;
    int aniosAntiguedad;
public:
    Cliente() {
        CI = 0;
        nombre = "";
        aniosAntiguedad = 0;
    }
    Cliente(int ci, string nombre) {
        CI = ci;
        nombre = nombre;
        aniosAntiguedad = 0;
    }

    Cliente(int CI, const string& nombre, int aniosAntiguedad)
        : CI(CI), nombre(nombre), aniosAntiguedad(aniosAntiguedad)
    {
    }
};
class Vehiculo {
private:
    string placa;
    string modelo;
    int tarifaDia;
public:
    Vehiculo() {
        placa = "";
        modelo = "";
        tarifaDia = 0;
    }
    Vehiculo(const string& placa, const string& modelo, int tarifaDia)
        : placa(placa), modelo(modelo), tarifaDia(tarifaDia)
    {
    }
};
class Reserva {
private:
    int fechaInicio;
    int cantidadDias;
    Cliente* cliente;
    Vehiculo* veiculo;
    int costoBase;
public:


    Reserva(int fechaInicio, int cantidadDias, Cliente* cliente, Vehiculo* veiculo, int costoBase)
        : fechaInicio(fechaInicio), cantidadDias(cantidadDias), cliente(cliente), veiculo(veiculo), costoBase(costoBase)
    {
    }

};