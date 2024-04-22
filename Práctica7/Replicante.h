//
// Created by Manuel Villegas Aceituno on 22/4/24.
//

#ifndef PROJECT_PR7_REPLICANTE_H
#define PROJECT_PR7_REPLICANTE_H

#include "Mutante.h"


class Replicante : public Mutante {
public:


    virtual float capacidadDestructivaTotal() const override;

    virtual void addPoder(const PoderPsiquico &poder) override;

    virtual void addPoderPsiquico(std::string nombre, std::string descripcion,
                          std::string afectaA, float capacidadD, float lucidez) override;

    Replicante();

    Replicante(Mutante orig);

    Replicante(std::string nombre, std::string apodo, int fechaN, std::string nacionalidad);

    ~Replicante() override;
};




#endif //PROJECT_PR7_REPLICANTE_H
