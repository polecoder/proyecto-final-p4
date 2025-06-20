#include "../include/DTInmueble.h"

using namespace std;

DTInmueble::DTInmueble(int codigo, string direccion, int numeroPuerta, int superficie, int anioConstruccion) {
    this->codigo = codigo;
    this->direccion = direccion;
    this->numeroPuerta = numeroPuerta;
    this->superficie = superficie;
    this->anioConstruccion = anioConstruccion;
}

int DTInmueble::getCodigo() const {
    return codigo;
}

string DTInmueble::getDireccion() const {
    return direccion;
}

int DTInmueble::getNumeroPuerta() const {
    return numeroPuerta;
}

int DTInmueble::getSuperficie() const {
    return superficie;
}

int DTInmueble::getAnioConstruccion() const {
    return anioConstruccion;
}

DTInmueble::~DTInmueble(){
    
}
bool DTInmueble:: operator<(const DTInmueble& other) const{
    return codigo < other.getCodigo();
}