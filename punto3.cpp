#include <iostream>
#include <fstream>
using namespace std;

const int MAX_CICLISTAS = 100;
const int MAX_ETAPAS = 10;

struct Etapa
{
    int numeroEtapa;
    float tiempo;
};

struct Ciclista
{
    int numeroCiclista;
    Etapa etapas[MAX_ETAPAS];
    int numEtapas;
};

void guardarDatos(ofstream &archivo, const Ciclista &ciclista)
{
    archivo << "Ciclista: " << ciclista.numeroCiclista << endl;
    float tiempoTotal = 0.0f;
    for (int i = 0; i < ciclista.numEtapas; i++)
    {
        archivo << "Etapa " << ciclista.etapas[i].numeroEtapa << ": " << ciclista.etapas[i].tiempo << " segundos" << endl;
        tiempoTotal += ciclista.etapas[i].tiempo;
    }
    archivo << "Tiempo total: " << tiempoTotal << " segundos" << endl;
    archivo << endl;
}

int main()
{
    ofstream archivo("competencia.txt");
    if (!archivo)
    {
        cerr << "No se pudo abrir el archivo." << endl;
        return 1;
    }

    Ciclista ciclistas[MAX_CICLISTAS];
    int numCiclistas = 0;

    while (true)
    {
        int numeroCiclista, numeroEtapa;
        float tiempo;
        cout << "Ingrese el numero del ciclista (0 para finalizar): ";
        cin >> numeroCiclista;
        if (numeroCiclista == 0)
        {
            break;
        }
        cout << "Ingrese el numero de la etapa: ";
        cin >> numeroEtapa;
        cout << "Ingrese el tiempo utilizado (en segundos): ";
        cin >> tiempo;

        int index = -1;
        for (int i = 0; i < numCiclistas; i++)
        {
            if (ciclistas[i].numeroCiclista == numeroCiclista)
            {
                index = i;
                break;
            }
        }

        if (index == -1)
        {
            if (numCiclistas == MAX_CICLISTAS)
            {
                cerr << "Se ha alcanzado el numero maximo de ciclistas." << endl;
                break;
            }
            index = numCiclistas;
            ciclistas[index].numeroCiclista = numeroCiclista;
            ciclistas[index].numEtapas = 0;
            numCiclistas++;
        }

        if (ciclistas[index].numEtapas == MAX_ETAPAS)
        {
            cerr << "Se ha alcanzado el numero maximo de etapas para el ciclista." << endl;
            break;
        }
        ciclistas[index].etapas[ciclistas[index].numEtapas] = {numeroEtapa, tiempo};
        ciclistas[index].numEtapas++;
    }

    for (int i = 0; i < numCiclistas; i++)
    {
        guardarDatos(archivo, ciclistas[i]);
    }

    archivo.close();

    int ciclistaGanador = 0;
    float tiempoGanador = 0.0;

    for (int i = 0; i < numCiclistas; i++)
    {
        float tiempoTotal = 0.0;
        for (int j = 0; j < ciclistas[i].numEtapas; j++)
        {
            tiempoTotal += ciclistas[i].etapas[j].tiempo;
        }
        if (tiempoTotal < tiempoGanador || tiempoGanador == 0.0)
        {
            ciclistaGanador = ciclistas[i].numeroCiclista;
            tiempoGanador = tiempoTotal;
        }
    }

    cout << "El ciclista ganador es: " << ciclistaGanador << " con un tiempo total de " << tiempoGanador << " segundos." << endl;

    return 0;
}