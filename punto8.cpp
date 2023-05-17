#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int MAX_USUARIOS = 100;

struct Cinema
{
    string nombre;
    string identificacion;
    int edad;
};

int main()
{
    Cinema cin[MAX_USUARIOS];
    int numUsuarios = 0;
    int numIncumplidos = 0;

    ifstream archivoUsuarios("usuarios.txt");
    if (!archivoUsuarios)
    {
        cerr << "No se pudo abrir el archivo usuarios.txt" << endl;
        return 1;
    }

    while (archivoUsuarios >> cin[numUsuarios].nombre >> cin[numUsuarios].identificacion >> cin[numUsuarios].edad)
    {
        if (cin[numUsuarios].edad > 12)
        {
            numIncumplidos++;
        }
        numUsuarios++;
    }

    archivoUsuarios.close();

    ofstream archivoRestriccion("restriccion.txt");
    if (!archivoRestriccion)
    {
        cerr << "No se pudo abrir el archivo restriccion.txt" << endl;
        return 1;
    }

    for (int i = 0; i < numUsuarios; i++)
    {
        if (cin[i].edad > 12)
        {
            archivoRestriccion << "Nombre: " << cin[i].nombre << endl;
            archivoRestriccion << "Identificación: " << cin[i].identificacion << endl;
            archivoRestriccion << "Edad: " << cin[i].edad << endl;
            archivoRestriccion << endl;
        }
    }

    archivoRestriccion << "Cantidad de usuarios que incumplieron la restricción: " << numIncumplidos << endl;

    archivoRestriccion.close();

    cout << "Proceso completado. Se ha generado el archivo restriccion.txt." << endl;

    return 0;
}
