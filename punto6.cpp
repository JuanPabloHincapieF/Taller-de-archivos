#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int MAX_PACIENTES = 100;

struct Paciente
{
    string nombre;
    string cedula;
    int nivelGlucosa;
};

int main()
{
    int numPacientes;

    cout << "Ingrese la cantidad de pacientes a evaluar: ";
    cin >> numPacientes;

    // Verificar que no se exceda el límite máximo de pacientes
    if (numPacientes > MAX_PACIENTES)
    {
        cout << "La cantidad de pacientes excede el límite máximo." << endl;
        return 1;
    }

    Paciente Pac[MAX_PACIENTES];

    ifstream archivo("historial.txt");

    if (!archivo)
    {
        cout << "Error al abrir el archivo historial.txt" << endl;
        return 1;
    }

    // Leer los datos de los pacientes desde el archivo
    for (int i = 0; i < numPacientes; i++)
    {
        archivo >> Pac[i].nombre >> Pac[i].cedula >> Pac[i].nivelGlucosa;
    }

    archivo.close();

    // Evaluar los niveles de glucosa de cada paciente
    for (int i = 0; i < numPacientes; i++)
    {
        cout << "Paciente " << i + 1 << ": " << Pac[i].nombre << endl;
        cout << "Cedula: " << Pac[i].cedula << endl;
        cout << "Nivel de glucosa: " << Pac[i].nivelGlucosa << endl;

        if (Pac[i].nivelGlucosa >= 70 && Pac[i].nivelGlucosa <= 100)
        {
            cout << "Niveles normales de glucosa..." << endl;
        }
        else if (Pac[i].nivelGlucosa >= 101 && Pac[i].nivelGlucosa <= 140)
        {
            cout << "Paciente con diabetes..." << endl;
        }
        else
        {
            cout << "Niveles de glucosa inválidos..." << endl;
        }

        cout << endl;
    }

    return 0;
}
