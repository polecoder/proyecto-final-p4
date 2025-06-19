#ifndef DTCASA_H
#define DTCASA_H
#include "DTInmueble.h"
#include "TipoTecho.h"

using namespace std;

class DTCasa : public DTInmueble {
    private:
        bool esPH;
        TipoTecho techo;

    public:
        DTCasa(int codigo, string direccion, int numeroPuerta, int superficie, int anioConstruccion, bool esPH, TipoTecho techo);
        bool getEsPH() const;
        TipoTecho getTecho() const;
        virtual ~DTCasa();
};

#endif