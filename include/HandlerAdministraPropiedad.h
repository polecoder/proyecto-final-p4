#ifndef HANDLER_ADMINISTRA_PROPIEDAD_H
#define HANDLER_ADMINISTRA_PROPIEDAD_H

#include "Inmobiliaria.h"
#include <map>

using namespace std;

class HandlerAdministraPropiedad
{
private:
    vector<AdministraPropiedad *> coleccionAdministraPropiedad;
    static HandlerAdministraPropiedad *instancia;
    HandlerAdministraPropiedad();

public:
    static HandlerAdministraPropiedad *getInstancia();
    const vector<AdministraPropiedad *> &getColecccionAdministraPropiedad() const;
    void agregarAdministraPropiedad(AdministraPropiedad *administraPropiedad);
    ~HandlerAdministraPropiedad();
    void imprimirColeccionAdministraPropiedad();
};
#endif