/**
 * @file StarFighter.cpp
 * @author Casipro Gramo
 *
 * @date Fecha estelar 20160309
 */

#include <stdexcept>
#include <sstream>

#include "StarFighter.h"

using std::string;

int StarFighter::_numStarFighters = 0;

StarFighter::StarFighter() : StarFighter("", "") {
}

StarFighter::StarFighter(string marca, string modelo) :
        _marca(marca), _modelo(modelo) {
    _numStarFighters++;
    _idSF = _numStarFighters;
}

StarFighter::StarFighter(const StarFighter &orig) :
        _marca(orig._marca), _modelo(orig._modelo),
        _numPlazas(orig._numPlazas) {
    _numStarFighters++;
    _idSF = _numStarFighters;
}

StarFighter::~StarFighter() {
    for (int i = 0; i < _numPiezasNave; ++i) {
        if (_piezasNave[i] != nullptr) { delete (_piezasNave[i]); }
        _piezasNave[i] = nullptr;
    }
}

/**
 * @todo Aquí hay que añadir la comprobación del parámetro y lanzar la excepción
 *       correspondiente. El número de plazas no puede ser <= 0
 */
StarFighter &StarFighter::setNumPlazas(int numPlazas) {
    if (numPlazas <= 0) {
        throw std::invalid_argument("StarFighter::StarFighter: el número de"
                                    " plazas no puede ser negativo");
    }

    this->_numPlazas = numPlazas;
    return *this;
}

int StarFighter::getNumPlazas() const {
    return _numPlazas;
}

StarFighter &StarFighter::setModelo(string modelo) {
    this->_modelo = modelo;
    return *this;
}

string StarFighter::getModelo() const {
    return _modelo;
}

StarFighter &StarFighter::setMarca(string marca) {
    this->_marca = marca;
    return *this;
}

string StarFighter::getMarca() const {
    return _marca;
}

int StarFighter::getIdSF() const {
    return _idSF;
}

string StarFighter::toCSV() const {
    std::stringstream aux;

    aux << _marca << " ; "
        << _modelo << " ; "
        << _numPlazas;

    return aux.str();
}

StarFighter &StarFighter::operator=(const StarFighter &otro) {
    if (this != &otro) {
        _marca = otro._marca;
        _modelo = otro._modelo;
        _numPlazas = otro._numPlazas;
    }

    return *this;
}

void StarFighter::fromCSV(string &datos) {
    std::stringstream aux;

    aux << datos;

    getline(aux, _marca, ';');
    getline(aux, _modelo, ';');
    aux >> _numPlazas;
}

void StarFighter::addPieza(Pieza *p1) {
    if (_numPiezasNave == _MAX_PIEZAS) {
        throw std::invalid_argument("StarFighter::nuevaPieza: no se pueden aniadir mas piezas a la nave");
    }
    else {
        _piezasNave[_numPiezasNave] = p1;
        ++_numPiezasNave;
    }
}

void StarFighter::removePieza(int pos_pieza) {
    if (pos_pieza < 0 || pos_pieza > _numPiezasNave){
        throw std::out_of_range ("[StarFighter::removePieza]: se esta pasando una posicion de pieza que no existe");
    } else {
        if (_piezasNave[pos_pieza] != nullptr) {
            delete _piezasNave[pos_pieza];
            _piezasNave[pos_pieza] = nullptr;
        }
    }
}

float StarFighter::calculaPeso() {
    float peso;
    for (int i = 0; i < _numPiezasNave; ++i) {
        peso += this->_piezasNave[i]->getPeso();
    }
    return peso;
}

int StarFighter::getNumStarFighters() {
    return _numStarFighters;
}

void StarFighter::setNumStarFighters(int numStarFighters) {
    _numStarFighters = numStarFighters;
}

int StarFighter::getIdSf() const {
    return _idSF;
}

void StarFighter::setIdSf(int idSf) {
    _idSF = idSf;
}

int StarFighter::getNumPiezasNave() const {
    return _numPiezasNave;
}

void StarFighter::setNumPiezasNave(int numPiezasNave) {
    _numPiezasNave = numPiezasNave;
}

Pieza *const *StarFighter::getPiezasNave() const {
    return _piezasNave;
}
