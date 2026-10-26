/*
    Proyecto: Bus Fever Party! FPOO-C++ Edition
    Modulo: Fila Estatica de pasajeros

    ESTE ARCHIVO ES SUYO: reemplacen los STUB por la implementacion real.
*/
#include "CFilaEstatica.h"

CFilaEstatica::CFilaEstatica(const vector<CPasajero>& secuencia) : pasajeros(secuencia) {
}

bool CFilaEstatica::estaVacia() const {
    // STUB: implementar
    return true;
}

int CFilaEstatica::cantidadRestante() const {
    // STUB: implementar
    return 0;
}

const CPasajero* CFilaEstatica::verPrimero() const {
    // STUB: implementar
    return nullptr;
}

bool CFilaEstatica::sacarPrimero(CPasajero& pasajeroSacado) {
    // STUB: implementar (false si la fila esta vacia)
    return false;
}
