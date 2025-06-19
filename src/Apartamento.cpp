#include "../include/Apartamento.h"

using namespace std;

Apartamento::Apartamento(int codigo, string direccion, int numeroPuerta, int superficie, int anoConstruccion, int piso, bool tieneAscensor, float gastosComunes)
    :Inmueble(codigo, direccion, numeroPuerta, superficie, anoConstruccion)
{
    this->piso = piso;
    this->tieneAscensor = tieneAscensor;
    this->gastosComunes = gastosComunes;
};
Apartamento::~Apartamento(){};

int Apartamento::getPiso() const{
    return this->piso;
};
bool Apartamento:: getAscensor() const{
    return this->tieneAscensor;
};
float Apartamento:: getGastosComunes() const{
    return this->gastosComunes;
};


