#ifndef INMUEBLE_H
#define INMUEBLE_H
#include <string>
#include "Propietario.h"

using namespace std;

<<<<<<< HEAD
    public:
        Inmueble();// constructor por defecto
        Inmueble(int codigo, std::string direccion, int numeroPuerta, int superficie, int anoConstruccion);

        virtual ~Inmueble();
        
        int getCodigo() ;
        std::string getDireccion() ;
        int getNumeroPuerta() ;
        int getSuperficie() ;
        int getAnoConstruccion() ;

        // Cambiado a const para poder usarlo en el menu
        Propietario* getPropietario() const;


=======
// Forward declaration
class Propietario;

class Inmueble
{
private:
    int codigo;
    string direccion;
    int numeroPuerta;
    int superficie;
    int anoConstruccion;
    Propietario *propietario;

public:
    Inmueble(int codigo, string direccion, int numeroPuerta, int superficie, int anoConstruccion);
    virtual ~Inmueble();

    int getCodigo();
    string getDireccion();
    int getNumeroPuerta();
    int getSuperficie();
    int getAnoConstruccion();
    // Cambiado a const para poder usarlo en el menu
    Propietario *getPropietario() const;
>>>>>>> origin/main
};


#endif
