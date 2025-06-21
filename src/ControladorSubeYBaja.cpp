#include "../include/ControladorSubeYBaja.h"
#include "../include/Casa.h"
#include "../include/Apartamento.h"
#include "../include/Inmueble.h"
#include "../include/HandlerInmueble.h"
#include "../include/IControladorFechaActual.h"
#include <iostream>

using namespace std;

ControladorSubeYBaja *ControladorSubeYBaja::instancia = nullptr;

ControladorSubeYBaja *ControladorSubeYBaja::getInstancia()
{
    if (instancia == nullptr)
    {
        instancia = new ControladorSubeYBaja();
    }
    return instancia;
};

ControladorSubeYBaja::ControladorSubeYBaja()
{
    Hinmobiliarias = HandlerInmobiliarias::getInstancia();
    HPublicacion = HandlerPublicacion::getInstancia();
    Hcliente = HandlerClientes::getInstancia();
    Hpropietario = HandlerPropietarios::getInstancia();
    HInmueble = HandlerInmueble::getInstancia();
    handlerAdministraPropiedad = HandlerAdministraPropiedad::getInstancia();
    fechaActual = ControladorFechaActual::getInstancia();
};
ControladorSubeYBaja::~ControladorSubeYBaja() {
    // Destructor vacio, no es necesario liberar memoria ya que no hay punteros
    // Los Handlers se encargan de liberar su propia memoria
};

bool ControladorSubeYBaja::altaPublicacion(string nicknameInmobiliaria, int codigoInmueble, TipoPublicacion tipoPublicacion, string texto, float precio)
{
    // se busca si existe una publicacion con el mismo tipo y fecha
    vector<AdministraPropiedad *> adProp = Hinmobiliarias->getColeccionAdministraPropiedad(nicknameInmobiliaria);
    vector<AdministraPropiedad *>::iterator it;
    it = adProp.begin();
    while ((((*it)->getInmueble())->getCodigo() != codigoInmueble))
    { // busco el ap que esta relacionado con el inmueble, por precondicion siempre hay uno
        it++;
    }
    bool e = (*it)->existePublicacion(fechaActual->getFechaActual(), tipoPublicacion);
    if (e)
    {
        return false; // si existe una publicacion de ese tipo y fecha se devuelve false
    }

    // no se encontro la publicacion asi que se crea una  nueva
    // se busca pu para ver si la nueva publicacion debe estar activa o no
    Publicacion *pu = (*it)->encontrarPublicacionActiva(tipoPublicacion);
    bool activa = false;
    if (pu == NULL)
    {
        activa = true;
    }
    else if ((*pu).getFecha()->operator<(fechaActual->getFechaActual()))
    {
        activa = true;
        (*pu).setActiva(false);
    }
    Publicacion *p = new Publicacion((*it)->getUltimaPublicacion() + 1, fechaActual->getFechaActual(), tipoPublicacion, texto, precio, activa, (*it)); // si no se encontro un pu activo o uno con fecha mayor a la actual, se crea una nueva publicacion con activa=true. sino se crea una con activa false
    (*it)->setUltimaPublicacion((*it)->getUltimaPublicacion() + 1);
    (*it)->agregarPublicacion(p->getCodigo(), p);

    // agregar a la coleccion de publicaciones
    HPublicacion->agregarPublicacion(p);

    // una vez creada la publicacion se debe notificar a los suscriptores
    Inmobiliaria Inmobiliaria = (*Hinmobiliarias->getInmobiliaria(nicknameInmobiliaria));
    Inmueble *inmueble = (*it)->getInmueble();
    class ::Casa *esCasa = dynamic_cast<class ::Casa *>(inmueble);
    if (esCasa != nullptr)
    {
        Inmobiliaria.notificar(DTNotificacion(nicknameInmobiliaria, p->getCodigo(), texto, tipoPublicacion, Casa));
    }
    else
    {
        Inmobiliaria.notificar(DTNotificacion(nicknameInmobiliaria, p->getCodigo(), texto, tipoPublicacion, Apartamento));
    }

    return true;
}

bool ControladorSubeYBaja::altaPropietario(string nickname, string contrasena, string nombre, string email, string cuentaBancaria, string telefono)
{
    bool existe = Hpropietario->existePropietario(nickname);
    if (!existe)
    {
        Propietario *nuevoPropietario = new Propietario(nickname, contrasena, nombre, email, cuentaBancaria, telefono);
        Hpropietario->agregarPropietario(nuevoPropietario);
        UltimoPropietario = nuevoPropietario; // Guardar el último propietario creado
        return true;                          // Alta exitosa
    }
    return false;
}

