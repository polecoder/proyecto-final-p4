#include "../include/C_Listar.h"
#include <iostream>

using namespace std;

void Listar::inicializarHInmobiliarias(handlerInmobiliaria* handler){
    Hinmobiliarias = handler;
}
set<DTUsuario> Listar::listarInmobiliarias() {
    map<string, Inmobiliaria> inmo = Hinmobiliarias->DevolverInmobiliarias();
    set<DTUsuario> salida; 
    for (map<string, Inmobiliaria>::iterator it = inmo.begin(); it != inmo.end(); ++it) { 
        salida.insert(DTUsuario(it->first, it->second.getNombre()));//first es el nickname, second es el objeto inmobiliaria
    } 
    return salida;
}

set<DTInmuebleAdministrado> Listar :: listarInmueblesAdministrados(string nicknameInmobiliaria){
    set<DTInmuebleAdministrado> salida;
    vector<AdministraPropiedad> adProp= Hinmobiliarias->DevolverAdProp(nicknameInmobiliaria);
    vector<AdministraPropiedad> ::iterator it;
    for (it=adProp.begin();it!=adProp.end();++it){
        Inmueble* in= (*it).getInmueble();
        int codigo = in->getCodigo();
        string direccion=in->getDireccion();
        salida.insert(DTInmuebleAdministrado(codigo, direccion,fechaActual->getFechaActual()));
    }
    return salida;
}

set<DTPublicacion> Listar:: listarPublicacionesActivas(TipoPublicacion tipoPub, float precioMin, float precioMax, TipoInmueble tipo){
    set<Publicacion> listaPublicaciones = HandlerPublicacion::getInstancia()->obtenerPublicacionesActivas(tipoPub, precioMin, precioMax, tipo);
    set<DTPublicacion> dtp;
    for(set<Publicacion>::iterator it = listaPublicaciones.begin(); it != listaPublicaciones.end(); ++it){
        int codigo = it->getCodigo();
        DTFecha* fecha = it->getFecha();
        string texto = it->getTexto();
        string precio = to_string(it->getPrecio());
        string inmobiliaria = it->getNicknameInmobiliaria();
        
        dtp.insert(DTPublicacion(codigo, fecha,texto, precio, inmobiliaria));
    }
    return dtp;
}