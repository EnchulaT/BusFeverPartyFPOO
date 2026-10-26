/*
    Proyecto: Bus Fever Party! FPOO-C++ Edition
    Modulo: Vehiculo (clase base abstracta)

    ESTE ARCHIVO ES SUYO: reemplacen los STUB por la implementacion real.
    getTipo() no se implementa aqui: queda pura virtual, la define cada subclase.
*/
#include "CVehiculo.h"

CVehiculo::CVehiculo(int id_, Color color_, Orientacion orientacion_, int largo_, int capacidadMaxima_, CPosicion posicion_)
    : id(id_), color(color_), orientacion(orientacion_), largo(largo_),
      capacidadMaxima(capacidadMaxima_), pasajerosActuales(0), posicion(posicion_), enParqueadero(false) {
}

int CVehiculo::getId() const {
    // STUB: implementar
    return id;
}

Color CVehiculo::getColor() const {
    // STUB: implementar
    return color;
}

Orientacion CVehiculo::getOrientacion() const {
    // STUB: implementar
    return orientacion;
}

int CVehiculo::getLargo() const {
    // STUB: implementar
    return largo;
}

int CVehiculo::getCapacidadMaxima() const {
    // STUB: implementar
    return capacidadMaxima;
}

int CVehiculo::getPasajerosActuales() const {
    // STUB: implementar
    return pasajerosActuales;
}

bool CVehiculo::estaLleno() const {
    // STUB: implementar
    return false;
}

CPosicion CVehiculo::getPosicion() const {
    // STUB: implementar
    return posicion;
}

void CVehiculo::setPosicion(const CPosicion& nuevaPosicion) {
    // STUB: implementar
}

vector<CPosicion> CVehiculo::celdasOcupadas() const {
    // STUB: implementar (usar posicion, orientacion y largo)
    return vector<CPosicion>();
}

bool CVehiculo::estaEnParqueadero() const {
    // STUB: implementar
    return enParqueadero;
}

void CVehiculo::setEnParqueadero(bool valor) {
    // STUB: implementar
}

bool CVehiculo::subirPasajero() {
    // STUB: implementar (false si ya esta lleno)
    return false;
}
