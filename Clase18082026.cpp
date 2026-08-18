#include <iostream>
#include <string>
using namespace std;

class Cliente{
    private:
    string ci;
    string Nombre;
    int antiguedad;
    public: 
    Cliente(string &ci,string &Nombre){
        this->ci=ci;
        this->nombre0nombre;
        this->antiguedad=0;
    }
    void setAntiguedad(int nuevosAnios){
        if(nuevosAnios>0){
            this->antiguedad=nuevosAnios;
        }else{
            cout<<"Error"<<endl;
        }
    }
    
};

class Vehiculo{
    private:
    string placa;
    string modelo;
    double tarifaDia;
    public:
    Vehiculo(string placa,string modelo,double tarifaDia){
        this->placa=placa;
        this->modelo=modelo;
        if(tarifaDia>0){
            this->tarifaDia=tarifaDia;
        }else{
            cout<<"La tarifa debe ser mayor a 0"<<endl;
        }
    }
};
class Reserva{
    string fechaInicio;
    int cantidadDias;
    Cliente *cliente;
    Vehiculo *vehiculo;
    double costoBase;
    
}

int main(){

}