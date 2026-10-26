/*
    Proyecto: Bus Fever Party! FPOO-C++ Edition
    Modulo: Bus (subclase de CVehiculo)

    ESTE ARCHIVO ES SUYO: reemplacen el STUB por la implementacion real.
*/
#include "CBus.h"

CBus::CBus(int id, Color color, Orientacion orientacion, int largo, int capacidadMaxima, CPosicion posicion)
    : CVehiculo(id, color, orientacion, largo, capacidadMaxima, posicion) {
}

TipoVehiculo CBus::getTipo() const {
    // STUB: implementar (debe devolver TipoVehiculo::BUS)
    return TipoVehiculo::BUS;
}
