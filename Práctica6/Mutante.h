/**
 * @file Mutante.h
 * @author algarcia
 *
 * @date 6 de abril de 2016, 19:52
 */

#ifndef MUTANTE_H
#define MUTANTE_H

#include <string>
#include "Poder.h"
#include "PoderPsiquico.h"
#include "PoderFisico.h"

using std::string;

/**
 * @brief Clase Muntante
 */
class Mutante {
public:
    static const int MAX_PODERES = 10; ///< Max. moderes de un mutante

public:
    Mutante() = default;
    Mutante(string nombre, string apodo, int fechaN,string nacionalidad);
    Mutante(const Mutante& orig);
    virtual ~Mutante();
    Mutante& setNombreReal(string nombreReal);
    string getNombreReal() const;
    Mutante& setNacionalidad(string nacionalidad);
    string getNacionalidad() const;
    Mutante& setFechaDeNacimiento(int fechaDeNacimiento);
    int getFechaDeNacimiento() const;
    Mutante& setApodo(string apodo);
    string getApodo() const;

    string toCSV();

    Mutante& operator=(const Mutante& orig);

    void addPoder(std::string nombre, std::string descripcion, std::string afectaA, float capacidadD);

    void removePoder(int pos);

    float capacidadDestructivaTotal();

    void addPoderFisico(std::string nombre, std::string descripcion, std::string afectaA, float capacidadD);

    void addPoderPsiquico(std::string nombre, std::string descripcion, std::string afectaA, float capacidadD);

    void addPoderFisico(const PoderFisico &orig);

    void addPoderPsiquico(const PoderPsiquico &orig);

    void addPoder(const Poder &orig);

    Poder *getPoderesMutante(int pos);

    int getNumPoderes() const;


private:
    string _nombreReal = "---";
    string _apodo = "---";
    int _fechaDeNacimiento = 0;
    string _nacionalidad = "---";
    Poder* _poderesMutante[MAX_PODERES];
    int _numPoderes = 0;
};

#endif /* MUTANTE_H */

