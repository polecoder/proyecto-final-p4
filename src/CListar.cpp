#include "../include/CListar.h"
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

set<DTPublicacion> Listar:: listarPublicaciones(TipoPublicacion tipoPub, float precioMin, float precioMax, 
TipoInmueble tipo){
    set<Publicacion*> listaPublicaciones = HandlerPublicacion::getInstancia()->obtenerPublicacionesActivas();
    set<DTPublicacion> dtp;
    for(set<Publicacion*>::iterator it = listaPublicaciones.begin(); it != listaPublicaciones.end(); ++it){
        if(tipo == Todos){
            if((*it)->getTipo()==tipoPub && precioMin<(*it)->getPrecio() && (*it)->getPrecio()<precioMax)
                dtp.insert(DTPublicacion((*it)->getCodigo(), (*it)->getFecha(), (*it)->getTexto(), to_string((*it)->getPrecio()), (*it)->getNicknameInmobiliaria()));
        }else if(tipo == Casa){
            if((*it)->getTipoInmueble()==tipo && (*it)->getTipo()==tipoPub && precioMin<(*it)->getPrecio() && (*it)->getPrecio()<precioMax)
                dtp.insert(DTPublicacion((*it)->getCodigo(), (*it)->getFecha(), (*it)->getTexto(), to_string((*it)->getPrecio()), (*it)->getNicknameInmobiliaria()));
        }else{
            dtp.insert(DTPublicacion((*it)->getCodigo(), (*it)->getFecha(), (*it)->getTexto(), to_string((*it)->getPrecio()), (*it)->getNicknameInmobiliaria()));
        }
    }
    return dtp;
};
DTInmueble Listar::detalleInmueblePublicacion(int codigoPublicacion){
    Publicacion* pub = HandlerPublicacion::getInstancia()->getPublicacion(codigoPublicacion);
    Inmueble* inmuebleAsociado = pub->getInmueble();
    int codigo = inmuebleAsociado->getCodigo();
    string direccion = inmuebleAsociado->getDireccion();
    int numeroPuerta = inmuebleAsociado->getNumeroPuerta();
    int superficie = inmuebleAsociado->getSuperficie();
    int anio = inmuebleAsociado->getAnoConstruccion();

    if(class::Casa *esCasa = dynamic_cast<class::Casa*>(inmuebleAsociado)){
        bool esPH = esCasa->getEsPH();
        TipoTecho techo = esCasa->getTipoTecho();
        return DTCasa(codigo,direccion, numeroPuerta,superficie,anio,esPH,techo);
    }else{
        class::Apartamento *esApartamento = dynamic_cast<class::Apartamento*>(inmuebleAsociado);
        int piso = esApartamento->getPiso();
        bool ascensor = esApartamento->getAscensor();
        float gastosComunes = esApartamento->getGastosComunes();
        return DTApartamento(codigo, direccion, numeroPuerta, superficie, anio, piso, ascensor, gastosComunes);
    }
}