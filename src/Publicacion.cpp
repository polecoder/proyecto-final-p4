#include "../include/Publicacion.h"
#include <iostream>
using namespace std;


Publicacion :: Publicacion(int codigo, DTFecha* fecha, TipoPublicacion tipo, std::string texto, float precio, bool activa){
    this->codigo = codigo;
    this->fecha = fecha;
    this->tipo = tipo;
    this->texto = texto;
    this->precio = precio;
    this->activa = activa;
};
Publicacion :: ~Publicacion(){
    delete fecha; // no se si esta bien, pero asumo que fecha es un puntero a un objeto DTFecha que se debe liberar
};
int Publicacion :: getCodigo(){
    return codigo;
}
DTFecha* Publicacion :: getFecha(){
    return fecha;
}
TipoPublicacion Publicacion :: getTipo(){
    return tipo;
};
string Publicacion::getTexto(){
    return texto;
};
float Publicacion:: getPrecio(){
    return precio;
}
bool Publicacion :: getActiva(){
    return activa;
};
void Publicacion :: setActiva(bool activa){
    this->activa = activa;
};
