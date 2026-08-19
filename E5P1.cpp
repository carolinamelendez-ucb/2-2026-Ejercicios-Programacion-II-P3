#include <iostream>
#include <string>
using namespace std;
enum TipoRemitente{PARTICULAR, EMPRESA};
enum TipoEnvio{NORMAL, EXPRESS};

class Remitente{
    private:
    string ci;
    string nombre;
    TipoRemitente tipoRemitente;
    public:
    Remitente(string ci, string nombre){
        this->ci=ci;
        this->nombre=nombre;
        this->tipoRemitente=PARTICULAR;
    }
    void setRemitente(TipoRemitente nuevoTipo){
        this->tipoRemitente=nuevoTipo;
    }
    TipoRemitente getTipoRemitete(){
        return tipoRemitente;
    }
    void mostrar(){
        cout<<"CI: "<<ci<<endl;
        cout<<"Nombre: "<<nombre<<endl;
        cout<<"Tipo Remitente: "<<(tipoRemitente==PARTICULAR? "PARTICULAR": "EMPRESA")<<endl;
    }
};

class Paquete{
    private:
    string codigo;
    double peso;
    TipoEnvio tipoEnvio;
    public:
    Paquete(string codigo,double peso,TipoEnvio tipoEnvio){
        this->codigo=codigo;
        this->tipoEnvio=tipoEnvio;
        setPeso(peso);
    }
    void setPeso(double nuevoPeso){
        if(nuevoPeso>0){
            this->peso=nuevoPeso;
        }else{
            cout<<"El peso ingresado es incorrecto"<<endl;
            this->peso=1;
        }
    }
    double getPeso(){
        return peso;
    }
    void setEnvio(TipoEnvio nuevoTipo){
        this->tipoEnvio=nuevoTipo;
    }
    TipoEnvio getEnvio(){
        return tipoEnvio;
    }
    void mostrar(){
        cout<<"Codigo de Paquete: "<<codigo<<endl;
        cout<<"Peso: "<<peso<<endl;
        cout<<"Tipo Envio: "<<(tipoEnvio==NORMAL? "NORMAL" : "EXPRESS")<<endl;
    }
};

class Envio {
    private:
    int numero;
    string destino;
    Remitente *remitente;
    Paquete *paquete;
    double distancia;
    public:
    Envio(int numero,string destino, Remitente *remitente,Paquete *paquete,double distancia){
        this->numero=numero;
        this->destino=destino;
        this->remitente=remitente;
        this->paquete=paquete;
        setDistancia(distancia);
    }
    void setDistancia(double nuevaDistancia){
        if(nuevaDistancia>0){
            this->distancia=nuevaDistancia;
        }else{
            cout<<"Ingrese una distancia correcta"<<endl;
            this->distancia=1;
        }
    }
    double costoBase(){
        return paquete->getPeso()*distancia*0.50;
    }
    double costoFinal(){
        double costo=costoBase();
        if(paquete->getEnvio()==EXPRESS){
            costo=costo*1.25;
        }
        if(remitente->getTipoRemitete()==EMPRESA){
            costo=costo*0.90;
        }
        if(paquete->getPeso()>10){
            double kilosExtra=paquete->getPeso()-10;
            costo=costo+(kilosExtra*5);
        }
        return costo;
    }
    void mostrar(){
        cout<<"DATOS DEL ENVIO NUMERO "<<numero<<endl;
        cout<<"Destino: "<<destino<<endl;
        cout<<"Distancia: "<<distancia<<endl;
        cout<<"Costo Base: "<<costoBase()<<endl;
        cout<<"Costo Final: "<<costoFinal()<<endl;
        cout<<"DATOS DEL REMITENTE"<<endl;
        remitente->mostrar();
        cout<<"DATOS DEL PAQUETE"<<endl;
        paquete->mostrar();
    }
};

int main(){
    Remitente *miRemitente=new Remitente("1234567", "Ana Lopez");
    miRemitente->mostrar();
    Paquete *miPaquete=new Paquete("PQ-001",5.0,NORMAL);
    miPaquete->setPeso(-3);
    miPaquete->setPeso(3);
    miPaquete->mostrar();
    Envio *envioError= new Envio(1,"Santa Cruz",miRemitente,miPaquete,-10);
    Envio *miEnvio=new Envio(2,"Beni",miRemitente,miPaquete,100.0);
    miEnvio->mostrar();
    miEnvio->setDistancia(150);
    miPaquete->setEnvio(EXPRESS);
    miRemitente->setRemitente(EMPRESA);
    miEnvio->mostrar();
    delete miEnvio;
    delete envioError;
    return 0;
}