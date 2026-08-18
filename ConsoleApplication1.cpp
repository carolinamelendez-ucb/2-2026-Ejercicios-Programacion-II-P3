
#include <iostream>
#include <string>

using namespace std;

class Cliente {
private:
    string ci;
    string nombre;
    int aniosAntiguedad;

public:
    Cliente() {
        ci = "";
        nombre = "";
        aniosAntiguedad = 0;
    }   

    void setAniosAntiguedad(int anios) {
        if (anios > 0) {
            aniosAntiguedad = anios;
        }
        else {
            cout << "Error: El año de antiguedad no es válido (Valor ingresado: " << anios << ")." << endl;
        }
    }

    int getAniosAntiguedad() {
        return aniosAntiguedad;
    }

    void mostrar() {
        cout << "-- Datos del Cliente --" << endl;
        cout << "CI: " << ci << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Años de Antigüedad: " << aniosAntiguedad << " años" << endl;
    }
};


class Vehiculo {
private:
    string placa;
    string modelo;
    double tarifaDia;

public:
    Vehiculo(string placa, string modelo, double _tarifaDia) {
        this ->placa = placa;
        this->modelo = modelo;
        setTarifaDia(_tarifaDia); 
    }

    void setTarifaDia(double _tarifaDia) {
        if (_tarifaDia > 0) {
            tarifaDia = _tarifaDia;
        }
        else {
            cout << "Error: La tarifa por día debe ser mayor que 0 (Valor ingresado: " << tarifaDia << ")." << endl;
        }
    }

    double getTarifaDia() {
        return tarifaDia;
    }

    void mostrar() {
        cout << "-- Datos del Vehículo --" << endl;
        cout << "Placa: " << placa << endl;
        cout << "Modelo: " << modelo << endl;
        cout << "Tarifa por Día: " << tarifaDia << " Bs" << endl;
    }
};

int main() {
   

    return 0;
}