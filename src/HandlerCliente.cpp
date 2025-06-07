#include "HandlerCliente.h"

HandlerCliente* HandlerCliente::instancia = nullptr;

HandlerCliente::HandlerCliente() {}

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
    for (auto& par : clientes) {
        delete par.second;
    }
}