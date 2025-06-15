#ifndef PUBLICACION_H
#define PUBLICACION_H
#include "DTFecha.h"
#include "TipoPublicacion.h"
#include <string>

class Publicacion {
private:
    int codigo;
    DTFecha* fecha;
    TipoPublicacion tipo;
    std::string texto;
    float precio;
    bool activa;

public:
    Publicacion(int codigo, DTFecha* fecha, TipoPublicacion tipo, std::string texto, float precio, bool activa);
    ~Publicacion();
    float getPrecio();
    TipoPublicacion getTipo();
    DTFecha* getFecha();
    bool getActiva();
    void setActiva(bool activa);
    int getCodigo();
};

#endif