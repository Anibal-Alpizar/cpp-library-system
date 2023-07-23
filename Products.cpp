#include <iostream>
#include <fstream> // Para trabajar con archivos
#include <sstream>


using namespace std;


bool existeCodigoEnArchivo(int codigo)
{
    ifstream archivoProductos("Productos.txt"); // Abre el archivo "Productos.txt" en modo de lectura
    int codigoLeido; // Variable para almacenar el código leído desde el archivo
    string linea; // Variable para almacenar cada línea leída desde el archivo

    while (getline(archivoProductos, linea)) // Lee cada línea del archivo y la guarda en "linea" hasta que llega al final del archivo
    {
        istringstream iss(linea); // Convierte la línea leída en un objeto istringstream para leer cada dato separado por espacios
        iss >> codigoLeido; // Lee el código del producto desde la línea

        if (codigoLeido == codigo) // Compara el código leído con el código que se está buscando
        {
            archivoProductos.close(); // Cierra el archivo
            return true; // Retorna true si encuentra el código en el archivo
        }
    }

    archivoProductos.close(); // Cierra el archivo
    return false; // Retorna false si no encuentra el código en el archivo
}


// Función para ingresar un nuevo producto y guardarlo en el archivo "Productos.txt"
void ingresarProducto()
{
    int codigo; // Variable para almacenar el código del nuevo producto
    string nombre; // Variable para almacenar el nombre del nuevo producto
    int cantidad; // Variable para almacenar la cantidad disponible del nuevo producto

    cout << "Ingresar producto" << endl;

    do
    {
        cout << "Código (cuatro dígitos): ";
        cin >> codigo;

        if (existeCodigoEnArchivo(codigo))
        {
            cout << "El código ya existe. Ingresa un código diferente." << endl;
        }
    }
    while (existeCodigoEnArchivo(codigo)); // Repite el proceso mientras el código ingresado ya exista en el archivo

    cout << "Nombre: ";
    cin.ignore();
    getline(cin, nombre); // Lee el nombre del nuevo producto (puede contener espacios)

    cout << "Cantidad disponible: ";
    cin >> cantidad; // Lee la cantidad disponible del nuevo producto

    ofstream archivoProductos("Productos.txt", ios::app); // Abre el archivo "Productos.txt" en modo de escritura al final (append)

    if (archivoProductos.is_open()) // Verifica si el archivo se abrió correctamente
    {
        archivoProductos << codigo << " " << nombre << " " << cantidad << endl; // Escribe los datos del nuevo producto en el archivo

        archivoProductos.close(); // Cierra el archivo

        cout << "Producto ingresado exitosamente." << endl; // Muestra un mensaje de éxito
    }
    else
    {
        cout << "Error al abrir el archivo." << endl; // Muestra un mensaje de error si no se pudo abrir el archivo
    }
}


// Función para consultar un producto por su código
void consultarProductoPorCodigo(int codigo)
{
    ifstream archivoProductos("Productos.txt"); // Abre el archivo "Productos.txt" en modo de lectura
    int codigoLeido; // Variable para almacenar el código leído desde el archivo
    string nombre; // Variable para almacenar el nombre leído desde el archivo
    int cantidad; // Variable para almacenar la cantidad disponible leída desde el archivo
    bool encontrado = false; // Variable para indicar si se ha encontrado el producto con el código dado
    char continuar; // Variable para almacenar la respuesta del usuario para continuar consultando

    while (archivoProductos >> codigoLeido >> nombre >> cantidad) // Lee cada registro del archivo y almacena los valores en las variables correspondientes
    {
        if (codigoLeido == codigo) // Compara el código leído con el código proporcionado como argumento
        {
            encontrado = true; // Marca como encontrado si el código coincide
            cout << "Código: " << codigoLeido << endl;
            cout << "Nombre: " << nombre << endl;
            cout << "Cantidad disponible: " << cantidad << endl;
            break; // Sale del ciclo si se encuentra el producto con el código dado
        }
    }

    archivoProductos.close(); // Cierra el archivo después de leerlo

    if (!encontrado) // Si no se encontró el producto con el código dado
    {
        cout << "El producto con código " << codigo << " no existe." << endl;

        do
        {
            cout << "Desea continuar consultando? (S/N): ";
            cin >> continuar;

            continuar = toupper(continuar); // Convertir el carácter ingresado a mayúscula

            if (continuar != 'S' && continuar != 'N') // Verifica si la opción ingresada es válida (S o N)
            {
                cout << "Opción no válida. Inténtelo nuevamente." << endl;
            }
        }
        while (continuar != 'S' && continuar != 'N');

        if (continuar == 'N') // Si el usuario no desea continuar consultando
        {
            return; // Sale de la función y vuelve al menú principal
        }
        else if (continuar == 'S') // Si el usuario desea continuar consultando
        {
            int nuevoCodigo;
            cout << "Ingresa el código del producto a consultar: ";
            cin >> nuevoCodigo;
            consultarProductoPorCodigo(nuevoCodigo); // Llama a la función nuevamente para continuar la consulta
        }
    }
}

// Función para eliminar un producto por su código
void eliminarProductoPorCodigo(int codigo)
{
    ifstream archivoProductos("Productos.txt"); // Abre el archivo "Productos.txt" en modo de lectura
    ofstream temporal("Temporal.txt"); // Crea un archivo temporal "Temporal.txt" en modo de escritura

    int codigoLeido; // Variable para almacenar el código leído desde el archivo
    string nombre; // Variable para almacenar el nombre leído desde el archivo
    int cantidad; // Variable para almacenar la cantidad disponible leída desde el archivo
    bool encontrado = false; // Variable para indicar si se ha encontrado el producto con el código dado
    char confirmarEliminar; // Variable para almacenar la respuesta del usuario para confirmar la eliminación

    while (archivoProductos >> codigoLeido >> nombre >> cantidad) // Lee cada registro del archivo y almacena los valores en las variables correspondientes
    {
        if (codigoLeido == codigo) // Compara el código leído con el código proporcionado como argumento
        {
            encontrado = true; // Marca como encontrado si el código coincide
            cout << "Código: " << codigoLeido << endl;
            cout << "Nombre: " << nombre << endl;
            cout << "Cantidad disponible: " << cantidad << endl;

            cout << "¿Está seguro de eliminar este producto? (S/N): ";
            cin >> confirmarEliminar;
            confirmarEliminar = toupper(confirmarEliminar); // Convierte el carácter ingresado a mayúscula

            if (confirmarEliminar == 'S') // Si el usuario confirma la eliminación
            {
                cout << "Producto eliminado exitosamente." << endl;
                continue; // Omitir el registro actual y pasar al siguiente
            }
            else if (confirmarEliminar == 'N') // Si el usuario no confirma la eliminación
            {
                temporal << codigoLeido << " " << nombre << " " << cantidad << endl; // Escribe el registro en el archivo temporal
            }
        }
        else
        {
            temporal << codigoLeido << " " << nombre << " " << cantidad << endl; // Escribe el registro en el archivo temporal (si no coincide con el código dado)
        }
    }

    archivoProductos.close(); // Cierra el archivo después de leerlo
    temporal.close(); // Cierra el archivo temporal después de escribir en él

    if (!encontrado) // Si no se encontró el producto con el código dado
    {
        cout << "El producto con código " << codigo << " no existe." << endl;
    }

    remove("Productos.txt"); // Elimina el archivo original "Productos.txt"
    rename("Temporal.txt", "Productos.txt"); // Renombra el archivo temporal como "Productos.txt"
}



