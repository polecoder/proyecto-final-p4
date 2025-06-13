#include "Usuario.h"
#include "DTNotificacion.h"
#include "Cliente.h"
#include <set>
#include <string>

using namespace std;

Cliente::Cliente(string nickname, string contrasena, string nombre, string email, string apellido, string documento)
    : Usuario(nickname, contrasena, nombre, email)
{
    this->apellido = apellido;
    this->documento = documento;
}

Cliente::~Cliente() {}

string Cliente::getApellido()
{
    return this->apellido;
}

string Cliente::getDocumento()
{
    return this->documento;
}

set<DTNotificacion> Cliente::getNotificaciones()
{
    return this->notificaciones;
}

void Cliente::setApellido(string apellido)
{
    this->apellido = apellido;
}

void Cliente::setDocumento(string documento)
{
    this->documento = documento;
}

void Cliente::agregarNotificacion(DTNotificacion const &notificacion)
{
    this->notificaciones.insert(notificacion);
}

void Cliente::eliminarNotificaciones()
{
    this->notificaciones.clear();
}