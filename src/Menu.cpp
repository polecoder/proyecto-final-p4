#include <iostream>
#include "../include/Menu.h"
#include "../include/CargaDatos.h"
#include "../include/TipoInmueble.h"
#include "../include/TipoPublicacion.h"
#include "../include/TipoTecho.h"
#include "../include/Factory.h"
#include "../include/DTApartamento.h"
#include "../include/DTCasa.h"
#include "../include/DTFecha.h"
#include "../include/DTInmueble.h"
#include "../include/DTInmuebleAdministrado.h"
#include "../include/DTinmuebleListado.h"
#include "../include/DTPublicacion.h"
#include "../include/DTUsuario.h"
#include "../include/Usuario.h"
#include "../include/Propietario.h"
#include "../include/Cliente.h"
#include "../include/IControladorSuscripciones.h"
#include "../include/IControladorListar.h"
#include <string>
#include <set>

using namespace std;

void mostrarMenu()
{
    cout << "=== Menu de Operaciones ===" << endl;
    cout << "1. Alta de Usuario" << endl;
    cout << "2. Alta de Publicacion" << endl;
    cout << "3. Consulta de Publicaciones" << endl;
    cout << "4. Eliminar Inmueble" << endl;
    cout << "5. Suscribirse a Notificaciones" << endl;
    cout << "6. Consulta de Notificaciones" << endl;
    cout << "7. Elimiinar Suscripciones" << endl;
    cout << "8. Alta de Administracion de Propiedad" << endl;
    cout << "9. Cargar Datos" << endl;
    cout << "10. Ver fecha actual" << endl;
    cout << "11. Asignar fecha actual" << endl;
    cout << "0. Salir" << endl;
    cout << "Ingrese el codigo de operacion: ";
}

int obtenerOpcion()
{
    int opcion;
    cin >> opcion;
    cin.ignore();
    return opcion;
}

void ejecutarOpcion(int opcion)
{
    switch (opcion)
    {
    case 1:
        cout << " - ALTA DE USUARIO - " << endl;
        altaUsuario();
        break;
    case 2:
        cout << " - ALTA DE PUBLICACION - " << endl;
        altaPublicacion();
        break;
    case 3:
        cout << " - CONSULTA DE PUBLICACIONES - " << endl;
        consultaPublicaciones();
        break;
    case 4:
        cout << " - ELIMINAR INMUEBLE - " << endl;
        eliminarInmueble();
        break;
    case 5:
        cout << " - SUSCRIBIRSE A NOTIFICACIONES - " << endl;
        suscribirseNotificaciones();
        break;
    case 6:
        cout << " - CONSLTAR NOTIFICACIONES - " << endl;
        consultaNotificaciones();
        break;
    case 7:
        cout << " - ELIMINAR SUSCRIPCIONES - " << endl;
        eliminarSuscripciones();
        break;
    case 8:
        cout << " - ALTA ADMINISTRACION DE PROPIEDAD - " << endl;
        altaAdministracionPropiedad();
        break;
    case 9:
        cout << " - CARGAR DATOS - " << endl;
        cargarDatos();
        break;
    case 10:
        cout << " - VER FECHA ACTUAL - " << endl;
        verFechaActual();
        break;
    case 11:
        cout << " - ASIGNAR FECHA ACTUAL - " << endl;
        asignarFechaActual();
        break;
    case 0:
        cout << "Saliendo del programa..." << endl;
        exit(0);
    default:
        cout << "Opcion no valida. Intente de nuevo." << endl;
    }
}

