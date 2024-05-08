//
// Created by algarcia on 8/03/23.
//

#ifndef G1_RESUELTO_JORNADA_H
#define G1_RESUELTO_JORNADA_H

#include "Actividad.h"
#include "Natacion.h"

#define MAX_ACTIVIDADES 10

class Jornada {
private:
    int _fecha = 0;
    float _horasDeSuenyo = 0;
    float _peso = 0;
    Actividad *_actividades[MAX_ACTIVIDADES];
    int _nActividades = 0;

public:
    Jornada();

    Jornada(int f, float hds, float p);

    Jornada(const Jornada &orig);

    ~Jornada();

    int getFecha() const;

    void setFecha(int fecha);

    float getHorasDeSuenyo() const;

    void setHorasDeSuenyo(float horasDeSuenyo);

    float getPeso() const;

    void setPeso(float peso);

    int getNActividades() const;

    Actividad *getActividad(unsigned int cual);

    void addActividad(const Actividad &a);

    void addActividad(const Natacion &a);

    Actividad *actividadMasIntensa();

    int totalEsfuerzo();
};

#endif //G1_RESUELTO_JORNADA_H
