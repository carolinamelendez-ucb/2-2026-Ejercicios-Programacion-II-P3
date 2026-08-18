#include <string>
#include <iostream>

using namespace std;

class Cliente {
private:
    int ci;
    string nombre;
    int aniosAntiguedad;

public:
    Cliente(int ci, const string& nombre)
        : ci(ci), nombre(nombre), aniosAntiguedad(0)
    {
    }
    void setAniosAntiguedad(int anios){
        if (anios>0) {
            aniosAntiguedad = anios;
        }
        else {
            cout << "Los anios de antiguedad deben ser mayores a 0" << endl;
        }
    }

    int getCi() {
        return ci;
    }
    string getNombre() {
        return nombre;
    }

    int getAniosAntiguedad() {
        return aniosAntiguedad;
    }

    void mostrarInformacion() {
        cout << "Nombre: " << nombre << endl;
        cout << " CI: " << ci << endl;
        cout << "Anios antiguedad" << aniosAntiguedad << endl;
    }

    class Vehiculo {
    private:
        string placa;
        string modelo;
        double tarifaDia;

    public:
        Vehiculo(string _placa, string _modelo, double _tarifaDia) {
            placa = _placa;
            modelo = _modelo;
            if (_tarifaDia > 0) {
                tarifaDia = _tarifaDia;
            }
            else {
                cout << "Error: La tarifa por día debe ser mayor que 0" << endl;
                tarifaDia = 0; 
            }
        }

        void setTarifaDia(double nuevaTarifa) {
            if (nuevaTarifa > 0) {
                tarifaDia = nuevaTarifa;
            }
            else {
                cout << "Error: La tarifa por día debe ser mayor que 0" << endl;
            }
        }

        string getPlaca() const { return placa; }
        string getModelo() const { return modelo; }
        double getTarifaDia() const { return tarifaDia; }

        void mostrarInformacion() const {
            cout << "=== INFORMACIÓN DEL VEHÍCULO ===" << endl;
            cout << "Placa: " << placa << endl;
            cout << "Modelo: " << modelo << endl;
            cout << "Tarifa por día: $" << tarifaDia << endl;
            cout << "==================================" << endl;
        }
    };

    class Reserva {
    private:
        string fechaInicio;
        int cantidadDias;
        Cliente* cliente;
        Vehiculo* vehiculo;
        double costoBase;
        double costoFinal;

        void calcularCostoBase() {
            costoBase = vehiculo->getTarifaDia() * cantidadDias;
        }

        void calcularCostoFinal() {
            double descuento = 0;

            if (cliente->getAniosAntiguedad() > 10) {
                descuento += 0.10;
            }

            if (cantidadDias >= 7) {
                descuento += 0.05;
            }

            costoFinal = costoBase * (1 - descuento);
        }

    public:
        Reserva(string _fechaInicio, int _cantidadDias, Cliente* _cliente, Vehiculo* _vehiculo) {
            fechaInicio = _fechaInicio;
            cliente = _cliente;
            vehiculo = _vehiculo;

            if (_cantidadDias > 0) {
                cantidadDias = _cantidadDias;
            }
            else {
                cout << "Error: La cantidad de días debe ser mayor que 0" << endl;
                cantidadDias = 1;
            }

            calcularCostoBase();
            calcularCostoFinal();
        }


        void setCantidadDias(int nuevaCantidad) {
            if (nuevaCantidad > 0) {
                cantidadDias = nuevaCantidad;
                calcularCostoBase();    
                calcularCostoFinal();  
            }
            else {
                cout << "Error: La cantidad de días debe ser mayor que 0" << endl;
            }
        }

        void setTarifaVehiculo(double nuevaTarifa) {
            vehiculo->setTarifaDia(nuevaTarifa);
            calcularCostoBase();    
            calcularCostoFinal();  
        }

        string getFechaInicio() const { return fechaInicio; }
        int getCantidadDias() const { return cantidadDias; }
        double getCostoBase() const { return costoBase; }
        double getCostoFinal() const { return costoFinal; }