void altaUsuario()
{

    Factory *factory = Factory::getInstance();

    cout << "Ingrese el tipo de usuario (0: Cliente, 1: Inmobiliaria, 2: Propietario): ";
    int tipoUsuario;
    cin >> tipoUsuario;
    cin.ignore();
    if (tipoUsuario < 0 || tipoUsuario > 2)
    {
        cout << "Opcion no valida. Intente de nuevo." << endl;
        return;
    }

    bool usuarioOk = false;

    string nickname;
    string contrasena;
    string nombre;
    string email;
    string apellido;
    string documento;
    string url;
    string telefono;
    string direccion;
    string cuentaBancaria;

    cout << "Nickname: ";
    getline(cin, nickname);
    cout << "Contrasena: ";
    getline(cin, contrasena);
    cout << "Nombre: ";
    getline(cin, nombre);
    cout << "Email: ";
    getline(cin, email);

    if (tipoUsuario == 0)
    {
        cout << "Apellido: ";
        getline(cin, apellido);
        cout << "Documento: ";
        getline(cin, documento);
        // TODO: usuarioOk = ci->altaCliente(nickname, contrasena, nombre, email, apellido, documento);
    }
    else if (tipoUsuario == 1)
    {
        cout << "Direccion: ";
        getline(cin, direccion);
        cout << "URL: ";
        getline(cin, url);
        cout << "Telefono: ";
        getline(cin, telefono);
        // TODO: usuarioOk = ci->altaInmobiliaria(nickname, contrasena, nombre, email, direccion, url, telefono);
    }
    else if (tipoUsuario == 2)
    {
        cout << "Cuenta Bancaria: ";
        getline(cin, cuentaBancaria);
        cout << "Telefono: ";
        getline(cin, telefono);
        // TODO: usuarioOk = ci->altaPropietario(nickname, contrasena, nombre, email, cuentaBancaria, telefono);
    }
    if (usuarioOk)
    {
        if (tipoUsuario == 1 || tipoUsuario == 2)
        {
            int salir = 1;
            cout << "¿Quiere ingresar los datos relacionados? (1: Si, 0: No): ";
            cin >> salir;
            cin.ignore();
            string inmuebleDireccion;
            int numeroPuerta;
            int superficie;
            int anoConstruccion;
            while (salir != 0)
            {
                if (tipoUsuario == 1)
                {
                    cout << "Lista de Propietarios:\n";
                    // TODO: Coleccion de DTUsuario = controlador->listarPropietarios();
                    // Recorrer la coleccion Mostrar "- Nickname: xx, Nombre: zz";
                    cout << "Nickname propietario a representar: ";
                    string nicknamePropietario;
                    getline(cin, nicknamePropietario);
                    // TODO: controlador->representarPropietario(nicknamePropietario)
                }
                else if (tipoUsuario == 2)
                {
                    int tipoInmueble;
                    cout << "Indique el tipo de inmueble (1: Casa, 0: Apartamento): ";
                    cin >> tipoInmueble;
                    cin.ignore();

                    cout << "Direccion: ";
                    getline(cin, inmuebleDireccion);
                    cout << "Numero de Puerta: ";
                    cin >> numeroPuerta;
                    cin.ignore();
                    cout << "Superficie: ";
                    cin >> superficie;
                    cin.ignore();
                    cout << "Ano de Construccion: ";
                    cin >> anoConstruccion;
                    cin.ignore();

                    if (tipoInmueble == 1)
                    {
                        cout << "Es PH (1 para si, 0 para no): ";
                        int inEsPH;
                        cin >> inEsPH;
                        bool esPH = (inEsPH == 1);
                        cin.ignore();
                        cout << "Tipo de Techo (0: Liviano 1: A dos aguas, 2: Plano): ";
                        int inTipoTecho;
                        cin >> inTipoTecho;
                        cin.ignore();
                        TipoTecho techo = Liviano;
                        if (inTipoTecho == 1)
                        {
                            techo = A_dos_aguas;
                        }
                        else if (inTipoTecho == 2)
                        {
                            techo = Plano;
                        }
                        // TODO: controlador->altaCasa(direccion, numeroPuerta, superficie, anoConstruccion, esPH, techo);
                    }
                    else
                    {
                        int piso;
                        cout << "Piso: ";
                        cin >> piso;
                        cin.ignore();
                        cout << "Tiene Ascensor (1 para si, 0 para no): ";
                        int inTieneAscensor;
                        cin >> inTieneAscensor;
                        bool tieneAscensor = (inTieneAscensor == 1);
                        cin.ignore();
                        cout << "Gastos Comunes: ";
                        float gastosComunes;
                        cin >> gastosComunes;
                        cin.ignore();
                        // TODO: controlador->altaApartamento(direccion, numeroPuerta, superficie, anoConstruccion, piso, tieneAscensor, gastosComunes)
                    }
                }
            }
            cout << "¿Quiere seguir ingresando? (1: Si, 0: No): ";
            cin >> salir;
            cin.ignore();
        }
        // TODO: controlador->finalizarAltaUsuario();
    }
    else
    {
        cout << "Error al crear el usuario" << endl;
    }
}

