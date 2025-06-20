#include <set>
#include "../include/HandlerPropietarios.h"
#include "../include/HandlerClientes.h"
#include "../include/HandlerInmobiliarias.h"
#include "../include/DTNotificacion.h"
#include "../include/ControladorListar.h"
#include "../include/DTUsuario.h"

using namespace std;

ControladorListar *ControladorListar::instancia = NULL;

ControladorListar::ControladorListar()
{
    this->handlerPropietarios = HandlerPropietarios::getInstancia();
    this->handlerClientes = HandlerClientes::getInstancia();
    this->handlerInmobiliarias = HandlerInmobiliarias::getInstancia();
    this->interfazFechaActual = ControladorFechaActual::getInstancia();
}

ControladorListar *ControladorListar::getInstancia()
{
    if (instancia == NULL)
    {
        instancia = new ControladorListar;
    }
    return instancia;
}

ControladorListar::~ControladorListar()
{
    // TODO: Revisar si corresponde eliminar los Handlers en este destructor
}

set<DTUsuario> ControladorListar::listarInmobiliarias()
{
    map<string, Inmobiliaria *> inmo = this->handlerInmobiliarias->getColeccionInmobiliarias();
    set<DTUsuario> salida;
    map<string, Inmobiliaria *>::iterator it;
    for (it = inmo.begin(); it != inmo.end(); ++it)
    {
        salida.insert(DTUsuario(it->first, it->second->getNombre())); // first es el nickname, second es el objeto inmobiliaria
    }
    return salida;
}

set<DTInmuebleAdministrado> ControladorListar::listarInmueblesAdministrados(string nicknameInmobiliaria)
{
    vector<AdministraPropiedad *> adProp = this->handlerInmobiliarias->getColeccionAdministraPropiedad(nicknameInmobiliaria);
    set<DTInmuebleAdministrado> salida;
    vector<AdministraPropiedad *>::iterator it;
    for (it = adProp.begin(); it != adProp.end(); ++it)
    {
        salida.insert(DTInmuebleAdministrado(((*it)->getInmueble())->getCodigo(), ((*it)->getInmueble())->getDireccion(), this->interfazFechaActual->getFechaActual()));
    }
    return salida;
}

// PRE-CONDICIÓN: (existePropietario(nicknameUsuario) || existeCliente(nicknameUsuario)) == true
set<DTNotificacion> ControladorListar::listarNotificacionesDeUsuario(string nicknameUsuario)
{
    if (this->handlerClientes->existeCliente(nicknameUsuario))
    {
        Cliente *cliente = this->handlerClientes->getCliente(nicknameUsuario);
        return cliente->getNotificaciones();
    }
    else
    {
        Propietario *propietario = this->handlerPropietarios->getPropietario(nicknameUsuario);
        return propietario->getNotificaciones();
    }
}

// PRE-CONDICIÓN: (existeCliente(nicknameUsuario) || existePropietario(nicknameUsuario))
set<DTUsuario> ControladorListar::listarSuscripciones(string nicknameUsuario)
{
    set<DTUsuario> resultado;
    // TODO: Hacerlo sin if/else (no se me ocurre mejor forma que esta)
    if (this->handlerClientes->existeCliente(nicknameUsuario))
    {
        Cliente *cliente = this->handlerClientes->getCliente(nicknameUsuario);
        map<string, Inmobiliaria *> suscripcionesCliente = cliente->getSuscripciones();
        map<string, Inmobiliaria *>::iterator it;
        for (it = suscripcionesCliente.begin(); it != suscripcionesCliente.end(); it++)
        {
            DTUsuario datosCliente(it->first, it->second->getNombre()); // Creo el objeto de forma estática (sin new)
            resultado.insert(datosCliente);
        }
    }
    else
    {
        Propietario *propietario = this->handlerPropietarios->getPropietario(nicknameUsuario);
        map<string, Inmobiliaria *> suscripcionesPropietario = propietario->getSuscripciones();
        map<string, Inmobiliaria *>::iterator it;
        for (it = suscripcionesPropietario.begin(); it != suscripcionesPropietario.end(); it++)
        {
            DTUsuario datosPropietario(it->first, it->second->getNombre()); // Creo el objeto de forma estática (sin new)
            resultado.insert(datosPropietario);
        }
    }
    return resultado;
}
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
        map<string, Inmobiliaria*> inmobiliarias = this->handlerInmobiliarias->getColeccionInmobiliarias();
        map<string, Inmobiliaria*>::iterator it;
        for(it = inmobiliarias.begin(); it != inmobiliarias.end(); ++it){
            string nicknameInmobiliaria = it->first;
            if(!cliente->estaSuscripto(nicknameInmobiliaria)){
                inmobiliariasNoSuscripto.insert(DTUsuario(it->second->getNickname(), it->second->getNombre()));
            }
        }
    }
    if(this->handlerPropietarios->existePropietario(nicknameUsuario)){
        Propietario *propietario = this->handlerPropietarios->getPropietario(nicknameUsuario);
        map<string, Inmobiliaria*> inmobiliarias = this->handlerInmobiliarias->getColeccionInmobiliarias();
        map<string, Inmobiliaria*>::iterator it;
        for(it = inmobiliarias.begin(); it != inmobiliarias.end(); ++it){
            string nicknameInmobiliaria = it->first;
            if(!propietario->estaSuscripto(nicknameInmobiliaria)){
                inmobiliariasNoSuscripto.insert(DTUsuario(it->second->getNickname(), it->second->getNickname()));
            }
        }
    }
    return inmobiliariasNoSuscripto;
};
