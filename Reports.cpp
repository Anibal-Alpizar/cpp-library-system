
#include <iostream>
#include <fstream>
#include <iomanip> // Agregar la biblioteca iomanip para usar setw()
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




void mostrarReportePedidosPendientes()
{
    ifstream archivoPedidos("Pedidos.txt");

    if (!archivoPedidos.is_open())
    {
        cout << "Error al abrir el archivo de pedidos." << endl;
        return;
    }

    cout << "Reporte de Pedidos Pendientes de Envío" << endl;
    cout << setw(15) << "Código pedido" << setw(30) << "Nombre Pedido" << setw(20) << "Codigo Producto" << setw(15) << "Cantidad" << setw(15) << "Enviado (S/N)" << endl;

    int codigoPedido, codigoProducto, cantidad;
    char enviado;
    string nombrePedido, palabra;

    while (archivoPedidos >> codigoPedido >> nombrePedido)
    {
        archivoPedidos >> palabra; // Leer "pedido" o cualquier otra palabra no necesaria para el reporte
        archivoPedidos >> codigoProducto >> nombrePedido >> cantidad >> enviado;

        if (enviado == 'N')
        {
            cout << setw(15) << codigoPedido << setw(30) << nombrePedido << setw(20) << codigoProducto << setw(15) << cantidad << setw(15) << enviado << endl;
        }
    }

    archivoPedidos.close();
}
