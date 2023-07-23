#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

// Función para verificar si un código de producto existe en el inventario
bool existeCodigoEnInventario(int codigo)
{
    ifstream archivoProductos("Productos.txt");
    int codigoLeido;
    string nombre;
    int cantidad;

    while (archivoProductos >> codigoLeido >> nombre >> cantidad)
    {
        if (codigoLeido == codigo)
        {
            archivoProductos.close();
            return true;
        }
    }

    archivoProductos.close();
    return false;
}


// Función para obtener el nombre del producto por su código
string obtenerNombreProducto(int codigo)
{
    ifstream archivoProductos("Productos.txt");
    int codigoLeido;
    string nombre;
    int cantidad;

    while (archivoProductos >> codigoLeido >> nombre >> cantidad)
    {
        if (codigoLeido == codigo)
        {
            archivoProductos.close();
            return nombre;
        }
    }

    archivoProductos.close();
    return "Producto no encontrado";
}


bool existeCodigoPedido(int codigo)
{
    ifstream archivoPedidos("Pedidos.txt");
    int codigoLeido;
    string linea;

    while (getline(archivoPedidos, linea))
    {
        istringstream iss(linea);
        iss >> codigoLeido;

        if (codigoLeido == codigo)
        {
            archivoPedidos.close();
            return true;
        }
    }

    archivoPedidos.close();
    return false;
}


int obtenerCantidadProducto(int codigo)
{
    ifstream archivoProductos("Productos.txt");
    int codigoLeido;
    string nombre;
    int cantidad;

    while (archivoProductos >> codigoLeido >> nombre >> cantidad)
    {
        if (codigoLeido == codigo)
        {
            archivoProductos.close();
            return cantidad;
        }
    }

    archivoProductos.close();
    return 0; // Si el producto no se encuentra, devolvemos 0 como cantidad predeterminada
}



// Función para generar un pedido
void generarPedido()
{
    int codigoPedido;
    string nombrePedido;
    vector<int> codigosProductos;
    vector<int> cantidadesProductos;
    int codigoProducto;
    int cantidadProducto;
    char continuar;
    bool codigoRepetido = false;

    cout << "Generar pedido" << endl;

    // Generar el código del pedido y verificar que no exista previamente
    do
    {
        codigoRepetido = false; // Reiniciar la variable de control en cada iteración
        cout << "Código del pedido: ";
        cin >> codigoPedido;

        if (existeCodigoPedido(codigoPedido))
        {
            cout << "El código del pedido ya existe. Ingresa un código diferente." << endl;
            codigoRepetido = true;
        }
    } while (codigoRepetido);

    cin.ignore(); // Limpiar el buffer después de leer el código del pedido
    cout << "Nombre del pedido: ";
    getline(cin, nombrePedido);

    do
    {
        cout << "Código del producto: ";
        cin >> codigoProducto;

        if (!existeCodigoEnInventario(codigoProducto))
        {
            cout << "El código del producto no existe en el inventario. Ingresa un código válido." << endl;
            continue;
        }

        // Obtener la cantidad disponible del producto antes de solicitar la cantidad del pedido
        int cantidadDisponible = obtenerCantidadProducto(codigoProducto);

        cout << "Cantidad del producto (disponible: " << cantidadDisponible << "): ";
        cin >> cantidadProducto;

        // Verificar si la cantidad solicitada excede la cantidad disponible en el inventario
        if (cantidadProducto <= 0 || cantidadProducto > cantidadDisponible)
        {
            cout << "Cantidad inválida. Ingresa una cantidad mayor a cero y no mayor a la cantidad disponible." << endl;
            continue;
        }

        // Resto del código...

        // Agregar los datos del producto al pedido
        codigosProductos.push_back(codigoProducto);
        cantidadesProductos.push_back(cantidadProducto);

        // Mostrar los productos que se van agregando al pedido (mostrar el nombre en lugar del ID)
        cout << "Producto agregado al pedido: " << obtenerNombreProducto(codigoProducto) << ", Cantidad " << cantidadProducto << endl;

        cout << "¿Desea agregar otro producto al pedido? (S/N): ";
        cin >> continuar;

        continuar = toupper(continuar); // Convertir el carácter ingresado a mayúscula
    } while (continuar == 'S');

    // Aquí puedes agregar la lógica para confirmar el pedido y actualizar el inventario
    // No implementaremos esto en detalle, pero debes verificar si el usuario confirma el pedido
    // y luego actualizar la cantidad de productos en el inventario.

    if (!codigosProductos.empty())
    {
        // Si el vector de productos no está vacío, se procede a guardar el pedido
        ofstream archivoPedidos("Pedidos.txt", ios::app);

        if (archivoPedidos.is_open())
        {
            archivoPedidos << codigoPedido << " " << nombrePedido;

            for (size_t i = 0; i < codigosProductos.size(); i++)
            {
                archivoPedidos << " " << codigosProductos[i] << " - " << obtenerNombreProducto(codigosProductos[i]) << " " << cantidadesProductos[i];
            }

            archivoPedidos << " N" << endl;

            archivoPedidos.close();

            cout << "Pedido generado exitosamente." << endl;
        }
        else
        {
            cout << "Error al abrir el archivo de pedidos." << endl;
        }
    }
    else
    {
        cout << "El pedido no contiene productos válidos. Se descartará el pedido." << endl;
    }
}



