#include "../include/CargaDatos.h"
#include "../include/ControladorSubeYBaja.h"
#include "../include/ControladorSuscripciones.h"
#include "../include/DTFecha.h"
#include <string>
#include <set>
#include <iostream>

using namespace std;

CargaDatos *CargaDatos::instancia = NULL;

CargaDatos::CargaDatos()
{
    this->interfazSubeYBaja = ControladorSubeYBaja::getInstancia();
    this->interfazFechaActual = ControladorFechaActual::getInstancia();
    this->interfazSuscripciones = ControladorSuscripciones::getInstancia();
    // Agregar Clientes
    interfazSubeYBaja->altaCliente("luisito23", "qweasd12", "Luis", "luisito23@gmail.com", "Pérez", "46859342");
    interfazSubeYBaja->altaCliente("anarojo88", "claveAna1", "Ana", "anarojo88@hotmail.com", "Rojo", "31287465");
    // Agregar Propietarios
    interfazSubeYBaja->altaPropietario("marcelom", "banco123", "Marcelo", "marcelo.m@gmail.com", "123456789012", "099876543");
    interfazSubeYBaja->altaCasa("Av. Rivera", 1011, 120, 1995, true, Plano);
    interfazSubeYBaja->altaApartamento("Av. Brasil", 2031, 75, 1980, 5, true, 3500);

    interfazSubeYBaja->altaPropietario("robertarce", "pass456", "Roberto", "roberto.a@yahoo.com", "987654321001", "091234567");
    interfazSubeYBaja->altaCasa("Camino Maldonado", 1540, 95, 1988, false, Plano);

    interfazSubeYBaja->altaPropietario("soledadf", "sole789", "Soledad", "soledad.f@gmail.com", "654321987654", "092345678");
    interfazSubeYBaja->altaApartamento("Colonia", 1542, 60, 1978, 12, true, 2800);

    interfazSubeYBaja->altaPropietario("martagal", "martA01", "Marta", "marta.galvez@outlook.com", "321098765432", "098765432");
    interfazSubeYBaja->altaCasa("Juan Paullier", 801, 110, 2000, true, Liviano);

    interfazSubeYBaja->altaPropietario("jorge88", "jorgepass88", "Jorge", "jorge.rivera@uy.com", "890123456789", "097654321");
    interfazSubeYBaja->altaApartamento("Bulevar Artigas", 871, 68, 2002, 3, false, 2200);
    interfazSubeYBaja->altaApartamento("Sarmiento", 1476, 80, 2008, 6, true, 3100);
    interfazSubeYBaja->altaCasa("Cno. Carrasco", 1576, 140, 2007, true, Plano);
    // Agregar Inmobiliarias
    interfazSubeYBaja->altaInmobiliaria("casasur123", "casasur99", "Casa Sur", "contacto@casasur.com", "Canelones 2345", "https://casasur.com.uy", "24012345");
    interfazSubeYBaja->representarPropietario("marcelom");
    interfazSubeYBaja->representarPropietario("jorge88");

    interfazSubeYBaja->altaInmobiliaria("idealhome", "home2025", "IHome", "info@idealhome.uy", "Av. Italia 4567", "https://idealhome.uy", "099123456");
    interfazSubeYBaja->representarPropietario("marcelom");
    interfazSubeYBaja->representarPropietario("martagal");
    interfazSubeYBaja->representarPropietario("jorge88");

    interfazSubeYBaja->altaInmobiliaria("vivaurbana", "viva4567", "Viva Urbana", "contacto@vivaurbana.com", "18 de Julio 7890", "https://vivaurbana.com", "29109876");
    interfazSubeYBaja->representarPropietario("robertarce");
    interfazSubeYBaja->representarPropietario("soledadf");
    interfazSubeYBaja->representarPropietario("jorge88");
    // Crear los Administra Propiedad
    interfazFechaActual->setNewFechaActual(12, 12, 2015);
    interfazSubeYBaja->altaAdministraPropiedad(2, "casasur123");

    interfazFechaActual->setNewFechaActual(25, 9, 2023);
    interfazSubeYBaja->altaAdministraPropiedad(1, "idealhome");

    interfazFechaActual->setNewFechaActual(20, 7, 2022);
    interfazSubeYBaja->altaAdministraPropiedad(3, "vivaurbana");

    interfazFechaActual->setNewFechaActual(1, 1, 2022);
    interfazSubeYBaja->altaAdministraPropiedad(4, "vivaurbana");

    interfazFechaActual->setNewFechaActual(3, 7, 2010);
    interfazSubeYBaja->altaAdministraPropiedad(5, "idealhome");

    interfazFechaActual->setNewFechaActual(4, 11, 2019);
    interfazSubeYBaja->altaAdministraPropiedad(6, "casasur123");

    interfazFechaActual->setNewFechaActual(19, 5, 2020);
    interfazSubeYBaja->altaAdministraPropiedad(6, "vivaurbana");

    interfazFechaActual->setNewFechaActual(19, 7, 2024);
    interfazSubeYBaja->altaAdministraPropiedad(6, "idealhome");

    interfazFechaActual->setNewFechaActual(18, 9, 2023);
    interfazSubeYBaja->altaAdministraPropiedad(7, "idealhome");

    interfazFechaActual->setNewFechaActual(19, 5, 2022);
    interfazSubeYBaja->altaAdministraPropiedad(8, "vivaurbana");

    // Crear Publicaciones
    interfazFechaActual->setNewFechaActual(9, 10, 2011);
    interfazSubeYBaja->altaPublicacion("idealhome", 5, Venta, "Casa al fondo Juan Paullier con 110 m fondo y techo liviano.", 47000);

    interfazFechaActual->setNewFechaActual(15, 1, 2016);
    interfazSubeYBaja->altaPublicacion("casasur123", 2, Alquiler, "Oportunidad en Av. Brasil: apartamento de 75 m piso 5 con ascensor.", 28000);

    interfazFechaActual->setNewFechaActual(5, 3, 2019);
    interfazSubeYBaja->altaPublicacion("casasur123", 2, Alquiler, "Apartamento luminoso en Av. Brasil piso alto con excelentes servicios.", 29500);

    interfazFechaActual->setNewFechaActual(3, 4, 2019);
    interfazSubeYBaja->altaPublicacion("idealhome", 5, Alquiler, "Casa ideal para familia en Juan Paullier barrio tranquilo.", 38500);

    interfazFechaActual->setNewFechaActual(12, 12, 2019);
    interfazSubeYBaja->altaPublicacion("casasur123", 6, Venta, "Apartamento en Bulevar Artigas piso 3 muy luminoso y moderno.", 375000);

    interfazFechaActual->setNewFechaActual(12, 6, 2020);
    interfazSubeYBaja->altaPublicacion("casasur123", 2, Venta, "Excelente apartamento en Av. Brasil con 75 m ideal para reforma.", 390000);

    interfazFechaActual->setNewFechaActual(20, 7, 2020);
    interfazSubeYBaja->altaPublicacion("vivaurbana", 6, Alquiler, "Apartamento 68 m en Bulevar Artigas tercer piso sin ascensor.", 23000);

    interfazFechaActual->setNewFechaActual(4, 3, 2022);
    interfazSubeYBaja->altaPublicacion("vivaurbana", 4, Alquiler, "Apartamento con ascensor en Colonia 1542 piso 12 excelente conectividad.", 26000);

    interfazFechaActual->setNewFechaActual(12, 9, 2022);
    interfazSubeYBaja->altaPublicacion("vivaurbana", 3, Alquiler, "Casa excelente en Camino Maldonado de 95 m con patio al fondo.", 27000);

    interfazFechaActual->setNewFechaActual(1, 10, 2023);
    interfazSubeYBaja->altaPublicacion("idealhome", 1, Venta, "Casa en Av. Rivera de 120 m con techo plano ideal para familia.", 520000);

    interfazFechaActual->setNewFechaActual(18, 10, 2023);
    interfazSubeYBaja->altaPublicacion("idealhome", 7, Alquiler, "Apartamento amplio en Sarmiento 1476 piso 6 con ascensor.", 32000);

    interfazFechaActual->setNewFechaActual(19, 10, 2023);
    interfazSubeYBaja->altaPublicacion("idealhome", 7, Venta, "Apartamento de 80 m en Sarmiento excelente estado y vista.", 455000);

    interfazFechaActual->setNewFechaActual(20, 11, 2023);
    interfazSubeYBaja->altaPublicacion("idealhome", 7, Alquiler, "Apartamento con gran vista a la rambla", 31000);

    interfazFechaActual->setNewFechaActual(20, 11, 2023);
    interfazSubeYBaja->altaPublicacion("idealhome", 7, Venta, "Apartamento en excelentes condiciones de 80 m", 450000);

    interfazFechaActual->setNewFechaActual(8, 3, 2024);
    interfazSubeYBaja->altaPublicacion("vivaurbana", 3, Venta, "Venta de casa en Camino Maldonado 95 m bien distribuidos.", 430000);

    interfazFechaActual->setNewFechaActual(5, 5, 2024);
    interfazSubeYBaja->altaPublicacion("idealhome", 7, Alquiler, "Alquiler en Sarmiento 80 m piso alto con excelentes terminaciones.", 33000);

    interfazFechaActual->setNewFechaActual(1, 8, 2024);
    interfazSubeYBaja->altaPublicacion("idealhome", 6, Venta, "A estrenar en Bulevar Artigas 871 apartamento moderno.", 400000);

    // Suscripciones a Inmobiliarias
    set<string> casasur123;
    casasur123.insert("casasur123");
    set<string> idealhome;
    idealhome.insert("idealhome");
    set<string> vivaurbana;
    vivaurbana.insert("vivaurbana");

    interfazSuscripciones->suscribirse("luisito23", casasur123);
    interfazSuscripciones->suscribirse("luisito23", idealhome);
    interfazSuscripciones->suscribirse("anarojo88", casasur123);
    interfazSuscripciones->suscribirse("anarojo88", idealhome);
    interfazSuscripciones->suscribirse("anarojo88", vivaurbana);
    interfazSuscripciones->suscribirse("marcelom", idealhome);
    interfazSuscripciones->suscribirse("robertarce", idealhome);
    interfazSuscripciones->suscribirse("soledadf", vivaurbana);
    interfazSuscripciones->suscribirse("martagal", vivaurbana);
    interfazSuscripciones->suscribirse("jorge88", casasur123);
    interfazSuscripciones->suscribirse("jorge88", idealhome);
    interfazSuscripciones->suscribirse("jorge88", vivaurbana);
}

CargaDatos *CargaDatos::getInstancia()
{
    if (instancia == 0)
    {
        instancia = new CargaDatos();
    }
    return instancia;
}