//
// Created by Manuel Villegas Aceituno on 13/3/24.
//

#include "Escuadron.h"
#include <string>
#include <sstream>



float Escuadron::promedioMisiones() {
    float promedio;
    for (int  i=0; i < this->_numPilotos; ++i){
        promedio += this->_pilotosEscuadron[i]->getNumMisiones();
    }
    promedio = promedio/this->_numPilotos;
    return promedio;
}

void Escuadron::fromCSV (std::string &datos){
    std::stringstream ss;
    ss<<datos;

    getline(ss, _nombre, ';');
    ss >> _numPilotos; ss.ignore(1);
    getline (ss, _base, ';');
}

const std::string &Escuadron::getNombre() const {
    return _nombre;
}

Escuadron Escuadron::setNombre(const std::string &nombre) {
    _nombre = nombre;

    return (*this);
}

int Escuadron::getNumPilotos() const {
    return this->_numPilotos;
}


const std::string &Escuadron::getBase() const {
    return _base;
}

Escuadron Escuadron::setBase(const std::string &base) {
    _base = base;
    return (*this);
}

Piloto *const *Escuadron::getPilotosEscuadron() const {
    return _pilotosEscuadron;
}

void Escuadron::addPiloto (Piloto *p1) {
    if (_numPilotos == _MAX_PILOTOS) {
        throw std::invalid_argument("Escuadron::nuevoPiloto: no se permiten aniadir mas pilotos al escuadron");
    }
        try {
            _pilotosEscuadron[_numPilotos] = p1;
            ++this->_numPilotos;
        } catch (std::invalid_argument &ia){

        }

}

void Escuadron::removePiloto (Piloto *p1){
    for (int i=0; i < _numPilotos; ++i){
        if (this->_pilotosEscuadron[i] == p1)
            this->_pilotosEscuadron[i] = nullptr;
        --this->_numPilotos;
        }
}

int Escuadron::numPilotos(std::string origen){
    int toRet=0;
    for (int i=0; i < _numPilotos; ++i){
        if (_pilotosEscuadron[i]->getNacionalidad() == origen){
            ++toRet;
        }
    }
    return toRet;
}
