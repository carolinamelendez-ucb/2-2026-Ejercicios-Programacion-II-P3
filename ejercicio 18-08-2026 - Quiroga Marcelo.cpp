#include <iostream>
#include <string>

using namespace std;

class Cliente{
private:
    int ci;
    string nombre;
    int aniosAntiguedad;
public:
    Cliente(int ci, string nombre, int aniosAntiguedad){
    this->ci=ci;
    this->nombre=nombre;
    this->aniosAntiguedad=aniosAntiguedad;
    if (aniosAntiguedad <= 0){
            this->aniosAntiguedad=0;
        }
        else{
            this->aniosAntiguedad=aniosAntiguedad;
        }
    }

    void mostrarCliente(){
        cout<<"CI: "<<ci<<endl;
        cout<<"Nombre: "<<nombre<<endl;
        cout<<"Antigüedad: "<<aniosAntiguedad<<endl;
    }

    setAntiguedad(int nuevaAntiguedad){
        aniosAntiguedad=nuevaAntiguedad;
    }
};

class Vehiculo{
private:
    string placa;
    string modelo;
    float tarifaDia;
public:
    Vehiculo(string placa, string modelo, float tarifaDia){
        this->placa=placa;
        this->modelo=modelo;
        this->tarifaDia=tarifaDia;
        if(tarifaDia<=0){
            this->tarifaDia=0;
        }
        else{
            this->tarifaDia=tarifaDia;
        }
    }

    void mostrarVehiculo(){
        cout<<"Placa: "<<placa<<endl;
        cout<<"Modelo: "<<modelo<<endl;
        cout<<"Tarifa del dia: "<<tarifaDia<<endl;
    }
};

class Reserva{
private:
    string fechaInicio;
    int cantidadDias;
    Cliente cliente;
    Vehiculo vehiculo;
    float costoBase;
public:
    Reserva(){
        this->fechaInicio=fechaInicio;
        this->cantidadDias=cantidadDias;
        this->
    }
};

int main()
{

}
