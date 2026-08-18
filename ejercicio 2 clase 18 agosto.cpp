#include <iostream>
using namespace std;
class Cliente
{
private:
    string ci;
    string nombre;
    int aniosAntiguedad;

public:
    Cliente(string ci, string nombre)
    {
        this->ci = ci;
        this->nombre = nombre;
        this->aniosAntiguedad = 0;
    }
    void setAniosAntiguedad(int anios)
    {
        if (anios > 0)
        {
            this->aniosAntiguedad = anios;
        }
        else
        {
            cout << "Error: los anios de antiguedad deben ser mayores que 0." << endl;
        }
    }
    int getAniosAntiguedad()
    {
        return this->aniosAntiguedad;
    }
    void mostrar()
    {
        cout << "CI: " << this->ci << endl;
        cout << "Nombre: " << this->nombre << endl;
        cout << "Anios de antiguedad: " << this->aniosAntiguedad << endl;
    }
};
class Vehiculo
{
private:
    string placa;
    string modelo;
    float tarifaDia;

public: 
    Vehiculo(string placa, string modelo, float tarifaDia)
    {
        this->placa = placa;
        this->modelo = modelo;

        if (tarifaDia > 0)
        {
            this->tarifaDia = tarifaDia;
        }
        else
        {
            cout << "Error: la tarifa debe ser mayor que 0." << endl;
            this->tarifaDia = 0;
        }
    }

    
    void setTarifaDia(float tarifa)
    {
        if (tarifa > 0)
        {
            this->tarifaDia = tarifa;
        }
        else
        {
            cout << "Error: la tarifa debe ser mayor que 0." << endl;
        }
    }
    float getTarifaDia()
    {
        return this->tarifaDia;
    }
    void mostrar()
    {
        cout << "Placa: " << this->placa << endl;
        cout << "Modelo: " << this->modelo << endl;
        cout << "Tarifa por dia: " << this->tarifaDia << endl;
    }
};




class Reserva
{
private:
    string fechaInicio;
    int cantidadDias;
    Cliente cliente;
    Vehiculo vehiculo;
    float costoBase;

public:

    
    Reserva(string fechaInicio, int cantidadDias, Cliente cliente, Vehiculo vehiculo)
        : cliente(cliente), vehiculo(vehiculo)
    {
        this->fechaInicio = fechaInicio;

        if (cantidadDias > 0)
        {
            this->cantidadDias = cantidadDias;
        }
        else
        {
            cout << "Error: la cantidad de dias debe ser mayor que 0." << endl;
            this->cantidadDias = 1;
        }

        this->costoBase = this->vehiculo.getTarifaDia() * this->cantidadDias;
    }
    void setCantidadDias(int dias)
    {
        if (dias > 0)
        {
            this->cantidadDias = dias;

            
            this->costoBase =
                this->vehiculo.getTarifaDia() * this->cantidadDias;
        }
        else
        {
            cout << "Error: la cantidad de dias debe ser mayor que 0." << endl;
        }
    }

 
    int getCantidadDias()
    {
        return this->cantidadDias;
    }

    
    void modificarTarifa(float tarifa)
    {
        this->vehiculo.setTarifaDia(tarifa);

        
        this->costoBase =
            this->vehiculo.getTarifaDia() * this->cantidadDias;
    }

    
    float calcularCostoFinal()
    {
        float costoFinal = this->costoBase;

        
        if (this->cliente.getAniosAntiguedad() > 10)
        {
            costoFinal = costoFinal * 0.90;
        }

       
        if (this->cantidadDias >= 7)
        {
            costoFinal = costoFinal * 0.95;
        }

        return costoFinal;
    }

   
    void mostrar()
    {
        cout << endl;
        cout << "========== RESERVA ==========" << endl;

        cout << "Fecha de inicio: " << this->fechaInicio << endl;
        cout << "Cantidad de dias: " << this->cantidadDias << endl;

        cout << endl;
        cout << "--- CLIENTE ---" << endl;
        this->cliente.mostrar();

        cout << endl;
        cout << "--- VEHICULO ---" << endl;
        this->vehiculo.mostrar();

        cout << endl;
        cout << "Costo base: " << this->costoBase << endl;
        cout << "Costo final: " << this->calcularCostoFinal() << endl;
    }
};




int main()
{
    cout << "===== CLIENTE =====" << endl;
    Cliente cliente1("1234567", "Juan");
    cout << endl;
    cout << "Cliente inicialmente:" << endl;
    cliente1.mostrar();
    cout << endl;
    cout << "Modificando antiguedad a 15..." << endl;
    cliente1.setAniosAntiguedad(15);
    cliente1.mostrar();
    cout << endl;
    cout << "Probando valor invalido..." << endl;
    cliente1.setAniosAntiguedad(0);
    cout << endl;
    cout << "===== VEHICULO =====" << endl;
    Vehiculo vehiculo1("ABC-123", "Toyota Corolla", 200);
    vehiculo1.mostrar();
    cout << endl;
    cout << "===== CREANDO RESERVA =====" << endl;
    Reserva reserva1(
        "18/08/2026",
        10,
        cliente1,
        vehiculo1
    );
    reserva1.mostrar();
    cout << endl;
    cout << "===== MODIFICANDO DIAS =====" << endl;
    reserva1.setCantidadDias(15);
    reserva1.mostrar();
    cout << endl;
    cout << "Probando cantidad de dias invalida..." << endl;
    reserva1.setCantidadDias(0);
    cout << endl;
    cout << "===== MODIFICANDO TARIFA =====" << endl;
    reserva1.modificarTarifa(300);
    reserva1.mostrar();
    cout << endl;
    cout << "Probando tarifa invalida..." << endl;
    reserva1.modificarTarifa(-100);
    return 0;
}