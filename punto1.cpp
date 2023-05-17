#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Edificacion
{
    string direccion;
    double area_construida;
    double area_lote;
    string cedula_dueno;
    string cedula_catastral;
    double precio;
    string barrio;
};

void guardar_edificacion(Edificacion e)
{
    ofstream archivo("edificaciones.txt", ios::app);
    archivo << e.direccion << ";" << e.area_construida << ";" << e.area_lote << ";"
            << e.cedula_dueno << ";" << e.cedula_catastral << ";" << e.precio << ";" << e.barrio << endl;
    archivo.close();
}

void mostrar_edificacion(string cedula_catastral)
{
    ifstream archivo("edificaciones.txt");
    string linea;
    while (getline(archivo, linea))
    {
        string token;
        size_t pos = 0;
        int i = 0;
        string datos[7];

        while ((pos = linea.find(';')) != string::npos)
        {
            token = linea.substr(0, pos);
            datos[i] = token;
            linea.erase(0, pos + 1);
            i++;
        }
        datos[i] = linea;

        if (datos[4] == cedula_catastral)
        {
            cout << "Direccion: " << datos[0] << endl;
            cout << "Area construida: " << datos[1] << endl;
            cout << "Area lote: " << datos[2] << endl;
            cout << "Cedula del dueno: " << datos[3] << endl;
            cout << "Cedula catastral: " << datos[4] << endl;
            cout << "Precio: " << datos[5] << endl;
            cout << "Barrio: " << datos[6] << endl;
            archivo.close();
            return;
        }
    }
    cout << "No se encontro ninguna edificación con la cédula catastral proporcionada." << endl;
    archivo.close();
}

int main()
{
    int opcion;
    do
    {
        cout << "1. Agregar edificacion" << endl;
        cout << "2. Buscar edificacion por cedula catastral" << endl;
        cout << "3. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        switch (opcion)
        {
        case 1:
        {
            Edificacion e;
            cout << "Ingrese la direccion: ";
            cin >> e.direccion;
            cout << "Ingrese el area construida: ";
            cin >> e.area_construida;
            cout << "Ingrese el area del lote: ";
            cin >> e.area_lote;
            cout << "Ingrese la cedula del dueno: ";
            cin >> e.cedula_dueno;
            cout << "Ingrese la cedula catastral: ";
            cin >> e.cedula_catastral;
            cout << "Ingrese el precio: ";
            cin >> e.precio;
            cout << "Ingrese el barrio: ";
            cin >> e.barrio;
            guardar_edificacion(e);
            cout << "La edificacion ha sido agregada exitosamente." << endl;
            break;
        }
        case 2:
        {
            string cedula_catastral;
            cout << "Ingrese la cedula catastral: ";
            cin >> cedula_catastral;
            mostrar_edificacion(cedula_catastral);
            break;
        }
        case 3:
            cout << "Gracias por utilizar el programa." << endl;
            break;
        default:
            cout << "Opcion invalida." << endl;
            break;
        }
    } while (opcion != 3);
    return 0;
}