#include <ostream>
#include <string>
#include "../include/TipoPublicacion.h"

using namespace std;

ostream &operator<<(ostream &os, TipoPublicacion tipo)
{
    switch (tipo)
    {
    case TipoPublicacion::Venta:
        os << "Venta";
        break;
    case TipoPublicacion::Alquiler:
        os << "Alquiler";
        break;
    default:
        os << "Desconocido";
        break;
    }
    return os;
}