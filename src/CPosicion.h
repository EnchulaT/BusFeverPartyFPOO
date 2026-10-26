/**
 * @file CPosicion.h
 * @brief Representa una celda (fila, columna) del tablero.
 *
 * @details
 * Estructura de datos simple (sin logica propia mas alla de comparar). Se usa en todo
 * el proyecto para ubicar vehiculos y validar colisiones.
 *
 * Ya esta implementada por completo (igual que CMedicamento en el Taller 5): no es un
 * contrato de ningun modulo, se puede usar libremente.
 *
 * @author Equipo Bus Fever Party! FPOO-C++ Edition
 */
#ifndef _CPOSICION_H_
#define _CPOSICION_H_

struct CPosicion {
    int fila;
    int columna;

    bool operator==(const CPosicion& otra) const {
        return fila == otra.fila && columna == otra.columna;
    }
    bool operator!=(const CPosicion& otra) const {
        return !(*this == otra);
    }
};

#endif
