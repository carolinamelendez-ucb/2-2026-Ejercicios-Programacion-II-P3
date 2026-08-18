#include <iostream>
#include <string>

using namespace std;

class Cliente {
private:
    string ci;
    string nombre;
    int aniosAntiguedad;

public:
    Cliente(string ci, string nombre) {
        this->ci = ci;
        this->nombre = nombre;
        this->aniosAntiguedad = 0; 
    }

    void setAniosAntiguedad(int anios) {
        if (anios > 0) {
            this->aniosAntiguedad = anios;
        }
        else {
            cout << "Los anios de antiguedad deben ser mayores a 0." << endl;
        }
    }

    int getAniosAntiguedad() {
        return aniosAntiguedad;
    }

    void mostrarInfo() {
        cout << "Ci del Cliente: " << ci << " | Nombre: " << nombre
            << " | Antigüedad: " << aniosAntiguedad << " años." << endl;
    }
};

class Vehiculo {
private:
    string placa;
    string modelo;
    double tarifaDia;

public:
    Vehiculo(string placa, string modelo, double tarifaDia) {
        this->placa = placa;
        this->modelo = modelo;
        if (tarifaDia > 0) {
            this->tarifaDia = tarifaDia;
        }
        else {
            cout << "La tarifa debe ser mayor a 0. Se asignará una tarifa base de 100." << endl;
            this->tarifaDia = 100.0;
        }
    }
    void setTarifaDia(double tarifaDia) {
        if (tarifaDia > 0) {
            this->tarifaDia = tarifaDia;
        }
        else {
            cout << "La tarifa actualizada debe ser mayor a 0." << endl;
        }
    }

    double getTarifaDia() {
        return tarifaDia;
    }

    // Req 5: Mostrar información
    void mostrarInfo() {
        cout << "Placa del Vehiculo: " << placa << " | Modelo: " << modelo
            << " | Tarifa diaria en Bs. " << tarifaDia << endl;
    }
};

class Reserva {
private:
    string fechaInicio;
    int cantidadDias;
    Cliente* cliente;   
    Vehiculo* vehiculo;
    double costoBase;

    void actualizarCostoBase() {
        this->costoBase = this->vehiculo->getTarifaDia() * this->cantidadDias;
    }

public:
    Reserva(string fechaInicio, int cantidadDias, Cliente* cliente, Vehiculo* vehiculo) {
        this->fechaInicio = fechaInicio;
        this->cliente = cliente;
        this->vehiculo = vehiculo;

        if (cantidadDias > 0) {
            this->cantidadDias = cantidadDias;
        }
        else {
            cout << "La cantidad de dias debe ser mayor a 0. se asignara 1 dia." << endl;
            this->cantidadDias = 1;
        }
        actualizarCostoBase();
    }

    void setCantidadDias(int cantidadDias) {
        if (cantidadDias > 0) {
            this->cantidadDias = cantidadDias;
            actualizarCostoBase(); 
        }
        else {
            cout << "la nueva cantidad de dias debe ser mayor a 0." << endl;
        }
    }

    double calcularCostoFinal() {
        actualizarCostoBase();

        double descuentoTotal = 0.0;

        if (cliente->getAniosAntiguedad() > 10) {
            descuentoTotal += 0.10; 
        }
        if (this->cantidadDias >= 7) {
            descuentoTotal += 0.05; 
        }

        return this->costoBase - (this->costoBase * descuentoTotal);
    }

    void mostrarInfo() {
        actualizarCostoBase();
        cout << "Fecha de reserva: " << fechaInicio << " | Días: " << cantidadDias
            << " | Costo Base en Bs. " << costoBase << endl;
        cout << "  [+] ";
        cliente->mostrarInfo();
        cout << "  [+] ";
        vehiculo->mostrarInfo();
    }
};


int main() {
    cout << "=== Crear Cliente ===" << endl;
    Cliente cliente("7895531", "Gabriel Espinoza");

    cout << "\n=== Modificar los anios de antiguedad ===" << endl;
    cliente.setAniosAntiguedad(-2); 
    cliente.setAniosAntiguedad(12); 

    cout << "\n=== Mostrar informacion del cliente ===" << endl;
    cliente.mostrarInfo();

    cout << "\n=== Crear vehiculo ===" << endl;
    Vehiculo vehiculoError("ABC-123", "Toyota Corolla", -50);
    Vehiculo vehiculo("XYZ-987", "Nissan Frontier", 200.0);  

    cout << "\n=== Mostrar informacion del Vehiculo ===" << endl;
    vehiculo.mostrarInfo();

    cout << "\n=== Crear reserva ===" << endl;
    Reserva reserva("2026-09-01", 5, &cliente, &vehiculo);

    cout << "\n=== Informacion de Reserva ===" << endl;
    reserva.mostrarInfo();

    cout << "\n=== Calculo costo final ===" << endl;
    cout << "Costo Final Calculado: Bs. " << reserva.calcularCostoFinal() << endl;

    cout << "\n=== Modificar cantidad de dias ===" << endl;
    reserva.setCantidadDias(-3); 
    reserva.setCantidadDias(8);  
    cout << "Días modificados a 8. Nuevo Costo Final: Bs. " << reserva.calcularCostoFinal() << endl;

    cout << "\n=== Modificar tarifa del vehiculo ===" << endl;
    vehiculo.setTarifaDia(-100); 
    vehiculo.setTarifaDia(250.0); 

    cout << "Tarifa actualizada a 250.0. Nuevo Costo Final de la Reserva: Bs. "
        << reserva.calcularCostoFinal() << endl;

    return 0;
}
