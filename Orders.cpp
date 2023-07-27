#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

// Funci�n para verificar si un c�digo de producto existe en el inventario
// Par�metros:
//   - codigo: El c�digo del producto a verificar
// Retorna:
//   - true si el c�digo del producto existe en el inventario
//   - false si el c�digo del producto no existe en el inventario
bool existeCodigoEnInventario(int codigo)
{
    // Abrir el archivo "Productos.txt" en modo lectura
    ifstream archivoProductos("Productos.txt");

    // Variables locales para almacenar los datos le�dos del archivo
    int codigoLeido;
    string nombre;
    int cantidad;

    // Leer cada l�nea del archivo hasta el final
    /*
    La funci�n utiliza un bucle while para recorrer cada l�nea del archivo "Productos.txt". En cada iteraci�n, se lee una l�nea y se extraen los valores de c�digo, nombre y cantidad del producto utilizando archivoProductos >> codigoLeido >> nombre >> cantidad.

    Luego, se verifica si el codigoLeido coincide con el c�digo del producto buscado. Si hay una coincidencia, la funci�n cierra el archivo y retorna la cantidad del producto encontrada en esa l�nea.

    Si no se encuentra ninguna coincidencia y se alcanza el final del archivo, el bucle termina, se cierra el archivo y se retorna 0 como cantidad predeterminada, indicando que el producto no se encuentra en el archivo "Productos.txt".
    */
    while (archivoProductos >> codigoLeido >> nombre >> cantidad)
    {
        // Verificar si el c�digo le�do coincide con el c�digo buscado
        if (codigoLeido == codigo)
        {
            // Cerrar el archivo y retornar true, indicando que el c�digo existe en el inventario
            archivoProductos.close();
            return true;
        }
    }

    // Cerrar el archivo y retornar false, indicando que el c�digo no existe en el inventario
    archivoProductos.close();
    return false;
}



// Funci�n para verificar si un c�digo de pedido existe en el archivo de pedidos
// Par�metros:
//   - codigo: El c�digo del pedido a verificar
// Retorna:
//   - true si el c�digo del pedido existe en el archivo de pedidos
//   - false si el c�digo del pedido no existe en el archivo de pedidos
bool existeCodigoPedido(int codigo)
{
    // Abrir el archivo "Pedidos.txt" en modo lectura
    ifstream archivoPedidos("Pedidos.txt");

    // Variables locales para almacenar los datos le�dos del archivo
    int codigoLeido;
    string linea;

    // Leer cada l�nea del archivo hasta el final
    /*
    La funci�n utiliza un bucle while para recorrer cada l�nea del archivo "Productos.txt". En cada iteraci�n, se lee una l�nea y se extraen los valores de c�digo, nombre y cantidad del producto utilizando archivoProductos >> codigoLeido >> nombre >> cantidad.

    Luego, se verifica si el codigoLeido coincide con el c�digo del producto buscado. Si hay una coincidencia, la funci�n cierra el archivo y retorna la cantidad del producto encontrada en esa l�nea.

    Si no se encuentra ninguna coincidencia y se alcanza el final del archivo, el bucle termina, se cierra el archivo y se retorna 0 como cantidad predeterminada, indicando que el producto no se encuentra en el archivo "Productos.txt".
    */
    while (getline(archivoPedidos, linea))
    {
        // Crear un stream de entrada stringstream para procesar la l�nea actual
        istringstream iss(linea);

        // Leer el c�digo de pedido del stream de entrada
        iss >> codigoLeido;

        // Verificar si el c�digo le�do coincide con el c�digo buscado
        if (codigoLeido == codigo)
        {
            // Cerrar el archivo y retornar true, indicando que el c�digo existe en el archivo de pedidos
            archivoPedidos.close();
            return true;
        }
    }

    // Cerrar el archivo y retornar false, indicando que el c�digo no existe en el archivo de pedidos
    archivoPedidos.close();
    return false;
}



