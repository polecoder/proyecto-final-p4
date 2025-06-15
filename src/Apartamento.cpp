#include "Apartamento.h"

Apartamento::Apartamento(int piso, bool tieneAscensor, float gastosComunes)
    : Inmueble(0, "", 0, 0, 0)
{
    this->piso = piso;
    this->tieneAscensor = tieneAscensor;
    this->gastosComunes = gastosComunes;
}

int Apartamento::getPiso()
{
    return piso;
}

bool Apartamento::getTieneAscensor()
{
    return tieneAscensor;
}

float Apartamento::getGastosComunes()
{
    return gastosComunes;
}

Apartamento::~Apartamento() {}
