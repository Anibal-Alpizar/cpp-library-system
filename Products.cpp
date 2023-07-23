#include <iostream>
#include <fstream> // Para trabajar con archivos
#include <sstream>


using namespace std;


bool existeCodigoEnArchivo(int codigo)
{
    ifstream archivoProductos("Productos.txt"); // Abre el archivo "Productos.txt" en modo de lectura
    int codigoLeido; // Variable para almacenar el c�digo le�do desde el archivo
    string linea; // Variable para almacenar cada l�nea le�da desde el archivo

    while (getline(archivoProductos, linea)) // Lee cada l�nea del archivo y la guarda en "linea" hasta que llega al final del archivo
    {
        istringstream iss(linea); // Convierte la l�nea le�da en un objeto istringstream para leer cada dato separado por espacios
        iss >> codigoLeido; // Lee el c�digo del producto desde la l�nea

        if (codigoLeido == codigo) // Compara el c�digo le�do con el c�digo que se est� buscando
        {
            archivoProductos.close(); // Cierra el archivo
            return true; // Retorna true si encuentra el c�digo en el archivo
        }
    }

    archivoProductos.close(); // Cierra el archivo
    return false; // Retorna false si no encuentra el c�digo en el archivo
}


// Funci�n para ingresar un nuevo producto y guardarlo en el archivo "Productos.txt"
void ingresarProducto()
{
    int codigo; // Variable para almacenar el c�digo del nuevo producto
    string nombre; // Variable para almacenar el nombre del nuevo producto
    int cantidad; // Variable para almacenar la cantidad disponible del nuevo producto

    cout << "Ingresar producto" << endl;

    do
    {
        cout << "C�digo (cuatro d�gitos): ";
        cin >> codigo;

        if (existeCodigoEnArchivo(codigo))
        {
            cout << "El c�digo ya existe. Ingresa un c�digo diferente." << endl;
        }
    }
    while (existeCodigoEnArchivo(codigo)); // Repite el proceso mientras el c�digo ingresado ya exista en el archivo

    cout << "Nombre: ";
    cin.ignore();
    getline(cin, nombre); // Lee el nombre del nuevo producto (puede contener espacios)

    cout << "Cantidad disponible: ";
    cin >> cantidad; // Lee la cantidad disponible del nuevo producto

    ofstream archivoProductos("Productos.txt", ios::app); // Abre el archivo "Productos.txt" en modo de escritura al final (append)

    if (archivoProductos.is_open()) // Verifica si el archivo se abri� correctamente
    {
        archivoProductos << codigo << " " << nombre << " " << cantidad << endl; // Escribe los datos del nuevo producto en el archivo

        archivoProductos.close(); // Cierra el archivo

        cout << "Producto ingresado exitosamente." << endl; // Muestra un mensaje de �xito
    }
    else
    {
        cout << "Error al abrir el archivo." << endl; // Muestra un mensaje de error si no se pudo abrir el archivo
    }
}


