#include "../include/Publicacion.h"
#include "../include/AdministraPropiedad.h"
#include <iostream>
#include <string>
using namespace std;

Publicacion ::Publicacion(int codigo, DTFecha *fecha, TipoPublicacion tipo, string texto, float precio, bool activa, AdministraPropiedad *apAsociado)
{
    this->codigo = codigo;
    this->fecha = fecha;
    this->tipo = tipo;
    this->texto = texto;
    this->precio = precio;
    this->activa = activa;
    this->apAsociado = apAsociado;
};
Publicacion::~Publicacion()
{
    delete fecha; // no se si esta bien, pero asumo que fecha es un puntero a un objeto DTFecha que se debe liberar
};
int Publicacion::getCodigo() const
{
    return codigo;
}
DTFecha *Publicacion ::getFecha() const
{
    return fecha;
}
TipoPublicacion Publicacion ::getTipo() const
{
    return tipo;
};
string Publicacion::getTexto() const
{
    return texto;
};
float Publicacion::getPrecio() const
{
    return precio;
}
bool Publicacion ::getActiva() const
{
    return activa;
};
void Publicacion ::setActiva(bool activa)
{
    this->activa = activa;
};
TipoInmueble Publicacion::getTipoInmueble() const
{ // accede al AdministraPropiedad asociado a la publicacion y devuelve el tipoInmueble del inmueble
    // if (this->apAsociado != NULL){
    //     Inmueble* inmueble = this->apAsociado->getInmueble();
    //     if (inmueble != nullptr) {
    return this->apAsociado->getInmueble()->getTipoInmueble();
    //     }
    // }
}
string Publicacion::getNicknameInmobiliaria() const
{
    if (this->apAsociado != NULL)
    {
        Inmobiliaria *inmo = this->apAsociado->getInmobiliaria();
        string nicknameInmobiliaria = inmo->getNickname();
        return nicknameInmobiliaria;
    }
    return "";
}
Inmobiliaria *Publicacion::getInmobiliaria() const
{
    return this->apAsociado->getInmobiliaria();
}
Inmueble *Publicacion::getInmueble() const
{
    return this->apAsociado->getInmueble();
}

ostream &operator<<(ostream &os, const Publicacion &p)
{
    os << "PUBLICACION: [codigo: " << p.getCodigo() << "; fecha: " << p.getFecha() << "; tipo publicacion: " << p.getTipo() << "; texto: " << p.getTexto() << "; precio: " << p.getPrecio() << "; activa?: " << p.getActiva() << "]";
    return os;
}