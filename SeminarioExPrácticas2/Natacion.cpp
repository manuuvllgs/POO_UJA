//
// Created by Manuel Villegas Aceituno on 8/5/24.
//

#include "Natacion.h"

Natacion::Natacion(int hIni, int dur, int pMx, int pMn, int pM
        , std::string desc, std::string sens, int longitudPiscina, int numLargos) : Actividad(hIni,dur,pMx,pMn,pM,desc,sens), _longitudPiscina(longitudPiscina), _numLargos(numLargos)
        {
    if (longitudPiscina < 0){
        throw NatacionEx("[Natacion::Natacion] se ha pasado una longitud de piscina negativa");
    }
            if (numLargos < 0){
                throw NatacionEx("[Natacion::Natacion] se ha pasado un numero de largos negativo");
            }
}



int Natacion::getLongitudPiscina() const {
    return _longitudPiscina;
}

void Natacion::setLongitudPiscina(int longitudPiscina) {
    _longitudPiscina = longitudPiscina;
}

int Natacion::getNumLargos() const {
    return _numLargos;
}

void Natacion::setNumLargos(int numLargos) {
    _numLargos = numLargos;
}

Natacion::Natacion(const Natacion& orig): Actividad(orig), _numLargos(orig._numLargos),_longitudPiscina(orig._longitudPiscina) {}

int Natacion::getPulsoNormalizado() {
    return Actividad::getPulsoNormalizado()*1.1;
}
