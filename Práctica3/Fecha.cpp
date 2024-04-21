//
// Created by Manuel Villegas Aceituno on 21/2/24.
//

#include "Fecha.h"
#include <iostream>
#include "Temazo.h"

/**
 * @brief Constructor de la clase Fecha por defecto
 */

Fecha::Fecha() : dia(dia), mes(mes), anio(anio) {
    std::time_t t = std::time(0);
    std::tm *now = std::localtime(&t);
    this->dia = now->tm_mday;
    this->mes = now->tm_mon + 1;
    this->anio = now->tm_year + 1900;
}

/**
 * @brief constructor parametrizado de la clase Fecha
 * @param [in]_dia
 * @param [in]_mes
 * @param [in]_anio
 */

Fecha::Fecha(int _dia, int _mes, int _anio) {
    this->dia = _dia;
    this->mes = _mes;
    this->anio = _anio;
}

/**
 * @brief Constructor de copia de la clase Fecha
 * @param [in]orig
 */

Fecha::Fecha(const Fecha &orig) {
    this->dia = orig.dia;
    this->mes = orig.mes;
    this->anio = orig.anio;
}

/**
 * @brief Get del atributo dia de la clase Fecha
 * @return el atributo dia
 */

int Fecha::getDia() const {
    return dia;
}

/**
 * @brief Set del atributo dia de la clase Fecha
 * @param [in] dia
 */

void Fecha::setDia(int dia) {
    Fecha::dia = dia;
}

/**
 * @brief Get del atributo mes de la clase Fecha
 * @return atributo mes
 */

int Fecha::getMes() const {
    return mes;
}

/**
 * @brief Set del atributo mes de la clase Fecha
 * @param [in]mes
 */

void Fecha::setMes(int mes) {
    Fecha::mes = mes;
}

/**
 * @brief Get del atributo anio de la clase Fecha
 * @return atributo anio
 */

int Fecha::getAnio() const {
    return anio;
}

/**
 * @brief Set del atributo anio de la clase
 * @param [in]anio
 */

void Fecha::setAnio(int anio) {
    Fecha::anio = anio;
}

/**
 * @brief Operador "menor que" de la clase Fecha
 * @param [in]f2
 * @return false si es mayor y true si es menor
 */

bool Fecha::operator<(const Fecha &f2) {
    if (this->getAnio() < f2.getAnio()){
        return true;
    } else if (this->getAnio() == f2.getAnio() && this->getMes() < f2.getMes()){
        return true;
    } else if (this->getAnio() == f2.getAnio() && this->getMes() == f2.getMes() && this->getDia() < f2.getDia()){
        return true;
    } else {
        return false;
    }
}

/**
 * @brief Operador "igual que" de la clase Fecha
 * @param [in]f2
 * @return false si no es igual y true si lo es
 */

bool Fecha::operator==(const Fecha &f2) {
    if (this->getAnio() == f2.getAnio() && this->getMes() == f2.getMes() && this->getDia() == f2.getDia()) {
        return true;
    } else return false;
}

/**
 * @brief Operador "menor o igual que" de la clase Fecha
 * @param [in]f2
 * @return false si es mayor y true si es menor o igual
 */

bool Fecha::operator<=(const Fecha &f2) {
    if (this->operator<(f2) || this->operator==(f2)) {
        return true;
    } else return false;
}

/**
 * @brief Operador "mayor que" de la clase Fecha
 * @param [in]f2
 * @return false si es menor y true si es mayor o igual
 */

bool Fecha::operator>=(const Fecha &f2){
    if (!(this->operator<(f2))){
        return true;
    } else if (this->operator==(f2)){
        return true;
    } else return false;
}

/**
 * @brief Operador "mayor que" de la clase Fecha
 * @param [in]f2
 * @return false si es menor y true si es mayor
 */

bool Fecha::operator>(const Fecha &f2){
    if (!(this->operator<(f2))){
        return true;
    } else return false;
}

/**
 * @brief Operador "desigual que" de la clase Fecha
 * @param [in]f2
 * @return false si es igual y true si es desigual
 */


bool Fecha::operator!=(const Fecha &f2){
    if (this->operator==(f2)){
        return false;
    } else return true;
}


