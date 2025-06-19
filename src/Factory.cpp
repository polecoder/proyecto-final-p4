#include "../include/Factory.h"
#include "../include/ControladorFechaActual.h"
#include "../include/ControladorSubeYBaja.h"
#include "../include/ControladorListar.h"
#include "../include/ControladorSuscripciones.h"
#include <cstddef>

Factory* Factory::instance = NULL;

Factory::Factory() {
}

Factory* Factory::getInstancia() {
    if (instance == NULL) {
        instance = new Factory();
    }
    return instance;
}

IControladorFechaActual* Factory::getControladorFechaActual(){
    return ControladorFechaActual::getInstance();
}
IControladorSubeYBaja* Factory::getControladorSubeYBaja(){
    return SubeYBaja::getInstancia();
}
IControladorListar* Factory:: getControladorListar(){
    return ControladorListar::getInstancia();
}

IControladorSuscripciones* Factory:: getControladorSuscripciones(){
    return ControladorSuscripciones::getInstancia();
}