// Funci�n para obtener la cantidad disponible de un producto por su c�digo
// Par�metros:
//   - codigo: El c�digo del producto cuya cantidad se desea obtener
// Retorna:
//   - La cantidad disponible del producto si se encuentra en el archivo "Productos.txt"
//   - 0 si el producto no se encuentra en el archivo "Productos.txt" (cantidad predeterminada)
int obtenerCantidadProducto(int codigo)
{
    // Abrir el archivo "Productos.txt" en modo lectura
    ifstream archivoProductos("Productos.txt");

    // Variables locales para almacenar los datos le�dos del archivo
    int codigoLeido;
    string nombre;
    int cantidad;

    // Leer cada l�nea del archivo hasta el final
    /*
    La funci�n utiliza un bucle while para recorrer cada l�nea del archivo "Productos.txt". En cada iteraci�n, se lee una l�nea y se extraen los valores de c�digo, nombre y cantidad del producto utilizando archivoProductos >> codigoLeido >> nombre >> cantidad.

    Luego, se verifica si el codigoLeido coincide con el c�digo del producto buscado. Si hay una coincidencia, la funci�n cierra el archivo y retorna la cantidad del producto encontrada en esa l�nea.

    Si no se encuentra ninguna coincidencia y se alcanza el final del archivo, el bucle termina, se cierra el archivo y se retorna 0 como cantidad predeterminada, indicando que el producto no se encuentra en el archivo "Productos.txt".
    */
    while (archivoProductos >> codigoLeido >> nombre >> cantidad)
    {
        // Verificar si el c�digo le�do coincide con el c�digo del producto buscado
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




// Funci�n para generar un pedido
void generarPedido()
{
    // Variables locales para almacenar los datos del pedido
    int codigoPedido;
    string nombrePedido;
    // Los vectores codigosProductos y cantidadesProductos se utilizan para almacenar la informaci�n de los productos que se agregar�n al pedido. Cada elemento del vector codigosProductos representa el c�digo de un producto que se agregar� al pedido, y el vector cantidadesProductos almacena las cantidades correspondientes de cada producto.
    vector<int> codigosProductos;
    vector<int> cantidadesProductos;
    // Estos vectores son necesarios para que la funci�n generarPedido pueda mantener un registro de los productos que se agregan al pedido y sus respectivas cantidades. Durante el proceso de generaci�n del pedido, el usuario puede agregar varios productos, y estos vectores permiten almacenar esa informaci�n temporalmente antes de guardarla en el archivo "Pedidos.txt".
    int codigoProducto;
    int cantidadProducto;
    char continuar;

    bool codigoRepetido = false;
    // La variable codigoRepetido se utiliza como una bandera para verificar si el c�digo del pedido ingresado por el usuario ya existe en el archivo de pedidos. La bandera se inicializa con el valor false para indicar que inicialmente no se ha encontrado un c�digo repetido.

//Durante el proceso de generaci�n del pedido, se utiliza un bucle do-while para solicitar al usuario un c�digo de pedido. Si el c�digo ingresado ya existe en el archivo de pedidos (es decir, es un c�digo repetido), la variable codigoRepetido se establece en true. Esto permite que el bucle continue pidiendo al usuario que ingrese un c�digo diferente hasta que se ingrese un c�digo que no est� repetido.
// En resumen, la variable codigoRepetido se utiliza para garantizar que el c�digo de pedido ingresado por el usuario no est� repetido y que se solicite un nuevo c�digo en caso de ser necesario.


    cout << "Generar pedido" << endl;

    // Generar el c�digo del pedido y verificar que no exista previamente
    do
    {
        codigoRepetido = false; // Reiniciar la variable de control en cada iteraci�n
        cout << "C�digo del pedido: ";
        cin >> codigoPedido;

        // Verificar si el c�digo del pedido ya existe en el archivo de pedidos
        if (existeCodigoPedido(codigoPedido))
        {
            cout << "El c�digo del pedido ya existe. Ingresa un c�digo diferente." << endl;
            codigoRepetido = true;
        }
    }
    while (codigoRepetido);

    // En C++, cuando se utiliza la funci�n cin para leer datos desde la entrada est�ndar (como el teclado), se almacenan esos datos en un b�fer de entrada. El b�fer es una especie de zona de memoria temporal que almacena los caracteres ingresados por el usuario hasta que se leen y procesan.

//Cuando se lee un n�mero o una cadena de caracteres usando cin, la funci�n lee los caracteres ingresados por el usuario, pero deja en el b�fer cualquier car�cter adicional (como el car�cter de nueva l�nea '\n') que el usuario haya ingresado. Esto puede causar problemas si se realiza una lectura adicional despu�s de la lectura original, ya que el b�fer a�n contiene caracteres no le�dos.
    cin.ignore(); // Limpiar el buffer despu�s de leer el c�digo del pedido
    cout << "Nombre del pedido: ";
    getline(cin, nombrePedido);

    // Ciclo para agregar productos al pedido
    do
    {
        cout << "C�digo del producto: ";
        cin >> codigoProducto;

        // Verificar si el c�digo del producto existe en el inventario
        if (!existeCodigoEnInventario(codigoProducto))
        {
            cout << "El c�digo del producto no existe en el inventario. Ingresa un c�digo v�lido." << endl;
            // para omitir el resto del c�digo dentro de un bucle y volver al inicio del bucle para continuar con la siguiente iteraci�n
            continue;
        }

        // Obtener la cantidad disponible del producto antes de solicitar la cantidad del pedido
        int cantidadDisponible = obtenerCantidadProducto(codigoProducto);

        cout << "Cantidad del producto (disponible: " << cantidadDisponible << "): ";
        cin >> cantidadProducto;

        // Verificar si la cantidad solicitada es v�lida
        if (cantidadProducto <= 0 || cantidadProducto > cantidadDisponible)
        {
            cout << "Cantidad inv�lida. Ingresa una cantidad mayor a cero y no mayor a la cantidad disponible." << endl;
            continue;
        }

        // Agregar los datos del producto al pedido
        // La funci�n push_back es una funci�n miembro de la clase vector en C++, y se utiliza para agregar un nuevo elemento al final del vector.
        // Supongamos que el usuario ingresa un c�digo de producto v�lido y una cantidad v�lida para ese producto. Luego de verificar que el producto existe en el inventario y que la cantidad es v�lida, se procede a agregar esos datos al pedido. Aqu� es donde se utiliza push_back.
        codigosProductos.push_back(codigoProducto);
        cantidadesProductos.push_back(cantidadProducto);

        // Por ejemplo, supongamos que el usuario ingres� el c�digo de producto 1234 y una cantidad de 2 para ese producto. Luego, los datos 1234 y 2 se agregar�an al final de los vectores codigosProductos y cantidadesProductos,
        // Una vez que el usuario decide que ya no quiere agregar m�s productos al pedido, el contenido de estos vectores se utilizar� para guardar toda la informaci�n del pedido en el archivo "Pedidos.txt".

        // Mostrar los detalles del producto agregado al pedido
        cout << "Pedido: " << codigoPedido << " " << nombrePedido << " pedido " << codigoProducto << " " << cantidadProducto << " N" << endl;

        cout << "�Desea agregar otro producto al pedido? (S/N): ";
        cin >> continuar;

        continuar = toupper(continuar); // Convertir el car�cter ingresado a may�scula
    }
    while (continuar == 'S');

    // Guardar el pedido en el archivo de pedidos si hay productos en el vector
    // verifica si el vector codigosProductos no est� vac�o. empty() es una funci�n miembro de la clase vector que devuelve true si el vector est� vac�o y false si contiene elementos. En este caso, la condici�n se eval�a como verdadera si hay productos agregados al pedido, y falso si no hay ning�n producto en el pedid
    if (!codigosProductos.empty())
    {
        // Esta l�nea crea un objeto de tipo ofstream llamado archivoPedidos. ofstream es una clase que se utiliza para escribir en archivos.
        // Aqu�, estamos abriendo el archivo "Pedidos.txt" en modo de escritura (ios::app significa "append", es decir, se agregar�n los datos al final del archivo sin borrar su contenido existente).
        ofstream archivoPedidos("Pedidos.txt", ios::app);

        // Esta l�nea verifica si el archivo "Pedidos.txt" se ha abierto correctamente. La funci�n is_open() es una funci�n miembro de la clase ofstream que devuelve true si el archivo est� abierto correctamente y false si ocurri� alg�n error al abrirlo.
        if (archivoPedidos.is_open())
        {
            // Escribir los datos del pedido en el archivo "Pedidos.txt"
            archivoPedidos << codigoPedido << " " << nombrePedido;
            // En esta l�nea, se escribe el c�digo del pedido y el nombre del pedido en el archivo "Pedidos.txt". La sintaxis archivoPedidos << dato se utiliza para escribir datos en el archivo. Los datos se escriben en el mismo orden en que aparecen en la l�nea de c�digo.

            // Este bucle for se utiliza para iterar sobre los vectores codigosProductos y cantidadesProductos y escribir la informaci�n de cada producto en el archivo "Pedidos.txt".
            for (size_t i = 0; i < codigosProductos.size(); i++)
            {
                // Dentro del bucle for, esta l�nea escribe la informaci�n de cada producto en el archivo. Cada l�nea contiene el c�digo del producto, la cantidad y una letra "N" para indicar que el pedido no ha sido enviado ("N" de "No enviado").
                archivoPedidos << " " << codigosProductos[i] << " " << cantidadesProductos[i] << " N";
            }

            // Esta l�nea escribe un salto de l�nea en el archivo, lo que significa que el pr�ximo pedido se escribir� en una nueva l�nea en el archivo.
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
        cout << "El pedido no contiene productos v�lidos. Se descartar� el pedido." << endl;
    }
}




// Funci�n para verificar si un pedido existe y si a�n no ha sido enviado
bool verificarPedidoNoEnviado(int codigoPedido)
{
    // Abrir el archivo "Pedidos.txt" en modo lectura
    ifstream archivoPedidos("Pedidos.txt");

    // Variables locales para almacenar informaci�n del archivo
    int codigoLeido;
    string nombrePedido;
    string productosInfo;

    // Leer cada l�nea del archivo hasta que se llegue al final
    while (getline(archivoPedidos, productosInfo))
    {
        // Crear un stream de entrada istringstream para procesar la l�nea actual
        // Se est� creando un objeto istringstream llamado iss. istringstream es una clase que se encuentra en la biblioteca <sstream> y se utiliza para realizar operaciones de lectura (entrada) en una cadena de texto.

//En este caso, la variable productosInfo es una cadena que contiene la informaci�n de un pedido desde el archivo "Pedidos.txt". La variable iss se crea para poder procesar esa cadena y extraer los valores necesarios.
        istringstream iss(productosInfo);

        // Leer el c�digo y el nombre del pedido desde la l�nea
        // La sintaxis iss >> codigoLeido >> nombrePedido se utiliza para extraer valores de la cadena de texto almacenada en productosInfo y asignarlos a las variables codigoLeido y nombrePedido, respectivamente.
        iss >> codigoLeido >> nombrePedido;

        // Verificar si el c�digo del pedido le�do coincide con el c�digo proporcionado
        if (codigoLeido == codigoPedido)
        {
            // Cerrar el archivo "Pedidos.txt" ya que ya no se necesita leer m�s
            archivoPedidos.close();

            // Verificar si el pedido a�n no ha sido enviado
            if (productosInfo.back() == 'N')
            {
                // Si el pedido no ha sido enviado, retornar true para indicar que existe y no ha sido enviado
                return true;
            }
            else
            {
                // Si el pedido ya ha sido enviado, mostrar un mensaje y retornar false
                cout << "El pedido con c�digo " << codigoPedido << " ya ha sido enviado." << endl;
                return false;
            }
        }
    }

    // Cerrar el archivo "Pedidos.txt" despu�s de terminar la lectura
    archivoPedidos.close();

    // Si el c�digo del pedido no se encontr� en el archivo, mostrar un mensaje y retornar false
    cout << "El pedido con c�digo " << codigoPedido << " no existe." << endl;
    return false;
}



// Funci�n para cambiar el estado de env�o de un pedido de 'N' a 'S'
void marcarPedidoEnviado(int codigoPedido)
{
    // Abrir el archivo "Pedidos.txt" en modo lectura
    // Se est� abriendo el archivo de texto llamado "Pedidos.txt" en modo lectura utilizando un objeto de tipo ifstream, que significa "Input File Stream" o flujo de archivo de entrada.
    ifstream archivoPedidos("Pedidos.txt");

    // Crear un archivo temporal "Temporal.txt" en modo escritura
    ofstream temporal("Temporal.txt");

    // Variables locales para almacenar informaci�n del archivo
    int codigoLeido;
    string nombrePedido;
    string productosInfo;

    // Leer cada l�nea del archivo "Pedidos.txt" hasta que se llegue al final
    // Este bucle while recorre l�nea por l�nea el contenido del archivo "Pedidos.txt". Cada l�nea se almacena en la variable productosInfo.
    while (getline(archivoPedidos, productosInfo))
    {
        // Crear un stream de entrada istringstream para procesar la l�nea actual
        // Aqu� se crea un istringstream llamado iss, que es un stream de entrada que procesar� la l�nea actual productosInfo. Esto se hace para poder leer y extraer los datos separados por espacios en esa l�nea.
        istringstream iss(productosInfo);

        // Leer el c�digo y el nombre del pedido desde la l�nea
        // Esta l�nea de c�digo utiliza el istringstream para leer y extraer el c�digo y el nombre del pedido desde la l�nea actual. Los datos se almacenan en las variables codigoLeido y nombrePedido
        iss >> codigoLeido >> nombrePedido;

        // Verificar si el c�digo del pedido le�do coincide con el c�digo proporcionado
        // Se verifica si el c�digo del pedido le�do (codigoLeido) coincide con el c�digo del pedido proporcionado por el usuario (codigoPedido). Si hay coincidencia, significa que se ha encontrado el pedido que se desea marcar como enviado.
        if (codigoLeido == codigoPedido)
        {
            // Escribir el c�digo y el nombre del pedido en el archivo temporal
            // Si el c�digo del pedido coincide, esta l�nea escribe el c�digo y el nombre del pedido en el archivo temporal llamado "Temporal.txt". Esto es para copiar el pedido actual al archivo temporal.

            temporal << codigoLeido << " " << nombrePedido << " ";

            // Leer y actualizar cada producto separado por guiones en la l�nea actual
           // while (getline(iss, productosInfo, '-'))
           // {
                // Encontrar la �ltima posici�n del espacio en blanco en la informaci�n del producto
           //     size_t separador = productosInfo.find_last_of(' ');

                // Escribir en el archivo temporal la informaci�n del producto sin el estado de env�o
             //   temporal << productosInfo.substr(0, separador) << " ";
            //}

            // Agregar el indicador de enviado (S) al final del pedido en el archivo temporal
            // Despu�s de procesar los productos, se agrega al final del pedido la marca "S" para indicar que ha sido enviado y se agrega un salto de l�nea (endl) para pasar a la siguiente l�nea en el archivo temporal.
            temporal << "S" << endl;
        }
        else
        {
            // Si el c�digo del pedido no coincide, simplemente copiar la l�nea actual al archivo temporal
            // Si el c�digo del pedido no coincide con el c�digo le�do, esta l�nea simplemente copia la l�nea actual completa (productosInfo) al archivo temporal. Esto es para mantener todas las l�neas que no est�n relacionadas con el pedido que se desea marcar como enviado.
            temporal << productosInfo << endl;
        }
    }

    // Cerrar los archivos "Pedidos.txt" y "Temporal.txt"
    // Estas dos l�neas cierran los archivos "Pedidos.txt" y "Temporal.txt" que se hab�an abierto previamente para leer y escribir, respectivamente. Es importante cerrar los archivos despu�s de utilizarlos para liberar los recursos y asegurar que los datos se han guardado correctamente.
    archivoPedidos.close();
    temporal.close();

    // Reemplazar el archivo original "Pedidos.txt" con el archivo temporal "Temporal.txt"
    // El archivo original "Pedidos.txt" se eliminar� y el archivo temporal se renombrar� como "Pedidos.txt"
    // La funci�n remove es una funci�n de la biblioteca <cstdio> que se utiliza para eliminar un archivo del sistema de archivos. En este caso, se est� eliminando el archivo "Pedidos.txt", que es el archivo original que contiene todos los pedidos.
    remove("Pedidos.txt");
    // La funci�n rename es otra funci�n de la biblioteca <cstdio> que se utiliza para cambiar el nombre de un archivo. En este caso, se est� renombrando el archivo "Temporal.txt" a "Pedidos.txt". Esto se hace para reemplazar el archivo original "Pedidos.txt" con el archivo temporal que contiene el pedido marcado como enviado.
    rename("Temporal.txt", "Pedidos.txt");

    // Mostrar un mensaje indicando que el pedido con el c�digo proporcionado ha sido marcado como enviado
    cout << "Pedido con c�digo " << codigoPedido << " marcado como enviado." << endl;
}





// Funci�n para enviar un pedido
void enviarPedido()
{
    // Declaraci�n de variables locales
    int codigoPedido;
    char respuesta;

    // Mostrar mensaje de "Enviar pedido" en la consola
    cout << "Enviar pedido" << endl;

    // Solicitar al usuario que ingrese el c�digo del pedido
    cout << "Ingrese el c�digo del pedido: ";
    cin >> codigoPedido;

    // Verificar si el pedido existe y a�n no ha sido enviado
    if (verificarPedidoNoEnviado(codigoPedido))
    {
        // Si el pedido existe y no ha sido enviado, preguntar al usuario si desea enviarlo
        cout << "�Desea enviar el pedido? (S/N): ";
        cin >> respuesta;

        // Convertir la respuesta ingresada a may�sculas usando la funci�n toupper
        respuesta = toupper(respuesta);

        // Si el usuario responde "S" (S�), marcar el pedido como enviado
        if (respuesta == 'S')
        {
            marcarPedidoEnviado(codigoPedido);
        }
    }
}



