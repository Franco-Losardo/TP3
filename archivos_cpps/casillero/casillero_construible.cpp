#include "../../archivos_h/casilleros/casillero_construible.h"

using namespace std;

Casillero_construible::Casillero_construible() {
    this -> edificio = nullptr;
    this -> jugador = nullptr;
    this -> tipo_terreno = TERRENO;
    this -> codigo_color = FONDO_VERDE;
}

Jugador* Casillero_construible::obtener_puntero_jugador() {
    return this -> jugador;
}

void Casillero_construible::mostrar() {
    cout << COLOR_DORADO << LINEA_DIVISORIA_DISENIO << COLOR_POR_DEFECTO << endl;
    if (!this -> edificio && !this -> jugador)
        cout << COLOR_VERDE << "Soy un terreno un casillero construible y me encuentro vacío." << COLOR_POR_DEFECTO << endl;
    else if (this -> jugador) 
        cout << COLOR_VERDE_AGUA << "Soy un casillero construible y no me encuentro vacio" << COLOR_POR_DEFECTO << endl << endl;
    else {
        cout << COLOR_VERDE_AGUA << "Soy un terreno, un casillero construible y no me encuentro vacío." << COLOR_POR_DEFECTO << endl;
        this -> edificio -> mostrar_saludo();
    }
    cout << COLOR_DORADO << LINEA_DIVISORIA_DISENIO << COLOR_POR_DEFECTO << endl;
}

void Casillero_construible::agregar_edificio(Edificio* edificio_a_construir) {
    this -> edificio = edificio_a_construir;
}

void Casillero_construible::agregar_jugador(Jugador* jugador) {
    this -> jugador = jugador;
}

Edificio* Casillero_construible::obtener_puntero_edificio() {
    return this -> edificio;
}

void Casillero_construible::limpiar_casillero() {
    this -> jugador = nullptr;
    this -> edificio = nullptr;
}

bool Casillero_construible::esta_ocupado() {
    return (bool) this -> edificio || (bool) this -> jugador;
}

Casillero_construible::~Casillero_construible() {
    if (this -> edificio)
        delete this -> edificio;
    else if (this -> jugador)
        delete this -> jugador;
    this -> edificio = nullptr;
    this -> jugador = nullptr;
}