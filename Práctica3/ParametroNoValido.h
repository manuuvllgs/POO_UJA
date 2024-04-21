//
// Created by Manuel Villegas Aceituno on 21/2/24.
//

#ifndef PROJECT_PARAMETRONOVALIDO_H
#define PROJECT_PARAMETRONOVALIDO_H
#include <iostream>


class ParametroNoValido {
private:
    std::string origen; ///< Nombre de la función o clase::método desde el que se realiza el throw.
    std::string descripcion; ///< Una descripción explicando qué parámetro no es válido y por qué
public:
    ParametroNoValido(std::string origen, std::string descripcion);
    std::string queOcurre();
};


#endif //PROJECT_PARAMETRONOVALIDO_H
