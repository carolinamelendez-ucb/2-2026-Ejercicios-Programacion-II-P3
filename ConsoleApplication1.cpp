// ConsoleApplication1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
using namespace std;

int main()
{
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
        string getCi()
        {
            return ci;
        }

        void setCi(string ci) {
            this->ci = ci;
        }
        string getNombre() {
            return nombre;
        }

        void setNombre(string nombre) {
            this->nombre = nombre;
        }
        int getAniosAntiguedad() {
            return aniosAntiguedad;
        }

    };
}