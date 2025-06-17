#include "../include/HandlerPublicacion.h"
#include <string>

using namespace std;

HandlerPublicacion *HandlerPublicacion:: instancia = NULL;

HandlerPublicacion::HandlerPublicacion() {
    map<int, Publicacion *> coleccionPublicaciones;
    this->coleccionPublicaciones = coleccionPublicaciones;
}

HandlerPublicacion* HandlerPublicacion::getInstancia(){
    if (instancia == NULL)
        instancia = new HandlerPublicacion();
    return instancia;
};

void HandlerPublicacion::agregarPublicacion(Publicacion* &publicacion){
  int codPublicacion = publicacion->getCodigo();
  coleccionPublicaciones[codPublicacion] = publicacion;
};

void HandlerPublicacion::eliminarPublicacion(int codigo){
    map<int, Publicacion*>::iterator it = this->coleccionPublicaciones.find(codigo);
    if(it != coleccionPublicaciones.end()){
        delete it->second;
        coleccionPublicaciones.erase(it);
    }
};

bool HandlerPublicacion::existePublicacion(int codigo){
    return coleccionPublicaciones.find(codigo) != coleccionPublicaciones.end();
};

Publicacion* HandlerPublicacion::getPublicacion(int codigo){
    if(coleccionPublicaciones.count(codigo) > 0)
        return coleccionPublicaciones[codigo];
    return nullptr;
};

set<Publicacion*> HandlerPublicacion::obtenerPublicacionesActivas(){
    set<Publicacion*> publicacionesActivas;
    map<int, Publicacion*>::iterator it;
    for(it = coleccionPublicaciones.begin() ; it != coleccionPublicaciones.end(); ++it){
        if((*it).second->getActiva())
            publicacionesActivas.insert((*it).second);
    }
    
};

HandlerPublicacion::~HandlerPublicacion(){
    map<int, Publicacion*>::iterator it;
    for(it != this->coleccionPublicaciones.begin(); it != this->coleccionPublicaciones.end(); it++){
       delete it->second;
    }
    this->coleccionPublicaciones.clear();
};