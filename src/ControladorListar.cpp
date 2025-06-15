#include "ControladorListar.h"
#include "Casa.h"
#include "Apartamento.h"
#include "DTCasa.h"
#include "DTApartamento.h"
#include <stdexcept>
#include <typeinfo>
#include <map>

using namespace std;

ControladorListar::ControladorListar()
{
    this->handlerInmuebles = HandlerInmuebles::getInstance();
}

ControladorListar *ControladorListar::getInstance()
{
    if (instance == NULL)
    {
        instance = new ControladorListar();
    }
    return instance;
}

set<DTInmuebleListado> ControladorListar::listarInmuebles()
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

DTInmueble ControladorListar::detalleInmueble(int codigoInmueble)
{
    Inmueble *inmueble = handlerInmuebles->getInmueble(codigoInmueble);

    int codigo = inmueble->getCodigo();
    string direccion = inmueble->getDireccion();
    int numeroPuerta = inmueble->getNumeroPuerta();
    int superficie = inmueble->getSuperficie();
    int anoConstruccion = inmueble->getAnoConstruccion();

    if (Casa *casa = dynamic_cast<Casa *>(inmueble))
    {
        bool esPH = casa->getEsPH();
        TipoTecho techo = casa->getTecho();
        return DTCasa(codigo, direccion, numeroPuerta, superficie, anoConstruccion, esPH, techo);
    }

    if (Apartamento *apartamento = dynamic_cast<Apartamento *>(inmueble))
    {
        int piso = apartamento->getPiso();
        bool tieneAscensor = apartamento->getTieneAscensor();
        float gastosComunes = apartamento->getGastosComunes();
        return DTApartamento(codigo, direccion, numeroPuerta, superficie, anoConstruccion, piso, tieneAscensor, gastosComunes);
    }
}
ControladorListar::~ControladorListar() {}