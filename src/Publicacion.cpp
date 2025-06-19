#include "../include/Publicacion.h"
#include "../include/AdministraPropiedad.h"
#include <iostream>
using namespace std;


Publicacion :: Publicacion(int codigo, DTFecha* fecha, TipoPublicacion tipo, string texto, float precio, bool activa, AdministraPropiedad* apAsociado){
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
DTFecha* Publicacion :: getFecha() {
    return fecha;
};
TipoPublicacion Publicacion :: getTipo() {
    return tipo;
};
bool Publicacion :: getActiva() {
    return activa;
};
int Publicacion :: getCodigo()const{
    return codigo;
};
void Publicacion :: setActiva(bool activa){
    this->activa = activa;
};
float Publicacion:: getPrecio(){
    return precio;
}