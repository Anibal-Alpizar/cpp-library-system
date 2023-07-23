
#include <iostream>
#include <fstream>
#include <iomanip> // Agregar la biblioteca iomanip para usar setw()
#include <sstream>
#include <regex>

using namespace std;



/*


// Función para mostrar el reporte de inventario
void mostrarReporteInventario()
{
    ifstream archivoProductos("Productos.txt");

    if (!archivoProductos.is_open())
    {
        cout << "Error al abrir el archivo de productos." << endl;
        return;
    }

    cout << "Reporte de Inventario" << endl;
    cout << "Código producto\tNombre\t\t\tCantidad\tDisponible" << endl;

    int codigo;
    string nombre;
    int cantidad;

    while (archivoProductos >> codigo >> nombre >> cantidad)
    {
        // Alineamos los campos del reporte
        cout << codigo << "\t\t" << nombre << "\t\t" << cantidad << "\t\t" << cantidad << endl;
    }

    archivoProductos.close();
}




*/




void mostrarReporteInventario()
{
    ifstream archivoProductos("Productos.txt");

    if (!archivoProductos.is_open())
    {
        cout << "Error al abrir el archivo de productos." << endl;
        return;
    }

    cout << "Reporte de Inventario" << endl;
    cout << setw(15) << "Código producto" << setw(35) << "Nombre" << setw(15) << "Cantidad" << setw(15) << "Disponible" << endl;

    int codigo;
    string nombre;
    int cantidad;

    while (archivoProductos >> codigo >> nombre >> cantidad)
    {
        // Alineamos los campos del reporte usando setw()
        cout << setw(15) << codigo << setw(35) << nombre << setw(15) << cantidad << setw(15) << cantidad << endl;
    }

    archivoProductos.close();
}


// Function to generate a report of products that have not been sent (status 'N')
void generarReporteNoEnviados()
{
    ifstream archivoPedidos("Pedidos.txt");
    string linea;

    cout << "Reporte de Productos No Enviados:" << endl;
    cout << left << setw(15) << "Pedido" << setw(20) << "Nombre" << setw(10) << "Código" << setw(10) << "Cantidad" << "Enviado" << endl;
    cout << setfill('-') << setw(67) << "-" << setfill(' ') << endl;

    bool foundNoEnviados = false;
    regex regexPattern("^(\\d+) (\\S+) pedido (\\d+) (\\d+) (N)$");

    while (getline(archivoPedidos, linea))
    {
        smatch matches;
        if (regex_search(linea, matches, regexPattern))
        {
            int codigoLeido = stoi(matches[1]);
            string nombrePedido = matches[2];
            int codigoProducto = stoi(matches[3]);
            int cantidadProducto = stoi(matches[4]);
            char enviado = matches[5].str()[0];

            foundNoEnviados = true;
            cout << left << setw(15) << codigoLeido << setw(20) << nombrePedido << setw(10) << codigoProducto << setw(10) << cantidadProducto << enviado << endl;
        }
    }

    archivoPedidos.close();

    if (!foundNoEnviados)
    {
        cout << "No se encontraron productos no enviados." << endl;
    }
}
