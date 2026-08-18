#include <iostream>
#include <string>

using namespace std;

class Cliente 
{
private:
    int ci;
    string nombre;
    int antiguedad;
public:
    Cliente()
    {
        ci = 0;
        nombre = "";
        antiguedad = 0;
    }
    Cliente(int ci, string nombre, int antiguedad)
    {
        this->antiguedad = antiguedad;
        this->ci = ci;
        this->nombre = nombre;
    }
};

class Vehiculo
{
private:
    string placa;
    string modelo;
    int tarifaDia;
public:
    Vehiculo()
    {
        placa = "";
        modelo = "";
        tarifaDia = 0;
    }
    Vehiculo(string placa, string modelo, int tarfiaDia)
    {
        this->placa = placa;
        this->modelo = modelo;
        this->tarifaDia = tarfiaDia;
    }
};

class Reserva
{
private:
    int fechaInicio;
    int cantDias;
    int costBase;
    Cliente* cliente;
    Vehiculo* vehiculo;
public:
    Reserva()
    {
        fechaInicio = 0;
        cantDias = 0;
        costBase = 0;
    }
    Reserva(int fechaInicio,int cantDias,int costBase)
    {
        this->fechaInicio = fechaInicio;
        this->cantDias = cantDias;
        this->costBase = costBase;
    }
};

int main()
{
    cout << "Hello World!";
}