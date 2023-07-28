#include <iostream>
#include "Products.cpp"
#include "Orders.cpp"
#include "reports.cpp"

using namespace std;


// Función para el submenú de Inventario Productos
void menuInventarioProductos()
{
    int opcion;

    do
    {
        cout << "\nInventario Productos" << endl;
        cout << "1. Ingresar producto" << endl;
        cout << "2. Consultar producto (Por código)" << endl;
        cout << "3. Eliminar producto" << endl;
        cout << "4. Volver al menú principal" << endl;

        cout << "Ingresa el número de opción: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            cout << "Haz presionado la opción 1: Ingresar producto" << endl;
            ingresarProducto();
            break;
        case 2:
            cout << "Haz presionado la opción 2: Consultar producto (Por código)" << endl;
            int codigoConsultar;
            cout << "Ingresa el código del producto a consultar: ";
            cin >> codigoConsultar;
            consultarProductoPorCodigo(codigoConsultar);
            break;
        case 3:
            cout << "Haz presionado la opción 3: Eliminar producto" << endl;
            int codigoEliminar;
            cout << "Ingresa el código del producto a eliminar: ";
            cin >> codigoEliminar;
            eliminarProductoPorCodigo(codigoEliminar);
            break;
        case 4:
            cout << "Haz presionado la opción 4: Volver al menú principal" << endl;
            break;
        default:
            cout << "Opción no válida. Inténtalo nuevamente." << endl;
        }
    }
    while (opcion != 4);
}

int main()
{
    int opcion;

    do
    {
        cout << "\nSoftware para libreria" << endl;
        cout << "1. Inventario productos" << endl;
        cout << "2. Generar pedido" << endl;
        cout << "3. Enviar Pedido" << endl;
        cout << "4. Reporte Inventario" << endl;
        cout << "5. Reporte Pedidos Pendientes" << endl;
        cout << "6. Salir del Programa" << endl;

        cout << "Ingresa el número de opción: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            cout << "Haz presionado la opción 1: Inventario productos" << endl;
            menuInventarioProductos(); // Llamar al submenú de Inventario Productos
            break;
        case 2:
            cout << "Haz presionado la opción 2: Generar pedido" << endl;
            generarPedido();
            break;
        case 3:
            cout << "Haz presionado la opción 3: Enviar Pedido" << endl;
            enviarPedido();
            break;
        case 4:
            cout << "Haz presionado la opción 4: Reporte Inventario" << endl;
            mostrarReporteInventario();
            break;
        case 5:
            cout << "Haz presionado la opción 5: Reporte Pedidos Pendientes" << endl;
            generarReporteNoEnviados();
            break;
        case 6:
            cout << "Haz presionado la opción 6: Salir del Programa" << endl;
            break;
        default:
            cout << "Opción no válida. Inténtalo nuevamente." << endl;
        }
    }
    while (opcion != 6);

    cout << "¡Hasta luego! El programa ha sido cerrado." << endl;

    return 0;
}
