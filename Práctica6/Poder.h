//
// Created by Manuel Villegas Aceituno on 11/4/24.
//

#ifndef PROJECT_PR6_PODER_H
#define PROJECT_PR6_PODER_H

#include <iostream>


class Poder {
    std::string _nombre = "";
    std::string _descripcion = "";
    std::string _afectaA = "";
    float _capacidadDestructiva = 0;
public:
    Poder(const std::string &nombre, const std::string &descripcion, const std::string &afectaA,
          float capacidadDestructiva);

    const std::string &getNombre() const;

    void setNombre(const std::string &nombre);

    const std::string &getDescripcion() const;

    void setDescripcion(const std::string &descripcion);

    const std::string &getAfectaA() const;

    void setAfectaA(const std::string &afectaA);

    float getCapacidadDestructiva() const;

    void setCapacidadDestructiva(float capacidadDestructiva);

    virtual ~Poder();

    void operator=(const Poder &orig);

    Poder(const Poder &orig);

    std::string toCSV(const Poder &orig);

    Poder();
};


#endif //PROJECT_PR6_PODER_H
