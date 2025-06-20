#ifndef HANDLER_INMUEBLE
#define HANDLER_INMUEBLE
#include "Inmueble.h"
#include "Propietario.h"
#include <map>
using namespace std; 

class HandlerInmueble {
private:
    map<int, Inmueble*> coleccionInmuebles;
    static HandlerInmueble* instancia;
    HandlerInmueble();  // Constructor
    
public:
    static HandlerInmueble* getInstancia();

    void agregarInmueble(Inmueble* inmueble);
    void eliminarInmueble(int codigo);

    bool existeInmueble(int codigoInmueble);
    map<int, Inmueble*> DevolverInmuebles(); // Devuelve el mapa completo
    Inmueble* DevolverInmueble(int codigo); // Devuelve el inmueble con ese codigo
    ~HandlerInmueble(); // Destructor
};
#endif