//
// Created by Manuel Villegas Aceituno on 11/4/24.
//

#include "Poder.h"
#include <sstream>

const std::string &Poder::getNombre() const {
    return _nombre;
}

void Poder::setNombre(const std::string &nombre) {
    _nombre = nombre;
}

const std::string &Poder::getDescripcion() const {
    return _descripcion;
}

void Poder::setDescripcion(const std::string &descripcion) {
    _descripcion = descripcion;
}

const std::string &Poder::getAfectaA() const {
    return _afectaA;
}

void Poder::setAfectaA(const std::string &afectaA) {
    _afectaA = afectaA;
}

float Poder::getCapacidadDestructiva() const {
    return _capacidadDestructiva;
}

void Poder::setCapacidadDestructiva(float capacidadDestructiva) {
    _capacidadDestructiva = capacidadDestructiva;
}

Poder::~Poder() {
}

Poder::Poder(const std::string &nombre, const std::string &descripcion, const std::string &afectaA,
             float capacidadDestructiva) : _nombre(nombre), _descripcion(descripcion), _afectaA(afectaA),
                                           _capacidadDestructiva(capacidadDestructiva) {}


void Poder::operator=(const Poder &orig) {
    if (this != &orig) {
        _nombre = orig._nombre;
        _descripcion = orig._descripcion;
        _afectaA = orig._afectaA;
        _capacidadDestructiva = orig._capacidadDestructiva;
    }
}

Poder::Poder(const Poder &orig) : _nombre(orig._nombre), _descripcion(orig._descripcion), _afectaA(orig._afectaA),
                                  _capacidadDestructiva(orig._capacidadDestructiva) {}


std::string Poder::toCSV(const Poder &orig) {
    std::stringstream toRet;
    toRet << _nombre << " ; " << _descripcion << " ; " << _afectaA << " ; " << _capacidadDestructiva;
    return toRet.str();
}

Poder::Poder() {}
