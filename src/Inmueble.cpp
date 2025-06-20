#include "Inmueble.h"
using namespace std;

Inmueble::Inmueble(int codigo, string direccion, int numeroPuerta, int superficie, int anoConstruccion)
{
    this->codigo = codigo;
    this->direccion = direccion;
    this->numeroPuerta = numeroPuerta;
    this->superficie = superficie;
    this->anoConstruccion = anoConstruccion;
}

int Inmueble::getCodigo()
{
    return codigo;
}

string Inmueble::getDireccion()
{
    return direccion;
}

int Inmueble::getNumeroPuerta()
{
    return numeroPuerta;
}

int Inmueble::getSuperficie()
{
    return superficie;
}

int Inmueble::getAnoConstruccion()
{
    return anoConstruccion;
}

Propietario *Inmueble::getPropietario()
{
    return propietario;
}

vector<AdministraPropiedad *> Inmueble::getAdministraPropiedad()
{
    return administraPropiedad;
}

void Inmueble::setCodigo(int codigo)
{
    this->codigo = codigo;
}

void Inmueble::setDireccion(string direccion)
{
    this->direccion = direccion;
}

void Inmueble::setNumeroPuerta(int numeroPuerta)
{
    this->numeroPuerta = numeroPuerta;
}

void Inmueble::setSuperficie(int superficie)
{
    this->superficie = superficie;
}

void Inmueble::setAnoConstruccion(int anoConstruccion)
{
    this->anoConstruccion = anoConstruccion;
}

void Inmueble::setPropietario(Propietario *propietario)
{
    this->propietario = propietario;
}

void Inmueble::agregarAdministraPropiedad(AdministraPropiedad *administraPropiedad)
{
    this->administraPropiedad.push_back(administraPropiedad);
}

Inmueble::~Inmueble()
{
    if (propietario != NULL)
    {
        vector<Inmueble *> &inmuebles = propietario->getInmuebles();
        vector<Inmueble *>::iterator inmuebleLinkeado = find(inmuebles.begin(), inmuebles.end(), this);
        if (inmuebleLinkeado != inmuebles.end())
        {
            inmuebles.erase(inmuebleLinkeado);
        }
        propietario = NULL;
    }
}
