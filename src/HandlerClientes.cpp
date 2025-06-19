#include "../include/HandlerClientes.h"

using namespace std;

HandlerClientes *HandlerClientes:: instancia = NULL;

HandlerClientes::HandlerClientes(){
    map<string, Cliente*> coleccionClientes;
    this->coleccionClientes = coleccionClientes;
};

HandlerClientes* HandlerClientes::getInstancia(){
    if(instancia == NULL)
        instancia = new HandlerClientes();
    return instancia;
};

void HandlerClientes::agregarCliente(Cliente* &cliente){
    coleccionClientes[cliente->getNickname()] = cliente;
};

void HandlerClientes::eliminarCliente(string nickname){
    map<string, Cliente*>::iterator it = this->coleccionClientes.find(nickname);
    if(it != coleccionClientes.end()){
        delete it->second;
        coleccionClientes.erase(it);
    }
};

bool HandlerClientes::existeCliente(string nickname){
    return this->coleccionClientes.find(nickname) != this->coleccionClientes.end();
};

Cliente* HandlerClientes::getCliente(string nickname){
    if(this->coleccionClientes.count(nickname) > 0)
        return this->coleccionClientes[nickname];
    return nullptr;
};

map<string, Cliente*> HandlerClientes:: getColeccionClientes(){
    return this->coleccionClientes;
};

HandlerClientes::~HandlerClientes(){
    map<string, Cliente*>::iterator it;
    for(it = this->coleccionClientes.begin(); it != this->coleccionClientes.end(); it++){
        delete it->second;
    }
    this->coleccionClientes.clear();
};