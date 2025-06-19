#ifndef CONTROLADORSUBEYBAJA_H
#define CONTROLADORSUBEYBAJA_H

#include "IControladorSubeYBaja.h"
#include "IControladorFechaActual.h"
#include "HandlerInmobiliarias.h"
#include "HandlerPublicacion.h"

#include <string>

using namespace std;

class ControladorSubeYBaja : public IControladorSubeYBaja
{
private:
    static ControladorSubeYBaja *Instancia;
    HandlerInmobiliarias *Hinmobiliarias;
    IControladorFechaActual *fechaActual;
    HandlerPublicacion *HPublicacion;
    ControladorSubeYBaja();

public:
    static ControladorSubeYBaja *getInstancia();
    ~ControladorSubeYBaja();
    bool altaPublicacion(string nicknameInmobiliaria, int codigoInmueble, TipoPublicacion tipoPublicacion, string texto, float precio);
};

#endif // CONTROLADORSUBEYBAJA_H