void altaPublicacion()
{

    Factory *factory = Factory::getInstance();

    cout << "Lista de Inmobiliarias:\n";
    // TODO: Coleccion de DTUsuario = controlador->listarInmobiliarias();
    // Recorrer la coleccion Mostrar "- Nickname: xx, Nombre: zz";
    cout << "Nickname de la inmobiliaria: ";
    string nicknameInmobiliaria;
    getline(cin, nicknameInmobiliaria);
    // TODO: Coleccion de DTInmuebleAdministrado = controlador->listarInmueblesAdministrados(nicknameInmobiliaria);
    // Recorrer la coleccion Mostrar "- Codigo: xx, Direccion: yy, Propietario: zzz"
    int codigoInmueble;
    cout << "Inmueble: ";
    cin >> codigoInmueble;
    cin.ignore();
    int inTipoPublicacion;
    cout << "Tipo de Publicacion: (1: Venta, 0: Alquiler)";
    cin >> inTipoPublicacion;
    TipoPublicacion tipoPublicacion = Alquiler;
    if (inTipoPublicacion == 1)
    {
        tipoPublicacion = Venta;
    }
    cin.ignore();
    cout << "Texto: ";
    string texto;
    getline(cin, texto);
    cout << "Precio: ";
    float precio;
    cin >> precio;
    cin.ignore();
    // TODO:Controlador->altaPublicacion(nicknameInmobiliaria, codigoInmueble, tipoPublicacion, texto, precio)
}

void consultaPublicaciones()
{

    Factory *factory = Factory::getInstance();

    int inTipoPublicacion;
    cout << "Tipo de Publicacion: (1: Venta, 0: Alquiler)";
    cin >> inTipoPublicacion;
    TipoPublicacion tipoPublicacion = Alquiler;
    if (inTipoPublicacion == 1)
    {
        tipoPublicacion = Venta;
    }
    cin.ignore();
    cout << "Precio (Min): ";
    float precioMinimo;
    cin >> precioMinimo;
    cin.ignore();
    cout << "Precio (Max): ";
    float precioMaximo;
    cin >> precioMaximo;
    cin.ignore();
    int inTipoInmueble;
    cout << "Tipo de Inmueble: (1: Casa, 2: Apartamento, 0: Todos)";
    cin >> inTipoInmueble;
    cin.ignore();
    TipoInmueble tipoInmueble = Todos;
    if (inTipoPublicacion == 1)
    {
        tipoInmueble = Casa;
    }
    else if (inTipoPublicacion == 2)
    {
        tipoInmueble = Apartamento;
    }
    cout << "Publicaciones encontradas:\n";
    // TODO: Coleccion de DTPublicacion = Controlador->listarPublicacion(tipoPublicacion, precionMinimo, precioMaximo, tipoInmueble);
    // Recorrer la coleccion Mostrar "- Codigo: xx, fecha: dd/mm/yyyy, texto: zzz, precio: aaa, inmobiliaria: bbb";
    int verDetalle;
    cout << "Ver detalle de la publicacion: (1: Si, 0: No)";
    cin >> verDetalle;
    cin.ignore();
    if (verDetalle == 1)
    {
        cout << "Codigo de publicacion: ";
        int codigoPublicacion;
        cin >> codigoPublicacion;
        cin.ignore();
        cout << "Detalle del inmueble:\n";
        // TODO: DTInmueble = Controlador->detalleInmueblePublicacion(codigoPublicacion): DTInmueble
        // Mostrarlo:
        //  Si es apartamento-> "Codigo: aaa, direccion: bbb, nro. puerta: ccc, superficie: xx m2, consturccion: dddd, piso: xx, ascensor: Si/No, gastos comunes: yyy"
        //  Si es casa-> "Codigo: aaa, direccion: bbb, nro. puerta: ccc, superficie: xx m2, consturccion: dddd, PH: Si/No, Tipo de techo: Liviano/A dos aguas/Plano"
    }
}

