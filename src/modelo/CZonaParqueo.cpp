/*
    Proyecto: Bus Fever Party! FPOO-C++ Edition
    Modulo: Zona de Parqueo

    ESTE ARCHIVO ES SUYO: reemplacen los STUB por la implementacion real.
*/
#include "CZonaParqueo.h"

CZonaParqueo::CZonaParqueo(int indice_) : indice(indice_), vehiculoEstacionado(nullptr) {
}

int CZonaParqueo::getIndice() const {
    // STUB: implementar
    return indice;
}

bool CZonaParqueo::estaLibre() const {
    // STUB: implementar
    return true;
}

CVehiculo* CZonaParqueo::getVehiculoEstacionado() const {
    // STUB: implementar
    return nullptr;
}

bool CZonaParqueo::asignarVehiculo(CVehiculo* vehiculo) {
    // STUB: implementar (false si ya estaba ocupada)
    return false;
}

void CZonaParqueo::liberar() {
    // STUB: implementar
}
