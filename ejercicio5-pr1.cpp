#include <iostream>
#include <string>

using namespace std;

enum TipoRemitente { PARTICULAR, EMPRESA };
enum TipoEnvio { NORMAL, EXPRESS };

class Remitente {
private:
    string ci;
    string nombre;
    TipoRemitente tipoRemitente;

public:
    Remitente(string _ci, string _nombre) {
        ci = _ci;
        nombre = _nombre;
        tipoRemitente = PARTICULAR;
    }
    void setTipoRemitente(TipoRemitente _tipo) {
        tipoRemitente = _tipo;
    }

    TipoRemitente getTipoRemitente() {
        return tipoRemitente;
    }

    void mostrar() {
        cout << "-- Remitente --" << endl;
        cout << "CI: " << ci << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Tipo de Remitente: " << (tipoRemitente == EMPRESA ? "EMPRESA" : "PARTICULAR") << endl;
    }
};

class Paquete {
private:
    string codigo;
    double peso;
    TipoEnvio tipoEnvio;

public:
    Paquete(string _codigo, double _peso, TipoEnvio _tipoEnvio) {
        codigo = _codigo;
        setPeso(_peso); // Validar con el setter
        tipoEnvio = _tipoEnvio;
    }

    void setPeso(double _peso) {
        if (_peso > 0) {
            peso = _peso;
        }
        else {
            cout << "Error: El peso debe ser mayor que 0 (Valor ingresado: " << _peso << ")." << endl;
            peso = 1.0; 
        }
    }
    void setTipoEnvio(TipoEnvio _tipoEnvio) {
        tipoEnvio = _tipoEnvio;
    }

    double getPeso() {
        return peso;
    }

    TipoEnvio getTipoEnvio() {
        return tipoEnvio;
    }

    void mostrar() {
        cout << "-- Paquete --" << endl;
        cout << "Codigo de Paquete: " << codigo << endl;
        cout << "Peso: " << peso << " kg" << endl;
        cout << "Tipo de Envio: " << (tipoEnvio == EXPRESS ? "EXPRESS" : "NORMAL") << endl;
    }
};

class Envio {
private:
    string numero;
    string destino;
    Remitente remitente;
    Paquete paquete;    
    double distancia;
    double costo;

public:
    Envio(string _numero, string _destino, Remitente _remitente, Paquete _paquete, double _distancia)
        : numero(_numero), destino(_destino), remitente(_remitente), paquete(_paquete) {

        setDistancia(_distancia); 
        calcularCostoFinal();     
    }

    void setDistancia(double _distancia) {
        if (_distancia > 0) {
            distancia = _distancia;
        }
        else {
            cout << "Error: La distancia debe ser mayor que 0 (Valor ingresado: " << _distancia << ")." << endl;
            distancia = 1.0;
        }
    }
    void setTipoEnvioEnEnvio(TipoEnvio nuevoTipo) {
        paquete.setTipoEnvio(nuevoTipo);
        calcularCostoFinal();
    }
    void setTipoRemitenteEnEnvio(TipoRemitente nuevoTipo) {
        remitente.setTipoRemitente(nuevoTipo);
        calcularCostoFinal();
    }
    double calcularCostoBase() {
        return paquete.getPeso() * distancia * 0.50;
    }
    void calcularCostoFinal() {
        double costoBase = calcularCostoBase();
        double costoFinal = costoBase;

        if (paquete.getTipoEnvio() == EXPRESS) {
            costoFinal += (costoBase * 0.25);
        }

        if (remitente.getTipoRemitente() == EMPRESA) {
            costoFinal -= (costoFinal * 0.10);
        }if (paquete.getPeso() > 10.0) {
            double pesoExtra = paquete.getPeso() - 10.0;
            costoFinal += (pesoExtra * 5.0);
        }

        costo = costoFinal;
    }

    double getCosto() {
        return costo;
    }

    void mostrar() {
        cout << "==INFORMACION DEL ENVIO ==" << endl;
        cout << "Numero de Envio: " << numero << endl;
        cout << "Destino: " << destino << endl;
        cout << "Distancia: " << distancia << " km" << endl;
        remitente.mostrar();
        paquete.mostrar();
        cout << "Costo Base: " << calcularCostoBase() << " Bs" << endl;
        cout << "Costo Final (con reglas de negocio): " << costo << " Bs" << endl;
    }
};

int main() {
    cout << "=== PRUEBAS EJERCICIO 5: ENVIO DE PAQUETE ===" << endl << endl;

    cout << "[Remitente]:" << endl;
    Remitente rem1("7654321", "Carla Sanchez");
    rem1.mostrar();

    cout << "\n[Modifica remitente a EMPRESA]:" << endl;
    rem1.setTipoRemitente(EMPRESA);
    rem1.mostrar();

    cout << "\n[Paquete]:" << endl;
    Paquete pkg1("PKG-99", -2.5, NORMAL); // Peso invalido 
    Paquete pkg2("PKG-10", 12.0, NORMAL); // Paquete de 12 kg (> 10 kg para regla de negocio)
    pkg2.mostrar();

    cout << "\n[Modificando peso del paquete]:" << endl;
    pkg2.setPeso(15.0); // Nuevo peso valido (15 kg > 5 kg el limite de 10)
    pkg2.mostrar();

    cout << "\n[Envio]:" << endl;
    Envio envio1("ENV-2026", "Santa Cruz", rem1, pkg2, -100.0); // Distancia invalida
    Envio envio2("ENV-2026", "Santa Cruz", rem1, pkg2, 200.0);  // Distancia valida (200 km)
    envio2.mostrar();

    cout << "\n[Prueba de Cambio a tipo EXPRESS]:" << endl;
    envio2.setTipoEnvioEnEnvio(EXPRESS); // Cambia a express, aplicando el 25%
    envio2.mostrar();

    return 0;
}