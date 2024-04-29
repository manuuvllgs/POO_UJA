//
// Created by Manuel Villegas Aceituno on 29/4/24.
//

#ifndef PROJECT_PR8_ITEMUSABLE_H
#define PROJECT_PR8_ITEMUSABLE_H

#include "Item.h"

class ItemUsable : public Item {
private:
    int _puntosEstado = 10;
public:
    explicit ItemUsable();

    void usar();

    int getPuntosEstado() const;

};


#endif //PROJECT_PR8_ITEMUSABLE_H
