//
// Created by Manuel Villegas Aceituno on 13/3/24.
//

#ifndef PRUEBA_ESCUADRON_H
#define PRUEBA_ESCUADRON_H

#include <iostream>
#include "Piloto.h"


class Escuadron {
public:
    static const int _MAX_PILOTOS=50;
private:
    std::string _nombre = ""; ///< Nombre del escuadron
    int _numPilotos=0; ///< Numero de pilotos que forman el escuadron
    std::string _base = ""; ///< Base del escuadron
    Piloto *_pilotosEscuadron[_MAX_PILOTOS]; ///< Pilotos que forman el escuadron
public:
    float promedioMisiones();

    void fromCSV(std::string &datos);

    const std::string &getNombre() const;

    Escuadron setNombre(const std::string &nombre);

    int getNumPilotos() const;

    Escuadron setNumPilotos(int numPilotos);

    const std::string &getBase() const;

    Escuadron setBase(const std::string &base);

    Piloto *const *getPilotosEscuadron() const;

    void addPiloto(Piloto *p1);

    void removePiloto(Piloto *p1);

    int numPilotos(std::string origen);
};


#endif //PRUEBA_ESCUADRON_H
