#include <iostream>
#include <fstream>

using namespace std;

struct Paciente
{
    string nombre;
    string cedula;
    int nivelGlucosa;
};

int main()
{
    int cantidadPacientes;
    ifstream archivoEntrada("historial.txt");
    ofstream archivoSalida("resultados.txt");
    Paciente Pac[100];

    if (!archivoEntrada.is_open())
    {
        cout << "Error al abrir el archivo historial.txt" << endl;
        return 1;
    }

    if (!archivoSalida.is_open())
    {
        cout << "Error al abrir el archivo resultados.txt" << endl;
        return 1;
    }

    cout << "Ingrese la cantidad de pacientes a evaluar: ";
    cin >> cantidadPacientes;

    for (int i = 0; i < cantidadPacientes; i++)
    {
        archivoEntrada >> Pac[i].nombre >> Pac[i].cedula >> Pac[i].nivelGlucosa;
    }

    int pacientesConDiabetes = 0;

    for (int i = 0; i < cantidadPacientes; i++)
    {
        archivoSalida << "Nombre: " << Pac[i].nombre << endl;
        archivoSalida << "Cedula: " << Pac[i].cedula << endl;
        archivoSalida << "Nivel de glucosa: " << Pac[i].nivelGlucosa << endl;

        if (Pac[i].nivelGlucosa >= 70 && Pac[i].nivelGlucosa <= 100)
        {
            archivoSalida << "Niveles normales de glucosa..." << endl;
        }
        else if (Pac[i].nivelGlucosa >= 101 && Pac[i].nivelGlucosa <= 140)
        {
            archivoSalida << "Paciente con diabetes..." << endl;
            pacientesConDiabetes++;
        }
        else
        {
            archivoSalida << "Niveles de glucosa invalidos..." << endl;
        }

        archivoSalida << endl;
    }

    float porcentajeDiabetes = (pacientesConDiabetes / static_cast<float>(cantidadPacientes)) * 100;
    archivoSalida << "Porcentaje de pacientes con diabetes: " << porcentajeDiabetes << "%" << endl;

    archivoEntrada.close();
    archivoSalida.close();

    return 0;
}
