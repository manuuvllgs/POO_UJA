/**
 * @file Mutante.cpp
 * @author algarcia
 *
 */

#include <stdexcept>
#include <sstream>

#include "Mutante.h"
#include "PoderFisico.h"
#include "PoderPsiquico.h"
#include "Poder.h"

Mutante::Mutante(string nombre, string apodo, int fechaN, string nacionalidad)
        : _nombreReal(nombre),
          _apodo(apodo),
          _fechaDeNacimiento(fechaN),
          _nacionalidad(nacionalidad) {

}

Mutante::Mutante(const Mutante &orig)
        : _nombreReal(orig._nombreReal),
          _apodo(orig._apodo),
          _fechaDeNacimiento(orig._fechaDeNacimiento),
          _nacionalidad(orig._nacionalidad) {

}

Mutante::~Mutante() {
    for (int i = 0; i < _numPoderes; ++i) {
        if (_poderesMutante[i] != nullptr) { delete _poderesMutante[i]; }
        _poderesMutante[i] = nullptr;
    }
}

Mutante &Mutante::setNombreReal(string nombreReal) {
    this->_nombreReal = nombreReal;
    return (*this);
}

string Mutante::getNombreReal() const {
    return _nombreReal;
}

Mutante &Mutante::setNacionalidad(string nacionalidad) {
    this->_nacionalidad = nacionalidad;
    return (*this);
}

string Mutante::getNacionalidad() const {
    return _nacionalidad;
}

Mutante &Mutante::setFechaDeNacimiento(int fechaDeNacimiento) {
    this->_fechaDeNacimiento = fechaDeNacimiento;
    return (*this);
}

int Mutante::getFechaDeNacimiento() const {
    return _fechaDeNacimiento;
}

Mutante &Mutante::setApodo(string apodo) {
    this->_apodo = apodo;
    return (*this);
}

string Mutante::getApodo() const {
    return _apodo;
}


/**@brief Representación CSV de un mutante
   @post  Genera la representación básica en CSV, sin incluir los poderes*/

string Mutante::toCSV() {
    std::stringstream aux;
    aux << "Nombre del mutante: " << _nombreReal << " ; "
        << "Apodo del mutante: " << _apodo << " ; "
        << "Fecha de nacimiento del mutante: " << _fechaDeNacimiento << " ; "
        << "Nacionalidad del mutante: " << _nacionalidad;

    return aux.str();
}

Mutante &Mutante::operator=(const Mutante &orig) {
    if (this != &orig) {
        _nombreReal = orig._nombreReal;
        _apodo = orig._apodo;
        _fechaDeNacimiento = orig._fechaDeNacimiento;
        _nacionalidad = orig._nacionalidad;

    }

    return *this;
}

void Mutante::addPoder(std::string nombre, std::string descripcion, std::string afectaA, float capacidadD) {
    if (_numPoderes == MAX_PODERES) {
        throw std::invalid_argument("[Mutante::addPoder] no se admiten mas poderes en el mutante");
    }
    _poderesMutante[_numPoderes] = new Poder(nombre, descripcion, afectaA, capacidadD);
    ++_numPoderes;
}

void Mutante::removePoder(int pos) {
    if (pos < 0 || pos > _numPoderes) {
        throw std::invalid_argument("[Mutante::removePoder] la posicion de poder dada no existe en este mutante");
    } else {
        delete _poderesMutante[pos];
        _poderesMutante[pos] = nullptr;
        for (int i=pos; i < _numPoderes ; ++i){
            _poderesMutante[i] = _poderesMutante[i+1];
        }
    }
    --_numPoderes;

}

float Mutante::capacidadDestructivaTotal() {
    float toRet = 0;
    for (int i = 0; i < _numPoderes; ++i) {
        toRet += _poderesMutante[i]->getCapacidadDestructiva();
    }
    return toRet;
}

void Mutante::addPoderFisico(std::string nombre, std::string descripcion, std::string afectaA, float capacidadD) {
    if (_numPoderes == MAX_PODERES) {
        throw std::invalid_argument("[Mutante::addPoder] no se admiten mas poderes en el mutante");
    }
    _poderesMutante[_numPoderes] = new PoderFisico(nombre, descripcion, afectaA, capacidadD);
    ++_numPoderes;
}

void Mutante::addPoderPsiquico(std::string nombre, std::string descripcion, std::string afectaA, float capacidadD) {
    if (_numPoderes == MAX_PODERES) {
        throw std::invalid_argument("[Mutante::addPoder] no se admiten mas poderes en el mutante");
    }
    _poderesMutante[_numPoderes] = new PoderPsiquico(nombre, descripcion, afectaA, capacidadD);
    ++_numPoderes;
}

void Mutante::addPoder(const Poder &orig) {
    if (_numPoderes == MAX_PODERES) {
        throw std::invalid_argument("[Mutante::addPoder] no se admiten mas poderes en el mutante");
    }
    _poderesMutante[_numPoderes] = new Poder(orig);
    ++_numPoderes;
}

void Mutante::addPoderFisico(const PoderFisico &orig) {
    if (_numPoderes == MAX_PODERES) {
        throw std::invalid_argument("[Mutante::addPoder] no se admiten mas poderes en el mutante");
    }
    _poderesMutante[_numPoderes] = new PoderFisico(orig);
    ++_numPoderes;
}

void Mutante::addPoderPsiquico(const PoderPsiquico &orig) {
    if (_numPoderes == MAX_PODERES) {
        throw std::invalid_argument("[Mutante::addPoder] no se admiten mas poderes en el mutante");
    }
    _poderesMutante[_numPoderes] = new PoderPsiquico(orig);
    ++_numPoderes;
}

Poder *Mutante::getPoderesMutante(int pos) {
    return _poderesMutante[pos];
}

int Mutante::getNumPoderes() const {
    return _numPoderes;
}
