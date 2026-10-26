/*
    Proyecto: Bus Fever Party! FPOO-C++ Edition
    Modulo: Tablero

    ESTE ARCHIVO ES SUYO: reemplacen los STUB por la implementacion real.
*/
#include "CTablero.h"

CTablero::CTablero(int filas_, int columnas_)
    : filas(filas_), columnas(columnas_),
      zonasParqueo{ CZonaParqueo(0), CZonaParqueo(1), CZonaParqueo(2), CZonaParqueo(3) } {
}

int CTablero::getFilas() const {
    // STUB: implementar
    return filas;
}

int CTablero::getColumnas() const {
    // STUB: implementar
    return columnas;
}

CVehiculo* CTablero::agregarVehiculo(unique_ptr<CVehiculo> vehiculo) {
    // STUB: implementar (nullptr si hay colision con el borde u otro vehiculo)
    return nullptr;
}

CVehiculo* CTablero::obtenerVehiculoPorId(int id) const {
    // STUB: implementar
    return nullptr;
}

const vector<unique_ptr<CVehiculo>>& CTablero::getVehiculos() const {
    // STUB: implementar
    return vehiculos;
}

bool CTablero::hayColision(const CVehiculo& vehiculo, const vector<CPosicion>& posicionesDestino) const {
    // STUB: implementar
    return false;
}

ResultadoMovimiento CTablero::moverVehiculo(int idVehiculo) {
    // STUB: implementar (ver ResultadoMovimiento en CTipos.h)
    return ResultadoMovimiento::ID_INVALIDO;
}

array<CZonaParqueo, CANTIDAD_ZONAS_PARQUEO>& CTablero::getZonasParqueo() {
    // STUB: implementar
    return zonasParqueo;
}

const array<CZonaParqueo, CANTIDAD_ZONAS_PARQUEO>& CTablero::getZonasParqueo() const {
    // STUB: implementar
    return zonasParqueo;
}

bool CTablero::todasLasZonasOcupadas() const {
    // STUB: implementar
    return false;
}
