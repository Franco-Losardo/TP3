#include "../../archivos_h/objetivos/objetivo_piedra.h"

using namespace std;

Objetivo_piedra::Objetivo_piedra() {
    this -> nombre = NOMBRE_OBJETIVO_PIEDRA;
    this -> cantidad_piedras = 0;
}

bool Objetivo_piedra::se_cumplio_el_objetivo(Jugador* jugador) {

    this -> cantidad_piedras = jugador -> obtener_inventario() -> obtener_material(PIEDRA) -> obtener_cantidad();
    return this -> cantidad_piedras >= OBJETIVO_PIEDRA;
}

void Objetivo_piedra::mostrar_progreso() {
    cout << "Faltan: " << OBJETIVO_PIEDRA - this -> cantidad_piedras << " piedras para lograr el objetivo." << endl;
}