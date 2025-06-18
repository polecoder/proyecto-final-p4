
#ifndef DTUSUARIO_H
#define DTUSUARIO_H
#include <string>

class DTUsuario {
    private:
        std::string nickname;
        std::string nombre;

    public:
        DTUsuario(std::string nickname, std::string nombre);
        std::string getNickname() const;
        std::string getNombre() const;
        // necesito que sea const para que compile
        bool operator<(const DTUsuario& other) const;
};

#endif