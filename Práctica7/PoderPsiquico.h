/**
 * @file PoderPsiquico.h
 * @author algarcia
 *
 * @date 6 de abril de 2016, 19:52
 */

#ifndef PODERPSIQUICO_H
#define PODERPSIQUICO_H

#include "Poder.h"

/**
 * @brief
 */
class PoderPsiquico : public Poder {
public:
    PoderPsiquico() = default;

    PoderPsiquico(std::string nmb, std::string dsc, std::string aA, float cD, float lucidez);

    PoderPsiquico(const PoderPsiquico &orig, float lucidez);

    virtual ~PoderPsiquico();

    virtual float getCapacidadDestructiva() const override;

    //ToDo, redefinir toCSV y getCapacidadDestructiva

private:
    //ToDo, añadir lucidez
    float _lucidez = 1; ///< Valores entre 0 y 1
public:
    float getLucidez() const;

    void setLucidez(float lucidez);

    virtual std::string toCSV() const override;

    virtual void operator=(const PoderPsiquico &orig) override;
};

#endif /* PODERPSIQUICO_H */

