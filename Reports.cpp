
#include <iostream>
#include <fstream>
#include <iomanip> // Agregar la biblioteca iomanip para usar setw()
#include <sstream>

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


void generarReporteNoEnviados()
{
    ifstream archivoPedidos("Pedidos.txt");
    string linea;

    cout << "Reporte de Productos No Enviados:" << endl;
    cout << left << setw(15) << "Código pedido" << setw(20) << "Nombre Pedido" << setw(15) << "Código Producto" << setw(10) << "Cantidad" << setw(15) << "Enviado (S/N)" << endl;
    cout << setfill('-') << setw(75) << "-" << setfill(' ') << endl;

    bool foundNoEnviados = false;

    while (getline(archivoPedidos, linea))
    {
        char enviado = linea.back(); // Get the last character of the line

        if (enviado == 'N')
        {
            // Remove the last character 'N' before processing the rest of the line
            linea.pop_back();

            istringstream iss(linea);
            int codigoPedido, codigoProducto, cantidadProducto;
            string nombrePedido;
            iss >> codigoPedido >> nombrePedido >> codigoProducto >> cantidadProducto;

            foundNoEnviados = true;
            cout << left << setw(15) << codigoPedido << setw(20) << nombrePedido << setw(15) << codigoProducto << setw(10) << cantidadProducto << setw(15) << enviado << endl;
        }
    }

    archivoPedidos.close();

    if (!foundNoEnviados)
    {
        cout << "No se encontraron productos no enviados." << endl;
    }
}

