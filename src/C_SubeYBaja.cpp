#include "../include/C_SubeYBaja.h"
#include <iostream>

bool SubeYBaja:: altaPublicacion(string nicknameInmobiliaria, int codigoInmueble,TipoPublicacion tipoPublicacion, string texto, float precio){
    vector<AdministraPropiedad> adProp= Hinmobiliarias->DevolverAdProp(nicknameInmobiliaria);
    vector<AdministraPropiedad> :: iterator it;
    it=adProp.begin();
    while(((*it).getInmueble().getCodigo()!=codigoInmueble)){//busco el ap que esta relacionado con el inmueble, por precondicion siempre hay uno 
        it++;
    }
    bool e=(*it).existePublicacion( fechaActual->getFechaActual(), tipoPublicacion);
    if (e){
        return false;// si existe una publicacion de ese tipo y fecha se devuelve false
    }
    bool activa =false;
    Publicacion* pu =(*it).encontrarPublicacionActiva(tipoPublicacion);//busca un pu con tiene ese tipo de publicacion que este activo
    if (pu==NULL||fechaActual->getFechaActual()->operator>=((*pu).getFecha())){
        activa=true;
    }
    Publicacion p = Publicacion((*it).getUltimaPublicacion()+1,fechaActual->getFechaActual(),tipoPublicacion,texto,precio,activa);//si no se encontro un pu activo o uno con fecha mayor a la actual, se crea una nueva publicacion con activa=true. sino se crea una con activa false
    if(activa){
         (*pu).setactiva(false);//si la fecha actual es mayor o igual a la de la publicacion, se desactiva
    }
    (*it).setUltimaPublicacion((*it).getUltimaPublicacion()+1);
    (*it).agregarPublicacion(p.getcodigo(),p);
    return true ;
};
 