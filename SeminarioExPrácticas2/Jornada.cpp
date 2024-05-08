//
// Created by algarcia on 8/03/23.
//

#include "Jornada.h"

#include <stdexcept>

Jornada::Jornada() : _fecha(0), _horasDeSuenyo(0), _peso(0), _nActividades(0) {
    for (int i = 0; i < MAX_ACTIVIDADES; i++) {
        _actividades[i] = nullptr;
    }
}

Jornada::Jornada(int f, float hds, float p) : _fecha(f), _horasDeSuenyo(hds), _peso(p), _nActividades(0) {
    for (int i = 0; i < MAX_ACTIVIDADES; i++) {
        _actividades[i] = nullptr;
    }
}

Jornada::Jornada(const Jornada &orig) : _fecha(orig._fecha), _horasDeSuenyo(orig._horasDeSuenyo), _peso(orig._peso),
                                        _nActividades(orig._nActividades) {
    int i = 0;

    for (; i < _nActividades; i++) {
        _actividades[i] = new Actividad(*orig._actividades[i]);
    }

    for (; i < MAX_ACTIVIDADES; i++) {
        _actividades[i] = nullptr;
    }
}

Jornada::~Jornada() {
    for (int i = 0; i < _nActividades; i++) {
        delete _actividades[i];
        _actividades[i] = nullptr;
    }
    _nActividades = 0;
}

int Jornada::getFecha() const {
    return _fecha;
}

void Jornada::setFecha(int fecha) {
    _fecha = fecha;
}

float Jornada::getHorasDeSuenyo() const {
    return _horasDeSuenyo;
}

void Jornada::setHorasDeSuenyo(float horasDeSuenyo) {
    _horasDeSuenyo = horasDeSuenyo;
}

float Jornada::getPeso() const {
    return _peso;
}

/**
 * M�todo para cambiar el peso del usuario en la jornada
 * @param[in] peso Nuevo valor de peso
 * @throw std::out_of_range Si el nuevo valor de peso es negativo
 * @post El peso del usuario en la jornada cambia al nuevo valor si es válido
 */
void Jornada::setPeso(float peso) {
    if (peso < 0) {
        throw std::out_of_range("Jornada::setPeso: el peso no puede ser negativo");
    }

    _peso = peso;
}

int Jornada::getNActividades() const {
    return _nActividades;
}

Actividad *Jornada::getActividad(unsigned int cual) {
    Actividad *toRet = nullptr;

    if (cual < _nActividades) {
        toRet = _actividades[cual];
    }

    return toRet;
}

void Jornada::addActividad(const Actividad &a) {
    if (_nActividades == MAX_ACTIVIDADES) {
        throw std::length_error("Jornada::addActividad: no caben m�s actividades");
    }

    _actividades[_nActividades] = new Actividad(a);
    _nActividades++;
}

int Jornada::totalEsfuerzo() {
    int toRet = 0;

    for (int i = 0; i < _nActividades; i++) {
        toRet += _actividades[i]->getDuracionSegs();
    }

    return toRet;
}

void Jornada::addActividad(const Natacion &a) {
    if (_nActividades == MAX_ACTIVIDADES) {
        throw std::length_error("Jornada::addActividad: no caben m�s actividades");
    }

    _actividades[_nActividades] = new Natacion(a);
    _nActividades++;
}

Actividad *Jornada::actividadMasIntensa() {
    int pos = 0;
    for (int i = 1; i < _nActividades; ++i) {
        if (this->_actividades[i]->getPulsoNormalizado() > this->_actividades[pos]->getPulsoNormalizado()) {
            pos = i;
        }
    }
    return _actividades[pos];
}
