#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

// Función para verificar si un código de producto existe en el inventario
// Parámetros:
//   - codigo: El código del producto a verificar
// Retorna:
//   - true si el código del producto existe en el inventario
//   - false si el código del producto no existe en el inventario
bool existeCodigoEnInventario(int codigo)
{
    // Abrir el archivo "Productos.txt" en modo lectura
    ifstream archivoProductos("Productos.txt");

    // Variables locales para almacenar los datos leídos del archivo
    int codigoLeido;
    string nombre;
    int cantidad;

    // Leer cada línea del archivo hasta el final
    /*
    La función utiliza un bucle while para recorrer cada línea del archivo "Productos.txt". En cada iteración, se lee una línea y se extraen los valores de código, nombre y cantidad del producto utilizando archivoProductos >> codigoLeido >> nombre >> cantidad.

    Luego, se verifica si el codigoLeido coincide con el código del producto buscado. Si hay una coincidencia, la función cierra el archivo y retorna la cantidad del producto encontrada en esa línea.

    Si no se encuentra ninguna coincidencia y se alcanza el final del archivo, el bucle termina, se cierra el archivo y se retorna 0 como cantidad predeterminada, indicando que el producto no se encuentra en el archivo "Productos.txt".
    */
    while (archivoProductos >> codigoLeido >> nombre >> cantidad)
    {
        // Verificar si el código leído coincide con el código buscado
        if (codigoLeido == codigo)
        {
            // Cerrar el archivo y retornar true, indicando que el código existe en el inventario
            archivoProductos.close();
            return true;
        }
    }

    // Cerrar el archivo y retornar false, indicando que el código no existe en el inventario
    archivoProductos.close();
    return false;
}



// Función para verificar si un código de pedido existe en el archivo de pedidos
// Parámetros:
//   - codigo: El código del pedido a verificar
// Retorna:
//   - true si el código del pedido existe en el archivo de pedidos
//   - false si el código del pedido no existe en el archivo de pedidos
bool existeCodigoPedido(int codigo)
{
    // Abrir el archivo "Pedidos.txt" en modo lectura
    ifstream archivoPedidos("Pedidos.txt");

    // Variables locales para almacenar los datos leídos del archivo
    int codigoLeido;
    string linea;

    // Leer cada línea del archivo hasta el final
    /*
    La función utiliza un bucle while para recorrer cada línea del archivo "Productos.txt". En cada iteración, se lee una línea y se extraen los valores de código, nombre y cantidad del producto utilizando archivoProductos >> codigoLeido >> nombre >> cantidad.

    Luego, se verifica si el codigoLeido coincide con el código del producto buscado. Si hay una coincidencia, la función cierra el archivo y retorna la cantidad del producto encontrada en esa línea.

    Si no se encuentra ninguna coincidencia y se alcanza el final del archivo, el bucle termina, se cierra el archivo y se retorna 0 como cantidad predeterminada, indicando que el producto no se encuentra en el archivo "Productos.txt".
    */
    while (getline(archivoPedidos, linea))
    {
        // Crear un stream de entrada stringstream para procesar la línea actual
        istringstream iss(linea);

        // Leer el código de pedido del stream de entrada
        iss >> codigoLeido;

        // Verificar si el código leído coincide con el código buscado
        if (codigoLeido == codigo)
        {
            // Cerrar el archivo y retornar true, indicando que el código existe en el archivo de pedidos
            archivoPedidos.close();
            return true;
        }
    }

    // Cerrar el archivo y retornar false, indicando que el código no existe en el archivo de pedidos
    archivoPedidos.close();
    return false;
}



