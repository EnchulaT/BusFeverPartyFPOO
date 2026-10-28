/*
    Proyecto: Bus Fever Party! FPOO-C++ Edition
    Modulo: Controlador del juego (logica de negocio)

    ESTE ARCHIVO ES SUYO: reemplacen los STUB por la implementacion real.
*/
#include "CControladorJuego.h"

CControladorJuego::CControladorJuego(
    CTablero& tablero_,
    CFilaEstatica& filaEstatica_,
    CFilaRotatoria& filaRotatoria_)
    : tablero(tablero_),
      filaEstatica(filaEstatica_),
      filaRotatoria(filaRotatoria_),
      estado(EstadoJuego::EN_CURSO) {
}

ResultadoMovimiento CControladorJuego::jugarTurno(int idVehiculo) {
    if (estado != EstadoJuego::EN_CURSO) {
        return ResultadoMovimiento::ID_INVALIDO;
    }

    ResultadoMovimiento resultado = tablero.moverVehiculo(idVehiculo);

    if (resultado == ResultadoMovimiento::OK) {
        CVehiculo* vehiculo = tablero.obtenerVehiculoPorId(idVehiculo);

        // El ciclo de embarque solo se ejecuta si el vehículo quedó parqueado.
        if (vehiculo != nullptr && vehiculo->estaEnParqueadero()) {
            ejecutarCicloEmbarque();

            if (verificarVictoria()) {
                estado = EstadoJuego::GANADO;
            } else if (verificarDerrota()) {
                estado = EstadoJuego::PERDIDO;
            }
        }
    }

    return resultado;
}

void CControladorJuego::ejecutarCicloEmbarque() {
    const int capacidad = filaRotatoria.getCapacidad();

    if (capacidad <= 0) {
        return;
    }

    int girosSinEmbarque = 0;

    while (!filaEstatica.estaVacia() ||
           !filaRotatoria.estaVacia()) {

        const CPasajero* pasajero =
            filaRotatoria.verPasajeroEnEmbarque();

        CVehiculo* compatible = nullptr;

        // Buscar un vehículo parqueado, del color correcto y con cupo.
        if (pasajero != nullptr) {
            auto& zonas = tablero.getZonasParqueo();

            for (auto& zona : zonas) {
                CVehiculo* vehiculo =
                    zona.getVehiculoEstacionado();

                if (vehiculo != nullptr &&
                    vehiculo->estaEnParqueadero() &&
                    !vehiculo->estaLleno() &&
                    vehiculo->getColor() == pasajero->getColor()) {

                    compatible = vehiculo;
                    break;
                }
            }
        }

        if (compatible != nullptr &&
            compatible->subirPasajero()) {

            filaRotatoria.sacarPasajeroEnEmbarque();
            filaRotatoria.intentarRellenar(filaEstatica);

            // Si el vehículo se llena, liberar su zona de parqueo.
            if (compatible->estaLleno()) {
                auto& zonas = tablero.getZonasParqueo();

                for (auto& zona : zonas) {
                    if (zona.getVehiculoEstacionado() == compatible) {
                        zona.liberar();
                        compatible->setEnParqueadero(false);
                        break;
                    }
                }
            }

            // Hubo un embarque: reiniciar el contador de giros.
            girosSinEmbarque = 0;
            continue;
        }

        // Ningún vehículo puede recibir al pasajero actual.
        filaRotatoria.girar();
        ++girosSinEmbarque;

        // Evitar girar indefinidamente sin conseguir embarcar.
        if (girosSinEmbarque >= capacidad) {
            break;
        }
    }
}

EstadoJuego CControladorJuego::getEstado() const {
    return estado;
}

bool CControladorJuego::verificarVictoria() const {
    return filaEstatica.estaVacia() &&
           filaRotatoria.estaVacia();
}

bool CControladorJuego::verificarDerrota() const {
    if (!tablero.todasLasZonasOcupadas()) {
        return false;
    }

    const CPasajero* pasajero =
        filaRotatoria.verPasajeroEnEmbarque();

    if (pasajero == nullptr) {
        return false;
    }

    const auto& zonas = tablero.getZonasParqueo();

    for (const auto& zona : zonas) {
        CVehiculo* vehiculo =
            zona.getVehiculoEstacionado();

        if (vehiculo != nullptr &&
            vehiculo->estaEnParqueadero() &&
            !vehiculo->estaLleno() &&
            vehiculo->getColor() == pasajero->getColor()) {

            return false;
        }
    }

    return true;
}