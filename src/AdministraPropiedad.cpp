#include "../include/AdministraPropiedad.h"
#include <map>
#include <iostream>

using namespace std;

AdministraPropiedad :: AdministraPropiedad(DTFecha* fecha, Inmueble* inmueble){
    this->fecha = fecha;
    this->ultimaPublicacion = 0;
    this->inmueble = inmueble;
    map<int,Publicacion> publicaciones;
    this->publicaciones = publicaciones;
};

AdministraPropiedad :: ~AdministraPropiedad(){
    // TODO: Implementar
};

Inmueble* AdministraPropiedad::getInmueble() {
    return this->inmueble;
};
  
int AdministraPropiedad::getUltimaPublicacion(){
    return this->ultimaPublicacion;
};  

void AdministraPropiedad::setUltimaPublicacion(int up){
    ultimaPublicacion=up;
};

// TODO: no usar codigo, usar publi.codigo
void AdministraPropiedad::agregarPublicacion(int codigo, Publicacion publi) {
    publicaciones.insert({codigo, publi});
};

bool AdministraPropiedad::existePublicacion(DTFecha fecha, TipoPublicacion tipoPublicacion){
    map<int,Publicacion> :: iterator it;
    it=publicaciones.begin();
    while(it!=publicaciones.end()&&(!(fecha.operator==((*it).second.getFecha()))|| (*it).second.getTipo()!=tipoPublicacion)){
        it++;
    };
    return (it!=publicaciones.end());
}

Publicacion* AdministraPropiedad::encontrarPublicacionActiva(TipoPublicacion tipoPublicacion) {
    map<int,Publicacion> :: iterator it;
    it=publicaciones.begin();
    while(it!=publicaciones.end()&&(!(*it).second.getActiva()||(*it).second.getTipo()!=tipoPublicacion)) {
        it++;
    };
    if (it==publicaciones.end()){
        return NULL;
    }
    Publicacion* pub = new Publicacion((*it).second);
    return pub;
};