// Función para obtener la cantidad disponible de un producto por su código
// Parámetros:
//   - codigo: El código del producto cuya cantidad se desea obtener
// Retorna:
//   - La cantidad disponible del producto si se encuentra en el archivo "Productos.txt"
//   - 0 si el producto no se encuentra en el archivo "Productos.txt" (cantidad predeterminada)
int obtenerCantidadProducto(int codigo)
{
    // Abrir el archivo "Productos.txt" en modo lectura
    ifstream archivoProductos("Productos.txt");

    // Variables locales para almacenar los datos leídos del archivo
    int codigoLeido;
    string nombre;
    int cantidad;

    // Leer cada línea del archivo hasta el final
    /*
    La función utiliza un bucle while para recorrer cada línea del archivo "Productos.txt". En cada iteración, se lee una línea y se extraen los valores de código, nombre y cantidad del producto utilizando archivoProductos >> codigoLeido >> nombre >> cantidad.

    Luego, se verifica si el codigoLeido coincide con el código del producto buscado. Si hay una coincidencia, la función cierra el archivo y retorna la cantidad del producto encontrada en esa línea.

    Si no se encuentra ninguna coincidencia y se alcanza el final del archivo, el bucle termina, se cierra el archivo y se retorna 0 como cantidad predeterminada, indicando que el producto no se encuentra en el archivo "Productos.txt".
    */
    while (archivoProductos >> codigoLeido >> nombre >> cantidad)
    {
        // Verificar si el código leído coincide con el código del producto buscado
        if (codigoLeido == codigo)
        {
            // Cerrar el archivo y retornar la cantidad del producto
            archivoProductos.close();
            return cantidad;
        }
    }

    // Cerrar el archivo y retornar 0, indicando que el producto no se encuentra en el archivo
    archivoProductos.close();
    return 0;
}




