<<<<<<< HEAD


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
#include "../include/DTInmuebleListado.h"
#include "../include/DTPublicacion.h"
#include "../include/DTUsuario.h"
#include "../include/CListar.h"
#include "../include/CSubeYBaja.h"
#include "../include/IControladorFechaActual.h"
#include "../include/IControladorListar.h"
#include "../include/IControladorSubeYBaja.h"
#include "../include/HandlerInmobiliaria.h"
#include "../include/HandlerInmueble.h"
#include <string>
#include <set>

void mostrarMenu() {
    std::cout << "=== Menu de Operaciones ===" << std::endl;
    std::cout << "1. Alta de Usuario" << std::endl;
    std::cout << "2. Alta de Publicacion" << std::endl;
    std::cout << "3. Consulta de Publicaciones" << std::endl;
    std::cout << "4. Eliminar Inmueble" << std::endl;
    std::cout << "5. Suscribirse a Notificaciones" << std::endl;
    std::cout << "6. Consulta de Notificaciones" << std::endl;
    std::cout << "7. Elimiinar Suscripciones" << std::endl;
    std::cout << "8. Alta de Administracion de Propiedad" << std::endl;
    std::cout << "9. Cargar Datos" << std::endl;
    std::cout << "10. Ver fecha actual" << std::endl;
    std::cout << "11. Asignar fecha actual" << std::endl;
    std::cout << "0. Salir" << std::endl;
    std::cout << "Ingrese el codigo de operacion: ";
}

int obtenerOpcion() {
    int opcion;
    std::cin >> opcion;
    std::cin.ignore();
    return opcion;
}

void ejecutarOpcion(int opcion) {
    switch (opcion) {
        case 1:
            std::cout << " - ALTA DE USUARIO - " << std::endl;
            altaUsuario();
            break;
        case 2:
            std::cout << " - ALTA DE PUBLICACION - " << std::endl;
            altaPublicacion();
            break;
        case 3:
            std::cout << " - CONSULTA DE PUBLICACIONES - " << std::endl;
            consultaPublicaciones();
            break;
        case 4:
            std::cout << " - ELIMINAR INMUEBLE - " << std::endl;
            eliminarInmueble();
            break;
        case 5:
            std::cout << " - SUSCRIBIRSE A NOTIFICACIONES - " << std::endl;
            suscribirseNotificaciones();
            break;
        case 6:
            std::cout << " - CONSLTAR NOTIFICACIONES - " << std::endl;
            consultaNotificaciones();
            break;
        case 7:
            std::cout << " - ELIMINAR SUSCRIPCIONES - " << std::endl;
            eliminarSuscripciones();
            break;
        case 8:
            std::cout << " - ALTA ADMINISTRACION DE PROPIEDAD - " << std::endl;
            altaAdministracionPropiedad();
            break;
        case 9:
            std::cout << " - CARGAR DATOS - " << std::endl;
            cargarDatos();
            break;
        case 10:
            std::cout << " - VER FECHA ACTUAL - " << std::endl;
            verFechaActual();
            break;
        case 11:
            std::cout << " - ASIGNAR FECHA ACTUAL - " << std::endl;
            asignarFechaActual();
            break;
        case 0:
            std::cout << "Saliendo del programa..." << std::endl;
            exit(0);
        default:
            std::cout << "Opcion no valida. Intente de nuevo." << std::endl;
    }
}

