#ifndef INMUEBLE_H
#define INMUEBLE_H
#include <string>
#include <algorithm>
#include <vector>
#include "AdministraPropiedad.h"
#include "TipoInmueble.h"
#include "Propietario.h"
#include "TipoInmueble.h"

class Propietario;
class AdministraPropiedad;

using namespace std;

class Inmueble {
    private:
        int codigo;
        string direccion;
        int numeroPuerta;
        int superficie;
        int anoConstruccion;
        Propietario *propietario;
        vector<AdministraPropiedad *> administraPropiedad;
    public:
        Inmueble(int codigo, string direccion, int numeroPuerta, int superficie, int anoConstruccion);
        virtual ~Inmueble();
        
        int getCodigo() ;
        string getDireccion() ;
        int getNumeroPuerta() ;
        int getSuperficie() ;
        int getAnoConstruccion() ;
        Propietario* getPropietario() const;
        vector<AdministraPropiedad *> getAdministraPropiedad();
        virtual TipoInmueble getTipoInmueble() const = 0;
        
        void setPropietario(Propietario *propietario);
        void setCodigo(int codigo);
        void setDireccion(string direccion);
        void setNumeroPuerta(int numeroPuerta);
        void setSuperficie(int superficie);
        void setAnoConstruccion(int anoConstruccion);
        void agregarAdministraPropiedad(AdministraPropiedad *administraPropiedad);
        
};

#endif
