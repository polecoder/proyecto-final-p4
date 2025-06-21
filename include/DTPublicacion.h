#ifndef DTPUBLICACION_H
#define DTPUBLICACION_H
#include "DTFecha.h"
#include <string>
using namespace std;
class DTPublicacion
{
private:
    int codigo;
    DTFecha *fecha;
    string texto;
    float precio;
    string inmobiliaria;

public:
    DTPublicacion(int codigo, DTFecha *fecha, string texto, float precio, string inmobiliaria);
    int getCodigo() const;
    DTFecha *getFecha() const;
    string getTexto() const;
    float getPrecio() const;
    string getInmobiliaria() const;
    ~DTPublicacion();

    bool operator<(const DTPublicacion &other) const;
};

#endif