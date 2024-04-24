//
// Created by Manuel Villegas Aceituno on 24/4/24.
//

#ifndef PROJECT_PR8_BLOQUE_H
#define PROJECT_PR8_BLOQUE_H
#include <iostream>
#include "Item.h"
#include "ItemApilable.h"


class Bloque: public ItemApilable{
public:
    virtual std::string getDescripcion() override;

    Bloque(): ItemApilable() {}

    Bloque(int cantidad): ItemApilable(cantidad) {}

    virtual ~Bloque();
};


#endif //PROJECT_PR8_BLOQUE_H
