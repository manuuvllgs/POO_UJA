//
// Created by Manuel Villegas Aceituno on 21/2/24.
//

#ifndef PROJECT_GARITO_H
#define PROJECT_GARITO_H
#include <iostream>


class Garito {
private:
    std::string nombre;
    std::string direccion;
public:
    Garito();
    Garito(std::string _nombre, std::string _direccion);
    Garito(const Garito &orig);

    const std::string &getNombre() const;

    void setNombre(const std::string &nombre);

    const std::string &getDireccion() const;

    void setDireccion(const std::string &direccion);

    virtual ~Garito();


};


#endif //PROJECT_GARITO_H
