#include <string>
#include "TipoPublicacion.h"
#include "TipoInmueble.h"
#include "DTNotificacion.h"

using namespace std;

DTNotificacion::DTNotificacion(const string &nicknameInmobiliaria, const int &codigoPublicacion, const string &textoPublicacion, const TipoPublicacion &tipoPublicacion, const TipoInmueble &tipoInmueble)
{
    this->nicknameInmobiliaria = nicknameInmobiliaria;
    this->codigoPublicacion = codigoPublicacion;
    this->textoPublicacion = textoPublicacion;
    this->tipoPublicacion = tipoPublicacion;
    this->tipoInmueble = tipoInmueble;
}

DTNotificacion::~DTNotificacion() {}

string DTNotificacion::getNicknameInmobiliaria()
{
    return this->nicknameInmobiliaria;
}

int DTNotificacion::getCodigoPublicacion()
{
    return this->codigoPublicacion;
}

string DTNotificacion::getTextoPublicacion()
{
    return this->textoPublicacion;
}

TipoPublicacion DTNotificacion::getTipoPublicacion()
{
    return this->tipoPublicacion;
}

TipoInmueble DTNotificacion::getTipoInmueble()
{
    return this->tipoInmueble;
}

void DTNotificacion::setNicknameInmobiliaria(string nicknameInmobiliaria)
{
    this->nicknameInmobiliaria = nicknameInmobiliaria;
}

void DTNotificacion::setCodigoPublicacion(int codigoPublicacion)
{
    this->codigoPublicacion = codigoPublicacion;
}

void DTNotificacion::setTextoPublicacion(string textoPublicacion)
{
    this->textoPublicacion = textoPublicacion;
}

void DTNotificacion::setTipoPublicacion(TipoPublicacion tipoPublicacion)
{
    this->tipoPublicacion = tipoPublicacion;
}

void DTNotificacion::setTipoInmueble(TipoInmueble tipoInmueble)
{
    this->tipoInmueble = tipoInmueble;
}

bool DTNotificacion::operator<(const DTNotificacion &other) const
{
    return this->codigoPublicacion < other.codigoPublicacion;
}