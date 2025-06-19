#include "../include/ControladorListar.h"
#include <iostream>
#include <ios>
#include <string>
#include <set>
#include <map>

using namespace std;


ControladorListar* ControladorListar::instancia = NULL;

ControladorListar::ControladorListar(){
    handlerInmobiliaria = HandlerInmobiliaria::getInstancia(); // Inicializa el handler de inmobiliarias
    handlerPropietarios = HandlerPropietarios::getInstancia();
    handlerClientes = HandlerClientes::getInstancia();
    fechaActual = ControladorFechaActual::getInstance(); // Inicializa el controlador de fecha actual
}; 

ControladorListar* ControladorListar:: getInstancia(){
    if (instancia == NULL){
        instancia= new ControladorListar;
    }
    return instancia;
};

ControladorListar:: ~ControladorListar(){

};

set<DTUsuario> ControladorListar::listarInmobiliarias() {
    map<string, Inmobiliaria*> inmo = handlerInmobiliaria->getInmobiliarias();
    set<DTUsuario> salida;
    map<string, Inmobiliaria*>::iterator it;
    for (it = inmo.begin(); it != inmo.end(); ++it) {
        salida.insert(DTUsuario(it->first, it->second->getNombre()));//first es el nickname, second es el objeto inmobiliaria
    }
    return salida;
}

set<DTInmuebleAdministrado> ControladorListar :: listarInmueblesAdministrados(string nicknameInmobiliaria){
    vector<AdministraPropiedad*> adProp= handlerInmobiliaria->getAdProp(nicknameInmobiliaria);
    set<DTInmuebleAdministrado> salida; 
    vector<AdministraPropiedad*>::iterator it;
    for (it = adProp.begin(); it != adProp.end(); ++it) {
        salida.insert(DTInmuebleAdministrado((*(*it)->getInmueble()).getCodigo(),(*(*it)->getInmueble()).getDireccion(),fechaActual->getFechaActual()));
    }
    return salida;
};

set<DTPublicacion> ControladorListar:: listarPublicaciones(TipoPublicacion tipoPub, float precioMin, float precioMax, 
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

DTInmueble ControladorListar::detalleInmueblePublicacion(int codigoPublicacion){
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
};

set<DTUsuario> ControladorListar::listarInmobiliariasNoSuscripto(string nicknameUsuario){
    set<DTUsuario> inmobiliariasNoSuscripto;
    if(this->handlerClientes->existeCliente(nicknameUsuario)){
        Cliente *cliente = this->handlerClientes->getCliente(nicknameUsuario);
        map<string, Inmobiliaria*> inmobiliarias = this->handlerInmobiliaria->getInmobiliarias();
        map<string, Inmobiliaria*>::iterator it;
        for(it = inmobiliarias.begin(); it != inmobiliarias.end(); ++it){
            string nicknameInmobiliaria = it->first;
            if(!cliente->estaSuscripto(nicknameInmobiliaria)){
                inmobiliariasNoSuscripto.insert(DTUsuario(it->second->getNickname(), it->second->getNombre()));
            }
        }
        // return inmobiliariasNoSuscripto;
    }
    if(this->handlerPropietarios->existePropietario(nicknameUsuario)){
        Propietario *propietario = this->handlerPropietarios->getPropietario(nicknameUsuario);
        map<string, Inmobiliaria*> inmobiliarias = this->handlerInmobiliaria->getInmobiliarias();
        map<string, Inmobiliaria*>::iterator it;
        for(it = inmobiliarias.begin(); it != inmobiliarias.end(); ++it){
            string nicknameInmobiliaria = it->first;
            if(!propietario->estaSuscripto(nicknameInmobiliaria)){
                inmobiliariasNoSuscripto.insert(DTUsuario(it->second->getNickname(), it->second->getNickname()));
            }
        }
        // return inmobiliariasNoSuscripto;
    }
    return inmobiliariasNoSuscripto;
};