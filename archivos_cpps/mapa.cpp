#include "../archivos_h/mapa.h"

using namespace std;

/*
* EN LOS CASOS QUE TENEMOS this -> mapa[coord_x][coord_y] CREO QUE DEBERÍAN IR AL REVÉS
  SUPONIENDO QUE TENGAMOS QUE LA FILA ES LA COORD_Y Y LA COLUMNA LA COORD_X 

* EL MOSTRAR MAPA HABRÍA QUE CAMBIARLO POR EL QUE ESTA EN EL TRABAJO DE BRAYAN Y EZE
*/

Mapa::Mapa(int filas, int columnas) {
    this -> cantidad_filas = filas;
    this -> cantidad_filas = columnas;
}

void Mapa::crear_mapa() {
    this -> mapa = new Casillero** [this -> cantidad_filas];

    for (int fila = 0; fila < this -> cantidad_filas; fila++) {
        this -> mapa[fila] = new Casillero*[this -> cantidad_columnas];
    }

    for (int fila = 0; fila < this -> cantidad_filas; fila++) {
        for (int columna = 0; columna < this -> cantidad_columnas; columna++) {
            this -> mapa[fila][columna] = 0;
        }
    }
}

bool Mapa::es_posible_insertar_materiales(int cantidad_a_insertar) {
    int fila = 0;
    int columna;
    while (cantidad_a_insertar > 0 && fila < this -> cantidad_filas) {
        columna = 0;
        while (cantidad_a_insertar > 0 && columna < this -> cantidad_columnas) {
            if ((this -> mapa[fila][columna] -> obtener_tipo_de_terreno() == 'C' || this -> mapa[fila][columna] -> obtener_tipo_de_terreno() == 'B' || this -> mapa[fila][columna] -> obtener_tipo_de_terreno() == 'M') && !this -> mapa[fila][columna] -> esta_ocupado()) {
                cantidad_a_insertar--;
            }
            columna++;
        }
        fila++;
    }

    return cantidad_a_insertar == 0;
}

int* Mapa::generar_coordenadas_validas() {
    int* coordenadas_validas = 0;
    while (!coordenadas_validas) {
        int coord_x = (rand() % this -> cantidad_filas);
        int coord_y = (rand() % this -> cantidad_columnas);
        if ((this -> mapa[coord_x][coord_y] -> obtener_tipo_de_terreno() == 'C' || this -> mapa[coord_x][coord_y] -> obtener_tipo_de_terreno() == 'B' || this -> mapa[coord_x][coord_y] -> obtener_tipo_de_terreno() == 'M') && !this -> mapa[coord_x][coord_y] -> esta_ocupado()) {
            coordenadas_validas = new int[2];
            coordenadas_validas[0] = coord_x;
            coordenadas_validas[1] = coord_y;
        }
    }

    return coordenadas_validas;
}

bool Mapa::esta_ocupado(int coord_x, int coord_y) {
    return this -> mapa[coord_x][coord_y] -> esta_ocupado();
}

char Mapa::obtener_casillero(int coordenada_x, int coordenada_y) {
    return this -> mapa[coordenada_x][coordenada_y] -> obtener_tipo_de_terreno();
}

Edificio* Mapa::obtener_elemento(int coord_x, int coord_y) {
    return this -> mapa[coord_x][coord_y] -> obtener_puntero_edificio();
}

void Mapa::agregar_material_casillero(Material* material, int fila, int columna) {
    this -> mapa[fila][columna] -> agregar_material(material);
}

void Mapa::agregar_edificio_casillero(Edificio* edificio, int fila, int columna) {
    this -> mapa[fila][columna] -> agregar_edificio(edificio);
}

void Mapa::liberar_posicion(int coordenada_x, int coordenada_y) {
    this -> mapa[coordenada_x][coordenada_y] -> limpiar_casillero();
}

bool Mapa::coordenadas_fuera_de_rango(int coord_x, int coord_y) {
    return (coord_x >= cantidad_filas || coord_y >= cantidad_columnas);
}

void Mapa::consultar_coordenada(int coord_x, int coord_y) {
    if (!coordenadas_fuera_de_rango(coord_x, coord_y)) {
        this -> mapa[coord_x][coord_y] -> mostrar();
    }
    else {
        cout << COLOR_ROJO << "Oops, intentaste acceder a una coordenada fuera de rango, intenta nuevamente" << COLOR_POR_DEFECTO <<endl;
    }
}

bool Mapa::se_puede_construir(int coord_x, int coord_y) {
    return this -> mapa[coord_x][coord_y] -> obtener_tipo_de_terreno() == 'T';
}

void Mapa::mostrar_mapa() {
    for (int fila = 0; fila < this -> cantidad_filas; fila++) {
        for (int columna = 0; columna < this -> cantidad_columnas; columna++) {
            char tipo = this -> mapa[fila][columna] -> obtener_tipo_de_terreno();
            if (!this -> mapa[fila][columna] -> esta_ocupado()) {
                if (tipo == 'C') {
                    cout << FONDO_GRIS + ' ';
                }
                else if (tipo == 'T') {
                    cout << FONDO_VERDE + ' ';
                }
                else {
                    cout << FONDO_AZUL + ' ';
                }
            }
            else if (this -> mapa[fila][columna] -> obtener_tipo_de_terreno() == 'T') {
                cout << FONDO_VERDE + this -> mapa[fila][columna] -> obtener_puntero_edificio() -> obtener_nombre_del_edificio();
            }
            else {
                cout << FONDO_GRIS + this -> mapa[fila][columna] -> obtener_puntero_material() -> obtener_nombre_material();
            }
            cout << COLOR_POR_DEFECTO;
        }
        cout << endl;
    }
}

Mapa::~Mapa() {
    for (int fila = 0; fila < this -> cantidad_filas; fila++) {
        for (int columna = 0; columna < this -> cantidad_columnas; columna++) {
            delete this -> mapa[fila][columna];
        }
        delete [] this -> mapa[fila];
    }
    delete [] this -> mapa;
    this -> mapa = 0;
}