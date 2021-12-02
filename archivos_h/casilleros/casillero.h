#ifndef _CASILLERO_H_
#define _CASILLERO_H_

#include "../construcciones/edificio.h"
#include "../materiales/material.h"
#include "../jugador.h"

class Casillero{

    protected:

        char tipo_terreno;
        std::string codigo_color;

    public:

        /*
        *Post: Creará un objeto de tipo Casillero, dejando sus atributos cargados con valores por defecto.
        */
        Casillero();

        /*
        *Post: Devolverá el tipo de terreno del casillero.
        */
        char obtener_tipo_de_terreno();

        /*
        *Post: Devolverá el codigo del color del casillero.
        */
        std::string obtener_color();

        /*
        *Post: Hace que las clases hijas muestren el casillero, según sea el comportamiento de cada hija.
        */
        virtual void mostrar() = 0;

        /*
        *Post: Hace que las clases hijas devuelvan el puntero a un edificio, según sea el comportamiento de cada hija.
        */
        virtual Edificio* obtener_puntero_edificio();

        /*
        *Post:
        */
        virtual Jugador* obtener_puntero_jugador();

        /*
        *Post: Hace que las clases hijas devuelvan el puntero a un material, según sea el comportamiento de cada hija.
        */
        virtual Material* obtener_puntero_material();

        /*
        *Post: Devolvera true si esta ocupado el casillero, o false en caso contrario.
        */
        virtual bool esta_ocupado();

        /*
        *Pre: Que el parámetro material_a_agregar no sea null.
        *Post: Hace que las clases hijas agreguen un material, según sea el comportamiento de cada hija.
        */
        virtual void agregar_material(Material* material_a_agregar);

        /*
        *Pre: Que el parametro edificio_a_agregar no sea null.
        *Post: Hace que las clases hijas agreguen un edificio, según sea el comportamiento de cada hija.
        */
        virtual void agregar_edificio(Edificio* edificio_a_agregar);

        /*
        *Pre:
        *Post:
        */
        virtual void agregar_jugador(Jugador* jugador);

        /*
        *Post: Hace que las clases hijas limpien el casillero, según sea el comportamiento de cada hija.
        */
        virtual void limpiar_casillero();

        /*
        *Post: Destruirá el casillero, liberando la memoria utilizada por el mismo.
        */
        virtual ~Casillero();

};

#endif // _CASILLERO_H_