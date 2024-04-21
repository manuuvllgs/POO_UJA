//
// Created by Manuel Villegas Aceituno on 21/2/24.
//

#include "ParametroNoValido.h"
#include <sstream>

/**
 * @brief Constructor parametrizado de clase ParametroNoValido
 * @author Manuel Villegas Aceituno
 * @date 23/02/2024
 * @param _origen
 * @param _descripcion
 * @ese ParametroNoValido.cpp
 */

ParametroNoValido::ParametroNoValido(std::string _origen, std::string _descripcion) {
    this->origen = _origen;
    this->descripcion = _descripcion;

}

/**
 * @brief Funcion que modifica los atributos de un dato tipo Garito que se le pasa
 * @author Manuel Villegas Aceituno
 * @date 23/02/2024
 * @pre Se debe llamar con un dato tipo ParametroNoValido
 * @post Se modifican los atributos del dato tipo Garito que se le pasa
 * @ese ParametroNoValido.cpp
 */

std::string ParametroNoValido::queOcurre() {
    std::string queOcurre;
    queOcurre = this->origen + ": " + this->descripcion;
    return queOcurre;
}