        void mostrarInformacion() const {
            cout << "=== INFORMACIÓN DE LA RESERVA ===" << endl;
            cout << "Fecha de inicio: " << fechaInicio << endl;
            cout << "Cantidad de días: " << cantidadDias << endl;
            cout << "Costo base: $" << costoBase << endl;
            cout << "Costo final: $" << costoFinal << endl;
            cout << "----------------------------------" << endl;
            cout << "Cliente asociado:" << endl;
            cliente->mostrarInformacion();
            cout << "----------------------------------" << endl;
            cout << "Vehículo asociado:" << endl;
            vehiculo->mostrarInformacion();
            cout << "==================================" << endl;
        }
    };

    int main() {
        cout << "=== SISTEMA DE RESERVA DE VEHÍCULOS ===" << endl << endl;

        cout << "1. Creando cliente..." << endl;
        Cliente cliente1("123456789", "Juan Pérez");
        cliente1.mostrarInformacion();
        cout << endl;

        cout << "2. Modificando años de antigüedad..." << endl;
        cliente1.setAniosAntiguedad(5);  
        cout << "Nuevos años de antigüedad: " << cliente1.getAniosAntiguedad() << endl;

        cliente1.setAniosAntiguedad(-2);  
        cout << endl;

        cout << "3. Mostrando información completa del cliente:" << endl;
        cliente1.mostrarInformacion();
        cout << endl;

        cout << "4. Creando vehículo..." << endl;
        Vehiculo vehiculo1("ABC-123", "Toyota Corolla", 50.0);
        vehiculo1.mostrarInformacion();

        cout << "Intentando crear vehículo con tarifa inválida:" << endl;
        Vehiculo vehiculoTest("XYZ-789", "Test", -10.0);
        cout << endl;

        cout << "5. Mostrando información completa del vehículo:" << endl;
        vehiculo1.mostrarInformacion();
        cout << endl;

        cout << "6. Creando reserva..." << endl;
        Reserva reserva1("2026-08-18", 5, &cliente1, &vehiculo1);
        reserva1.mostrarInformacion();
        cout << endl;

        cout << "7. Mostrando información completa de la reserva:" << endl;
        reserva1.mostrarInformacion();
        cout << endl;

        cout << "8. Calculando costo final con descuentos..." << endl;
        cout << "Costo base: $" << reserva1.getCostoBase() << endl;
        cout << "Costo final: $" << reserva1.getCostoFinal() << endl;
        cout << "Descuento aplicado: $" << (reserva1.getCostoBase() - reserva1.getCostoFinal()) << endl;
        cout << endl;

        cout << "--- Demostrando descuentos con cliente antiguo ---" << endl;
        Cliente cliente2("987654321", "María López");
        cliente2.setAniosAntiguedad(12);  

        Vehiculo vehiculo2("DEF-456", "Honda Civic", 60.0);

        Reserva reserva2("2026-08-25", 7, &cliente2, &vehiculo2);
        reserva2.mostrarInformacion();
        cout << "Descuento total: $" << (reserva2.getCostoBase() - reserva2.getCostoFinal()) << endl;
        cout << endl;

        cout << "9. Modificando cantidad de días..." << endl;
        cout << "Cantidad de días actual: " << reserva1.getCantidadDias() << endl;
        cout << "Costo final actual: $" << reserva1.getCostoFinal() << endl;

        reserva1.setCantidadDias(10);
        cout << "Nueva cantidad de días: " << reserva1.getCantidadDias() << endl;
        cout << "Nuevo costo final: $" << reserva1.getCostoFinal() << endl;

        reserva1.setCantidadDias(-3);
        cout << endl;

        cout << "10. Modificando tarifa del vehículo..." << endl;
        cout << "Tarifa actual: $" << vehiculo1.getTarifaDia() << endl;
        cout << "Costo final actual: $" << reserva1.getCostoFinal() << endl;

        reserva1.setTarifaVehiculo(75.0);
        cout << "Nueva tarifa: $" << vehiculo1.getTarifaDia() << endl;
        cout << "Nuevo costo final: $" << reserva1.getCostoFinal() << endl;

        reserva1.setTarifaVehiculo(-20.0);

        cout << "\n=== FIN DEL PROGRAMA ===" << endl;

        return 0;
    }