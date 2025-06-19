#ifndef DTPUBLICACION_H
#define DTPUBLICACION_H
#include "DTFecha.h"
#include <string>
using namespace std;
class DTPublicacion {
    private:
        int codigo;
        DTFecha* fecha;
        string texto;
        string precio;
        string inmobiliaria;

    public:
        DTPublicacion(int codigo, DTFecha* fecha, string texto, string precio, string inmobiliaria);
        int getCodigo()const;
        DTFecha* getFecha()const;
        string getTexto()const;
        string getPrecio()const;
        string getInmobiliaria()const;
        ~DTPublicacion();
};

#endif