bool ControladorSubeYBaja::altaInmobiliaria(string nickname, string contrasena, string nombre, string email, string direccion, string url, string telefono)
{
    bool existe = Hinmobiliarias->existeInmobiliaria(nickname);
    if (!existe)
    {
        Inmobiliaria *nuevaInmobiliaria = new Inmobiliaria(nickname, contrasena, nombre, email, direccion, url, telefono);
        Hinmobiliarias->agregarInmobiliaria(nuevaInmobiliaria);
        UltimaInmobiliaria = nuevaInmobiliaria; // Guardar la última inmobiliaria creada
        return true;
    }
    return false;
}

bool ControladorSubeYBaja::altaCliente(string nickname, string contrasena, string nombre, string email, string apellido, string documento)
{
    bool existe = Hcliente->existeCliente(nickname);
    if (!existe)
    {
        Cliente* nuevoCliente = new Cliente(nickname, contrasena, nombre, email, apellido, documento);
        this->Hcliente->agregarCliente(nuevoCliente);
        return true;
    }
    return false;
}

// PRE: Existe una referencia a una instancia Inmobiliaria recordada
// PRE2: Existe un propietario p con p.nickname = nicknamePropietario
void ControladorSubeYBaja::representarPropietario(string nicknamePropietario)
{
    if (Hpropietario->existePropietario(nicknamePropietario))
    {
        Propietario *propietario = Hpropietario->getPropietario(nicknamePropietario);
        if (UltimaInmobiliaria != nullptr)
        { // Verifica si hay una inmobiliaria registrada
            UltimaInmobiliaria->agregarPropietario(propietario);
        }
    }
}

void ControladorSubeYBaja::altaCasa(string direccion, int numeroPuerta, int superficie, int anoConstruccion, bool esPH, TipoTecho techo)
{
    int codigoInmueble = codigoUltimoInmueble + 1;
    class ::Casa *nuevaCasa = new class ::Casa(codigoInmueble, direccion, numeroPuerta, superficie, anoConstruccion, esPH, techo);
    if (UltimoPropietario != nullptr)
    {
        nuevaCasa->setPropietario(UltimoPropietario);
    }
    // Aquí deberías guardar nuevaCasa en el handler correspondiente, por ejemplo:
    HInmueble->agregarInmueble(nuevaCasa);
    codigoUltimoInmueble = codigoInmueble;
}

void ControladorSubeYBaja::altaApartamento(string direccion, int numeroPuerta, int superficie, int anoConstruccion, int piso, bool tieneAscensor, float gastosComunes)
{
    int codigoInmueble = codigoUltimoInmueble + 1;
    class ::Apartamento *nuevoApartamento = new class ::Apartamento(codigoInmueble, direccion, numeroPuerta, superficie, anoConstruccion, piso, tieneAscensor, gastosComunes);
    if (UltimoPropietario != nullptr)
    {
        nuevoApartamento->setPropietario(UltimoPropietario);
    }
    // Aquí deberías guardar nuevoApartamento en el handler correspondiente, por ejemplo:
    HInmueble->agregarInmueble(nuevoApartamento);
    codigoUltimoInmueble = codigoInmueble;
}

void ControladorSubeYBaja::finalizarAltaUsuario()
{
    if (UltimoPropietario != nullptr)
    {
        delete UltimoPropietario;
    }
    else if (UltimaInmobiliaria != nullptr)
    {
        delete UltimaInmobiliaria;
    }
};

void ControladorSubeYBaja::altaAdministraPropiedad(int codigoInmueble, string nicknameInmobiliaria)
{
    Inmobiliaria *inmobiliaria = Hinmobiliarias->getInmobiliaria(nicknameInmobiliaria);
    Inmueble *inmueble = HInmueble->DevolverInmueble(codigoInmueble);
    DTFecha *fechaActual = this->fechaActual->getFechaActual();
    AdministraPropiedad *administraPropiedad = new AdministraPropiedad(fechaActual, inmueble, inmobiliaria);
    inmueble->agregarAdministraPropiedad(administraPropiedad);
    inmobiliaria->agregarAdministraPropiedad(administraPropiedad);
    handlerAdministraPropiedad->agregarAdministraPropiedad(administraPropiedad);
}

void ControladorSubeYBaja::eliminarInmueble(int codigoInmueble)
{
    Inmueble *inmuebleElim = HInmueble->DevolverInmueble(codigoInmueble);
    if (inmuebleElim != NULL)
    {
        Propietario *propietario = inmuebleElim->getPropietario();
        if (propietario != NULL)
        {
            vector<Inmueble *> &inmuebles = propietario->getInmuebles();
            vector<Inmueble *>::iterator inmuebleLinkeado = find(inmuebles.begin(), inmuebles.end(), inmuebleElim);
            if (inmuebleLinkeado != inmuebles.end())
            {
                inmuebles.erase(inmuebleLinkeado);
            }
        }
        HInmueble->eliminarInmueble(codigoInmueble);
        delete inmuebleElim;
    }
}