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
  coleccionPublicaciones.insert({publicacion.getCodigo(), publicacion})  
}

void HandlerPublicacion::eliminarPublicacion(int codigo){

}

bool HandlerPublicacion::existePublicacion(int codigo){

}

Publicacion HandlerPublicacion::getPublicacion(int codigo){
    
    return coleccionPublicaciones.at(codigo);
}

vector<Publicacion> HandlerPublicacion::obtenerPublicacionesActivas(TipoPublicacion tipoPub, float precioMin, float precioMax, TipoInmueble tipo){
    vector<Publicacion> publicaciones;
    if(tipo == Todos){
        for(map<int, Publicacion>::iterator it = coleccionPublicaciones.begin(); it != coleccionPublicaciones.end(); ++it){
            Publicacion& pub = it->second;
            if(pub.getActiva() && pub.getTipo() == tipoPub && precioMin < pub.getPrecio() && pub.getPrecio() < precioMax){
                publicaciones.push_back(pub);
            }
        }
    }else{
        for(map<int, Publicacion>::iterator it = coleccionPublicaciones.begin(); it != coleccionPublicaciones.end(); ++it){
            Publicacion& pub = it->second;
            if(pub.getActiva() && pub.getTipo() == tipo && precioMin < pub.getPrecio() && pub.getPrecio() < precioMax && pub.getTipoInmueble() == tipo){
                publicaciones.push_back(pub);
            }
        }
    }
    return publicaciones;
}