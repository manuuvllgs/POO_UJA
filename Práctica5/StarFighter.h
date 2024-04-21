/**
 * @file StarFighter.h
 * @author Casipro Gramo
 *
 * @date Fecha estelar 20160309
 */

#ifndef STARFIGHTER_H
#define STARFIGHTER_H

#include <string>
#include "Pieza.h"

/**
 * @brief
 */
class StarFighter {
public:
    static const int _MAX_PIEZAS = 50;
private:
    static int _numStarFighters; ///< Número de objetos de esta clase instanciados
    int _idSF = 0; ///< Identificador único de la nave
    std::string _marca; ///< Marca de la nave (parece que las VW contaminan más)
    std::string _modelo; ///< Modelo de la nava
    int _numPlazas = 1; ///< Número de plazas de la nave
    int _numPiezasNave = 0;  ///< Numero de piezas que tiene la nave
    Pieza *_piezasNave[_MAX_PIEZAS]; ///< Piezas que contiene la nave
public:
    static int getNumStarFighters();

    static void setNumStarFighters(int numStarFighters);

    int getIdSf() const;

    void setIdSf(int idSf);

    int getNumPiezasNave() const;

    void setNumPiezasNave(int numPiezasNave);

    Pieza *const *getPiezasNave() const;

    StarFighter();

    StarFighter(std::string marca, std::string modelo);

    StarFighter(const StarFighter &orig);

    virtual ~StarFighter();

    StarFighter &setNumPlazas(int numPlazas);

    int getNumPlazas() const;

    StarFighter &setModelo(std::string modelo);

    std::string getModelo() const;

    StarFighter &setMarca(std::string marca);

    std::string getMarca() const;

    int getIdSF() const;

    std::string toCSV() const;

    StarFighter &operator=(const StarFighter &otro);

    void fromCSV(std::string &datos);

    void addPieza(Pieza *p1);

    void removePieza(int pos_pieza);

    float calculaPeso();
};

#endif /* STARFIGHTER_H */