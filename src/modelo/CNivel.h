/**
 * @file CNivel.h
 * @brief Estructura de datos (DTO) con la configuracion de un nivel ya leida.
 *
 * @details
 * Es el "puente" entre CCargadorNivel (que lee el archivo .txt) y el resto del
 * modelo (CTablero, CFilaEstatica), que construyen sus objetos reales a partir de
 * estos datos simples. No tiene logica de negocio, es solo un contenedor.
 *
 * Ya esta implementada por completo (como CPosicion y CPasajero): no es un contrato
 * de ningun modulo en particular, pero CCargadorNivel SI debe llenarla correctamente
 * (eso si es parte de su contrato).
 *
 * @author Equipo Bus Fever Party! FPOO-C++ Edition
 */
#ifndef _CNIVEL_H_
#define _CNIVEL_H_
#include <vector>
#include "CTipos.h"
#include "CPosicion.h"
using namespace std;

// Datos de un vehiculo tal como aparecen en el archivo de nivel.
struct CVehiculoDatos {
    TipoVehiculo tipo;
    Color color;
    CPosicion posicion;
    Orientacion orientacion;
    int largo;
    int capacidad;
};

struct CNivel {
    int filas = 0;
    int columnas = 0;
    vector<CVehiculoDatos> vehiculos;
    vector<Color> secuenciaPasajeros;  // en el orden exacto en que deben salir
};

#endif
