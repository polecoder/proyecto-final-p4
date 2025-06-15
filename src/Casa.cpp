#include "Casa.h"

Casa::Casa(bool esPH, TipoTecho techo)
    : Inmueble(0, "", 0, 0, 0)
{
    this->esPH = esPH;
    this->techo = techo;
}

bool Casa::getEsPH()
{
    return esPH;
}

TipoTecho Casa::getTecho()
{
    return techo;
}

Casa::~Casa() {}