/*
    Proyecto: Bus Fever Party! FPOO-C++ Edition
    Modulo: Controlador del juego (logica de negocio)

    ESTE ARCHIVO ES SUYO: reemplacen los STUB por la implementacion real.
*/
#include "CControladorJuego.h"

CControladorJuego::CControladorJuego(CTablero& tablero_, CFilaEstatica& filaEstatica_, CFilaRotatoria& filaRotatoria_)
    : tablero(tablero_), filaEstatica(filaEstatica_), filaRotatoria(filaRotatoria_), estado(EstadoJuego::EN_CURSO) {
}

ResultadoMovimiento CControladorJuego::jugarTurno(int idVehiculo) {
    // STUB: implementar (mover + ciclo de embarque + actualizar estado)
    return ResultadoMovimiento::ID_INVALIDO;
}

void CControladorJuego::ejecutarCicloEmbarque() {
    // STUB: implementar (ver los 3 pasos del contrato en el .h)
}

EstadoJuego CControladorJuego::getEstado() const {
    // STUB: implementar
    return estado;
}

bool CControladorJuego::verificarVictoria() const {
    // STUB: implementar
    return false;
}

bool CControladorJuego::verificarDerrota() const {
    // STUB: implementar
    return false;
}