void altaUsuario(){

    Factory* factory = Factory::getInstance();

    std::cout << "Ingrese el tipo de usuario (0: Cliente, 1: Inmobiliaria, 2: Propietario): ";
    int tipoUsuario;
    std::cin >> tipoUsuario;
    std::cin.ignore();
    if (tipoUsuario < 0 || tipoUsuario > 2){
        std::cout << "Opcion no valida. Intente de nuevo." << std::endl;
        return;
    }

    bool usuarioOk = false;
    
    std::string nickname;
    std::string contrasena;
    std::string nombre;
    std::string email;
    std::string apellido;
    std::string documento;
    std::string url;
    std::string telefono;
    std::string direccion;
    std::string cuentaBancaria;
    
    std::cout << "Nickname: ";
    std::getline(std::cin, nickname);
    std::cout << "Contrasena: ";
    std::getline(std::cin, contrasena);
    std::cout << "Nombre: ";
    std::getline(std::cin, nombre);
    std::cout << "Email: ";
    std::getline(std::cin, email);

    if (tipoUsuario == 0){
        std::cout << "Apellido: ";
        std::getline(std::cin, apellido);
        std::cout << "Documento: ";
        std::getline(std::cin, documento);
        IControladorSubeYBaja* ci = factory->getControladorSubeYBaja();
        bool usuarioOk = ci->altaCliente(nickname, contrasena, nombre, email, apellido, documento);
        //TODO: usuarioOk = ci->altaCliente(nickname, contrasena, nombre, email, apellido, documento);

    }else if (tipoUsuario == 1){
        std::cout << "Direccion: ";
        std::getline(std::cin, direccion);
        std::cout << "URL: ";
        std::getline(std::cin, url);
        std::cout << "Telefono: ";
        std::getline(std::cin, telefono);
        IControladorSubeYBaja* ci = factory->getControladorSubeYBaja();
        usuarioOk = ci->altaInmobiliaria(nickname, contrasena, nombre, email, direccion, url, telefono);
        //TODO: usuarioOk = ci->altaInmobiliaria(nickname, contrasena, nombre, email, direccion, url, telefono);

    }else if (tipoUsuario == 2){
        std::cout << "Cuenta Bancaria: ";
        std::getline(std::cin, cuentaBancaria);
        std::cout << "Telefono: ";
        std::getline(std::cin, telefono);
        IControladorSubeYBaja* ci = factory->getControladorSubeYBaja();
        usuarioOk = ci->altaPropietario(nickname, contrasena, nombre, email, cuentaBancaria, telefono);
        //TODO: usuarioOk = ci->altaPropietario(nickname, contrasena, nombre, email, cuentaBancaria, telefono);

    }
    if (usuarioOk){
        if (tipoUsuario == 1 || tipoUsuario == 2){
            int salir = 1;
            std::cout << "¿Quiere ingresar los datos relacionados? (1: Si, 0: No): ";
            std::cin >> salir;
            std::cin.ignore();
            std::string inmuebleDireccion;
            int numeroPuerta;
            int superficie;
            int anoConstruccion;
            while (salir != 0){
                if (tipoUsuario == 1){
                    std::cout << "Lista de Propietarios:\n";
                    //TODO: Coleccion de DTUsuario = controlador->listarPropietarios();
                    //Recorrer la coleccion Mostrar "- Nickname: xx, Nombre: zz";
                    std::cout << "Nickname propietario a representar: ";
                    std::string nicknamePropietario;
                    std::getline(std::cin, nicknamePropietario);
                    //TODO: controlador->representarPropietario(nicknamePropietario)
                }else if (tipoUsuario == 2){
                    int tipoInmueble;
                    std::cout << "Indique el tipo de inmueble (1: Casa, 0: Apartamento): ";
                    std::cin >> tipoInmueble;
                    std::cin.ignore();
    
                    std::cout << "Direccion: ";
                    std::getline(std::cin, inmuebleDireccion);
                    std::cout << "Numero de Puerta: ";
                    std::cin >> numeroPuerta;
                    std::cin.ignore(); 
                    std::cout << "Superficie: ";
                    std::cin >> superficie;
                    std::cin.ignore();
                    std::cout << "Ano de Construccion: ";
                    std::cin >> anoConstruccion;
                    std::cin.ignore();

                    if (tipoInmueble == 1){
                        std::cout << "Es PH (1 para si, 0 para no): ";
                        int inEsPH;
                        std::cin >> inEsPH;
                        bool esPH = (inEsPH == 1);
                        std::cin.ignore();
                        std::cout << "Tipo de Techo (0: Liviano 1: A dos aguas, 2: Plano): ";
                        int inTipoTecho;
                        std::cin >> inTipoTecho;
                        std::cin.ignore();
                        TipoTecho techo = Liviano;
                        if(inTipoTecho == 1){
                            techo = A_dos_aguas;
                        }else if (inTipoTecho == 2){
                            techo = Plano;
                        }
                        //TODO: controlador->altaCasa(direccion, numeroPuerta, superficie, anoConstruccion, esPH, techo);
                    }else{
                        int piso;
                        std::cout << "Piso: ";
                        std::cin >> piso;
                        std::cin.ignore();
                        std::cout << "Tiene Ascensor (1 para si, 0 para no): ";
                        int inTieneAscensor;
                        std::cin >> inTieneAscensor;
                        bool tieneAscensor = (inTieneAscensor == 1);
                        std::cin.ignore();
                        std::cout << "Gastos Comunes: ";
                        float gastosComunes;
                        std::cin >> gastosComunes;
                        std::cin.ignore();
                        //TODO: controlador->altaApartamento(direccion, numeroPuerta, superficie, anoConstruccion, piso, tieneAscensor, gastosComunes)
                    }
                }
            }
            std::cout << "¿Quiere seguir ingresando? (1: Si, 0: No): ";
            std::cin >> salir;
            std::cin.ignore();
        }
        //TODO: controlador->finalizarAltaUsuario();
    }else{
        std::cout << "Error al crear el usuario" << std::endl;
    }
}

