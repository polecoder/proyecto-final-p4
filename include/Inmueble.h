#ifndef INMUEBLE_H
#define INMUEBLE_H
#include <string>

class Inmueble {
    private:
        int codigo;
        std::string direccion;
        int numeroPuerta;
        int superficie;
        int anoConstruccion;

    public:
        Inmueble(int codigo, std::string direccion, int numeroPuerta, int superficie, int anoConstruccion);
        virtual ~Inmueble();
        
        int getCodigo() ;
        std::string getDireccion() ;
        int getNumeroPuerta() ;
        int getSuperficie() ;
        int getAnoConstruccion() ;

};

#endif