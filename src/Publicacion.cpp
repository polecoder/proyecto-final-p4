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
DTFecha* Publicacion :: getFecha() {
    return fecha;
};
TipoPublicacion Publicacion :: getTipo() {
    return tipo;
};
bool Publicacion :: getActiva() {
    return activa;
};
int Publicacion :: getCodigo(){
    return codigo;
};
void Publicacion :: setActiva(bool activa){
    this->activa = activa;
};
float Publicacion:: getPrecio(){
    return precio;
}