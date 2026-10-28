/*
    Proyecto: Bus Fever Party! FPOO-C++ Edition
    Modulo: Fila Estatica de pasajeros

    El primer pasajero de la fila es siempre pasajeros[0]: es el unico que se
    puede consultar (verPrimero) o sacar (sacarPrimero). Al sacarlo, los demas
    avanzan un puesto.
*/
#include "CFilaEstatica.h"

CFilaEstatica::CFilaEstatica(const vector<CPasajero>& secuencia) : pasajeros(secuencia) {
}

bool CFilaEstatica::estaVacia() const {
    return pasajeros.size() == 0;
}

int CFilaEstatica::cantidadRestante() const {
    return (int)pasajeros.size();
}

const CPasajero* CFilaEstatica::verPrimero() const {
    if (estaVacia()) {
        return nullptr;
    }
    return &pasajeros[0];
}

bool CFilaEstatica::sacarPrimero(CPasajero& pasajeroSacado) {
    if (estaVacia()) {
        return false;
    }
    pasajeroSacado = pasajeros[0];
    pasajeros.erase(pasajeros.begin());
    return true;
}
