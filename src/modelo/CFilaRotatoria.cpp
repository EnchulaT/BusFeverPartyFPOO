/*
    Proyecto: Bus Fever Party! FPOO-C++ Edition
    Modulo: Fila Rotatoria de pasajeros

    Decisiones del equipo (ver REGLAS DEL CONTRATO en CFilaRotatoria.h):
    - La posicion de embarque es el indice 0 (POSICION_EMBARQUE).
    - girar() funciona como un carrusel: cada pasajero avanza un puesto hacia
      el embarque (el del indice 1 pasa al 0) y el que estaba en embarque pasa
      al ultimo puesto. Los puestos vacios giran igual que los ocupados.
    - intentarRellenar() llena el primer puesto vacio empezando por el
      embarque, asi el pasajero que entra desde la fila estatica ocupa el lugar
      que dejo el que acaba de abordar.
*/
#include "CFilaRotatoria.h"

static const int POSICION_EMBARQUE = 0;

CFilaRotatoria::CFilaRotatoria(int capacidad) : posiciones(capacidad) {
}

int CFilaRotatoria::getCapacidad() const {
    return (int)posiciones.size();
}

bool CFilaRotatoria::estaLlena() const {
    for (int i = 0; i < getCapacidad(); i++) {
        if (!posiciones[i].has_value()) {
            return false;
        }
    }
    return true;
}

bool CFilaRotatoria::estaVacia() const {
    for (int i = 0; i < getCapacidad(); i++) {
        if (posiciones[i].has_value()) {
            return false;
        }
    }
    return true;
}

const CPasajero* CFilaRotatoria::verPasajeroEnEmbarque() const {
    if (getCapacidad() == 0 || !posiciones[POSICION_EMBARQUE].has_value()) {
        return nullptr;
    }
    return &posiciones[POSICION_EMBARQUE].value();
}

bool CFilaRotatoria::intentarRellenar(CFilaEstatica& filaEstatica) {
    if (filaEstatica.estaVacia()) {
        return false;
    }
    for (int i = 0; i < getCapacidad(); i++) {
        if (!posiciones[i].has_value()) {
            CPasajero pasajero = *filaEstatica.verPrimero();
            filaEstatica.sacarPrimero(pasajero);
            posiciones[i] = pasajero;
            return true;
        }
    }
    return false;
}

bool CFilaRotatoria::sacarPasajeroEnEmbarque() {
    if (getCapacidad() == 0 || !posiciones[POSICION_EMBARQUE].has_value()) {
        return false;
    }
    posiciones[POSICION_EMBARQUE].reset();
    return true;
}

void CFilaRotatoria::girar() {
    if (getCapacidad() == 0) {
        return;
    }
    optional<CPasajero> enEmbarque = posiciones[0];
    for (int i = 0; i < getCapacidad() - 1; i++) {
        posiciones[i] = posiciones[i + 1];
    }
    posiciones[getCapacidad() - 1] = enEmbarque;
}
