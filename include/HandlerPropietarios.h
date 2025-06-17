#ifndef HANDLERPROPIETARIO_H
#define HANDLERPROPIETARIO_H
#include "Propietario.h"
#include <map>
#include <string>

using namespace std;

class HandlerPropietarios{
private:
    map<string, Propietario*> coleccionPropietarios;
    static HandlerPropietarios* instancia;
    HandlerPropietarios();

public:
    static HandlerPropietarios* getInstancia();
    ~HandlerPropietarios();

    void agregarPropietario(Propietario* &propietario);
    void eliminarPorpietario(string nickname);
    bool existePropietario(string nickname);

    Propietario* getPropietario(string nickname);
    map<string, Propietario*> getColeccionPropietarios();
};

#endif