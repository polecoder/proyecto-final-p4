#include "../include/ControladorFechaActual.h"
#include <cstddef>

<<<<<<< HEAD
ControladorFechaActual* ControladorFechaActual::instance = NULL;

ControladorFechaActual::ControladorFechaActual() {
    fechaActual = new DTFecha(1,1,1900);
}

ControladorFechaActual* ControladorFechaActual::getInstance() {
    if (instance == NULL) {
        instance = new ControladorFechaActual();
    }
    return instance;
}

DTFecha* ControladorFechaActual::getFechaActual(){
    return new DTFecha(fechaActual);
}
void ControladorFechaActual::setNewFechaActual(int dia, int mes, int anio){
=======
ControladorFechaActual *ControladorFechaActual::instancia = NULL;

ControladorFechaActual::ControladorFechaActual()
{
    fechaActual = new DTFecha(1, 1, 1900);
}

ControladorFechaActual *ControladorFechaActual::getInstancia()
{
    if (instancia == NULL)
    {
        instancia = new ControladorFechaActual();
    }
    return instancia;
}

DTFecha *ControladorFechaActual::getFechaActual()
{
    return new DTFecha(fechaActual);
}
void ControladorFechaActual::setNewFechaActual(int dia, int mes, int anio)
{
>>>>>>> origin/main
    delete fechaActual;
    fechaActual = new DTFecha(dia, mes, anio);
}

<<<<<<< HEAD
ControladorFechaActual::~ControladorFechaActual(){
    delete fechaActual;
    instance = NULL;
=======
ControladorFechaActual::~ControladorFechaActual()
{
    delete fechaActual;
>>>>>>> origin/main
}