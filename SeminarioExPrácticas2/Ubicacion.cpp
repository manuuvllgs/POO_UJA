//
// Created by algarcia on 8/03/23.
//

#include "Ubicacion.h"

const std::string &Ubicacion::getDescripcion () const
{
   return _descripcion;
}

void Ubicacion::setDescripcion ( const std::string &descripcion )
{
   _descripcion = descripcion;
}
