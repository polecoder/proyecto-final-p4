#include "../include/Publicacion.h"
#include <iostream>
using namespace std;


Publicacion :: Publicacion( int codigo, DTFecha* fecha, TipoPublicacion tipo, string texto, float precio, bool activa, AdministraPropiedad* apAsociado){
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
    delete apAsociado;// se elimina el link al administraPropiedad asociado a la publicacion
};
int Publicacion::getCodigo() {
    return codigo;
}
DTFecha* Publicacion :: getFecha() {
    return fecha;
}
TipoPublicacion Publicacion :: getTipo() {
    return tipo;
};
string Publicacion::getTexto() {
    return texto;
};
float Publicacion:: getPrecio() {
    return precio;
}
bool Publicacion :: getActiva() {
    return activa;
};
void Publicacion :: setActiva(bool activa){
    this->activa = activa;
};
TipoInmueble Publicacion::getTipoInmueble() { // accede al AdministraPropiedad asociado a la publicacion y devuelve el tipoInmueble del inmueble
    if (this->apAsociado != NULL){
        Inmueble* inmueble = this->apAsociado->getInmueble();
        if (inmueble != nullptr) {
            return inmueble->getTipoInmueble();
        }
    }
    return TipoInmueble();
}
string Publicacion:: getNicknameInmobiliaria() {
    if (this->apAsociado != NULL){
        Inmobiliaria* inmo = this->apAsociado->getInmobiliaria();
        string nicknameInmobiliaria = inmo->getNickname();
        return nicknameInmobiliaria;
    }
    
}
Inmobiliaria* Publicacion:: getInmobiliaria(){
    return this->apAsociado->getInmobiliaria();
}
Inmueble* Publicacion:: getInmueble(){
    return this->apAsociado->getInmueble();
}