#include<string>
#include <iostream>
using namespace std;

class Cliente {
    private:
    int ci;
    string nombre;
    int aniosAntiguedad;
public:
    Cliente(int ci, const string& nombre)
        : ci(ci), nombre(nombre)
    {
        this->ci = ci;
        this->nombre = nombre;
        this->aniosAntiguedad = 0;
    }
    void setAniosAntiguedad(int anios){
        if (anios < 0) {
            cout << "Amios de antiguedad es invalido. Valor ingreado: " << anios << endl;
        }
        else {
            this->aniosAntiguedad = anios;
        }
    }
    void mostrar() {
        cout << "Cliente: " << nombre << endl;
        cout << "Ci: " << ci << endl;
        cout << "Anios de antiguedad: " << aniosAntiguedad << endl;
    }
};

class Vehiculo {
private:
    int placa;
    string modelo;
    int tarifaDiaria;
public:
    Vehiculo(int placa, const string& modelo, int tarifaDiaria)
        : placa(placa), modelo(modelo), tarifaDiaria(tarifaDiaria)
    {
        this->placa = placa;
        this->modelo = modelo;
        if (tarifaDiaria < 0) {
            this->tarifaDiaria = tarifaDiaria;
        }
        else {
            this->tarifaDiaria = tarifaDiaria+1;
        }
        
    }
    void mostrar() {
        cout << "Placa: " << placa << endl;
        cout << "Modelo: " << modelo << endl;
        cout << "Tarifa diaria : " << tarifaDiaria << endl;
    }
};

class Reserva {
private:
    string fechaInicio;
    int cantidadDias;
    Cliente* Clientes;
    Vehiculo* Vehiculos;
    int costoBase;
public:
    Reserva( string fechaInicio, int cantidadDias, Cliente* Clientes,  Vehiculo* Vehiculos, int costoBase)
    {
    }
};

int main()
{
    Cliente Pau = Cliente(01, "Paula");
    Pau.mostrar();
    cout << "Despues del seteer de 5 anios" << endl;
    Pau.setAniosAntiguedad(5);
    Pau.mostrar();

    Vehiculo car = Vehiculo(1022, "Mazdacx3", 120);
    car.mostrar();

}
