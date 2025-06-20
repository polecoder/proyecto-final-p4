#ifndef PUBLICACION_H
#define PUBLICACION_H
#include "DTFecha.h"
#include "TipoInmueble.h"
#include "Inmueble.h"
#include "TipoPublicacion.h"
#include "AdministraPropiedad.h"
#include <string>
using namespace std;

class Inmueble;

class AdministraPropiedad;
class Inmobiliaria;

class Publicacion {
private:
    int codigo;
    DTFecha *fecha;
    TipoPublicacion tipo;
    string texto;
    float precio;
    bool activa;
    AdministraPropiedad* apAsociado;

public:
    Publicacion(int codigo, DTFecha* fecha, TipoPublicacion tipo, string texto, float precio, bool activa, AdministraPropiedad* apAsociado);
    ~Publicacion();
    int getCodigo() const;//se devuelve el codigo de la publicacion.
    DTFecha* getFecha() const;
    TipoPublicacion getTipo() const;// se devuelve el tipo de publicacion Venta o Alquiler.
    string getTexto() const;//se devuelve el texto de la publicacion.
    float getPrecio() const ;//se devuelve el precio en la publicacion.
    bool getActiva() const ;//devuelve true sii activa = true.
    void setActiva(bool activa);
    TipoInmueble getTipoInmueble() const ;// devuelve el tipoInmueble de la instancia de inmueble asociada a AdministraPropiedad asociado a la publicacion.
    string getNicknameInmobiliaria() const ;
    Inmobiliaria* getInmobiliaria() const;// se devuelve un puntero a la instancia  inmobiliaria asociada al AdministraPropiedad asociado con la publicacion.
    Inmueble* getInmueble() const;// se devuelve un puntero a la instancia asociada al inmueble asociado al AdministraPropiedad asociado con la publiaccion.
};

#endif