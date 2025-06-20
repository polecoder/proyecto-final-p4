
#ifndef DTINMUEBLEADMINISTRADO_H
#define DTINMUEBLEADMINISTRADO_H
#include "DTFecha.h"
#include <string>

using namespace std; 

class DTInmuebleAdministrado {
    private:
        int codigo;
        string direccion;
        DTFecha* fechaComienzo;

    public:
        DTInmuebleAdministrado(int codigo, string direccion, DTFecha* fechaComienzo);
        ~DTInmuebleAdministrado();  
        //les puse const porque siono no puedo mostrarlo en el menu
        int getCodigo() const;
        string getDireccion()const;
        DTFecha* getFechaComienzo();

        bool operator<(const DTInmuebleAdministrado& other) const;
       
};


#endif