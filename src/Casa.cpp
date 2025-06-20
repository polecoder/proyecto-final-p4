#include "../include/Casa.h"
#include <iostream>

using namespace std;

Casa::Casa(int codigo, string direccion, int numeroPuerta, int superficie, int anoConstruccion, bool esPH, TipoTecho tipo)
    : Inmueble(codigo, direccion, numeroPuerta, superficie, anoConstruccion)
    {
        this->esPH = esPH;
        this->techo = tipo;
};
Casa::~Casa(){};

bool Casa:: getEsPH() const{
    return this->esPH;
}
TipoTecho Casa:: getTipoTecho() const{
    return this->techo;
}