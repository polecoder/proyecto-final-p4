#include "../include/DTPublicacion.h"

using namespace std;

DTPublicacion::DTPublicacion(int codigo, DTFecha *fecha, string texto, float precio, string inmobiliaria)
{
    this->codigo = codigo;
    this->fecha = new DTFecha(fecha);
    this->texto = texto;
    this->precio = precio;
    this->inmobiliaria = inmobiliaria;
}

int DTPublicacion::getCodigo() const
{
    return codigo;
}

DTFecha *DTPublicacion::getFecha() const
{
    return fecha;
}

string DTPublicacion::getTexto() const
{
    return texto;
}

float DTPublicacion::getPrecio() const
{
    return precio;
}

string DTPublicacion::getInmobiliaria() const
{
    return inmobiliaria;
}

DTPublicacion::~DTPublicacion()
{

};

bool DTPublicacion::operator<(const DTPublicacion &other) const
{
    return codigo < other.codigo;
};
