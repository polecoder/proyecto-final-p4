#include "../include/CListar.h"
#include <iostream>
#include <ios>
#include <string>
#include <set>
#include <map>
using namespace std;

Listar *Listar::instancia = nullptr;

Listar *Listar::getInstancia()
{
    if (instancia == nullptr)
    {
        instancia = new Listar();
    }
    return instancia;
};

Listar::Listar()
{
    Hinmobiliarias = HandlerInmobiliarias::getInstancia(); // Inicializa el handler de inmobiliarias
    IControladorFechaActual *IControlador = ControladorFechaActual::getInstance();
    fechaActual = IControlador; // Inicializa el controlador de fecha actual
};
Listar::~Listar() {

};

set<DTUsuario> Listar::listarInmobiliarias()
{
    map<string, Inmobiliaria *> inmo = Hinmobiliarias->getColeccionInmobiliarias();
    set<DTUsuario> salida;
    map<string, Inmobiliaria *>::iterator it;
    for (it = inmo.begin(); it != inmo.end(); ++it)
    {
        salida.insert(DTUsuario(it->first, it->second->getNombre())); // first es el nickname, second es el objeto inmobiliaria
    }
    return salida;
}

set<DTInmuebleAdministrado> Listar ::listarInmueblesAdministrados(string nicknameInmobiliaria)
{
    vector<AdministraPropiedad *> adProp = Hinmobiliarias->getColeccionAdministraPropiedad(nicknameInmobiliaria);
    set<DTInmuebleAdministrado> salida;
    vector<AdministraPropiedad *>::iterator it;
    for (it = adProp.begin(); it != adProp.end(); ++it)
    {
        salida.insert(DTInmuebleAdministrado(((*it)->getInmueble())->getCodigo(), ((*it)->getInmueble())->getDireccion(), fechaActual->getFechaActual()));
    }
    return salida;
}