void altaPublicacion(){
    Factory* factory = Factory::getInstance();

    std::cout << "Lista de Inmobiliarias:\n";
    //TODO: Coleccion de DTUsuario = controlador->listarInmobiliarias();
    IControladorListar* controladorListar = factory->getControladorListar();
    set<DTUsuario> DTUsuarios = controladorListar->listarInmobiliarias();
    //Recorrer la coleccion Mostrar "- Nickname: xx, Nombre: zz";
    set<DTUsuario>::iterator it;
    for (it = DTUsuarios.begin(); it != DTUsuarios.end(); ++it) {
        std::cout << "- Nickname: " << (*it).getNickname() << ", Nombre: " << (*it).getNombre() << std::endl;
    };
    std::cout << "Nickname de la inmobiliaria: ";
    std::string nicknameInmobiliaria;
    std::getline(std::cin, nicknameInmobiliaria);
    //TODO: Coleccion de DTInmuebleAdministrado = controlador->listarInmueblesAdministrados(nicknameInmobiliaria);
    set<DTInmuebleAdministrado> DTInmueblesAdministrados=controladorListar->listarInmueblesAdministrados(nicknameInmobiliaria);
    //Recorrer la coleccion Mostrar "- Codigo: xx, Direccion: yy, Propietario: zzz"
    set<DTInmuebleAdministrado>::iterator it2;
    for(it2=DTInmueblesAdministrados.begin();it2!=DTInmueblesAdministrados.end();++it2){
        std::cout << "- Codigo: " << (*it2).getCodigo() << ", Direccion: " << (*it2).getDireccion()<< std::endl;
    };
    int codigoInmueble;
    std::cout << "Inmueble: ";
    std::cin >> codigoInmueble;
    std::cin.ignore();
    int inTipoPublicacion;
    std::cout << "Tipo de Publicacion: (1: Venta, 0: Alquiler)";
    std::cin >> inTipoPublicacion;
    TipoPublicacion tipoPublicacion = Alquiler;
    if(inTipoPublicacion == 1){
        tipoPublicacion = Venta;
    }
    std::cin.ignore();
    std::cout << "Texto: ";
    std::string texto;
    std::getline(std::cin, texto);
    std::cout << "Precio: ";
    float precio;
    std::cin >> precio;
    std::cin.ignore();
    //TODO:Controlador->altaPublicacion(nicknameInmobiliaria, codigoInmueble, tipoPublicacion, texto, precio)
    IControladorSubeYBaja* controladorSubeYBaja = factory->getControladorSubeYBaja();
    bool altapublicacion= controladorSubeYBaja->altaPublicacion(nicknameInmobiliaria, codigoInmueble, tipoPublicacion, texto, precio);
}

