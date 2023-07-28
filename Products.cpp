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

void consultarProductoPorCodigo(int codigo)
{
    ifstream archivoProductos("Productos.txt"); // Abre el archivo "Productos.txt" en modo de lectura
    int codigoLeido; // Variable para almacenar el código leído desde el archivo
    string nombreProducto; // Variable para almacenar el nombre junto con la cantidad leídos desde el archivo
    bool encontrado = false; // Variable para indicar si se ha encontrado el producto con el código dado

    while (archivoProductos >> codigoLeido) // Lee el código del producto desde el archivo
    {
        archivoProductos.ignore(); // Ignorar el espacio después del código
        getline(archivoProductos, nombreProducto); // Leer el resto de la línea como el nombre del producto junto con la cantidad

        if (codigoLeido == codigo) // Compara el código leído con el código proporcionado como argumento
        {
            encontrado = true; // Marca como encontrado si el código coincide
            cout << "Código: " << codigoLeido << endl;
            cout << "Nombre y cantidad: " << nombreProducto << endl;
            break; // Sale del ciclo si se encuentra el producto con el código dado
        }
    }

    archivoProductos.close(); // Cierra el archivo después de leerlo

    if (!encontrado) // Si no se encontró el producto con el código dado
    {
        cout << "El producto con código " << codigo << " no existe." << endl;
    }
}


// Función para eliminar un producto por su código
void eliminarProductoPorCodigo(int id)
{
     std::ifstream archivoProductos("Productos.txt"); // Abre el archivo "Productos.txt" en modo de lectura
    std::ofstream archivoNuevo("Productos_nuevo.txt"); // Crea un nuevo archivo "Productos_nuevo.txt"

    std::string linea; // Variable para almacenar cada línea leída desde el archivo
    bool encontrado = false; // Variable para indicar si se ha encontrado el producto con el ID dado

    while (getline(archivoProductos, linea)) { // Lee cada línea del archivo "Productos.txt"
        std::istringstream iss(linea); // Convierte la línea leída en un objeto istringstream para leer cada dato separado por espacios
        int codigoLeido; // Variable para almacenar el código del producto
        std::string nombreProducto; // Variable para almacenar el nombre del producto
        int cantidad; // Variable para almacenar la cantidad del producto

        iss >> codigoLeido >> nombreProducto >> cantidad; // Lee los datos del producto desde la línea

        if (codigoLeido != id) { // Si el código del producto no es igual al ID proporcionado
            archivoNuevo << linea << std::endl; // Escribe la línea en el archivo "Productos_nuevo.txt"
        }
        else {
            encontrado = true; // Marca como encontrado si el ID coincide con el producto a eliminar
        }
    }

    archivoProductos.close(); // Cierra el archivo "Productos.txt"
    archivoNuevo.close(); // Cierra el archivo "Productos_nuevo.txt"

    if (encontrado) {
        // Renombra el archivo "Productos_nuevo.txt" a "Productos.txt"
        std::remove("Productos.txt");
        std::rename("Productos_nuevo.txt", "Productos.txt");

        std::cout << "El producto con el ID " << id << " ha sido eliminado." << std::endl;
    }
    else {
        std::cout << "El producto con el ID " << id << " no existe." << std::endl;
    }
}
