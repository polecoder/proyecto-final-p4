#include "../include/HandlerCliente.h"
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

Cliente* HandlerCliente::obtenerCliente( string& nickname) {
    if (clientes.count(nickname))
        return clientes[nickname];
    return nullptr;
}

bool HandlerCliente::existeCliente( string& nickname) {
    return clientes.count(nickname) > 0;
}

HandlerCliente::~HandlerCliente() {
    auto it = clientes.begin();
    while (it != clientes.end()) {
        delete it->second; // Libera la memoria del Cliente*
        it = clientes.erase(it);
    }
}