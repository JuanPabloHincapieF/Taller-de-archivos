#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Cliente
{
    string nombre;
    string cedula;
    string tamanoPizza;
};

struct Pizzeria
{
    Cliente Piz[100];
};

int main()
{
    ifstream archivoEntrada("datos.txt");
    ofstream archivoSalida("salida.txt");

    if (!archivoEntrada)
    {
        cout << "No se pudo abrir el archivo de entrada." << endl;
        return 1;
    }

    if (!archivoSalida)
    {
        cout << "No se pudo abrir el archivo de salida." << endl;
        return 1;
    }

    int numClientes;
    archivoEntrada >> numClientes;

    Pizzeria pizzeria;

    for (int i = 0; i < numClientes; i++)
    {
        archivoEntrada >> pizzeria.Piz[i].nombre;
        archivoEntrada >> pizzeria.Piz[i].cedula;
        archivoEntrada >> pizzeria.Piz[i].tamanoPizza;
    }

    const int costoPizzaPequena = 7000;
    const int costoPizzaMediana = 12000;
    const int costoPizzaGrande = 23000;

    int totalClientesGrande = 0;
    double precioVentaTotal = 0.0;

    for (int i = 0; i < numClientes; i++)
    {
        double precioVenta = 0.0;

        if (pizzeria.Piz[i].tamanoPizza == "pequena")
        {
            precioVenta = 1.5 * costoPizzaPequena;
        }
        else if (pizzeria.Piz[i].tamanoPizza == "mediana")
        {
            precioVenta = 1.5 * costoPizzaMediana;
        }
        else if (pizzeria.Piz[i].tamanoPizza == "grande")
        {
            precioVenta = 1.5 * costoPizzaGrande;
            totalClientesGrande++;
        }

        precioVentaTotal += precioVenta;

        archivoSalida << "Cliente: " << pizzeria.Piz[i].nombre << endl;
        archivoSalida << "Tamano de la pizza: " << pizzeria.Piz[i].tamanoPizza << endl;
        archivoSalida << "Precio de venta: " << precioVenta << endl;
        archivoSalida << endl;
    }

    double porcentajeClientesGrande = (static_cast<double>(totalClientesGrande) / numClientes) * 100;

    archivoSalida << "Porcentaje de clientes que compraron pizzas de tamano grande: " << porcentajeClientesGrande << "%" << endl;

    archivoEntrada.close();
    archivoSalida.close();

    cout << "El programa se ha ejecutado correctamente. Se ha generado el archivo de salida 'salida.txt'." << endl;

    return 0;
}
