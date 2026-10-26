/**
 * @file CControladorJuego.h
 * @brief CONTRATO del modulo Controlador (logica de negocio del juego).
 *
 * ATENCION: ESTE ARCHIVO ES UN CONTRATO.
 *
 * Estandar CRC:
 *   Clase: CControladorJuego
 *   Responsabilidades:
 *     - Procesar la jugada del usuario: mover un vehiculo (delega en CTablero).
 *     - Ejecutar el ciclo automatico de embarque de pasajeros descrito en el
 *       enunciado, cada vez que un vehiculo queda parqueado.
 *     - Calcular y exponer el estado de la partida (en curso / ganado / perdido).
 *     - Es la UNICA clase con logica de negocio "de alto nivel": no imprime nada
 *       (eso es trabajo de CVistaConsola) ni lee cin directamente.
 *   Colaboradores:
 *     - CTablero: mueve vehiculos, consulta zonas de parqueo.
 *     - CFilaEstatica / CFilaRotatoria: dirige el flujo de pasajeros.
 *     - CVehiculo: sube pasajeros, consulta color/capacidad.
 *
 * REGLAS DEL CONTRATO (resumen del ciclo de embarque, ver enunciado seccion 2):
 *   1. Se examina el pasajero en la posicion de embarque de la fila rotatoria.
 *      Si hay un vehiculo PARQUEADO del mismo color con asientos libres, el
 *      pasajero aborda (subirPasajero + sacarPasajeroEnEmbarque) y la fila
 *      rotatoria se rellena desde la fila estatica (intentarRellenar).
 *   2. Si ningun vehiculo puede recibirlo, la fila rotatoria gira una posicion.
 *   3. El ciclo se repite hasta que nadie en la posicion de embarque pueda
 *      abordar, o hasta que no queden pasajeros.
 *   - Un vehiculo que completa su capacidad debe abandonar su zona de parqueo
 *     (liberarla) segun las reglas del enunciado.
 *   - Victoria: no quedan pasajeros ni en la fila estatica, ni en la fila
 *     rotatoria, ni pendientes de abordar.
 *   - Derrota: las 4 zonas de parqueo estan ocupadas Y ningun pasajero en la
 *     posicion de embarque puede abordar ningun vehiculo estacionado (el
 *     trafico queda bloqueado para siempre).
 */
#ifndef _CCONTROLADORJUEGO_H_
#define _CCONTROLADORJUEGO_H_
#include "CTipos.h"
#include "CTablero.h"
#include "CFilaEstatica.h"
#include "CFilaRotatoria.h"

class CControladorJuego
{
  private:
    CTablero& tablero;
    CFilaEstatica& filaEstatica;
    CFilaRotatoria& filaRotatoria;
    EstadoJuego estado;

  public:
    CControladorJuego(CTablero& tablero, CFilaEstatica& filaEstatica, CFilaRotatoria& filaRotatoria);

    // Mueve el vehiculo, ejecuta el ciclo de embarque si quedo parqueado,
    // actualiza 'estado' y lo devuelve.
    ResultadoMovimiento jugarTurno(int idVehiculo);

    // Ciclo descrito en el contrato arriba.
    void ejecutarCicloEmbarque();

    EstadoJuego getEstado() const;
    bool verificarVictoria() const;
    bool verificarDerrota() const;
};

#endif
