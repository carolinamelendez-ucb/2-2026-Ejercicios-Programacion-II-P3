#include <iostream>
#include <string>
using namespace std;

class Cliente {
private:
    string ci;
    string nombre;
    int aniosAntiguedad;

public:
    // Requerimiento 1: crear cliente con ci y nombre; aniosAntiguedad = 0 por defecto
    Cliente(string ci, string nombre)
        : ci(ci), nombre(nombre), aniosAntiguedad(0) {
    }

    string getCi() const {
        return ci; 
    }
    string getNombre() const { 
        return nombre; 
    }
    int getAniosAntiguedad() const { return aniosAntiguedad; }

    // Requerimiento 2: setter con validación
    void setAniosAntiguedad(int anios) {
        if (anios > 0) {
            aniosAntiguedad = anios;
        }
        else {
            cout << "  [Error] aniosAntiguedad debe ser mayor que 0. Valor no modificado." << endl;
        }
    }

    // Requerimiento 3: mostrar info completa
    void mostrarInfo() const {
        cout << "  Cliente -> CI: " << ci
            << " | Nombre: " << nombre
            << " | Anios de antiguedad: " << aniosAntiguedad << endl;
    }
};

class Vehiculo {
private:
    string placa;
    string modelo;
    double tarifaDia;

public:
    // Requerimiento 4: crear vehiculo con todos los atributos; tarifa validada
    Vehiculo(string placa, string modelo, double tarifaDia)
        : placa(placa), modelo(modelo), tarifaDia(0.0) {
        setTarifaDia(tarifaDia);
    }

    string getPlaca() const { return placa; }
    string getModelo() const { return modelo; }
    double getTarifaDia() const { return tarifaDia; }

    // Requerimiento 10: setter con validación
    void setTarifaDia(double tarifa) {
        if (tarifa > 0) {
            tarifaDia = tarifa;
        }
        else {
            cout << "  [Error] La tarifa por dia debe ser mayor que 0. Valor no modificado." << endl;
        }
    }

    // Requerimiento 5: mostrar info completa
    void mostrarInfo() const {
        cout << "  Vehiculo -> Placa: " << placa
            << " | Modelo: " << modelo
            << " | Tarifa/Dia: " << tarifaDia << endl;
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
        costoBase = vehiculo->getTarifaDia() * cantidadDias;
    }

public:
    // Requerimiento 6: crear reserva con todos los atributos; costoBase = tarifaDia * cantidadDias
    Reserva(string fechaInicio, int dias, Cliente* cliente, Vehiculo* vehiculo)
        : fechaInicio(fechaInicio), cantidadDias(0),
        cliente(cliente), vehiculo(vehiculo), costoBase(0.0) {
        setCantidadDias(dias);
    }

    // Requerimiento 9: setter con validación, actualiza el costo
    void setCantidadDias(int dias) {
        if (dias > 0) {
            cantidadDias = dias;
            actualizarCostoBase();
        }
        else {
            cout << "  [Error] cantidadDias debe ser mayor que 0. Valor no modificado." << endl;
        }
    }

    int getCantidadDias() const { return cantidadDias; }
    double getCostoBase() const { return costoBase; }

    // Requerimiento 10 (parte de Reserva): permite actualizar tarifa del vehiculo y recalcular costo base
    void actualizarTarifaVehiculo(double nuevaTarifa) {
        vehiculo->setTarifaDia(nuevaTarifa);
        actualizarCostoBase();
    }

    // Requerimiento 8: costo final con reglas de negocio
    // 10% descuento si aniosAntiguedad del cliente > 10
    // 5% descuento adicional si cantidadDias >= 7
    double calcularCostoFinal() const {
        double costoFinal = costoBase;

        if (cliente->getAniosAntiguedad() > 10) {
            costoFinal *= 0.90; // 10% de descuento
        }
        if (cantidadDias >= 7) {
            costoFinal *= 0.95; // 5% de descuento adicional
        }
        return costoFinal;
    }

    // Requerimiento 7: mostrar info completa de la reserva
    void mostrarInfo() const {
        cout << "  Reserva -> Fecha inicio: " << fechaInicio
            << " | Dias: " << cantidadDias
            << " | Cliente: " << cliente->getNombre()
            << " | Vehiculo: " << vehiculo->getPlaca()
            << " | Costo base: " << costoBase << endl;
    }
};

int main() {
    Cliente cliente1("7845123", "Juan Perez");
    cliente1.mostrarInfo(); // aniosAntiguedad = 0 por defecto

    
    cliente1.setAniosAntiguedad(12); // > 10 para activar descuento mas adelante

    cliente1.mostrarInfo();

    
    
    Vehiculo vehiculo1("ABC123", "Toyota Corolla", 150.0);
    vehiculo1.mostrarInfo();

    vehiculo1.mostrarInfo();

    
    Reserva reserva1("01/09/2026", 8, &cliente1, &vehiculo1);
    reserva1.mostrarInfo();

    reserva1.mostrarInfo();

    cout << "  Cliente con " << cliente1.getAniosAntiguedad()
        << " anios de antiguedad (>10 => 10% dcto) y reserva de "
        << reserva1.getCantidadDias() << " dias (>=7 => 5% dcto adicional)." << endl;
    cout << "  Costo final: " << reserva1.calcularCostoFinal() << endl;

    
    reserva1.setCantidadDias(5);
    reserva1.mostrarInfo();
    cout << "  Nuevo costo final: " << reserva1.calcularCostoFinal() << endl;

    reserva1.actualizarTarifaVehiculo(200.0);
    reserva1.mostrarInfo();
    cout << "  Costo final actualizado: " << reserva1.calcularCostoFinal() << endl;

    return 0;
}