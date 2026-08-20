#include <iostream>
#include <string>
using namespace std;


enum TipoRemitente { PARTICULAR, EMPRESA };
enum TipoEnvio { NORMAL, EXPRESS };

string tipoRemitenteToString(TipoRemitente t) {
    return (t == PARTICULAR) ? "PARTICULAR" : "EMPRESA";
}

string tipoEnvioToString(TipoEnvio t) {
    return (t == NORMAL) ? "NORMAL" : "EXPRESS";
}

class Remitente {
private:
    int ci;
    string nombre;
    TipoRemitente tipoRemitente;

public:
    Remitente(int ci, const string& nombre)
        : ci(ci), nombre(nombre), tipoRemitente(PARTICULAR) {
    }

    int getCi() const { return ci; }
    string getNombre() const { return nombre; }
    TipoRemitente getTipoRemitente() const { return tipoRemitente; }

    void setTipoRemitente(TipoRemitente nuevoTipo) {
        if (nuevoTipo != PARTICULAR && nuevoTipo != EMPRESA) {
            cout << "Error: tipo de remitente invalido." << endl;
            return;
        }
        tipoRemitente = nuevoTipo;
    }

    void mostrarInfo() const {
        cout << "  CI: " << ci << endl;
        cout << "  Nombre: " << nombre << endl;
        cout << "  Tipo Remitente: " << tipoRemitenteToString(tipoRemitente) << endl;
    }
};

class Paquete {
private:
    int codigo;
    double peso;
    TipoEnvio tipoEnvio;

public:
    Paquete(int codigo, double peso, TipoEnvio tipoEnvio)
        : codigo(codigo), peso(peso > 0 ? peso : 0), tipoEnvio(tipoEnvio) {
        if (peso <= 0) {
            cout << "Error: el peso debe ser mayor que 0. Se asigno 0 por defecto." << endl;
        }
    }

    int getCodigo() const { return codigo; }
    double getPeso() const { return peso; }
    TipoEnvio getTipoEnvio() const { return tipoEnvio; }

    void setPeso(double nuevoPeso) {
        if (nuevoPeso <= 0) {
            cout << "Error: el nuevo peso debe ser mayor que 0." << endl;
            return;
        }
        peso = nuevoPeso;
    }

    void setTipoEnvio(TipoEnvio nuevoTipo) {
        if (nuevoTipo != NORMAL && nuevoTipo != EXPRESS) {
            cout << "Error: tipo de envio invalido." << endl;
            return;
        }
        tipoEnvio = nuevoTipo;
    }

    void mostrarInfo() const {
        cout << "  Codigo: " << codigo << endl;
        cout << "  Peso: " << peso << " kg" << endl;
        cout << "  Tipo Envio: " << tipoEnvioToString(tipoEnvio) << endl;
    }
};

class Envio {
private:
    int numero;
    string destino;
    Remitente remitente;
    Paquete paquete;
    double distancia;
    double costo;

    void actualizarCosto() {
        costo = calcularCostoFinal();
    }

public:
    Envio(int numero, const string& destino, const Remitente& remitente,
        const Paquete& paquete, double distancia)
        : numero(numero), destino(destino), remitente(remitente),
        paquete(paquete), distancia(distancia > 0 ? distancia : 0), costo(0) {
        if (distancia <= 0) {
            cout << "Error: la distancia debe ser mayor que 0. Se asigno 0 por defecto." << endl;
        }
        actualizarCosto();
    }

    double calcularCostoBase() const {
        return paquete.getPeso() * distancia * 0.50;
    }

    double calcularCostoFinal() const {
        double costoFinal = calcularCostoBase();

        if (paquete.getTipoEnvio() == EXPRESS) {
            costoFinal += costoFinal * 0.25;
        }

        if (remitente.getTipoRemitente() == EMPRESA) {
            costoFinal -= costoFinal * 0.10;
        }

        if (paquete.getPeso() > 10) {
            double kgExtra = paquete.getPeso() - 10;
            costoFinal += kgExtra * 5;
        }

        return costoFinal;
    }

    void setDistancia(double nuevaDistancia) {
        if (nuevaDistancia <= 0) {
            cout << "Error: la nueva distancia debe ser mayor que 0." << endl;
            return;
        }
        distancia = nuevaDistancia;
        actualizarCosto();
    }

    void setTipoEnvio(TipoEnvio nuevoTipo) {
        paquete.setTipoEnvio(nuevoTipo);
        actualizarCosto();
    }

    void mostrarInfo() const {
        cout << "" << endl;
        cout << "----- Datos del Envio -----" << endl;
        cout << "Numero: " << numero << endl;
        cout << "Destino: " << destino << endl;
        cout << "Distancia: " << distancia << " km" << endl;
        cout << "Costo final: " << costo << endl;
        cout << "-- Remitente --" << endl;
        remitente.mostrarInfo();
        cout << "-- Paquete --" << endl;
        paquete.mostrarInfo();
      
    }
};

int main() {
    Remitente rem1(12345678, "Juan Perez");
    rem1.mostrarInfo();
    cout << endl;

    rem1.setTipoRemitente(EMPRESA);
    rem1.mostrarInfo();
    cout << endl;

    Paquete paq1(101, 8, NORMAL);
    paq1.mostrarInfo();
    cout << endl;

    Paquete paqInvalido(102, -5, NORMAL);
    cout << endl;

    paq1.setPeso(12);
    paq1.mostrarInfo();
    cout << endl;

    paq1.setPeso(0);
    cout << endl;

    Envio envio1(1, "La Paz", rem1, paq1, 50);
    envio1.mostrarInfo();
    cout << endl;

    Envio envioInvalido(2, "Santa Cruz", rem1, paq1, -10);
    cout << endl;

    cout << "Costo base: " << envio1.calcularCostoBase() << endl;
    cout << "Costo final: " << envio1.calcularCostoFinal() << endl << endl;

    Remitente rem2(87654321, "Maria Lopez");
    Paquete paq2(103, 15, EXPRESS);
    Envio envio2(3, "Cochabamba", rem2, paq2, 30);
    envio2.mostrarInfo();
    cout << endl;

    envio1.setDistancia(80);
    envio1.mostrarInfo();
    cout << endl;

    envio1.setDistancia(-20);
    cout << endl;

    envio1.setTipoEnvio(EXPRESS);
    envio1.mostrarInfo();
    cout << endl;

    return 0;
}
