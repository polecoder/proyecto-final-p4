#include "../include/AdministraPropiedad.h"
#include <map>

using namespace std;

AdministraPropiedad ::AdministraPropiedad(DTFecha *fecha, Inmueble *inmueble, Inmobiliaria *inmo)
{ // paso un puntero de una instancia de inmueble // paso un puntero de una instancia de inmobiliaria
    this->fecha = fecha;
    this->ultimaPublicacion = 0;
    this->inmueble = inmueble;
    map<int, Publicacion *> publicaciones;
    this->publicaciones = publicaciones;
    this->inmobiliaria = inmo;
};

AdministraPropiedad ::~AdministraPropiedad()
{
    delete this->fecha;
    publicaciones.clear();
};

Inmueble *AdministraPropiedad::getInmueble() const
{
    return this->inmueble;
};

int AdministraPropiedad::getUltimaPublicacion() const
{
    return this->ultimaPublicacion;
};

string AdministraPropiedad::getNicknameInmobiliaria() const
{
    return inmobiliaria->getNickname();
}

void AdministraPropiedad::setUltimaPublicacion(int up)
{
    ultimaPublicacion = up;
};

// TODO: no usar codigo, usar publi.codigo
void AdministraPropiedad::agregarPublicacion(int codigo, Publicacion *publi)
{
    publicaciones.insert({codigo, publi});
};

bool AdministraPropiedad::existePublicacion(DTFecha fecha, TipoPublicacion tipoPublicacion)
{
    map<int, Publicacion *>::iterator it;
    it = publicaciones.begin();
    while (it != publicaciones.end() && (!(fecha.operator==((*it).second->getFecha())) || (*it).second->getTipo() != tipoPublicacion))
    {
        it++;
    };
    return (it != publicaciones.end());
}

Publicacion *AdministraPropiedad::encontrarPublicacionActiva(TipoPublicacion tipoPublicacion)
{
    map<int, Publicacion *>::iterator it;
    it = publicaciones.begin();
    while (it != publicaciones.end())
    {
        if ((((*it).second->getActiva()) && ((*it).second->getTipo() == tipoPublicacion)))
        {
            return it->second;
        }
        it++;
    };
    return NULL;
};

Inmobiliaria *AdministraPropiedad::getInmobiliaria() const
{
    return this->inmobiliaria;
};

map<int, Publicacion *> AdministraPropiedad::getColeccionPublicaciones() const
{
    return this->publicaciones;
}

ostream &operator<<(ostream &os, const AdministraPropiedad &ap)
{
    os << "ADMINISTRAPROPIEDAD: " << endl;
    os << "|    " << *ap.getInmobiliaria() << endl;
    os << "|    " << *ap.getInmueble() << endl;
    os << "|    PUBLICACIONES:" << endl;
    map<int, Publicacion *> publicaciones = ap.getColeccionPublicaciones();
    int contador = 1;
    for (map<int, Publicacion *>::iterator it = publicaciones.begin(); it != publicaciones.end(); ++it)
    {
        os << "    | " << contador << " - " << *(it->second) << endl;
        contador++;
    }
    return os;
}