#include "../include/C_SubeYBaja.h"
#include <iostream>

bool SubeYBaja:: altaPublicacion(string nicknameInmobiliaria, int codigoInmueble,TipoPublicacion tipoPublicacion, string texto, float precio){
    vector<AdministraPropiedad> adProp= Hinmobiliarias->DevolverAdProp(nicknameInmobiliaria);
    vector<AdministraPropiedad> :: iterator it;
    it=adProp.begin();
    while(((*it).getinmueble().getCodigo()!=codigoInmueble)){//busco el ap que esta relacionado con el inmueble, por precondicion siempre hay uno 
        it++;
    }
    bool e=(*it).existepubli( fechaActual->getFechaActual(), tipoPublicacion);
    if (e){
        return false;// si existe una publicacion de ese tipo y fecha se devuelve false
    }
    Publicacion pu =(*it).encontrarPu(tipoPublicacion);//tiene que tener ese tipo de publicacion y estar activa
    bool activa=false;
    if (fechaActual->getFechaActual()->operator>=(pu.getFecha())){
        pu.setactiva(false);//si la fecha actual es mayor o igual a la de la publicacion, se desactiva
        activa=true;
    }
    Publicacion p = Publicacion((*it).getultimaPublicacion()+1,fechaActual->getFechaActual(),tipoPublicacion,texto,precio,activa);
    (*it).setultimaPublicacion((*it).getultimaPublicacion()+1);
    (*it).agregarPubli(p.getcodigo(),p);
    return true ;
};