void consultaPublicaciones(){

    Factory* factory = Factory::getInstance();

    int inTipoPublicacion;
    std::cout << "Tipo de Publicacion: (1: Venta, 0: Alquiler)";
    std::cin >> inTipoPublicacion;
    TipoPublicacion tipoPublicacion = Alquiler;
    if(inTipoPublicacion == 1){
        tipoPublicacion = Venta;
    }
    std::cin.ignore();
    std::cout << "Precio (Min): ";
    float precioMinimo;
    std::cin >> precioMinimo;
    std::cin.ignore();
    std::cout << "Precio (Max): ";
    float precioMaximo;
    std::cin >> precioMaximo;
    std::cin.ignore();
    int inTipoInmueble;
    std::cout << "Tipo de Inmueble: (1: Casa, 2: Apartamento, 0: Todos)";
    std::cin >> inTipoInmueble;
    std::cin.ignore();
    TipoInmueble tipoInmueble = Todos;
    if(inTipoPublicacion == 1){
        tipoInmueble = Casa;
    }else if(inTipoPublicacion == 2){
        tipoInmueble = Apartamento;
    }
    std::cout << "Publicaciones encontradas:\n";
    //TODO: Coleccion de DTPublicacion = Controlador->listarPublicacion(tipoPublicacion, precionMinimo, precioMaximo, tipoInmueble);
    //Recorrer la coleccion Mostrar "- Codigo: xx, fecha: dd/mm/yyyy, texto: zzz, precio: aaa, inmobiliaria: bbb";
    int verDetalle;
    std::cout << "Ver detalle de la publicacion: (1: Si, 0: No)";
    std::cin >> verDetalle;
    std::cin.ignore();
    if (verDetalle == 1){
        std::cout << "Codigo de publicacion: ";
        int codigoPublicacion;
        std::cin >> codigoPublicacion;
        std::cin.ignore();
        std::cout << "Detalle del inmueble:\n";
        //TODO: DTInmueble = Controlador->detalleInmueblePublicacion(codigoPublicacion): DTInmueble
        //Mostrarlo:
        // Si es apartamento-> "Codigo: aaa, direccion: bbb, nro. puerta: ccc, superficie: xx m2, consturccion: dddd, piso: xx, ascensor: Si/No, gastos comunes: yyy"
        // Si es casa-> "Codigo: aaa, direccion: bbb, nro. puerta: ccc, superficie: xx m2, consturccion: dddd, PH: Si/No, Tipo de techo: Liviano/A dos aguas/Plano"
    }
}

void eliminarInmueble(){

    Factory* factory = Factory::getInstance();
    std::cout << "Listado de inmuebles:\n";
    //TODO: Coleccion de DTInmuebleListado = Controlador->listarInmuebles();
    //Recorrer la coleccion Mostrar "- Codigo: xx, direccion: xxxx, propietario: bbbbb";
    std::cout << "Codigo del inmueble a eliminar: ";
    int codigoInmueble;
    std::cin >> codigoInmueble;
    std::cin.ignore();
    std::cout << "Detalle del inmueble:\n";
    //TODO: DTInmueble = Controlador->detalleInmueble(codigoInmueble)
    //Mostrarlo:
    // Si es apartamento-> "Codigo: aaa, direccion: bbb, nro. puerta: ccc, superficie: xx m2, consturccion: dddd, piso: xx, ascensor: Si/No, gastos comunes: yyy"
    // Si es casa-> "Codigo: aaa, direccion: bbb, nro. puerta: ccc, superficie: xx m2, consturccion: dddd, PH: Si/No, Tipo de techo: Liviano/A dos aguas/Plano"
    int deseaEliminar;
    std::cout << "¿Desea eliminar?: (1: Si, 0: No)";
    std::cin >> deseaEliminar;
    std::cin.ignore();
    if (deseaEliminar == 1){
        //TODO: Controlador->eliminarInmueble(codigoInmueble)
    }

}

void suscribirseNotificaciones(){

}

void consultaNotificaciones(){

}

void eliminarSuscripciones(){

}