// Función para generar un pedido
void generarPedido()
{
    // Variables locales para almacenar los datos del pedido
    int codigoPedido;
    string nombrePedido;
    // Los vectores codigosProductos y cantidadesProductos se utilizan para almacenar la información de los productos que se agregarán al pedido. Cada elemento del vector codigosProductos representa el código de un producto que se agregará al pedido, y el vector cantidadesProductos almacena las cantidades correspondientes de cada producto.
    vector<int> codigosProductos;
    vector<int> cantidadesProductos;
    // Estos vectores son necesarios para que la función generarPedido pueda mantener un registro de los productos que se agregan al pedido y sus respectivas cantidades. Durante el proceso de generación del pedido, el usuario puede agregar varios productos, y estos vectores permiten almacenar esa información temporalmente antes de guardarla en el archivo "Pedidos.txt".
    int codigoProducto;
    int cantidadProducto;
    char continuar;

    bool codigoRepetido = false;
    // La variable codigoRepetido se utiliza como una bandera para verificar si el código del pedido ingresado por el usuario ya existe en el archivo de pedidos. La bandera se inicializa con el valor false para indicar que inicialmente no se ha encontrado un código repetido.

//Durante el proceso de generación del pedido, se utiliza un bucle do-while para solicitar al usuario un código de pedido. Si el código ingresado ya existe en el archivo de pedidos (es decir, es un código repetido), la variable codigoRepetido se establece en true. Esto permite que el bucle continue pidiendo al usuario que ingrese un código diferente hasta que se ingrese un código que no esté repetido.
// En resumen, la variable codigoRepetido se utiliza para garantizar que el código de pedido ingresado por el usuario no esté repetido y que se solicite un nuevo código en caso de ser necesario.


    cout << "Generar pedido" << endl;

    // Generar el código del pedido y verificar que no exista previamente
    do
    {
        codigoRepetido = false; // Reiniciar la variable de control en cada iteración
        cout << "Código del pedido: ";
        cin >> codigoPedido;

        // Verificar si el código del pedido ya existe en el archivo de pedidos
        if (existeCodigoPedido(codigoPedido))
        {
            cout << "El código del pedido ya existe. Ingresa un código diferente." << endl;
            codigoRepetido = true;
        }
    }
    while (codigoRepetido);

    // En C++, cuando se utiliza la función cin para leer datos desde la entrada estándar (como el teclado), se almacenan esos datos en un búfer de entrada. El búfer es una especie de zona de memoria temporal que almacena los caracteres ingresados por el usuario hasta que se leen y procesan.

//Cuando se lee un número o una cadena de caracteres usando cin, la función lee los caracteres ingresados por el usuario, pero deja en el búfer cualquier carácter adicional (como el carácter de nueva línea '\n') que el usuario haya ingresado. Esto puede causar problemas si se realiza una lectura adicional después de la lectura original, ya que el búfer aún contiene caracteres no leídos.
    cin.ignore(); // Limpiar el buffer después de leer el código del pedido
    cout << "Nombre del pedido: ";
    getline(cin, nombrePedido);

    // Ciclo para agregar productos al pedido
    do
    {
        cout << "Código del producto: ";
        cin >> codigoProducto;

        // Verificar si el código del producto existe en el inventario
        if (!existeCodigoEnInventario(codigoProducto))
        {
            cout << "El código del producto no existe en el inventario. Ingresa un código válido." << endl;
            // para omitir el resto del código dentro de un bucle y volver al inicio del bucle para continuar con la siguiente iteración
            continue;
        }

        // Obtener la cantidad disponible del producto antes de solicitar la cantidad del pedido
        int cantidadDisponible = obtenerCantidadProducto(codigoProducto);

        cout << "Cantidad del producto (disponible: " << cantidadDisponible << "): ";
        cin >> cantidadProducto;

        // Verificar si la cantidad solicitada es válida
        if (cantidadProducto <= 0 || cantidadProducto > cantidadDisponible)
        {
            cout << "Cantidad inválida. Ingresa una cantidad mayor a cero y no mayor a la cantidad disponible." << endl;
            continue;
        }

        // Agregar los datos del producto al pedido
        // La función push_back es una función miembro de la clase vector en C++, y se utiliza para agregar un nuevo elemento al final del vector.
        // Supongamos que el usuario ingresa un código de producto válido y una cantidad válida para ese producto. Luego de verificar que el producto existe en el inventario y que la cantidad es válida, se procede a agregar esos datos al pedido. Aquí es donde se utiliza push_back.
        codigosProductos.push_back(codigoProducto);
        cantidadesProductos.push_back(cantidadProducto);

        // Por ejemplo, supongamos que el usuario ingresó el código de producto 1234 y una cantidad de 2 para ese producto. Luego, los datos 1234 y 2 se agregarían al final de los vectores codigosProductos y cantidadesProductos,
        // Una vez que el usuario decide que ya no quiere agregar más productos al pedido, el contenido de estos vectores se utilizará para guardar toda la información del pedido en el archivo "Pedidos.txt".

        // Mostrar los detalles del producto agregado al pedido
        cout << "Pedido: " << codigoPedido << " " << nombrePedido << " pedido " << codigoProducto << " " << cantidadProducto << " N" << endl;

        cout << "¿Desea agregar otro producto al pedido? (S/N): ";
        cin >> continuar;

        continuar = toupper(continuar); // Convertir el carácter ingresado a mayúscula
    }
    while (continuar == 'S');

    // Guardar el pedido en el archivo de pedidos si hay productos en el vector
    // verifica si el vector codigosProductos no está vacío. empty() es una función miembro de la clase vector que devuelve true si el vector está vacío y false si contiene elementos. En este caso, la condición se evalúa como verdadera si hay productos agregados al pedido, y falso si no hay ningún producto en el pedid
    if (!codigosProductos.empty())
    {
        // Esta línea crea un objeto de tipo ofstream llamado archivoPedidos. ofstream es una clase que se utiliza para escribir en archivos.
        // Aquí, estamos abriendo el archivo "Pedidos.txt" en modo de escritura (ios::app significa "append", es decir, se agregarán los datos al final del archivo sin borrar su contenido existente).
        ofstream archivoPedidos("Pedidos.txt", ios::app);

        // Esta línea verifica si el archivo "Pedidos.txt" se ha abierto correctamente. La función is_open() es una función miembro de la clase ofstream que devuelve true si el archivo está abierto correctamente y false si ocurrió algún error al abrirlo.
        if (archivoPedidos.is_open())
        {
            // Escribir los datos del pedido en el archivo "Pedidos.txt"
            archivoPedidos << codigoPedido << " " << nombrePedido;
            // En esta línea, se escribe el código del pedido y el nombre del pedido en el archivo "Pedidos.txt". La sintaxis archivoPedidos << dato se utiliza para escribir datos en el archivo. Los datos se escriben en el mismo orden en que aparecen en la línea de código.

            // Este bucle for se utiliza para iterar sobre los vectores codigosProductos y cantidadesProductos y escribir la información de cada producto en el archivo "Pedidos.txt".
            for (size_t i = 0; i < codigosProductos.size(); i++)
            {
                // Dentro del bucle for, esta línea escribe la información de cada producto en el archivo. Cada línea contiene el código del producto, la cantidad y una letra "N" para indicar que el pedido no ha sido enviado ("N" de "No enviado").
                archivoPedidos << " " << codigosProductos[i] << " " << cantidadesProductos[i] << " N";
            }

            // Esta línea escribe un salto de línea en el archivo, lo que significa que el próximo pedido se escribirá en una nueva línea en el archivo.
            archivoPedidos << endl;

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
    // Abrir el archivo "Pedidos.txt" en modo lectura
    ifstream archivoPedidos("Pedidos.txt");

    // Variables locales para almacenar información del archivo
    int codigoLeido;
    string nombrePedido;
    string productosInfo;

    // Leer cada línea del archivo hasta que se llegue al final
    while (getline(archivoPedidos, productosInfo))
    {
        // Crear un stream de entrada istringstream para procesar la línea actual
        // Se está creando un objeto istringstream llamado iss. istringstream es una clase que se encuentra en la biblioteca <sstream> y se utiliza para realizar operaciones de lectura (entrada) en una cadena de texto.

//En este caso, la variable productosInfo es una cadena que contiene la información de un pedido desde el archivo "Pedidos.txt". La variable iss se crea para poder procesar esa cadena y extraer los valores necesarios.
        istringstream iss(productosInfo);

        // Leer el código y el nombre del pedido desde la línea
        // La sintaxis iss >> codigoLeido >> nombrePedido se utiliza para extraer valores de la cadena de texto almacenada en productosInfo y asignarlos a las variables codigoLeido y nombrePedido, respectivamente.
        iss >> codigoLeido >> nombrePedido;

        // Verificar si el código del pedido leído coincide con el código proporcionado
        if (codigoLeido == codigoPedido)
        {
            // Cerrar el archivo "Pedidos.txt" ya que ya no se necesita leer más
            archivoPedidos.close();

            // Verificar si el pedido aún no ha sido enviado
            if (productosInfo.back() == 'N')
            {
                // Si el pedido no ha sido enviado, retornar true para indicar que existe y no ha sido enviado
                return true;
            }
            else
            {
                // Si el pedido ya ha sido enviado, mostrar un mensaje y retornar false
                cout << "El pedido con código " << codigoPedido << " ya ha sido enviado." << endl;
                return false;
            }
        }
    }

    // Cerrar el archivo "Pedidos.txt" después de terminar la lectura
    archivoPedidos.close();

    // Si el código del pedido no se encontró en el archivo, mostrar un mensaje y retornar false
    cout << "El pedido con código " << codigoPedido << " no existe." << endl;
    return false;
}



// Función para cambiar el estado de envío de un pedido de 'N' a 'S'
void marcarPedidoEnviado(int codigoPedido)
{
    // Abrir el archivo "Pedidos.txt" en modo lectura
    // Se está abriendo el archivo de texto llamado "Pedidos.txt" en modo lectura utilizando un objeto de tipo ifstream, que significa "Input File Stream" o flujo de archivo de entrada.
    ifstream archivoPedidos("Pedidos.txt");

    // Crear un archivo temporal "Temporal.txt" en modo escritura
    ofstream temporal("Temporal.txt");

    // Variables locales para almacenar información del archivo
    int codigoLeido;
    string nombrePedido;
    string productosInfo;

    // Leer cada línea del archivo "Pedidos.txt" hasta que se llegue al final
    // Este bucle while recorre línea por línea el contenido del archivo "Pedidos.txt". Cada línea se almacena en la variable productosInfo.
    while (getline(archivoPedidos, productosInfo))
    {
        // Crear un stream de entrada istringstream para procesar la línea actual
        // Aquí se crea un istringstream llamado iss, que es un stream de entrada que procesará la línea actual productosInfo. Esto se hace para poder leer y extraer los datos separados por espacios en esa línea.
        istringstream iss(productosInfo);

        // Leer el código y el nombre del pedido desde la línea
        // Esta línea de código utiliza el istringstream para leer y extraer el código y el nombre del pedido desde la línea actual. Los datos se almacenan en las variables codigoLeido y nombrePedido
        iss >> codigoLeido >> nombrePedido;

        // Verificar si el código del pedido leído coincide con el código proporcionado
        // Se verifica si el código del pedido leído (codigoLeido) coincide con el código del pedido proporcionado por el usuario (codigoPedido). Si hay coincidencia, significa que se ha encontrado el pedido que se desea marcar como enviado.
        if (codigoLeido == codigoPedido)
        {
            // Escribir el código y el nombre del pedido en el archivo temporal
            // Si el código del pedido coincide, esta línea escribe el código y el nombre del pedido en el archivo temporal llamado "Temporal.txt". Esto es para copiar el pedido actual al archivo temporal.

            temporal << codigoLeido << " " << nombrePedido << " ";

            // Leer y actualizar cada producto separado por guiones en la línea actual
           // while (getline(iss, productosInfo, '-'))
           // {
                // Encontrar la última posición del espacio en blanco en la información del producto
           //     size_t separador = productosInfo.find_last_of(' ');

                // Escribir en el archivo temporal la información del producto sin el estado de envío
             //   temporal << productosInfo.substr(0, separador) << " ";
            //}

            // Agregar el indicador de enviado (S) al final del pedido en el archivo temporal
            // Después de procesar los productos, se agrega al final del pedido la marca "S" para indicar que ha sido enviado y se agrega un salto de línea (endl) para pasar a la siguiente línea en el archivo temporal.
            temporal << "S" << endl;
        }
        else
        {
            // Si el código del pedido no coincide, simplemente copiar la línea actual al archivo temporal
            // Si el código del pedido no coincide con el código leído, esta línea simplemente copia la línea actual completa (productosInfo) al archivo temporal. Esto es para mantener todas las líneas que no están relacionadas con el pedido que se desea marcar como enviado.
            temporal << productosInfo << endl;
        }
    }

    // Cerrar los archivos "Pedidos.txt" y "Temporal.txt"
    // Estas dos líneas cierran los archivos "Pedidos.txt" y "Temporal.txt" que se habían abierto previamente para leer y escribir, respectivamente. Es importante cerrar los archivos después de utilizarlos para liberar los recursos y asegurar que los datos se han guardado correctamente.
    archivoPedidos.close();
    temporal.close();

    // Reemplazar el archivo original "Pedidos.txt" con el archivo temporal "Temporal.txt"
    // El archivo original "Pedidos.txt" se eliminará y el archivo temporal se renombrará como "Pedidos.txt"
    // La función remove es una función de la biblioteca <cstdio> que se utiliza para eliminar un archivo del sistema de archivos. En este caso, se está eliminando el archivo "Pedidos.txt", que es el archivo original que contiene todos los pedidos.
    remove("Pedidos.txt");
    // La función rename es otra función de la biblioteca <cstdio> que se utiliza para cambiar el nombre de un archivo. En este caso, se está renombrando el archivo "Temporal.txt" a "Pedidos.txt". Esto se hace para reemplazar el archivo original "Pedidos.txt" con el archivo temporal que contiene el pedido marcado como enviado.
    rename("Temporal.txt", "Pedidos.txt");

    // Mostrar un mensaje indicando que el pedido con el código proporcionado ha sido marcado como enviado
    cout << "Pedido con código " << codigoPedido << " marcado como enviado." << endl;
}





// Función para enviar un pedido
void enviarPedido()
{
    // Declaración de variables locales
    int codigoPedido;
    char respuesta;

    // Mostrar mensaje de "Enviar pedido" en la consola
    cout << "Enviar pedido" << endl;

    // Solicitar al usuario que ingrese el código del pedido
    cout << "Ingrese el código del pedido: ";
    cin >> codigoPedido;

    // Verificar si el pedido existe y aún no ha sido enviado
    if (verificarPedidoNoEnviado(codigoPedido))
    {
        // Si el pedido existe y no ha sido enviado, preguntar al usuario si desea enviarlo
        cout << "¿Desea enviar el pedido? (S/N): ";
        cin >> respuesta;

        // Convertir la respuesta ingresada a mayúsculas usando la función toupper
        respuesta = toupper(respuesta);

        // Si el usuario responde "S" (Sí), marcar el pedido como enviado
        if (respuesta == 'S')
        {
            marcarPedidoEnviado(codigoPedido);
        }
    }
}



