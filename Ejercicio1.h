#pragma once
#include <iostream>
#include<string>
using namespace std;
class Paciente {
private:
    int ci;
    string nombre;
    int edad;
public:
    Paciente(int ci, const string& nombre, int edad)
        : ci(ci), nombre(nombre), edad(edad)
    {
    }
    void Edad(Paciente paciente,int edadnueva) {
        if (edadnueva<0) {
            cout << "El paciente no puede tener edad negativa o cero" << endl;
        }
        else {
            paciente.edad = edadnueva;
        }
    }
    void mostrar() {
        cout << "CI: " << ci << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Edad: " << edad << endl;
    }

    int getEdad() {
        return edad;
    }
};
class Medico {
private:
    int codigo;
    string nombre;
    string especialidad;
public:
    Medico(int codigo, const string& nombre, const string& especialidad)
        : codigo(codigo), nombre(nombre), especialidad(especialidad)
    {
    }
    void mostrar() {
        cout << "Codigo: " << codigo << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Especialidad: " << especialidad << endl;
    }
};
class Consulta {
private:
    string fecha;
    Paciente paciente;
    Medico medico;
    float costo;
public:
    Consulta(const string& fecha, const Paciente& paciente, const Medico& medico, float costo)
        : fecha(fecha), paciente(paciente), medico(medico), costo(costo)
    {
    }
    void mostrar() {
        cout << "\n===== CONSULTA =====" << endl;

        cout << "Fecha: " << fecha << endl;

        cout << "\nPaciente:" << endl;
        paciente.mostrar();

        cout << "\nMedico:" << endl;
        medico.mostrar();

        cout << "Costo: " << costo << endl;
    }

    void descuento(float porcentaje) {

        if (porcentaje < 0 || porcentaje > 80) {
            cout << "Error: el descuento debe estar entre 0 y 80%." << endl;
            return;
        }

        if (paciente.getEdad() > 80)
            porcentaje = porcentaje + 5;

        costo = costo - costo * porcentaje / 100;
    }

    void setCosto(float nuevoCosto) {

        if (nuevoCosto > 0)
            costo = nuevoCosto;
        else
            cout << "Error: el costo debe ser mayor que 0." << endl;
    }
};
