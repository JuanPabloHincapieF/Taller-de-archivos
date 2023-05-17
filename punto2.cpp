#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Reserva
{
    string codigoPelicula;
    string cedulaCliente;
    int cupos;
    string ubicacion;
};

void ingresarReserva()
{
    Reserva reserva;

    cout << "Ingrese el codigo de la pelicula: ";
    cin >> reserva.codigoPelicula;

    cout << "Ingrese la cedula del cliente: ";
    cin >> reserva.cedulaCliente;

    cout << "Ingrese el numero de cupos: ";
    cin >> reserva.cupos;

    cout << "Ingrese la ubicacion (centro, lateral izquierda, lateral derecha, centro arriba, centro abajo): ";
    cin >> reserva.ubicacion;

    ofstream archivo("reservas.txt", ios::app);
    archivo << reserva.codigoPelicula << " " << reserva.cedulaCliente << " "
            << reserva.cupos << " " << reserva.ubicacion << endl;
    archivo.close();

    cout << "Reserva agregada exitosamente." << endl;
}

void ubicarReserva()
{
    string cedula;

    cout << "Ingrese la cedula del cliente: ";
    cin >> cedula;

    ifstream archivo("reservas.txt");
    string codigoPelicula;
    string cedulaCliente;
    int cupos;
    string ubicacion;
    bool encontrada = false;

    while (archivo >> codigoPelicula >> cedulaCliente >> cupos >> ubicacion)
    {
        if (cedulaCliente == cedula)
        {
            encontrada = true;
            cout << "Reserva encontrada:" << endl;
            cout << "Codigo de la pelicula: " << codigoPelicula << endl;
            cout << "Cedula del cliente: " << cedulaCliente << endl;
            cout << "Numero de cupos: " << cupos << endl;
            cout << "Ubicacion: " << ubicacion << endl;
            break;
        }
    }

    if (!encontrada)
    {
        cout << "No se encontro ninguna reserva con la cedula ingresada." << endl;
    }

    archivo.close();
}

void eliminarReserva()
{
    string cedula;

    cout << "Ingrese la cedula del cliente: ";
    cin >> cedula;

    ifstream archivo("reservas.txt");
    ofstream archivoTemporal("temp.txt");

    string codigoPelicula;
    string cedulaCliente;
    int cupos;
    string ubicacion;
    bool encontrada = false;

    while (archivo >> codigoPelicula >> cedulaCliente >> cupos >> ubicacion)
    {
        if (cedulaCliente != cedula)
        {
            archivoTemporal << codigoPelicula << " " << cedulaCliente << " "
                            << cupos << " " << ubicacion << endl;
        }
        else
        {
            encontrada = true;
        }
    }

    archivo.close();
    archivoTemporal.close();

    remove("reservas.txt");
    rename("temp.txt", "reservas.txt");

    if (encontrada)
    {
        cout << "Reserva eliminada exitosamente." << endl;
    }
    else
    {
        cout << "No se encontro ninguna reserva con la cedula ingresada." << endl;
    }
}

int main()
{
    int opcion;

    do
    {
        cout << "----- Menu -----" << endl;
        cout << "1. Ingresar una reserva." << endl;
        cout << "2. Ubicar una reserva con la cedula del usuario." << endl;
        cout << "3. Eliminar (cancelar) una reserva." << endl;
        cout << "4. Salir." << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            ingresarReserva();
            break;
        case 2:
            ubicarReserva();
            break;
        case 3:
            eliminarReserva();
            break;
        case 4:
            cout << "Saliendo del programa..." << endl;
            break;
        default:
            cout << "Opcion invalida. Por favor, ingrese una opcion valida." << endl;
        }

        cout << endl;
    } while (opcion != 4);

    return 0;
}
