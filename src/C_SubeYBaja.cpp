#include "../include/C_SubeYBaja.h"
#include "../include/HandlerInmobiliaria.h"
#include "../include/DTFecha.h"
#include "../include/Publicacion.h"
#include "../include/TipoPublicacion.h"
#include "../include/Propietario.h"
#include "../include/Inmobiliaria.h"
#include "..include/HandlerCliente.h"
#include "../include/HandlerPropietario.h"
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

bool altaPropietario(string nickname, string contrasena, string nombre, string email, string cuentaBancaria, string telefono){
    bool existe = existePropietario(nickname);
    if (!existe) {
        Propietario* nuevoPropietario = new Propietario(nickname, contrasena, nombre, email, cuentaBancaria, telefono);
        HandlerPropietario::getInstancia()->agregarPropietario(nuevoPropietario);
        return true; // Alta exitosa
    }
    return false;
}

bool altaInmobiliaria(string nickname, stirng contrasena, string nombre, string email, string url, string telefono){
    bool existe = existeInmobiliaria (nickname);
    if (!existe){
        Inmobilaria* nuevaInmobiliaria = new Inmobiliaria (nickname, contrasena, nombre, email, direccion, url, telefono);
        HandlerInmobiliaria:: getInstancia()->agregarInmobiliaria (nuevaInmobiliaria);
        return true;  
    }
    return false;
}

bool altaCliente (string nickname, string contrasena, string nombre, string email, string apellido, string documento){
    bool existe = existeCliente (nickname);
    if (!existe){
        cliente* nuevoCliente = new NuevoCliente (nickname, contrasena, nombre, email, apellido, documento);
        HandlerCliente:: getInstancia()->agregarCliente(NuevoCliente);
        return true;
    }
    return false;
}