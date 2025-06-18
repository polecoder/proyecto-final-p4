#ifndef HANDLERPROPIETARIO_H
#define HANDLERPROPIETARIO_H


#include "Cliente.h"
#include "Propietario.h"
#include <map>
#include <string>
using namespace std;

class Propietario;

class HandlerPropietario {
private:
    static HandlerPropietario* instancia;
    map<string, Propietario*> propietarios;

    HandlerPropietario();
public: 
    static HandlerPropietario* getInstancia();

    void agregarPropietario(Propietario* propietario);
    Propietario* obtenerPropietario(const string& nickname);
    bool existePropietario(const string& nickname);

    ~HandlerPropietario();
};


#endif // HANDLERPROPIETARIO_H