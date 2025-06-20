#ifndef CONTROLADORSUBEYBAJA_H
#define CONTROLADORSUBEYBAJA_H

#include "Publicacion.h"
#include "Inmobiliaria.h"
#include "HandlerInmobiliarias.h"
#include "HandlerPublicacion.h"
#include "DTFecha.h"
#include "IControladorFechaActual.h"
#include "AdministraPropiedad.h"
#include "TipoPublicacion.h"
#include "DTNotificacion.h"
#include "Casa.h"
#include "IControladorSubeYBaja.h"
#include "Apartamento.h"
#include "TipoInmueble.h"
#include <string>

using namespace std;

class ControladorSubeYBaja : public IControladorSubeYBaja
{
private:
    static ControladorSubeYBaja *instancia;
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