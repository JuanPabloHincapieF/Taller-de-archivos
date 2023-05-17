#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Pan
{
    string tipo;
    int codigo;
    double precio;
    int cantidad;
};

void ingresarDatos()
{
    ofstream archivo("datos_panaderia.txt", ios::app);
    if (!archivo)
    {
        cout << "Error al abrir el archivo." << endl;
        return;
    }

    Pan pan;

    cout << "Ingrese el tipo de pan: ";
    cin >> pan.tipo;

    cout << "Ingrese el codigo del pan: ";
    cin >> pan.codigo;

    cout << "Ingrese el precio del pan: ";
    cin >> pan.precio;

    cout << "Ingrese la cantidad horneada del pan: ";
    cin >> pan.cantidad;

    archivo << pan.tipo << " " << pan.codigo << " " << pan.precio << " " << pan.cantidad << endl;

    archivo.close();
    cout << "Datos ingresados correctamente." << endl;
}

void cantidadPanesHorneados()
{
    ifstream archivo("datos_panaderia.txt");
    if (!archivo)
    {
        cout << "Error al abrir el archivo." << endl;
        return;
    }

    int codigo;
    int totalHorneados = 0;

    cout << "Ingrese el codigo del pan: ";
    cin >> codigo;

    Pan pan;
    while (archivo >> pan.tipo >> pan.codigo >> pan.precio >> pan.cantidad)
    {
        if (pan.codigo == codigo)
        {
            totalHorneados += pan.cantidad;
        }
    }

    archivo.close();
    cout << "La cantidad total de panes horneados con el codigo " << codigo << " es: " << totalHorneados << endl;
}

void valorPanPorTipo()
{
    ifstream archivo("datos_panaderia.txt");
    if (!archivo)
    {
        cout << "Error al abrir el archivo." << endl;
        return;
    }

    string tipo;
    double valorTotal = 0.0;

    cout << "Ingrese el tipo de pan: ";
    cin >> tipo;

    Pan pan;
    while (archivo >> pan.tipo >> pan.codigo >> pan.precio >> pan.cantidad)
    {
        if (pan.tipo == tipo)
        {
            valorTotal += pan.cantidad * pan.precio;
        }
    }

    archivo.close();
    cout << "El valor total del pan de tipo " << tipo << " es: " << valorTotal << endl;
}

void numeroVecesHorneado()
{
    ifstream archivo("datos_panaderia.txt");
    if (!archivo)
    {
        cout << "Error al abrir el archivo." << endl;
        return;
    }

    string tipo;
    int vecesHorneado = 0;

    cout << "Ingrese el tipo de pan: ";
    cin >> tipo;

    Pan pan;
    while (archivo >> pan.tipo >> pan.codigo >> pan.precio >> pan.cantidad)
    {
        if (pan.tipo == tipo)
        {
            vecesHorneado++;
        }
    }

    archivo.close();
    cout << "El pan de tipo " << tipo << " ha sido horneado " << vecesHorneado << " veces." << endl;
}

int main()
{
    int opcion;

    do
    {
        cout << "Menu" << endl;
        cout << "1. Ingresar Datos" << endl;
        cout << "2. Cantidad de panes horneados a partir del codigo" << endl;
        cout << "3. Valor del pan segun su tipo (cantidad * precio)" << endl;
        cout << "4. Numero de veces de horneado de un tipo de pan" << endl;
        cout << "5. Terminar" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            ingresarDatos();
            break;
        case 2:
            cantidadPanesHorneados();
            break;
        case 3:
            valorPanPorTipo();
            break;
        case 4:
            numeroVecesHorneado();
            break;
        case 5:
            cout << "Terminando el programa." << endl;
            break;
        default:
            cout << "Opcion invalida. Intente nuevamente." << endl;
            break;
        }

        cout << endl;
    } while (opcion != 5);

    return 0;
}