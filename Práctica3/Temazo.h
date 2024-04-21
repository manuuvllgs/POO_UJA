//
// Created by Manuel Villegas Aceituno on 21/2/24.
//

#ifndef PROJECT_TEMAZO_H
#define PROJECT_TEMAZO_H

#include <iostream>
#include "Fecha.h"


class Temazo {
private:
    std::string titulo;
    std::string interprete;
    int duracion; ///< se medira en segundos
    int puntuacion_del_publico;
    std::string nombreUltimoGarito;
    Fecha fechaUltimoUso;
public:
    const std::string &getNombreUltimoGarito() const;

    void setNombreUltimoGarito(const std::string &nombreUltimoGarito);

    const Fecha &getFechaUltimoUso() const;

    void setFechaUltimoUso(const Fecha &fechaUltimoUso);

public:
    Temazo();

    virtual ~Temazo();

    Temazo(std::string _titulo, std::string _interprete, int _duracion);

    const std::string &getTitulo() const;

    void setTitulo(const std::string &titulo);

    const std::string &getInterprete() const;

    void setInterprete(const std::string &interprete);

    int getDuracion() const;

    void setDuracion(int duracion);

    Temazo(const Temazo &orig);

    bool operator>(const Temazo &t2);
};



#endif //PROJECT_TEMAZO_H
