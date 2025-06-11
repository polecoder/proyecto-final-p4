#include "../include/C_SubeYBaja.h"
#include <iostream>


bool SubeYBaja:: altaPublicacion(string nicknameInmobiliaria, int codigoInmueble,TipoPublicacion tipoPublicacion, string texto, float precio){
   //se busca si existe una publicacion con el mismo tipo y fecha 
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

    //no se encontro la publicacion asi que se crea una  nueva
    //se busca pu para ver si la nueva publicacion debe estar activa o no
    Publicacion* pu =(*it).encontrarPublicacionActiva(tipoPublicacion);
    bool activa =false;
    if (pu==NULL||fechaActual->getFechaActual()->operator>=((*pu).getFecha())){
        activa=true;
    }
    if(activa){
         (*pu).setActiva(false);//si la fecha actual es mayor o igual a la de la publicacion, se desactiva
    }
    Publicacion p = Publicacion((*it).getUltimaPublicacion()+1,fechaActual->getFechaActual(),tipoPublicacion,texto,precio,activa);//si no se encontro un pu activo o uno con fecha mayor a la actual, se crea una nueva publicacion con activa=true. sino se crea una con activa false
    (*it).setUltimaPublicacion((*it).getUltimaPublicacion()+1);
    (*it).agregarPublicacion(p.getCodigo(),p);

    //agregar a la coleccion de publicaciones
    HPublicacion->agregarPublicacion(p);

    //una vez creada la publicacion se debe notificar a los suscriptores
    Inmobiliaria Inmobiliaria = Hinmobiliarias->DevolverInmobiliaria(nicknameInmobiliaria);
    Inmueble* inmueble = &(*it).getInmueble();
    class::Casa* esCasa = dynamic_cast<class::Casa*>(inmueble);
    if (esCasa != nullptr) {
        Inmobiliaria.notificar(DTNotificacion( nicknameInmobiliaria, p.getCodigo(), texto, tipoPublicacion, Casa));
    } else {
        Inmobiliaria.notificar(DTNotificacion(nicknameInmobiliaria, p.getCodigo(), texto, tipoPublicacion, Apartamento));
    }

    return true;
};
 