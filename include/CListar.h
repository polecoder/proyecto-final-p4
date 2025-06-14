#ifndef C_LISTAR
#define C_LISTAR
#include "DTUsuario.h"
#include "Usuario.h"
#include "Inmobiliaria.h"
#include "HandlerInmobiliaria.h"
#include "HandlerInmueble.h"
#include "DTInmuebleAdministrado.h"
#include "AdministraPropiedad.h"
#include "ControladorFechaActual.h"
#include <map>
#include <string>
#include <set>
using namespace std; // Esto evita tener que escribir std::

class Listar {
private:
    HandlerInmobiliaria* Hinmobiliarias;
    ControladorFechaActual* fechaActual;
public:
    Listar();  
    ~Listar(); 

    set<DTUsuario> listarInmobiliarias();
    set<DTInmuebleAdministrado> listarInmueblesAdministrados(string nicknameInmobiliaria);
};

#endif
