#ifndef C_LISTAR
#define C_LISTAR
#include "DTUsuario.h"
#include "Usuario.h"
#include "Inmobiliaria.h"
#include "HandlerInmobiliaria.h"
<<<<<<< HEAD
#include "DTInmuebleAdministrado.h"
#include "AdministraPropiedad.h"
#include "IControladorFechaActual.h"
=======
#include "HandlerInmueble.h"
#include "DTInmuebleAdministrado.h"
#include "AdministraPropiedad.h"
#include "ControladorFechaActual.h"
>>>>>>> origin/main
#include <map>
#include <string>
#include <set>
using namespace std; // Esto evita tener que escribir std::

class Listar {
private:
<<<<<<< HEAD
    handlerInmobiliaria* Hinmobiliarias;
    IControladorFechaActual* fechaActual;
public:
    void inicializarHInmobiliarias(handlerInmobiliaria* handler);
=======
    static Listar* instancia;
    HandlerInmobiliaria* Hinmobiliarias;
    ControladorFechaActual* fechaActual; // TODO: chequear si corresponde usar directamente el controlador, o si corresponde usar la interfaz
public:
    Listar();  
public:
    static Listar* getInstancia();

    ~Listar(); 

>>>>>>> origin/main
    set<DTUsuario> listarInmobiliarias();
    set<DTInmuebleAdministrado> listarInmueblesAdministrados(string nicknameInmobiliaria);
};

#endif
