#include "Handlers.h"

// Handler para Inmueble

HandlerInmuebles *HandlerInmuebles::instance = NULL;

HandlerInmuebles::HandlerInmuebles()
{
    map<int, Inmueble *> coleccionInmuebles;
    this->coleccionInmuebles = coleccionInmuebles;
}

HandlerInmuebles *HandlerInmuebles::getInstance()
{
    if (instance == NULL)
    {
        instance = new HandlerInmuebles();
    }
    return instance;
}

bool HandlerInmuebles::existeInmueble(int codigoInmueble)
{
    return coleccionInmuebles.find(codigoInmueble) != coleccionInmuebles.end();
}

Inmueble *HandlerInmuebles::getInmueble(int codigoInmueble)
{
    if (existeInmueble(codigoInmueble))
    {
        return coleccionInmuebles[codigoInmueble];
    }
    return NULL;
}

const map<int, Inmueble *> &HandlerInmuebles::getColecccionInmuebles() const
{
    return coleccionInmuebles;
}

void HandlerInmuebles::eliminarInmuebleColeccion(int codigoInmueble)
{
    coleccionInmuebles.erase(codigoInmueble);
}

HandlerInmuebles::~HandlerInmuebles()
{
    for (auto &par : coleccionInmuebles)
    {
        delete par.second;
    }
    coleccionInmuebles.clear();
}

// Handler para Inmobiliaria

HandlerInmobiliarias *HandlerInmobiliarias::instance = NULL;

HandlerInmobiliarias::HandlerInmobiliarias()
{
    map<string, Inmobiliaria *> coleccionInmobiliarias;
    this->coleccionInmobiliarias = coleccionInmobiliarias;
}

bool HandlerInmobiliarias::existeInmobiliaria(string nicknameInmobiliaria)
{
    return coleccionInmobiliarias.find(nicknameInmobiliaria) != coleccionInmobiliarias.end();
}

// PRE: Existe unja inmobiliaria tal que inmobiliaria.nickname=nicknameInmobiliaria
Inmobiliaria *HandlerInmobiliarias::getInmobiliaria(string nicknameInmobiliaria)
{
    map<string, Inmobiliaria *>::iterator inmobiliaria = coleccionInmobiliarias.find(nicknameInmobiliaria);
    if (inmobiliaria != coleccionInmobiliarias.end())
    {
        return inmobiliaria->second;
    }
}

const map<string, Inmobiliaria *> &HandlerInmobiliarias::getColecccionInmobiliaria()
{
    return coleccionInmobiliarias;
}

HandlerInmobiliarias *HandlerInmobiliarias::getInstance()
{
    if (instance == NULL)
    {
        instance = new HandlerInmobiliarias();
    }
    return instance;
}

// Handler para AdministraPropiedad

HandlerAdministraPropiedad *HandlerAdministraPropiedad::instance = NULL;

HandlerAdministraPropiedad::HandlerAdministraPropiedad()
{
    coleccionAdministraPropiedad = vector<AdministraPropiedad *>();
}

const vector<AdministraPropiedad *> &HandlerAdministraPropiedad::getColecccionAdministraPropiedad() const
{
    return coleccionAdministraPropiedad;
}

void HandlerAdministraPropiedad::agregarAdministraPropiedad(AdministraPropiedad *AdministraPropiedad)
{
    coleccionAdministraPropiedad.push_back(AdministraPropiedad);
}

HandlerAdministraPropiedad *HandlerAdministraPropiedad::getInstance()
{
    if (instance == NULL)
    {
        instance = new HandlerAdministraPropiedad();
    }
    return instance;
}
