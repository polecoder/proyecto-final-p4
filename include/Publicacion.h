#ifndef PUBLICACION_H
#define PUBLICACION_H
#include "DTFecha.h"
#include "TipoPublicacion.h"
#include <string>
class AdministraPropiedad;
using namespace std;

class Publicacion {
private:
    int codigo;
    DTFecha* fecha;
    TipoPublicacion tipo;
    std::string texto;
    float precio;
    bool activa;
    AdministraPropiedad* apAsociado; 

public:
    Publicacion(int codigo, DTFecha* fecha, TipoPublicacion tipo, string texto, float precio, bool activa, AdministraPropiedad* apAsociado);
    ~Publicacion();
    float getPrecio();
    TipoPublicacion getTipo();
    DTFecha* getFecha();
    bool getActiva();
    void setActiva(bool activa);
    int getCodigo()const;
};

#endif