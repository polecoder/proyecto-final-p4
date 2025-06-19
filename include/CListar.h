#ifndef C_LISTAR
#define C_LISTAR
#include "DTUsuario.h"
#include "Usuario.h"
#include "Inmobiliaria.h"
#include "HandlerInmobiliarias.h"
#include "HandlerInmueble.h"
#include "DTInmuebleAdministrado.h"
#include "IControladorListar.h"
#include "AdministraPropiedad.h"
#include "ControladorFechaActual.h"
#include "IControladorListar.h"
#include <map>
#include <string>
#include <set>
using namespace std;

class Listar : public IControladorListar
{
private:
    static Listar *instancia;
    HandlerInmobiliarias *Hinmobiliarias;
    IControladorFechaActual *fechaActual; // TODO: chequear si corresponde usar directamente el controlador, o si corresponde usar la interfaz
    Listar();

public:
    static Listar *getInstancia();

    ~Listar();

    set<DTUsuario> listarInmobiliarias();
    set<DTInmuebleAdministrado> listarInmueblesAdministrados(string nicknameInmobiliaria);
};

#endif
