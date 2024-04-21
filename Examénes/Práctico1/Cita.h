/** @file Cita.h
 * @author POOUJA
 */

#ifndef G7_ABRIL_UJAHEALTH_INI_CITA_H
#define G7_ABRIL_UJAHEALTH_INI_CITA_H

#include <string>
#include "Medico.h"

class Cita {
private:
    std::string _fecha; /// < Fecha de la cita (DDMMAAAA)
    std::string _hora; /// < Hora de la cita (HHMMSS)
    std::string _motivo; /// < Motivo de la cita
    int _duracionMinutos = 0; /// < Duración en minutos de la cita
    Medico *_medicoCita = nullptr; ///< Medico que ha llevado la cita
public:
    Medico *getMedicoCita() const;

    void setMedicoCita(Medico *medicoCita);

public:
    Cita(const std::string &fecha, const std::string &hora, const std::string &motivo, int duracionMinutos);
    ~Cita();

    const std::string &getFecha() const;
    void setFecha(const std::string &fecha);

    const std::string &getHora() const;
    void setHora(const std::string &hora);

    const std::string &getMotivo() const;
    void setMotivo(const std::string &motivo);

    int getDuracionMinutos() const;
    void setDuracionMinutos(int duracionMinutos);
};


#endif //G7_ABRIL_UJAHEALTH_INI_CITA_H
