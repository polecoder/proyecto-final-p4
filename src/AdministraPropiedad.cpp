#include "../include/AdministraPropiedad.h"
#include "Usuario.h"
#include <iostream>

AdministraPropiedad::AdministraPropiedad(DTFecha *fecha, Inmueble *inmueble, Inmobiliaria *inmobiliaria)
{
    this->fecha = fecha;
    this->inmueble = inmueble;
    this->inmobiliaria = inmobiliaria;
};

Inmueble *AdministraPropiedad::getInmueble()
{
    return inmueble;
}

Inmobiliaria *AdministraPropiedad::getInmobiliaria()
{
    return inmobiliaria;
}

string AdministraPropiedad::getNicknameInmobiliaria()
{
    return inmobiliaria->getNickname();
}

AdministraPropiedad::~AdministraPropiedad() {};
