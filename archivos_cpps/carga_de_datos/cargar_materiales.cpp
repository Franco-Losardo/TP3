#include "../../archivos_h/carga_de_datos/cargar_materiales.h"

using namespace std;

Cargar_materiales::Cargar_materiales() {
    this -> archivo_ruta = RUTA_MATERIALES;
}

void Cargar_materiales::carga_materiales(Jugador* jugador_1, Jugador* jugador_2) {
    ifstream archivo_materiales(this -> archivo_ruta);
    if (!archivo_materiales) {
        cout << COLOR_ROJO << "El archivo_materiales de materiales no existe. Para continuar, crealo y volve a correr el programa." << COLOR_POR_DEFECTO << endl;
        exit(1);
    }

    string tipo_material;
    int cantidad_material_jugador_1;
    int cantidad_material_jugador_2;

    while (archivo_materiales >> tipo_material >> cantidad_material_jugador_1 >> cantidad_material_jugador_2) {
        procesar_archivo(tipo_material, cantidad_material_jugador_1, jugador_1);
        procesar_archivo(tipo_material, cantidad_material_jugador_2, jugador_2);
    }
    archivo_materiales.close();
}

void Cargar_materiales::guardar_materiales(Jugador* jugador_1, Jugador* jugador_2) {
    ofstream archivo_materiales(this -> archivo_ruta);
    Material** inventario_jugador_1 = jugador_1 -> obtener_inventario() -> obtener_inventario();
    Material** inventario_jugador_2 = jugador_2 -> obtener_inventario() -> obtener_inventario();
    int cantidad_materiales = jugador_1 -> obtener_inventario() -> obtener_cantidad_materiales();
    string nombre_material;
    int cantidad_jugador_1 = 0;
    int cantidad_jugador_2 = 0;        
    for (int i = 0; i < cantidad_materiales; i++) {
        nombre_material = inventario_jugador_1[i] -> obtener_nombre_material();
        cantidad_jugador_1 = inventario_jugador_1[i] -> obtener_cantidad();
        cantidad_jugador_2 = inventario_jugador_2[i] -> obtener_cantidad();
        archivo_materiales << nombre_material << VACIO << cantidad_jugador_1 << VACIO << cantidad_jugador_2 << endl;
    }
    archivo_materiales.close();
}

void Cargar_materiales::procesar_archivo(string tipo_material, int cantidad_material, Jugador* jugador) {
    Material* nuevo_material = nullptr;

    if (tipo_material == ANDYCOINS)
       nuevo_material = new Andycoins(cantidad_material);
    else if (tipo_material == MADERA)
       nuevo_material = new Madera(cantidad_material);
    else if (tipo_material == METAL)
       nuevo_material = new Metal(cantidad_material);
    else if (tipo_material == PIEDRA)
       nuevo_material = new Piedra(cantidad_material);
    else
       nuevo_material = new Bomba(cantidad_material);

    jugador -> cargar_material(nuevo_material);
    nuevo_material = nullptr;
}