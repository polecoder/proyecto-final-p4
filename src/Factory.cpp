#include "../include/Factory.h"
#include "../include/ControladorFechaActual.h"
#include "../include/CSubeYBaja.h"
#include "../include/CListar.h"
#include <cstddef>

Factory* Factory::instance = NULL;

Factory::Factory() {
}

Factory* Factory::getInstance() {
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
    return Listar::getInstancia();
}