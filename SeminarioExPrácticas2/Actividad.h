//
// Created by algarcia on 8/03/23.
//

#ifndef G1_RESUELTO_ACTIVIDAD_H
#define G1_RESUELTO_ACTIVIDAD_H

#include <string>

#include "Ubicacion.h"

class Actividad
{
   private:
      int _horaInicio = 0;
      int _duracionSegs = 0;
      int _pulsoMax = 0;
      int _pulsoMin = 0;
      int _pulsoMedio = 0;
      std::string _descripcion = "";
      std::string _sensaciones = "";
      Ubicacion* _lugar = nullptr;

   public:
      Actividad () = default;
      Actividad ( int hIni, int dur, int pMx, int pMn, int pM
                , std::string desc, std::string sens );
      Actividad ( const Actividad& orig ) = default;
      ~Actividad ();
      int getHoraInicio () const;
      void setHoraInicio ( int horaInicio );
      int getDuracionSegs () const;
      void setDuracionSegs ( int duracionSegs );
      int getPulsoMax () const;
      void setPulsoMax ( int pulsoMax );
      int getPulsoMin () const;
      void setPulsoMin ( int pulsoMin );
      int getPulsoMedio () const;
      void setPulsoMedio ( int pulsoMedio );
      virtual int getPulsoNormalizado ();
      const std::string &getDescripcion () const;
      void setDescripcion ( const std::string &descripcion );
      const std::string &getSensaciones () const;
      void setSensaciones ( const std::string &sensaciones );
      Ubicacion& getLugar () const;
      void setLugar ( Ubicacion& lugar );
};

#endif //G1_RESUELTO_ACTIVIDAD_H