// Funci�n para consultar un producto por su c�digo
void consultarProductoPorCodigo(int codigo)
{
    ifstream archivoProductos("Productos.txt"); // Abre el archivo "Productos.txt" en modo de lectura
    int codigoLeido; // Variable para almacenar el c�digo le�do desde el archivo
    string nombre; // Variable para almacenar el nombre le�do desde el archivo
    int cantidad; // Variable para almacenar la cantidad disponible le�da desde el archivo
    bool encontrado = false; // Variable para indicar si se ha encontrado el producto con el c�digo dado
    char continuar; // Variable para almacenar la respuesta del usuario para continuar consultando

    while (archivoProductos >> codigoLeido >> nombre >> cantidad) // Lee cada registro del archivo y almacena los valores en las variables correspondientes
    {
        if (codigoLeido == codigo) // Compara el c�digo le�do con el c�digo proporcionado como argumento
        {
            encontrado = true; // Marca como encontrado si el c�digo coincide
            cout << "C�digo: " << codigoLeido << endl;
            cout << "Nombre: " << nombre << endl;
            cout << "Cantidad disponible: " << cantidad << endl;
            break; // Sale del ciclo si se encuentra el producto con el c�digo dado
        }
    }

    archivoProductos.close(); // Cierra el archivo despu�s de leerlo

    if (!encontrado) // Si no se encontr� el producto con el c�digo dado
    {
        cout << "El producto con c�digo " << codigo << " no existe." << endl;

        do
        {
            cout << "Desea continuar consultando? (S/N): ";
            cin >> continuar;

            continuar = toupper(continuar); // Convertir el car�cter ingresado a may�scula

            if (continuar != 'S' && continuar != 'N') // Verifica si la opci�n ingresada es v�lida (S o N)
            {
                cout << "Opci�n no v�lida. Int�ntelo nuevamente." << endl;
            }
        }
        while (continuar != 'S' && continuar != 'N');

        if (continuar == 'N') // Si el usuario no desea continuar consultando
        {
            return; // Sale de la funci�n y vuelve al men� principal
        }
        else if (continuar == 'S') // Si el usuario desea continuar consultando
        {
            int nuevoCodigo;
            cout << "Ingresa el c�digo del producto a consultar: ";
            cin >> nuevoCodigo;
            consultarProductoPorCodigo(nuevoCodigo); // Llama a la funci�n nuevamente para continuar la consulta
        }
    }
}

// Funci�n para eliminar un producto por su c�digo
void eliminarProductoPorCodigo(int codigo)
{
    ifstream archivoProductos("Productos.txt"); // Abre el archivo "Productos.txt" en modo de lectura
    ofstream temporal("Temporal.txt"); // Crea un archivo temporal "Temporal.txt" en modo de escritura

    int codigoLeido; // Variable para almacenar el c�digo le�do desde el archivo
    string nombre; // Variable para almacenar el nombre le�do desde el archivo
    int cantidad; // Variable para almacenar la cantidad disponible le�da desde el archivo
    bool encontrado = false; // Variable para indicar si se ha encontrado el producto con el c�digo dado
    char confirmarEliminar; // Variable para almacenar la respuesta del usuario para confirmar la eliminaci�n

    while (archivoProductos >> codigoLeido >> nombre >> cantidad) // Lee cada registro del archivo y almacena los valores en las variables correspondientes
    {
        if (codigoLeido == codigo) // Compara el c�digo le�do con el c�digo proporcionado como argumento
        {
            encontrado = true; // Marca como encontrado si el c�digo coincide
            cout << "C�digo: " << codigoLeido << endl;
            cout << "Nombre: " << nombre << endl;
            cout << "Cantidad disponible: " << cantidad << endl;

            cout << "�Est� seguro de eliminar este producto? (S/N): ";
            cin >> confirmarEliminar;
            confirmarEliminar = toupper(confirmarEliminar); // Convierte el car�cter ingresado a may�scula

            if (confirmarEliminar == 'S') // Si el usuario confirma la eliminaci�n
            {
                cout << "Producto eliminado exitosamente." << endl;
                continue; // Omitir el registro actual y pasar al siguiente
            }
            else if (confirmarEliminar == 'N') // Si el usuario no confirma la eliminaci�n
            {
                temporal << codigoLeido << " " << nombre << " " << cantidad << endl; // Escribe el registro en el archivo temporal
            }
        }
        else
        {
            temporal << codigoLeido << " " << nombre << " " << cantidad << endl; // Escribe el registro en el archivo temporal (si no coincide con el c�digo dado)
        }
    }

    archivoProductos.close(); // Cierra el archivo despu�s de leerlo
    temporal.close(); // Cierra el archivo temporal despu�s de escribir en �l

    if (!encontrado) // Si no se encontr� el producto con el c�digo dado
    {
        cout << "El producto con c�digo " << codigo << " no existe." << endl;
    }

    remove("Productos.txt"); // Elimina el archivo original "Productos.txt"
    rename("Temporal.txt", "Productos.txt"); // Renombra el archivo temporal como "Productos.txt"
}



