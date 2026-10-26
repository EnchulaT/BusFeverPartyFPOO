/**
 * @file CTipos.h
 * @brief Tipos y enumeraciones compartidas por todo el proyecto Bus Fever Party!
 *
 * @details
 * Este archivo centraliza los "vocabularios" comunes (colores, orientacion, tipos de
 * vehiculo, estado de la partida) para que todos los modulos (modelo, vista, controlador)
 * hablen el mismo idioma. No contiene logica de negocio.
 *
 * No es un contrato de un modulo en particular: es de uso libre para todo el equipo.
 * Si se necesita un color o estado nuevo, se agrega aqui y se avisa al resto del equipo
 * (afecta a CCargadorNivel, que parsea estos nombres desde el archivo de nivel, y a
 * CVistaConsola, que los imprime).
 *
 * @author Equipo Bus Fever Party! FPOO-C++ Edition
 */
#ifndef _CTIPOS_H_
#define _CTIPOS_H_

// Colores posibles de vehiculos y pasajeros. Ampliar esta lista si el nivel lo requiere.
enum class Color {
    ROJO,
    AZUL,
    AMARILLO,
    VERDE,
    MORADO,
    NARANJA,
    ROSA,
    CYAN
};

// Eje sobre el que se puede mover un vehiculo (fijo desde su creacion).
enum class Orientacion {
    HORIZONTAL,
    VERTICAL
};

// Tipo de vehiculo (determina tamanio/capacidad tipicos, ver CCarro y CBus).
enum class TipoVehiculo {
    CARRO,
    BUS
};

// Estado general de la partida, calculado por CControladorJuego.
enum class EstadoJuego {
    EN_CURSO,
    GANADO,
    PERDIDO
};

// Resultado de intentar mover un vehiculo (CTablero::moverVehiculo / CControladorJuego::jugarTurno).
enum class ResultadoMovimiento {
    OK,                  // el vehiculo se movio (o llego a una zona de parqueo)
    ID_INVALIDO,          // no existe un vehiculo con ese id
    BLOQUEADO,            // no se movio ni una celda: el camino esta obstruido desde el inicio
    SIN_ZONA_PARQUEO_LIBRE // el vehiculo llego al borde del tablero pero no hay zona de parqueo libre
};

#endif
