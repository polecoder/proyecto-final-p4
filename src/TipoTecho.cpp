#include <ostream>
#include <string>
#include "../include/TipoTecho.h"

using namespace std;

ostream &operator<<(ostream &os, TipoTecho tipo)
{
    switch (tipo)
    {
    case TipoTecho::Liviano:
        os << "Liviano";
        break;
    case TipoTecho::A_dos_aguas:
        os << "A dos aguas";
        break;
    case TipoTecho::Plano:
        os << "Plano";
        break;
    default:
        os << "Desconocido";
        break;
    }
    return os;
}