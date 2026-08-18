#include <iostream>
#include <string>
using namespace std;

class Cliente {
private:
    int CI;
    string nombre;
    int anioAntiguo;
public:
    Cliente() {
        nombre = " "
            CI=0;
        anioAntiguo = 0;
    }
    Cliente(const string& nombre, int CI, int AnioAntiguo):
    nombre(nombre), CI(CI), anioAntiguo(AnioAntiguo)
    {
    }
    void setAniosAntiguedad(int anios) {
        if (anios > 0) {
            AnioAntiguo = anios;
        }
        else {
            cout << "Error: los anios de antiguedad deben ser mayores que 0."
                << endl;
        }
    }
    string getNombre() {
        return nombre;
    }
    void mostraCli() {
        cout << "CI"<< <<endl;
        cout << "Nombre"<< <<endl;
        cout << "Anio Antiguo"<<anioAntiguo <<endl;

    }
};



int main()
{
    
}