void altaAdministracionPropiedad(){
    Factory* factory = Factory::getInstance();

    std::cout << "Lista de Inmobiliarias:\n";
    //TODO: Coleccion de DTUsuario = controlador->listarInmobiliarias();
    //Recorrer la coleccion Mostrar "- Nickname: xx, Nombre: zz";
    std::cout << "Nickname de la inmobiliaria: ";
    std::string nicknameInmobiliaria;
    std::getline(std::cin, nicknameInmobiliaria);
    //TODO: Coleccion de DTInmuebleListado = Controlador->listarInmueblesNoAdministradosInmobiliaria(nicknameInmobiliaria);
    //Recorrer la coleccion Mostrar "- Codigo: xx, direccion: xxxx, propietario: bbbbb";
    std::cout << "Codigo del inmueble a administrar: ";
    int codigoInmueble;
    std::cin >> codigoInmueble;
    std::cin.ignore();
    //TODO: Controlador->altaAdministraPropiedad(nicknameInmobiliaria, codigoInmueble);
}

void cargarDatos(){
    CargaDatos::getInstance();
}

void verFechaActual(){
Factory* factory = Factory::getInstance();
IControladorFechaActual* cfecha = factory->getControladorFechaActual();
DTFecha* fechaActual = cfecha->getFechaActual();
std::cout << "fecha actual: " << fechaActual;
delete fechaActual;
}

void asignarFechaActual(){
Factory* factory = Factory::getInstance();
IControladorFechaActual* cfecha = factory->getControladorFechaActual();
std::cout << "dia: ";
int dia;
std::cin >> dia;
std::cin.ignore();
std::cout << "mes: ";
int mes;
std::cin >> mes;
std::cin.ignore();
std::cout << "ano: ";
int ano;
std::cin >> ano;
std::cin.ignore();
cfecha->setNewFechaActual(dia, mes, ano);

=======
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
#include "../include/DTInmuebleListado.h"
#include "../include/DTPublicacion.h"
#include "../include/DTUsuario.h"
#include "../include/Usuario.h"
#include "../include/Propietario.h"
#include "../include/Cliente.h"
#include "../include/IControladorSubeYBaja.h"
#include "../include/IControladorFechaActual.h"
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

    Factory *factory = Factory::getInstancia();

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
        IControladorSubeYBaja* ci = factory->getControladorSubeYBaja();
        bool usuarioOk = ci->altaCliente(nickname, contrasena, nombre, email, apellido, documento);
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
        IControladorSubeYBaja* ci = factory->getControladorSubeYBaja();
        usuarioOk = ci->altaInmobiliaria(nickname, contrasena, nombre, email, direccion, url, telefono);
        // TODO: usuarioOk = ci->altaInmobiliaria(nickname, contrasena, nombre, email, direccion, url, telefono);
    }
    else if (tipoUsuario == 2)
    {
        cout << "Cuenta Bancaria: ";
        getline(cin, cuentaBancaria);
        cout << "Telefono: ";
        getline(cin, telefono);
        IControladorSubeYBaja* ci = factory->getControladorSubeYBaja();
        usuarioOk = ci->altaPropietario(nickname, contrasena, nombre, email, cuentaBancaria, telefono);
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
    Factory *factory = Factory::getInstancia();

    std::cout << "Lista de Inmobiliarias:\n";
    // TODO: Coleccion de DTUsuario = controlador->listarInmobiliarias();
    IControladorListar *controladorListar = factory->getControladorListar();
    set<DTUsuario> DTUsuarios = controladorListar->listarInmobiliarias();
    // Recorrer la coleccion Mostrar "- Nickname: xx, Nombre: zz";
    set<DTUsuario>::iterator it;
    for (it = DTUsuarios.begin(); it != DTUsuarios.end(); ++it)
    {
        std::cout << "- Nickname: " << (*it).getNickname() << ", Nombre: " << (*it).getNombre() << std::endl;
    };
    std::cout << "Nickname de la inmobiliaria: ";
    std::string nicknameInmobiliaria;
    std::getline(std::cin, nicknameInmobiliaria);
    // TODO: Coleccion de DTInmuebleAdministrado = controlador->listarInmueblesAdministrados(nicknameInmobiliaria);
    set<DTInmuebleAdministrado> DTInmueblesAdministrados = controladorListar->listarInmueblesAdministrados(nicknameInmobiliaria);
    // Recorrer la coleccion Mostrar "- Codigo: xx, Direccion: yy, Propietario: zzz"
    set<DTInmuebleAdministrado>::iterator it2;
    for (it2 = DTInmueblesAdministrados.begin(); it2 != DTInmueblesAdministrados.end(); ++it2)
    {
        std::cout << "- Codigo: " << (*it2).getCodigo() << ", Direccion: " << (*it2).getDireccion() << std::endl;
    };
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
    std::cin >> precio;
    std::cin.ignore();
    // TODO:Controlador->altaPublicacion(nicknameInmobiliaria, codigoInmueble, tipoPublicacion, texto, precio)
    IControladorSubeYBaja *controladorSubeYBaja = factory->getControladorSubeYBaja();
    bool altapublicacion = controladorSubeYBaja->altaPublicacion(nicknameInmobiliaria, codigoInmueble, tipoPublicacion, texto, precio);
}

