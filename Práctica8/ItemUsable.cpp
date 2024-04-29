//
// Created by Manuel Villegas Aceituno on 29/4/24.
//

#include "ItemUsable.h"

ItemUsable::ItemUsable(): _puntosEstado(10) {}

void ItemUsable::usar() {
    if (_puntosEstado == 0){
        throw std::overflow_error ("[ItemUsable::usar] puntos de estado = 0");
    }
    --_puntosEstado;
}

int ItemUsable::getPuntosEstado() const {
    return _puntosEstado;
}
