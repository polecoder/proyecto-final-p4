#ifndef INMUEBLE_H
#define INMUEBLE_H
#include <string>
#include "TipoInmueble.h"
#include "Propietario.h"
#include "TipoInmueble.h"

class Propietario;

using namespace std;

class Inmueble {
    private:
        int codigo;
        string direccion;
        int numeroPuerta;
        int superficie;
        int anoConstruccion;
        Propietario *propietario;
    public:
        Inmueble(int codigo, string direccion, int numeroPuerta, int superficie, int anoConstruccion);
        virtual ~Inmueble();
        
        int getCodigo() ;
        string getDireccion() ;
        int getNumeroPuerta() ;
        int getSuperficie() ;
        int getAnoConstruccion() ;
        virtual TipoInmueble getTipoInmueble() const = 0;

        Propietario* getPropietario() const;
};

#endif
