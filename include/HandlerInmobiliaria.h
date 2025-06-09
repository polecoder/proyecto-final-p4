#ifndef HANDLERINMOBILIARIA_H
#define HANDLERINMOBILIARIA_H   

#include "Inmobiliaria.h"
#include <map>  
#include <string>
using namespace std;

class HandlerInmobiliaria {
private:      
    static HandlerInmobiliaria* instancia;
    map<string, Inmobiliaria*> inmobiliarias;

    HandlerInmobiliaria();
    public:
    static HandlerInmobiliaria* getInstancia(); 
    void agregarInmobiliaria(Inmobiliaria* inmobiliaria);
    Inmobiliaria* obtenerInmobiliaria(const string& nickname);  

    bool existeInmobiliaria(const string& nickname);        
    ~HandlerInmobiliaria();
};  

#endif // HANDLERINMOBILIARIA_H