#include "../include/Publicacion.h"
#include <iostream>
using namespace std;


Publicacion :: Publicacion(const int codigo, DTFecha* fecha,const TipoPublicacion tipo,const string texto,const float precio,const bool activa, AdministraPropiedad* apAsociado){
    this->codigo = codigo;
    this->fecha = fecha;
    this->tipo = tipo;
    this->texto = texto;
    this->precio = precio;
    this->activa = activa;
    this->apAsociado = apAsociado;
};
Publicacion :: ~Publicacion(){
    delete fecha; // no se si esta bien, pero asumo que fecha es un puntero a un objeto DTFecha que se debe liberar
};
int Publicacion::getCodigo() const{
    return codigo;
}
DTFecha* Publicacion :: getFecha() const{
    return fecha;
}
TipoPublicacion Publicacion :: getTipo() const{
    return tipo;
};
string Publicacion::getTexto() const{
    return texto;
};
float Publicacion:: getPrecio() const{
    return precio;
}
bool Publicacion :: getActiva() const{
    return activa;
};
void Publicacion :: setActiva(bool activa){
    this->activa = activa;
};
TipoInmueble Publicacion::getTipoInmueble() const{ // accede al AdministraPropiedad asociado a la publicacion y devuelve el tipoInmueble del inmueble
    if (this->apAsociado != NULL){
        Inmueble* inmueble = this->apAsociado->getInmueble();
        if (inmueble != nullptr) {
            return inmueble->getTipoInmueble();
        }
    }
    return TipoInmueble();
}