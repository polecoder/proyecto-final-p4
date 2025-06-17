#include "../include/HandlerPublicacion.h"
#include <string>

using namespace std;

HandlerPublicacion* HandlerPublicacion:: instancia = NULL;

HandlerPublicacion::HandlerPublicacion() {}

HandlerPublicacion* HandlerPublicacion::getInstancia(){
    if (instancia == NULL)
        instancia = new HandlerPublicacion();
    return instancia;
};

void HandlerPublicacion::agregarPublicacion(Publicacion* &publicacion){
  int codPublicacion = publicacion->getCodigo();
  coleccionPublicaciones[codPublicacion] = publicacion;
};

void HandlerPublicacion::eliminarPublicacion(const int& codigo){
    if(coleccionPublicaciones.count(codigo))
        coleccionPublicaciones[codigo]->~Publicacion();
};

bool HandlerPublicacion::existePublicacion(const int& codigo){
    return coleccionPublicaciones.find(codigo) != coleccionPublicaciones.end();
};

Publicacion* HandlerPublicacion::getPublicacion(const int& codigo){
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
    for(it != coleccionPublicaciones.begin(); it != coleccionPublicaciones.end(); it++){
        (*it).second->~Publicacion();
    }
};