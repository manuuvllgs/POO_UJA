//
// Created by Manuel Villegas Aceituno on 24/4/24.
//

#include "ItemApilable.h"

ItemApilable::ItemApilable(int numElementos) : _numElementos(numElementos) {
    if (numElementos > MAX_ELEMENTOS || numElementos < MIN_ELEMENTOS){
        throw std::out_of_range ("[ItemApilable::ItemApilable] no se admite tal cantidad de objetos");
    }
}

ItemApilable::~ItemApilable() {

}

ItemApilable::ItemApilable(): _numElementos(1) {}

void ItemApilable::incrementaNumElementos(int cantidad) {
    if (_numElementos==MAX_ELEMENTOS || _numElementos + cantidad > MAX_ELEMENTOS){
        throw std::out_of_range ("[ItemApilable::incrementaNumElementos] no se pueden apilar mas objetos");
    } else {
        _numElementos += cantidad;
    }
}

void ItemApilable::decrementaNumElementos(int cantidad) {
    if (_numElementos==MIN_ELEMENTOS || _numElementos - cantidad < MIN_ELEMENTOS){
        throw std::out_of_range ("[ItemApilable::decrementaNumElementos] no ha sido posible retirar los objetos");
    } else {
        _numElementos -= cantidad;
    }
}

int ItemApilable::getNumElementos() const {
    return _numElementos;
}
