/** @file Medico.h
 * @author POOUJA
 */

#ifndef G7_ABRIL_UJAHEALTH_INI_MEDICO_H
#define G7_ABRIL_UJAHEALTH_INI_MEDICO_H

#include <string>

class Medico {
private:
    std::string _nombre; /// < Nombre del médico
    std::string _dni; /// < DNI del médico
    std::string _especialidad; /// < Especialidad del médico
    int _numConsulta = 0; /// < Número de consulta del médico

public:
    Medico(const std::string &nombre, const std::string &dni, const std::string &especialidad, int numConsulta);
    Medico(const Medico &orig) = default;
    ~Medico();

    const std::string &getNombre() const;
    void setNombre(const std::string &nombre);

    const std::string &getDni() const;
    void setDni(const std::string &dni);

    const std::string &getEspecialidad() const;
    void setEspecialidad(const std::string &especialidad);

    int getNumConsulta() const;
    void setNumConsulta(int numConsulta);
};


#endif //G7_ABRIL_UJAHEALTH_INI_MEDICO_H
