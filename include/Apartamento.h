#ifndef APARTAMENTO_H
#define APARTAMENTO_H
#include "Inmueble.h"

<<<<<<< HEAD

class Apartamento : public Inmueble {
    private:
        int piso;
        bool tieneAscensor;
        float gastosComunes;

    public:
        Apartamento(int piso, bool tieneAscensor, float gastosComunes);
        ~Apartamento();
=======
class Apartamento : public Inmueble
{
private:
    int piso;
    bool tieneAscensor;
    float gastosComunes;

public:
    Apartamento(int piso, bool tieneAscensor, float gastosComunes);
    ~Apartamento();
>>>>>>> origin/main
};

#endif