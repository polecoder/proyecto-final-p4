#include <ostream>
#include <string>
#include "../include/TipoInmueble.h"

using namespace std;

ostream &operator<<(ostream &os, TipoInmueble tipo)
{
    switch (tipo)
    {
    case TipoInmueble::Todos:
        os << "Todos";
        break;
    case TipoInmueble::Casa:
        os << "Casa";
        break;
    case TipoInmueble::Apartamento:
        os << "Apartamento";
        break;
    default:
        os << "Desconocido";
        break;
    }
    return os;
}