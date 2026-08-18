//Ejercicio 3: Cuenta Bancaria


#include <iostream>
#include <string>
using namespace std;

enum class TipoCliente { NORMAL, PREMIUM };
enum class EstadoTarjeta { BLOQUEADA, ACTIVA };

class Cliente {
private:
    string ci;
    string nombre;
    TipoCliente tipoCliente;

public:
    Cliente(string ci, string nombre) {
        this->ci = ci;
        this->nombre = nombre;
        this->tipoCliente = TipoCliente::NORMAL;
    }

    void mostrarInfo() const {
        cout << "  Cliente -> CI: " << ci << " | Nombre: " << nombre
             << " | Tipo: " << (tipoCliente == TipoCliente::NORMAL ? "NORMAL" : "PREMIUM") << endl;
    }
};

class Tarjeta {
private:
    string numero;
    double limiteRetiro;
    EstadoTarjeta estado;

public:
    Tarjeta(string numero, double limiteRetiro, EstadoTarjeta estado) {
        this->numero = numero;
        if (limiteRetiro <= 0) {
            cout << "  [ERROR] limiteRetiro invalido, se asigna 1000 por defecto." << endl;
            this->limiteRetiro = 1000;
        } else {
            this->limiteRetiro = limiteRetiro;
        }
        this->estado = estado;
    }

    double getLimiteRetiro() const { return limiteRetiro; }
    EstadoTarjeta getEstado() const { return estado; }

    void mostrarInfo() const {
        cout << "  Tarjeta -> Numero: " << numero << " | Limite: " << limiteRetiro
             << " | Estado: " << (estado == EstadoTarjeta::ACTIVA ? "ACTIVA" : "BLOQUEADA") << endl;
    }
};

class CuentaBancaria {
private:
    string numeroCuenta;
    double saldo;
    Cliente cliente;
    Tarjeta tarjeta;

public:
    CuentaBancaria(string numeroCuenta, double saldo, Cliente cliente, Tarjeta tarjeta)
        : cliente(cliente), tarjeta(tarjeta) {
        this->numeroCuenta = numeroCuenta;
        if (saldo < 0) {
            cout << "  [ERROR] saldo negativo, se asigna 0." << endl;
            this->saldo = 0;
        } else {
            this->saldo = saldo;
        }
    }

    void mostrarInfo() const {
        cout << "Cuenta N. " << numeroCuenta << " | Saldo: " << saldo << endl;
        cliente.mostrarInfo();
        tarjeta.mostrarInfo();
    }

    void retirar(double monto) {
        if (tarjeta.getEstado() == EstadoTarjeta::BLOQUEADA) {
            cout << "  [ERROR] Tarjeta bloqueada, no se permite retiro." << endl;
            return;
        }
        if (monto <= 0 || monto > tarjeta.getLimiteRetiro() || monto > saldo) {
            cout << "  [ERROR] Retiro invalido." << endl;
            return;
        }
        saldo -= monto;
        cout << "  Retiro exitoso. Nuevo saldo: " << saldo << endl;
    }

    void depositar(double monto) {
        if (monto <= 0) {
            cout << "  [ERROR] Deposito invalido." << endl;
            return;
        }
        saldo += monto;
        cout << "  Deposito exitoso. Nuevo saldo: " << saldo << endl;
    }
};

int main() {
    cout << "===== EJERCICIO 3: CUENTA BANCARIA (version parcial) =====" << endl << endl;

    Cliente cli1("V-12345678", "Ana Perez");
    return 0;
}
