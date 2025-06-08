#include "../include/AdministraPropiedad.h"
#include <iostream>

using namespace std;

AdministraPropiedad :: AdministraPropiedad(DTFecha* fecha, Inmueble Inmueble ){
    this->fecha = fecha;
    this->ultimaPublicacion = 0;
    this->inmueble = inmueble;
    map<int,Publicacion> publis;
    this->Publis = publis;
};
AdministraPropiedad :: ~AdministraPropiedad(){

};

Inmueble AdministraPropiedad:: getinmueble() {
    return *inmueble;
};  
int AdministraPropiedad:: getultimaPublicacion(){
    return ultimaPublicacion;
};  

void AdministraPropiedad:: setultimaPublicacion(int up){
    ultimaPublicacion=up;
};
void AdministraPropiedad:: agregarPubli(int codigo, Publicacion publi){
    Publis.insert({codigo,publi});
};

bool AdministraPropiedad::existepubli(DTFecha fecha, TipoPublicacion tipoPublicacion){
    map<int,Publicacion> :: iterator it;
    it=Publis.begin();
    while(it!=Publis.end()&&(!(fecha.operator==((*it).second.getFecha()))|| (*it).second.getTipo()!=tipoPublicacion)){
        it++;
    };
    return (it!=Publis.end());
}
Publicacion AdministraPropiedad ::encontrarPu(TipoPublicacion tipoPublicacion){
    map<int,Publicacion> :: iterator it;
    it=Publis.begin();
    while(it!=Publis.end()&&(!(*it).second.getactiva()||(*it).second.getTipo()!=tipoPublicacion)){
        it++;
    };
    return (*it).second;
};