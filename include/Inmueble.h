#ifndef INMUEBLE_H
#define INMUEBLE_H
#include <string>
#include "Propietario.h"
#include "TipoInmueble.h"

using namespace std;

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

    void setPropietario(Propietario *propietario);
    
    Propietario *getPropietario() const;    // Cambiado a const para poder usarlo en el menu
    virtual TipoInmueble getTipoInmueble() const = 0;
};

#endif
