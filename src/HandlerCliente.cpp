#include "HandlerCliente.h"
#include "../include/Cliente.h"
#include <map>

using namespace std;

HandlerCliente* HandlerCliente::instancia = nullptr; //inicializar el puntero estático a nullptr, me lo dijo mi amigo que lo agregue (copilot)

HandlerCliente::HandlerCliente() {} //El credor va vacio

HandlerCliente* HandlerCliente::getInstancia() {
    if (!instancia)
        instancia = new HandlerCliente();
    return instancia;
}

void HandlerCliente::agregarCliente(Cliente* cliente) {
    std::string nick = cliente->getNickname();
    clientes[nick] = cliente;
}

Cliente* HandlerCliente::obtenerCliente(const std::string& nickname) {
    if (clientes.count(nickname))
        return clientes[nickname];
    return nullptr;
}

bool HandlerCliente::existeCliente(const std::string& nickname) {
    return clientes.count(nickname) > 0;
}

HandlerCliente::~HandlerCliente() {
    map<string, Cliente*>::iterator it;
    while (it != clientes.end()) {
        it = coleccionClientes.erase(it); // Eliminar el cliente del map
    }
}