/*
    Proyecto: Bus Fever Party! FPOO-C++ Edition
    Modulo: Fila Rotatoria de pasajeros

    ESTE ARCHIVO ES SUYO: reemplacen los STUB por la implementacion real.
*/
#include "CFilaRotatoria.h"

CFilaRotatoria::CFilaRotatoria(int capacidad) : posiciones(capacidad) {
}

int CFilaRotatoria::getCapacidad() const {
    // STUB: implementar
    return (int)posiciones.size();
}

bool CFilaRotatoria::estaLlena() const {
    // STUB: implementar
    return false;
}

bool CFilaRotatoria::estaVacia() const {
    // STUB: implementar
    return true;
}

const CPasajero* CFilaRotatoria::verPasajeroEnEmbarque() const {
    // STUB: implementar
    return nullptr;
}

bool CFilaRotatoria::intentarRellenar(CFilaEstatica& filaEstatica) {
    // STUB: implementar
    return false;
}

bool CFilaRotatoria::sacarPasajeroEnEmbarque() {
    // STUB: implementar
    return false;
}

void CFilaRotatoria::girar() {
    // STUB: implementar
}
