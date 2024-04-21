/** @file Cita.cpp
 * @author POOUJA
 */

#include "Cita.h"
#include <stdexcept>

Cita::Cita(const std::string &fecha, const std::string &hora, const std::string &motivo, int duracionMinutos)
        : _fecha(fecha), _hora(hora), _motivo(motivo), _duracionMinutos(duracionMinutos) {}

Cita::~Cita() {

}

const std::string &Cita::getFecha() const {
    return _fecha;
}

void Cita::setFecha(const std::string &fecha) {
    _fecha = fecha;
}

const std::string &Cita::getHora() const {
    return _hora;
}

void Cita::setHora(const std::string &hora) {
    _hora = hora;
}

const std::string &Cita::getMotivo() const {
    return _motivo;
}

void Cita::setMotivo(const std::string &motivo) {
    _motivo = motivo;
}

int Cita::getDuracionMinutos() const {
    return _duracionMinutos;
}

void Cita::setDuracionMinutos(int duracionMinutos) {
    _duracionMinutos = duracionMinutos;
}

Medico *Cita::getMedicoCita() const {
    return _medicoCita;
}

void Cita::setMedicoCita(Medico *medicoCita) {
    if (medicoCita->getDni() == ""){
        throw std::invalid_argument ("[Cita::setMedicoCita] el dni del medico que se intenta asociar no existe");
    }
        _medicoCita = medicoCita;
}
