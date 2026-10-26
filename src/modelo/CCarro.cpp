/*
    Proyecto: Bus Fever Party! FPOO-C++ Edition
    Modulo: Carro (subclase de CVehiculo)

    ESTE ARCHIVO ES SUYO: reemplacen el STUB por la implementacion real.
*/
#include "CCarro.h"

CCarro::CCarro(int id, Color color, Orientacion orientacion, int largo, int capacidadMaxima, CPosicion posicion)
    : CVehiculo(id, color, orientacion, largo, capacidadMaxima, posicion) {
}

TipoVehiculo CCarro::getTipo() const {
    // STUB: implementar (debe devolver TipoVehiculo::CARRO)
    return TipoVehiculo::CARRO;
}
