#include "../include/Inmueble.h"
#include <iostream>
using namespace std;

Inmueble ::Inmueble(int codigo, std::string direccion, int numeroPuerta, int superficie, int anoConstruccion)
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

int Inmueble::getCodigo()
{
    return codigo;
};
string Inmueble::getDireccion()
{
    return direccion;
};
int Inmueble::getNumeroPuerta()
{
    return numeroPuerta;
};
int Inmueble::getSuperficie()
{
    return superficie;
};
int Inmueble::getAnoConstruccion()
{
    return anoConstruccion;
};

Propietario *Inmueble::getPropietario() const
{
    return propietario;
};
