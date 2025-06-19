#include "../include/HandlerPropietarios.h"

using namespace std;

HandlerPropietarios *HandlerPropietarios::instancia = NULL;

HandlerPropietarios::HandlerPropietarios(){
    map<string, Propietario*> coleccionPropietarios;
    this->coleccionPropietarios = coleccionPropietarios;
};

HandlerPropietarios *HandlerPropietarios::getInstancia(){
    if(instancia == NULL)
        instancia = new HandlerPropietarios();
    return instancia;
};

void HandlerPropietarios::agregarPropietario(Propietario* &propietario){
    this->coleccionPropietarios[propietario->getNickname()] = propietario;
};

void HandlerPropietarios::eliminarPorpietario(string nickname){
    map<string, Propietario*>:: iterator it = this->coleccionPropietarios.find(nickname);
    if(it != coleccionPropietarios.end()){
        delete it->second;
        coleccionPropietarios.erase(it);
    }
};

bool HandlerPropietarios:: existePropietario(string nickname){
    return this->coleccionPropietarios.find(nickname) != this->coleccionPropietarios.end();
};

Propietario* HandlerPropietarios::getPropietario(string nickname){
    if(this->coleccionPropietarios.count(nickname) > 0)
        return this->coleccionPropietarios[nickname];
    return nullptr;
};

map<string, Propietario*> HandlerPropietarios::getColeccionPropietarios(){
    return this->coleccionPropietarios;
};

HandlerPropietarios::~HandlerPropietarios(){
    map<string, Propietario*>::iterator it;
    for(it = this->coleccionPropietarios.begin(); it != this->coleccionPropietarios.end(); it++){
        delete it->second;
    }
    this->coleccionPropietarios.clear();
}
