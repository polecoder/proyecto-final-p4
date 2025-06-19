#ifndef DTAPARTAMENTO_H
#define DTAPARTAMENTO_H
#include "DTInmueble.h"

using namespace std;

class DTApartamento : public DTInmueble {
    private:
        int piso;
        bool tieneAscensor;
        float gastosComunes;

    public:
        DTApartamento(int codigo, string direccion, int numeroPuerta, int superficie, int anioConstruccion, int piso, bool tieneAscensor, float gastosComunes);
        int getPiso() const;
        bool getTieneAscensor() const;
        float getGastosComunes() const;
        virtual ~DTApartamento();
};

#endif