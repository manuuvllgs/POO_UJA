/**
 * @file Poder.h
 * @author algarcia
 *
 * @date 6 de abril de 2016, 19:52
 */

#ifndef PODER_H
#define PODER_H

#include <string>

/**
 * @brief
 */
class Poder {
private:
    std::string _nombre = "---";
    std::string _descripcion = "---";
    std::string _afectaA = "---";
    float _capacidadDestructiva = 0;

public:
    Poder() = default;

    Poder(std::string nmb, std::string dsc, std::string aA, float cD);

    Poder(const Poder &orig);

    virtual ~Poder();

    Poder &setNombre(std::string nombre);

    std::string getNombre() const;

    Poder &setCapacidadDestructiva(float capacidadDestructiva);

    virtual float getCapacidadDestructiva() const;

    Poder &setAfectaA(std::string afectaA);

    std::string getAfectaA() const;

    Poder &setDescripcion(std::string descripcion);

    std::string getDescripcion() const;

    virtual std::string toCSV() const;

    virtual void operator=(const Poder &orig);

    bool operator<(const Poder &orig);

};

#endif /* PODER_H */