void consultaPublicaciones()
{

    Factory *factory = Factory::getInstancia();

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

    Factory *factory = Factory::getInstancia();
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
    Factory *factory = Factory::getInstancia();
    IControladorSuscripciones *controladorSuscripciones = factory->getControladorSuscripciones();
    IControladorListar *controladorListar = factory->getControladorListar();
    // IMPORTANTE: Se asume que el nickname de usuario ingresado está en el sistema, y además es o un Usuario o un Propietario
    cout << "Indique el nickname del usuario del que quiere consultar las notificaciones:\n";
    string nicknameUsuario;
    getline(cin, nicknameUsuario);
    set<DTNotificacion> notificaciones = controladorListar->listarNotificacionesDeUsuario(nicknameUsuario);
    controladorSuscripciones->borrarNotificaciones(nicknameUsuario);
    int contador = 1;
    for (set<DTNotificacion>::const_iterator it = notificaciones.begin(); it != notificaciones.end(); ++it)
    {
        cout << contador << " - " << *it << endl;
        ++contador;
    }
}

void eliminarSuscripciones()
{
    Factory *factory = Factory::getInstancia();
    IControladorSuscripciones *controladorSuscripciones = factory->getControladorSuscripciones();
    IControladorListar *controladorListar = factory->getControladorListar();
    // IMPORTANTE: Se asume que el nickname de usuario ingresado está en el sistema, y además es o un Usuario o un Propietario
    cout << "Indique el nickname del usuario del que quiere eliminar las suscripciones:\n";
    string nicknameUsuario;
    getline(cin, nicknameUsuario);
    // Listar las suscripciones del usuario
    set<DTUsuario> suscripciones = controladorListar->listarSuscripciones(nicknameUsuario);
    cout << "Las suscripciones son las siguientes:\n";
    int contador = 1;
    for (set<DTUsuario>::const_iterator it = suscripciones.begin(); it != suscripciones.end(); ++it)
    {
        cout << contador << " - " << *it << endl;
        ++contador;
    }
    // Eliminar las suscripciones elegidas por el Administrador
    int deseaEliminar;
    cout << "¿Desea eliminar alguna suscripción?: (1: Si, 0: No)";
    cin >> deseaEliminar;
    cin.ignore();
    if (deseaEliminar = 0)
    {
        return;
    }
    set<string> inmobiliariasElegidas;
    while (deseaEliminar = 1)
    {
        cout << "Ingrese el nickname de la inmobiliaria de la que se quiere desuscribir:\n";
        string nicknameInmobiliaria;
        getline(cin, nicknameInmobiliaria);
        inmobiliariasElegidas.insert(nicknameInmobiliaria);
        cout << "¿Desea eliminar otra suscripción?: (1: Si, 0: No)";
        cin >> deseaEliminar;
        cin.ignore();
    }
    controladorSuscripciones->eliminarSuscripcion(nicknameUsuario, inmobiliariasElegidas);
}

void altaAdministracionPropiedad()
{
    Factory *factory = Factory::getInstancia();

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
    CargaDatos::getInstancia();
}

void verFechaActual()
{
    Factory *factory = Factory::getInstancia();
    IControladorFechaActual *cfecha = factory->getControladorFechaActual();
    DTFecha *fechaActual = cfecha->getFechaActual();
    cout << "fecha actual: " << fechaActual;
    delete fechaActual;
}

void asignarFechaActual()
{
    Factory *factory = Factory::getInstancia();
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
>>>>>>> origin/main
}