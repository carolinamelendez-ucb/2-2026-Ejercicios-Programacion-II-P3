#pragma once
#include <iostream>
#include <string>

using namespace std;


class Exception {
protected:
    string mensaje;
public:
    Exception() {
        this->mensaje = "";
    }
    string getMensaje() {
        return this->mensaje;
    }
};


class ClientDuplicadoException : public Exception {
public:
    ClientDuplicadoException() {
        this->mensaje = "Error: Cliente Duplicado ";
    }
};

class PaqueteDuplicadoException : public Exception {
public:
    PaqueteDuplicadoException() {
        this->mensaje = "Error: ete sech duplicado ";
    }
};

class ClienteNoEncontradoException : public Exception {
public:
    ClienteNoEncontradoException() {
        this->mensaje = "error no encontrado";
    }
};


class EnvioNoEncontradoException : public Exception {
public:
    EnvioNoEncontradoException() {
        this->mensaje = "no encontrado";
    }
};




class PesoMaximoExedido : public Exception {
public:
    PesoMaximoExedido() {
        this->mensaje = "mucho peso";
    }
};






