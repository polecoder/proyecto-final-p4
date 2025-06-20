#include "ControladorListar.h"
#include "Casa.h"
#include "Apartamento.h"
#include "DTCasa.h"
#include "DTApartamento.h"
#include <typeinfo>
#include <map>

using namespace std;

ControladorInmueblesListar::ControladorInmueblesListar()
{
    this->handlerInmuebles = HandlerInmuebles::getInstance();
}

ControladorInmueblesListar *ControladorInmueblesListar::getInstance()
{
    if (instance == NULL)
    {
        instance = new ControladorInmueblesListar();
    }
    return instance;
}

set<DTInmuebleListado> ControladorInmueblesListar::listarInmuebles()
{
    set<DTInmuebleListado> inmueblesListados;
    map<int, Inmueble *> inmuebles = handlerInmuebles->getColecccionInmuebles();
    for (const pair<int, Inmueble *> &par : inmuebles)
    {
        Inmueble *inmueble = par.second;
        int codigo = inmueble->getCodigo();
        string direccion = inmueble->getDireccion();
        Propietario *propietario = inmueble->getPropietario();
        string nicknamePropietario;
        if (propietario != NULL)
            nicknamePropietario = propietario->getNickname();
        DTInmuebleListado DTInmuebleListado(codigo, direccion, nicknamePropietario);
        inmueblesListados.insert(DTInmuebleListado);
    }
    return inmueblesListados;
}

DTInmueble ControladorInmueblesListar::detalleInmueble(int codigoInmueble)
{
    Inmueble *inmueble = handlerInmuebles->getInmueble(codigoInmueble);
    int codigo = inmueble->getCodigo();
    string direccion = inmueble->getDireccion();
    int numeroPuerta = inmueble->getNumeroPuerta();
    int superficie = inmueble->getSuperficie();
    int anoConstruccion = inmueble->getAnoConstruccion();
    Casa *casa = dynamic_cast<Casa *>(inmueble);

    if (casa)
    {
        bool esPH = casa->getEsPH();
        TipoTecho techo = casa->getTecho();
        return DTCasa(codigo, direccion, numeroPuerta, superficie, anoConstruccion, esPH, techo);
    }

    else
    {
        Apartamento *apartamento = dynamic_cast<Apartamento *>(inmueble);
        int piso = apartamento->getPiso();
        bool tieneAscensor = apartamento->getTieneAscensor();
        float gastosComunes = apartamento->getGastosComunes();
        return DTApartamento(codigo, direccion, numeroPuerta, superficie, anoConstruccion, piso, tieneAscensor, gastosComunes);
    }
}
ControladorInmueblesListar::~ControladorInmueblesListar() {}

// CONTROLADOR PARA INMOBILIARIAS

ControladorInmobiliariasListar::ControladorInmobiliariasListar()
{
    this->handlerInmobiliarias = HandlerInmobiliarias::getInstance();
}

set<DTUsuario> ControladorInmobiliariasListar::listarInmobiliarias()
{
    set<DTUsuario> inmobiliariasListadas;
    map<string, Inmobiliaria *> inmobiliarias = handlerInmobiliarias->getColecccionInmobiliaria();
    for (const pair<string, Inmobiliaria *> &par : inmobiliarias)
    {
        Inmobiliaria *inmobiliaria = par.second;
        string nickname = inmobiliaria->getNickname();
        string nombre = inmobiliaria->getNombre();
        DTUsuario DTUsuario(nickname, nombre);
        inmobiliariasListadas.insert(DTUsuario);
    }
    return inmobiliariasListadas;
}

// PRE: Existe inmobiliarias.nickname = nicknameInmobiliaria

Inmobiliaria *ControladorInmobiliariasListar::getInmobiliaria(string nicknameInmobiliaria)
{
    map<string, Inmobiliaria *> inmobiliarias = handlerInmobiliarias->getColecccionInmobiliaria();
    map<string, Inmobiliaria *>::iterator iterador = inmobiliarias.find(nicknameInmobiliaria);
    if (iterador != inmobiliarias.end())
    {
        return iterador->second;
    }
    return NULL;
}

set<DTInmuebleListado> ControladorInmobiliariasListar::getInmueblesNoAdministradosInmobiliaria(string nicknameInmobiliaria)
{
    set<DTInmuebleListado> inmueblesNoAdministrados;
    Inmobiliaria *Inmobiliaria = getInmobiliaria(nicknameInmobiliaria);
    map<string, Propietario *> propietariosRepresentados = Inmobiliaria->getPropietarios();
    // Recorro la coleccion de propietarios que son representados por la inmobiliaria
    for (const auto &par : propietariosRepresentados)
    {
        Propietario *propietario = par.second;
        vector<Inmueble *> &inmuebles = propietario->getInmuebles();
        // Recorro la coleccion de inmuebles que tiene el propietario
        for (Inmueble *inmueble : inmuebles)
        {
            bool esAdministrado = false;
            vector<AdministraPropiedad *> administraPropiedades = inmueble->getAdministraPropiedad();
            // Recorro los administra propiedad del inmueble
            for (AdministraPropiedad *administraPropiedad : administraPropiedades)
            {
                string inmobiliariaActual = administraPropiedad->getNicknameInmobiliaria();
                if (nicknameInmobiliaria == inmobiliariaActual)
                {
                    esAdministrado = true;
                }
            }
            // Si la inmobiliaria no administra el inmueble se agrega al set<DTInmuebleListado>
            if (!esAdministrado)
            {
                int codigo = inmueble->getCodigo();
                string direccion = inmueble->getDireccion();
                // Es el nickname?
                string nicknamePropietario = propietario->getNickname();
                DTInmuebleListado DTInmList = DTInmuebleListado(codigo, direccion, nicknamePropietario);
                inmueblesNoAdministrados.insert(DTInmList);
            }
        }
    }
}

ControladorInmobiliariasListar::~ControladorInmobiliariasListar() {}