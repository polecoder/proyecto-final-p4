#include "../include/Inmueble.h"
#include <iostream>
#include <string>
using namespace std;

Inmueble ::Inmueble(int codigo, string direccion, int numeroPuerta, int superficie, int anoConstruccion)
{
    this->codigo = codigo;
    this->direccion = direccion;
    this->numeroPuerta = numeroPuerta;
    this->superficie = superficie;
    this->anoConstruccion = anoConstruccion;
};
Inmueble::~Inmueble() {
    // Destructor vacio, no es necesario liberar memoria ya que no hay punteros
};

int Inmueble::getCodigo() const
{
    return codigo;
}

string Inmueble::getDireccion() const
{
    return direccion;
}

int Inmueble::getNumeroPuerta() const
{
    return numeroPuerta;
}

int Inmueble::getSuperficie() const
{
    return superficie;
}

int Inmueble::getAnoConstruccion() const
{
    return anoConstruccion;
}

Propietario *Inmueble::getPropietario() const
{
    return propietario;
}

vector<AdministraPropiedad *> Inmueble::getAdministraPropiedad() const
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

/*Inmueble::~Inmueble()
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
}*/

ostream &operator<<(ostream &os, const Inmueble &i)
{
    os << "INMUEBLE: [codigo: " << i.getCodigo() << "; direccion: " << i.getDireccion() << "; numero de puerta: " << i.getNumeroPuerta() << "; superficie en m2: " << i.getAnoConstruccion() << "]";
    return os;
}
