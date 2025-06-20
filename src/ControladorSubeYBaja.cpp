#include "ControladorSubeYBaja.h"
#include "AdministraPropiedad.h"
#include <ctime>
using namespace std;

ControladorSubeYBaja *ControladorSubeYBaja::instance = NULL;

ControladorSubeYBaja::ControladorSubeYBaja()
{
    handlerInmuebles = HandlerInmuebles::getInstance();
    handlerInmobiliarias = HandlerInmobiliarias::getInstance();
    handlerAdministraPropiedad = HandlerAdministraPropiedad::getInstance();
}

ControladorSubeYBaja *ControladorSubeYBaja::getInstance()
{
    if (instance == NULL)
    {
        instance = new ControladorSubeYBaja();
    }
    return instance;
}

bool ControladorSubeYBaja::existeInmueble(int codigoInmueble)
{
    return handlerInmuebles->existeInmueble(codigoInmueble);
}

Inmueble *ControladorSubeYBaja::getInmueble(int codigoInmueble)
{
    return handlerInmuebles->getInmueble(codigoInmueble);
}

void ControladorSubeYBaja::eliminarInmueble(int codigoInmueble)
{
    Inmueble *inmuebleElim = handlerInmuebles->getInmueble(codigoInmueble);
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
        handlerInmuebles->eliminarInmuebleColeccion(codigoInmueble);
        delete inmuebleElim;
    }
}

ControladorSubeYBaja *ControladorSubeYBaja::getInstance()
{
    if (instance == NULL)
    {
        instance = new ControladorSubeYBaja();
    }
    return instance;
}

Inmobiliaria *ControladorSubeYBaja::getInmobiliaria(string nicknameInmobiliaria)
{
    map<string, Inmobiliaria *> inmobiliarias = handlerInmobiliarias->getColecccionInmobiliaria();
    map<string, Inmobiliaria *>::iterator iterador = inmobiliarias.find(nicknameInmobiliaria);
    if (iterador != inmobiliarias.end())
    {
        return iterador->second;
    }
    return NULL;
}

void ControladorSubeYBaja::altaAdministraPropiedad(string nicknameInmobiliaria, int codigoInmueble)
{
    Inmobiliaria *inmobiliaria = getInmobiliaria(nicknameInmobiliaria);
    Inmueble *inmueble = getInmueble(codigoInmueble);
    // Fecha actual del sistema
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int dia = ltm->tm_mday;
    int mes = ltm->tm_mon + 1;
    int anio = ltm->tm_year + 1900;
    DTFecha *fechaActual = new DTFecha(dia, mes, anio);
    AdministraPropiedad *administraPropiedad = new AdministraPropiedad(fechaActual, inmueble, inmobiliaria);
    inmueble->agregarAdministraPropiedad(administraPropiedad);
    inmobiliaria->agregarAdministraPropiedad(administraPropiedad);
    handlerAdministraPropiedad->agregarAdministraPropiedad(administraPropiedad);
}

ControladorSubeYBaja::~ControladorSubeYBaja() {}