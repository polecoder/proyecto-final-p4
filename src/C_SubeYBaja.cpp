#include "../include/C_SubeYBaja.h"
#include "../include/HandlerInmobiliaria.h"
#include "../include/DTFecha.h"
#include "../include/Publicacion.h"
#include "../include/TipoPublicacion.h"
#include "../include/Propietario.h"
#include "../include/Inmobiliaria.h"
#include "../include/HandlerCliente.h"
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

bool SubeYBaja:: altaPropietario(string nickname, string contrasena, string nombre, string email, string cuentaBancaria, string telefono) {
    bool existe = Hpropietario->existePropietario(nickname);
    if (!existe) {
        Propietario* nuevoPropietario = new Propietario(nickname, contrasena, nombre, email, cuentaBancaria, telefono);
        Hpropietario->agregarPropietario(nuevoPropietario);
        return true; // Alta exitosa
    }
    return false;
}

bool SubeYBaja:: altaInmobiliaria(string nickname, string contrasena, string nombre, string email, string url, string telefono) {
    bool existe = Hinmobiliarias->existeInmobiliaria(nickname);
    if (!existe) {
        Inmobiliaria* nuevaInmobiliaria = new Inmobiliaria(nickname, contrasena, nombre, email, url, telefono);
        Hinmobiliarias->agregarInmobiliaria(nuevaInmobiliaria);
        return true;
    }
    return false;
}

bool SubeYBaja:: altaCliente(string nickname, string contrasena, string nombre, string email, string apellido, string documento) {
    bool existe = Hcliente->existeCliente(nickname);
    if (!existe) {
        Cliente* nuevoCliente = new Cliente(nickname, contrasena, nombre, email, apellido, documento);
        Hcliente->agregarCliente(nuevoCliente);
        return true;
    }
    return false;
}