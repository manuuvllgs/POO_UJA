//
// Created by Manuel Villegas Aceituno on 24/4/24.
//

#ifndef PROJECT_PR8_ESPADA_H
#define PROJECT_PR8_ESPADA_H
#include "Item.h"

class Espada: public Item {
public:
    Espada();

    virtual std::string getDescripcion() override;

    virtual ~Espada();

};


#endif //PROJECT_PR8_ESPADA_H
