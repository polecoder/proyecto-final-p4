#include "../include/HandlerPublicacion.h"
#include <string>

using namespace std;

HandlerPublicacion* HandlerPublicacion:: instancia = NULL;

HandlerPublicacion::HandlerPublicacion(){}

HandlerPublicacion* HandlerPublicacion::getInstancia(){
    if (instancia == NULL)
        instancia = new HandlerPublicacion();
    return instancia;
}

void HandlerPublicacion::agregarPublicacion(Publicacion &publicacion){
  coleccionPublicaciones.insert({publicacion.getCodigo(), publicacion});  
}

void HandlerPublicacion::eliminarPublicacion(int codigo){
    map<int, Publicacion>::iterator it = coleccionPublicaciones.find(codigo);//si ponemos como precondicion que existe podemos sacar este if 
    if (it != coleccionPublicaciones.end()) {
        coleccionPublicaciones.erase(it);
    }
}


Publicacion HandlerPublicacion::getPublicacion(int codigo){
    
    return coleccionPublicaciones.at(codigo);
}

