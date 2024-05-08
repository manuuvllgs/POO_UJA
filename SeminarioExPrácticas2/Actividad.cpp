//
// Created by algarcia on 8/03/23.
//

#include "Actividad.h"

#include <stdexcept>

Actividad::Actividad ( int hIni, int dur, int pMx, int pMn, int pM
                     , std::string desc, std::string sens ): _horaInicio ( hIni )
                                                           , _duracionSegs ( dur )
                                                           , _pulsoMax ( pMx )
                                                           , _pulsoMin ( pMn )
                                                           , _pulsoMedio ( pM )
                                                           , _descripcion ( desc )
                                                           , _sensaciones ( sens )
{}

Actividad::~Actividad ()
{
   _lugar = nullptr;
}

int Actividad::getHoraInicio () const
{
   return _horaInicio;
}

void Actividad::setHoraInicio ( int horaInicio )
{
   _horaInicio = horaInicio;
}

int Actividad::getDuracionSegs () const
{
   return _duracionSegs;
}

void Actividad::setDuracionSegs ( int duracionSegs )
{
   _duracionSegs = duracionSegs;
}

int Actividad::getPulsoMax () const
{
   return _pulsoMax;
}

void Actividad::setPulsoMax ( int pulsoMax )
{
   _pulsoMax = pulsoMax;
}

int Actividad::getPulsoMin () const
{
   return _pulsoMin;
}

void Actividad::setPulsoMin ( int pulsoMin )
{
   _pulsoMin = pulsoMin;
}

int Actividad::getPulsoMedio () const
{
   return _pulsoMedio;
}

void Actividad::setPulsoMedio ( int pulsoMedio )
{
   _pulsoMedio = pulsoMedio;
}

int Actividad::getPulsoNormalizado ()
{
   return _pulsoMedio;
}

const std::string &Actividad::getDescripcion () const
{
   return _descripcion;
}

void Actividad::setDescripcion ( const std::string &descripcion )
{
   _descripcion = descripcion;
}

const std::string &Actividad::getSensaciones () const
{
   return _sensaciones;
}

void Actividad::setSensaciones ( const std::string &sensaciones )
{
   _sensaciones = sensaciones;
}

Ubicacion& Actividad::getLugar () const
{
   return *_lugar;
}

void Actividad::setLugar ( Ubicacion& lugar )
{
   if ( lugar.getDescripcion() == "" )
   {
      throw std::invalid_argument ( "Actividad::setLugar: ubicación incompleta" );
   }

   _lugar = &lugar;
}
