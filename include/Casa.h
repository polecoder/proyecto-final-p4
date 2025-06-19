#ifndef CASA_H
#define CASA_H
#include "Inmueble.h"
#include "TipoTecho.h"
#include "TipoInmueble.h"

using namespace std;

class Casa : public Inmueble {
    private:
        bool esPH;
        TipoTecho techo;

    public:
        Casa(int codigo, string direccion, int numeroPuerta, int superficie, int anoConstruccion, bool esPH, TipoTecho tipo);
        ~Casa();
        TipoInmueble getTipoInmueble() const override {return TipoInmueble::Casa;}
        bool getEsPH() const;
        TipoTecho getTipoTecho() const;
};

#endif