//
// Created by admin on 08/04/2024.
//

#ifndef G7_ABRIL_UJAHEALTH_INI_PACIENTE_H
#define G7_ABRIL_UJAHEALTH_INI_PACIENTE_H
#include <iostream>
#include "Cita.h"


class Paciente {
public: static const int _MAX_CITAS = 100;
private:
    std::string _nombre = ""; ///< Nombre del paciente
    std::string _dni=""; ///< DNI del paciente
    int _edad=0; ///< Edad del paciente
    int _numCitas=0; ///< Numero de citas del paciente
    Cita *_citasPaciente[_MAX_CITAS]; ///< Citas del paciente
public:
    const std::string &getNombre() const;

    Paciente& setNombre(const std::string &nombre);

    const std::string &getDni() const;

    Paciente& setDni(const std::string &dni);

    int getEdad() const;

    Paciente& setEdad(int edad);

    int getNumCitas() const;

    Paciente (std::string dni);

    Paciente();

    explicit Paciente(const std::string &dni);

    Paciente(const Paciente &orig);

    void addCita(Cita cita);

    Cita *getCita(int pos);

    virtual ~Paciente();

    Cita* getMayorDuracion();
};


#endif //G7_ABRIL_UJAHEALTH_INI_PACIENTE_H
