//
// Created by Manuel Villegas Aceituno on 8/5/24.
//

#ifndef G1_NATACION_H
#define G1_NATACION_H
#include "Actividad.h"
#include "NatacionEx.h"


class Natacion: public Actividad {
private:
    int _longitudPiscina = 0; ///< Longitud de la piscina
    int _numLargos = 0; ///< Numero de largos realizados
public:

    Natacion(int hIni, int dur, int pMx, int pMn, int pM
            , std::string desc, std::string sens, int longitudPiscina, int numLargos);

    int getLongitudPiscina() const;

    void setLongitudPiscina(int longitudPiscina);

    int getNumLargos() const;

    void setNumLargos(int numLargos);

    Natacion(const Natacion& orig);

    virtual int getPulsoNormalizado () override;
};


#endif //G1_NATACION_H
