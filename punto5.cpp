#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Disco
{
    string titulo;
    string nombreCantante;
    string apellidoCantante;
    int anioProduccion;
    double costoProduccion;
    string bandaSonora;
};

void agregarDisco(ofstream &archivo)
{
    Disco nuevoDisco;

    cout << "Ingrese el titulo del disco: ";
    getline(cin, nuevoDisco.titulo);
    cout << "Ingrese el nombre del cantante: ";
    getline(cin, nuevoDisco.nombreCantante);
    cout << "Ingrese el apellido del cantante: ";
    getline(cin, nuevoDisco.apellidoCantante);
    cout << "Ingrese el ano de produccion: ";
    cin >> nuevoDisco.anioProduccion;
    cout << "Ingrese el costo de produccion: ";
    cin >> nuevoDisco.costoProduccion;

    cout << "Ingrese la banda sonora: ";
    getline(cin, nuevoDisco.bandaSonora);

    archivo.write(reinterpret_cast<const char *>(&nuevoDisco), sizeof(Disco));
}

void mostrarDiscosPorAnio(ifstream &archivo, int anio)
{
    Disco disco;
    bool encontrado = false;

    archivo.seekg(0, ios::beg);

    while (archivo.read(reinterpret_cast<char *>(&disco), sizeof(Disco)))
    {
        if (disco.anioProduccion == anio)
        {
            cout << "Titulo: " << disco.titulo << endl;
            cout << "Cantante: " << disco.nombreCantante << " " << disco.apellidoCantante << endl;
            cout << "Ano de produccion: " << disco.anioProduccion << endl;
            cout << "Costo de produccion: " << disco.costoProduccion << endl;
            cout << "Banda sonora: " << disco.bandaSonora << endl
                 << endl;
            encontrado = true;
        }
    }

    if (!encontrado)
    {
        cout << "No se encontraron discos producidos en el ano " << anio << endl;
    }
}

void mostrarCostosYAnios(ifstream &archivo, int anioInicio)
{
    Disco disco;
    double totalInvertido = 0.0;

    archivo.seekg(0, ios::beg);

    while (archivo.read(reinterpret_cast<char *>(&disco), sizeof(Disco)))
    {
        if (disco.anioProduccion >= anioInicio)
        {
            cout << "Ano de produccion: " << disco.anioProduccion << endl;
            cout << "Costo de produccion: " << disco.costoProduccion << endl
                 << endl;
            totalInvertido += disco.costoProduccion;
        }
    }

    cout << "Total invertido en produccion desde el ano " << anioInicio << ": " << totalInvertido << endl;
}

int main()
{
    ofstream archivoSalida("discos.dat", ios::binary | ios::app);
    if (!archivoSalida)
    {
        cerr << "Error al abrir el archivo de salida." << endl;
        return 1;
    }

    ifstream archivoEntrada("discos.dat", ios::binary);

    if (!archivoEntrada)
    {
        cerr << "Error al abrir el archivo de entrada." << endl;
        return 1;
    }

    int opcion;
    int anio;
    int anioInicio;

    do
    {
        cout << "==== Menu ====" << endl;
        cout << "1. Agregar disco" << endl;
        cout << "2. Mostrar discos producidos en un ano especifico" << endl;
        cout << "3. Mostrar costos y ano de produccion desde el ano 2010" << endl;
        cout << "4. Mostrar total invertido en produccion desde el ano 2010" << endl;
        cout << "5. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            agregarDisco(archivoSalida);
            break;
        case 2:
            cout << "Ingrese el ano: ";
            cin >> anio;

            mostrarDiscosPorAnio(archivoEntrada, anio);
            break;
        case 3:
            anioInicio = 2010;
            mostrarCostosYAnios(archivoEntrada, anioInicio);
            break;
        case 4:
            anioInicio = 2010;
            mostrarCostosYAnios(archivoEntrada, anioInicio);
            break;
        case 5:
            cout << "Saliendo del programa..." << endl;
            break;
        default:
            cout << "Opcion invalida. Intente nuevamente." << endl;
        }

        cout << endl;
    } while (opcion != 5);

    archivoSalida.close();
    archivoEntrada.close();

    return 0;
}