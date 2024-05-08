//
// Created by algarcia on 8/03/23.
//

#ifndef G1_RESUELTO_UBICACION_H
#define G1_RESUELTO_UBICACION_H

#include <string>

class Ubicacion
{
   private:
      std::string _descripcion = "";

   public:
      Ubicacion () = default;
      Ubicacion (const Ubicacion& orig) = default;
      ~Ubicacion() = default;
      const std::string &getDescripcion () const;
      void setDescripcion ( const std::string &descripcion );
};

#endif //G1_RESUELTO_UBICACION_H
