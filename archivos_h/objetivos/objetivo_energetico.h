#ifndef _OBJETIVO_ENERGETICO_H
#define _OBJETIVO_ENERGETICO_H

#include "objetivo.h"

class Objetivo_energetico: public Objetivo{

    private:

        int cantidad_energia;

    public:

        /*
        *Post: Construira un objeto de tipo Objetivo_energetico, con sus valores por defecto.
        */
        Objetivo_energetico();

        /*
        *Post: Mostrará por consola el progreso.
        */
        void mostrar_progreso();

        /*
        *Post: Devolverá true si se termina el turno con 100 de energía, o false en caso contrario.
        */
        bool se_cumplio_el_objetivo(int cantidad);
};

#endif // _OBJETIVO_ENERGETICO_H_