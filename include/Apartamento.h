#ifndef APARTAMENTO_H
#define APARTAMENTO_H
#include "Inmueble.h"

using namespace std;


class Apartamento : public Inmueble {
    private:
        int piso;
        bool tieneAscensor;
        float gastosComunes;

    public:
        Apartamento(int codigo, string direccion, int numeroPuerta, int superficie, int anoConstruccion, int piso, bool tieneAscensor, float gastosComunes);
        ~Apartamento();
        int getPiso() const;
        bool getAscensor() const;
        float getGastosComunes() const;
};

#endif