// Función para verificar si un pedido existe y si aún no ha sido enviado
bool verificarPedidoNoEnviado(int codigoPedido)
{
    ifstream archivoPedidos("Pedidos.txt");
    int codigoLeido;
    string nombrePedido;
    string productosInfo;

    while (getline(archivoPedidos, productosInfo))
    {
        istringstream iss(productosInfo);
        iss >> codigoLeido >> nombrePedido;

        if (codigoLeido == codigoPedido)
        {
            char enviado;
            // Leer cada producto separado por guiones
            while (iss >> productosInfo)
            {
                size_t separador = productosInfo.find_last_of('-');
                string estado = productosInfo.substr(separador + 1);
                enviado = estado[0];
            }

            archivoPedidos.close();

            // Verificar si el pedido no ha sido enviado
            if (enviado == 'N')
            {
                return true;
            }
            else
            {
                cout << "El pedido con código " << codigoPedido << " ya ha sido enviado." << endl;
                return false;
            }
        }
    }

    archivoPedidos.close();
    cout << "El pedido con código " << codigoPedido << " no existe." << endl;
    return false;
}

// Función para cambiar el estado de envío de un pedido de 'N' a 'S'
void marcarPedidoEnviado(int codigoPedido)
{
    ifstream archivoPedidos("Pedidos.txt");
    ofstream temporal("Temporal.txt");

    int codigoLeido;
    string nombrePedido;
    string productosInfo;

    while (getline(archivoPedidos, productosInfo))
    {
        istringstream iss(productosInfo);
        iss >> codigoLeido >> nombrePedido;

        if (codigoLeido == codigoPedido)
        {
            // Leer y actualizar cada producto separado por guiones
            temporal << codigoLeido << " " << nombrePedido << " ";

            while (getline(iss, productosInfo, '-'))
            {
                size_t separador = productosInfo.find_last_of(' ');
                temporal << productosInfo.substr(0, separador) << " ";
            }

            temporal << "S" << endl; // Agregamos el indicador de enviado (S) al final del pedido
        }
        else
        {
            temporal << productosInfo << endl;
        }
    }

    archivoPedidos.close();
    temporal.close();

    // Reemplazar el archivo original con el temporal
    remove("Pedidos.txt");
    rename("Temporal.txt", "Pedidos.txt");

    cout << "Pedido con código " << codigoPedido << " marcado como enviado." << endl;
}




// Función para enviar un pedido
void enviarPedido()
{
    int codigoPedido;
    char respuesta;

    cout << "Enviar pedido" << endl;
    cout << "Ingrese el código del pedido: ";
    cin >> codigoPedido;

    if (verificarPedidoNoEnviado(codigoPedido))
    {
        cout << "¿Desea enviar el pedido? (S/N): ";
        cin >> respuesta;

        if (toupper(respuesta) == 'S')
        {
            marcarPedidoEnviado(codigoPedido);
        }
    }
}




