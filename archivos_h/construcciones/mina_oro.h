#ifndef _MINA_ORO_H_
#define _MINA_ORO_H

#include "../edificio.h"

class Mina_oro : public Edificio{

public:
    /*
        * Post: Creará un objeto de tipo PlantaElectrica, dejando sus atributos cargados con valores por defecto.
        */
    Mina_oro();

    /*
        * Post: Creará un objeto de tipo PlantaElectrica con los parámetros recibidos.
        */
    Mina_oro(int piedra_necesaria, int metal_necesario, int madera_necesaria);
};

#endif // _MINA_ORO_H_