#include "../include/ControladorSubeYBaja.h"
#include "../include/Casa.h"
#include <iostream>

using namespace std;

SubeYBaja* SubeYBaja::Instancia = nullptr;

SubeYBaja* SubeYBaja::getInstancia(){
    if (Instancia==nullptr){
        Instancia= new SubeYBaja();
    }
    return Instancia;
};

SubeYBaja::SubeYBaja() {
    Hinmobiliarias = HandlerInmobiliaria::getInstancia(); // Inicializa el Handler de inmobiliarias
    fechaActual = ControladorFechaActual::getInstance(); // Inicializa el controlador de fecha actual
    HPublicacion = HandlerPublicacion::getInstancia(); // Inicializa el Handler de publicaciones
};
SubeYBaja::~SubeYBaja() {
    // Destructor vacio, no es necesario liberar memoria ya que no hay punteros
    // Los Handlers se encargan de liberar su propia memoria
};

bool SubeYBaja::altaPublicacion(string nicknameInmobiliaria, int codigoInmueble, TipoPublicacion tipoPublicacion, string texto, float precio) {
    //se busca si existe una publicacion con el mismo tipo y fecha
    vector<AdministraPropiedad*> adProp = Hinmobiliarias->getAdProp(nicknameInmobiliaria);
    vector<AdministraPropiedad*>::iterator it;
    it = adProp.begin();
    while ((((*it)->getInmueble())->getCodigo() != codigoInmueble)) { //busco el ap que esta relacionado con el inmueble, por precondicion siempre hay uno
        it++;
    }
    bool e=(*it)->existePublicacion( fechaActual->getFechaActual(), tipoPublicacion);
    if (e){
        return false;// si existe una publicacion de ese tipo y fecha se devuelve false
    }

    //no se encontro la publicacion asi que se crea una  nueva
    //se busca pu para ver si la nueva publicacion debe estar activa o no
    Publicacion* pu = (*it)->encontrarPublicacionActiva(tipoPublicacion);
    bool activa = false;
    if (pu == NULL) {
        activa = true;
    } else if ((pu->getFecha()->operator<(fechaActual->getFechaActual()))) {
        activa = true;
        pu->setActiva(false);
    }
    Publicacion* p = new Publicacion((*it)->getUltimaPublicacion() + 1, fechaActual->getFechaActual(), tipoPublicacion, texto, precio, activa, (*it));//si no se encontro un pu activo o uno con fecha mayor a la actual, se crea una nueva publicacion con activa=true. sino se crea una con activa false
    (*it)->setUltimaPublicacion((*it)->getUltimaPublicacion() + 1);
    (*it)->agregarPublicacion(p->getCodigo(), p);
//agregar a la coleccion de publicaciones
    HPublicacion->agregarPublicacion(p);

    //una vez creada la publicacion se debe notificar a los suscriptores
    Inmobiliaria *Inmobiliaria = (Hinmobiliarias->getInmobiliaria(nicknameInmobiliaria));
    Inmueble *inmueble = (*it)->getInmueble();
    class::Casa* esCasa = dynamic_cast<class::Casa*>(inmueble);
    if (esCasa != nullptr) {
        Inmobiliaria->notificar(DTNotificacion( nicknameInmobiliaria, p->getCodigo(), texto, tipoPublicacion, Casa));
    } else {
        Inmobiliaria->notificar(DTNotificacion(nicknameInmobiliaria, p->getCodigo(), texto, tipoPublicacion, Apartamento));
    }

    return true;
};
 