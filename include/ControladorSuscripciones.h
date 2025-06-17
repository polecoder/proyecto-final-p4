#ifndef CONTROLADORSUSCRIPCIONES_H
#define CONTROLADORSUSCRIPCIONES_H

#include <HandlerClientes.h>
#include <HandlerPropietarios.h>
#include <HandlerInmobiliaria.h>
#include <DTUsuario.h>
#include <set>
#include <string>

using namespace std;

class ControladorSuscripciones{
private:
    static ControladorSuscripciones *instancia;
    HandlerClientes *HClientes;
    HandlerPropietarios *HPropietarios;
    HandlerInmobiliaria *HInmobiliaria;
    ControladorSuscripciones();

public:

    static ControladorSuscripciones *getInstancia();
    ~ControladorSuscripciones();

    set<DTUsuario> listarSuscripciones(string nicknameUsuario);
    set<DTUsuario> listarInmobiliariasNoSuscripto(string nicknameUsuario);//PRE: existe un usuario con nickname=nicknameUsuario. 
    void suscribirse(string nicknameUsuario, set<string> inmobiliariasElegidas);//PRE: existe usuario con nickname=nicknameUsuario && existen todas las inmobiliarias del set y ademas no estan relacionadas con el usuario. 
    void eliminarSuscripcion(string nicknameUsuario, set<string> inmobiliariasElegidas);

};

#endif