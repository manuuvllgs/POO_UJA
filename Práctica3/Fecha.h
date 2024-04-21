//
// Created by Manuel Villegas Aceituno on 21/2/24.
//

#ifndef PROJECT_FECHA_H
#define PROJECT_FECHA_H

#include <ctime>


class Fecha {
private:
    int dia, mes, anio;
public:
    Fecha();

    Fecha(int dia, int mes, int anio);

    Fecha(const Fecha &orig);

    int getDia() const;

    void setDia(int dia);

    int getMes() const;

    void setMes(int mes);

    int getAnio() const;

    void setAnio(int anio);

    bool operator<(const Fecha &f2);

    bool operator==(const Fecha &f2);

    bool operator<=(const Fecha &f2);

    bool operator>=(const Fecha &f2);

    bool operator>(const Fecha &f2);

    bool operator!=(const Fecha &f2);
};

#endif //PROJECT_FECHA_H
