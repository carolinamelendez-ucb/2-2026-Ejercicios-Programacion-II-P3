#include <iostream>
#include <string>

using namespace std;

class Carrera
{
private:
    string nombre;
    int duracionAnios;
    bool cupoDisponible;

public:
    Carrera()
    {
        nombre = "";
        duracionAnios = 0;
        cupoDisponible = false;
    }

    Carrera(string nombre, int duracionAnios, bool cupoDisponible)
    {
        this->nombre = nombre;
        this->duracionAnios = duracionAnios;
        this->cupoDisponible = cupoDisponible;
    }

    string getNombre()
    {
        return nombre;
    }

    int getDuracionAnios()
    {
        return duracionAnios;
    }

    bool getCupoDisponible()
    {
        return cupoDisponible;
    }

    void mostrar()
    {
        cout << "Carrera: " << nombre << endl;
        cout << "Duracion: " << duracionAnios << " anios" << endl;

        if (cupoDisponible)
            cout << "Cupo disponible: Si" << endl;
        else
            cout << "Cupo disponible: No" << endl;
    }
};


class Estudiante
{
private:
    string nombre;
    int edad;
    Carrera carrera;

public:
    Estudiante()
    {
        nombre = "";
        edad = 0;
    }

    Estudiante(string nombre, int edad, Carrera carrera)
        : carrera(carrera)
    {
        this->nombre = nombre;
        this->edad = edad;
    }

    string getNombre()
    {
        return nombre;
    }

    int getEdad()
    {
        return edad;
    }

    Carrera getCarrera()
    {
        return carrera;
    }

    bool puedeInscribirse()
    {
        return edad >= 18 && carrera.getCupoDisponible();
    }

    void mostrar()
    {
        cout << "Nombre: " << nombre << endl;
        cout << "Edad: " << edad << endl;
        carrera.mostrar();
    }
};


class Universidad
{
private:
    Estudiante* estudiantes;
    int cantidad;

public:
    Universidad(int cantidad)
    {
        this->cantidad = cantidad;
        estudiantes = new Estudiante[cantidad];
    }

    void cargar()
    {
        for (int i = 0; i < cantidad; i++)
        {
            string nombreEstudiante;
            int edad;

            string nombreCarrera;
            int duracion;
            bool cupo;

            cout << "Estudiante " << i + 1 << endl;

            cout << "Nombre: ";
            cin >> nombreEstudiante;

            cout << "Edad: ";
            cin >> edad;

            cout << "Carrera: ";
            cin >> nombreCarrera;

            cout << "Duracion de la carrera: ";
            cin >> duracion;

            cout << "Tiene cupo? (1 = Si, 0 = No): ";
            cin >> cupo;

            Carrera carrera(nombreCarrera, duracion, cupo);

            estudiantes[i] =
                Estudiante(nombreEstudiante, edad, carrera);
        }
    }

    void contarPuedenInscribirse()
    {
        int contador = 0;

        for (int i = 0; i < cantidad; i++)
        {
            if (estudiantes[i].puedeInscribirse())
            {
                contador++;
            }
        }

        cout << "Estudiantes que pueden inscribirse: "
            << contador << endl;
    }

    void estudianteCarreraMayorDuracion()
    {
        if (cantidad == 0)
            return;

        int posMayor = 0;

        for (int i = 1; i < cantidad; i++)
        {
            if (estudiantes[i].getCarrera().getDuracionAnios() >
                estudiantes[posMayor].getCarrera().getDuracionAnios())
            {
                posMayor = i;
            }
        }

        cout << "Estudiante con carrera de mayor duracion: "
            << estudiantes[posMayor].getNombre() << endl;
    }

    void promedioEdadConCupo()
    {
        int suma = 0;
        int contador = 0;

        for (int i = 0; i < cantidad; i++)
        {
            if (estudiantes[i].getCarrera().getCupoDisponible())
            {
                suma += estudiantes[i].getEdad();
                contador++;
            }
        }

        if (contador > 0)
        {
            cout << "Edad promedio: "
                << (double)suma / contador << endl;
        }
        else
        {
            cout << "No hay estudiantes con cupo disponible" << endl;
        }
    }

    void contarSinCupo()
    {
        int contador = 0;

        for (int i = 0; i < cantidad; i++)
        {
            if (!estudiantes[i].getCarrera().getCupoDisponible())
            {
                contador++;
            }
        }

        cout << "Estudiantes que no pueden inscribirse por falta de cupo: "
            << contador << endl;
    }

    void contarPorCarrera()
    {
        string nombreCarrera;
        int contador = 0;

        cout << "Ingrese carrera: ";
        cin >> nombreCarrera;

        for (int i = 0; i < cantidad; i++)
        {
            if (estudiantes[i].getCarrera().getNombre() == nombreCarrera)
            {
                contador++;
            }
        }

        cout << "Cantidad de estudiantes en "
            << nombreCarrera << ": "
            << contador << endl;
    }

    ~Universidad()
    {
        delete[] estudiantes;
    }
};


int main()
{
    int cantidad;
    cout << "Cantidad de estudiantes: ";
    cin >> cantidad;
    Universidad universidad(cantidad);
    universidad.cargar();
    universidad.contarPuedenInscribirse();
    universidad.estudianteCarreraMayorDuracion();
    universidad.promedioEdadConCupo();
    universidad.contarSinCupo();
    universidad.contarPorCarrera();
    return 0;
}