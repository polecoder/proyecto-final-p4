#include "../include/ControladorSuscripciones.h"
#include <set>
#include <map>

using namespace std;

ControladorSuscripciones *ControladorSuscripciones::instancia =NULL;

ControladorSuscripciones::ControladorSuscripciones(){
    this->HInmobiliaria = HandlerInmobiliaria::getInstancia();
    this->HPropietarios = HandlerPropietarios::getInstancia();
    this->HClientes = HandlerClientes::getInstancia();
};

ControladorSuscripciones *ControladorSuscripciones::getInstancia(){
    if(instancia == NULL){
        instancia = new ControladorSuscripciones();
    }
    return instancia;
}
ControladorSuscripciones::~ControladorSuscripciones(){};

set<DTUsuario> ControladorSuscripciones::listarInmobiliariasNoSuscripto(string nicknameUsuario){
    set<DTUsuario> inmobiliariasNoSuscripto;
    if(this->HClientes->existeCliente(nicknameUsuario)){
        Cliente *cliente = this->HClientes->getCliente(nicknameUsuario);
        map<string, Inmobiliaria*> inmobiliarias = this->HInmobiliaria->DevolverInmobiliarias();
        map<string, Inmobiliaria*>::iterator it;
        for(it = inmobiliarias.begin(); it != inmobiliarias.end(); ++it){
            string nicknameInmobiliaria = it->first;
            if(!cliente->estaSuscripto(nicknameInmobiliaria)){
                inmobiliariasNoSuscripto.insert(DTUsuario(it->second->getNickname(), it->second->getNombre()));
            }
        }
        return inmobiliariasNoSuscripto;
    }
    if(this->HPropietarios->existePropietario(nicknameUsuario)){
        Propietario *propietario = this->HPropietarios->getPropietario(nicknameUsuario);
        map<string, Inmobiliaria*> inmobiliarias = this->HInmobiliaria->DevolverInmobiliarias();
        map<string, Inmobiliaria*>::iterator it;
        for(it = inmobiliarias.begin(); it != inmobiliarias.end(); ++it){
            string nicknameInmobiliaria = it->first;
            if(!propietario->estaSuscripto(nicknameInmobiliaria)){
                inmobiliariasNoSuscripto.insert(DTUsuario(it->second->getNickname(), it->second->getNickname()));
            }
        }
        return inmobiliariasNoSuscripto;
    }
};

void ControladorSuscripciones::suscribirse(string nicknameUsuario, set<string> inmobiliariasElegidas){
    if(this->HClientes->existeCliente(nicknameUsuario)){
        Cliente *cliente = this->HClientes->getCliente(nicknameUsuario);
        for(set<string>::iterator it = inmobiliariasElegidas.begin(); it != inmobiliariasElegidas.end(); ++it){
            string nicknameInmobiliaria = *it;
            Inmobiliaria *inmobiliaria = this->HInmobiliaria->DevolverInmobiliaria(nicknameInmobiliaria);
            cliente->agregarSuscripcion(inmobiliaria);
            inmobiliaria->agregarClienteSuscripto(cliente);
        }
    }
    if(this->HPropietarios->existePropietario(nicknameUsuario)){
        Propietario *propietario = this->HPropietarios->getPropietario(nicknameUsuario);
        for(set<string>::iterator it = inmobiliariasElegidas.begin(); it != inmobiliariasElegidas.end(); ++it){
            string nicknameInmobiliaria = *it;
            Inmobiliaria *inmobiliaria = this->HInmobiliaria->DevolverInmobiliaria(nicknameInmobiliaria);
            propietario->agregarSuscripcion(inmobiliaria);
            inmobiliaria->agregarPropietarioSuscripto(propietario);
        }
    }
}