void eliminarInmueble()
{

    Factory *factory = Factory::getInstance();
    cout << "Listado de inmuebles:\n";
    // TODO: Coleccion de DTInmuebleListado = Controlador->listarInmuebles();
    // Recorrer la coleccion Mostrar "- Codigo: xx, direccion: xxxx, propietario: bbbbb";
    cout << "Codigo del inmueble a eliminar: ";
    int codigoInmueble;
    cin >> codigoInmueble;
    cin.ignore();
    cout << "Detalle del inmueble:\n";
    // TODO: DTInmueble = Controlador->detalleInmueble(codigoInmueble)
    // Mostrarlo:
    //  Si es apartamento-> "Codigo: aaa, direccion: bbb, nro. puerta: ccc, superficie: xx m2, consturccion: dddd, piso: xx, ascensor: Si/No, gastos comunes: yyy"
    //  Si es casa-> "Codigo: aaa, direccion: bbb, nro. puerta: ccc, superficie: xx m2, consturccion: dddd, PH: Si/No, Tipo de techo: Liviano/A dos aguas/Plano"
    int deseaEliminar;
    cout << "¿Desea eliminar?: (1: Si, 0: No)";
    cin >> deseaEliminar;
    cin.ignore();
    if (deseaEliminar == 1)
    {
        // TODO: Controlador->eliminarInmueble(codigoInmueble)
    }
}

void suscribirseNotificaciones()
{
}

void consultaNotificaciones()
{
    Factory *factory = Factory::getInstance();
    IControladorSuscripciones *controladorSuscripciones = factory->getControladorSuscripciones();
    IControladorListar *controladorListar = factory->getControladorListar();
    // IMPORTANTE: Se asume que el nickname de usuario ingresado está en el sistema, y además es o un Usuario o un Propietario
    cout << "Indique el nickname del usuario del que quiere consultar las notificaciones:";
    string nicknameUsuario;
    getline(cin, nicknameUsuario);
    controladorListar->listarNotificacionesDeUsuario(nicknameUsuario);
    controladorSuscripciones->borrarNotificaciones(nicknameUsuario);
}

void eliminarSuscripciones()
{
}

void altaAdministracionPropiedad()
{
    Factory *factory = Factory::getInstance();

    cout << "Lista de Inmobiliarias:\n";
    // TODO: Coleccion de DTUsuario = controlador->listarInmobiliarias();
    // Recorrer la coleccion Mostrar "- Nickname: xx, Nombre: zz";
    cout << "Nickname de la inmobiliaria: ";
    string nicknameInmobiliaria;
    getline(cin, nicknameInmobiliaria);
    // TODO: Coleccion de DTInmuebleListado = Controlador->listarInmueblesNoAdministradosInmobiliaria(nicknameInmobiliaria);
    // Recorrer la coleccion Mostrar "- Codigo: xx, direccion: xxxx, propietario: bbbbb";
    cout << "Codigo del inmueble a administrar: ";
    int codigoInmueble;
    cin >> codigoInmueble;
    cin.ignore();
    // TODO: Controlador->altaAdministraPropiedad(nicknameInmobiliaria, codigoInmueble);
}

void cargarDatos()
{
    CargaDatos::getInstance();
}

void verFechaActual()
{
    Factory *factory = Factory::getInstance();
    IControladorFechaActual *cfecha = factory->getControladorFechaActual();
    DTFecha *fechaActual = cfecha->getFechaActual();
    cout << "fecha actual: " << fechaActual;
    delete fechaActual;
}

void asignarFechaActual()
{
    Factory *factory = Factory::getInstance();
    IControladorFechaActual *cfecha = factory->getControladorFechaActual();
    cout << "dia: ";
    int dia;
    cin >> dia;
    cin.ignore();
    cout << "mes: ";
    int mes;
    cin >> mes;
    cin.ignore();
    cout << "ano: ";
    int ano;
    cin >> ano;
    cin.ignore();
    cfecha->setNewFechaActual(dia, mes, ano);
}