#ifndef PUBLICACION_H
#define PUBLICACION_H
#include "DTFecha.h"
#include "TipoInmueble.h"
#include "TipoPublicacion.h"
#include <string>

using namespace std;

class Publicacion {
private:
    int codigo;
    DTFecha* fecha;
    TipoPublicacion tipo;
    string texto;
    float precio;
    bool activa;
    AdministraPropiedad* ap;

public:
    Publicacion(int codigo, DTFecha* fecha, TipoPublicacion tipo, string texto, float precio, bool activa);
    ~Publicacion();
    int getCodigo(); //se devuelve el codigo de la publicacion
    DTFecha* getFecha();
    TipoPublicacion getTipo();// se devuelve el tipo de publicacion Venta o Alquiler
    string getTexto();//se devuelve el texto de la publicacion
    float getPrecio();//se devuelve el precio en la publicacion
    bool getActiva();//devuelve true sii activa = true
    void setActiva(bool activa);
    
};

#endif