/**
 * @file CFilaRotatoria.h
 * @brief CONTRATO del modulo Fila Rotatoria de pasajeros.
 *
 * ATENCION: ESTE ARCHIVO ES UN CONTRATO.
 *
 * Estandar CRC:
 *   Clase: CFilaRotatoria
 *   Responsabilidades:
 *     - Estructura circular de capacidad FIJA que contiene pasajeros listos
 *       para abordar. Tiene una posicion de embarque fija (por convencion, el
 *       indice 0), frente a las zonas de parqueo.
 *     - Girar una posicion a la vez.
 *     - Rellenarse desde la CFilaEstatica cada vez que queda un espacio libre.
 *   Colaboradores:
 *     - CPasajero: lo que contiene en cada posicion (puede haber posiciones vacias
 *       mientras la fila estatica todavia no la ha llenado por completo).
 *     - CFilaEstatica: de ahi saca pasajeros para rellenarse.
 *     - CControladorJuego: dirige el ciclo de embarque (ver ejecutarCicloEmbarque
 *       en CControladorJuego.h), llamando a estos metodos en el orden correcto.
 *
 * REGLAS DEL CONTRATO:
 *   - La posicion de embarque es siempre el mismo indice logico (el equipo decide
 *     si es el indice 0 u otro, pero debe documentarlo y ser consistente).
 *   - intentarRellenar() debe llenar como maximo UNA posicion vacia por llamada
 *     (saca un pasajero de la fila estatica), y devuelve false si no habia
 *     posicion vacia o si la fila estatica ya estaba vacia.
 *   - sacarPasajeroEnEmbarque() quita al pasajero que esta en la posicion de
 *     embarque (porque abordo un vehiculo). Devuelve false si esa posicion ya
 *     estaba vacia.
 *   - girar() rota todas las posiciones una celda (el sentido de giro lo define
 *     y documenta el equipo).
 */
#ifndef _CFILAROTATORIA_H_
#define _CFILAROTATORIA_H_
#include <vector>
#include <optional>
#include "CPasajero.h"
#include "CFilaEstatica.h"
using namespace std;

class CFilaRotatoria
{
  private:
    vector<optional<CPasajero>> posiciones;

  public:
    explicit CFilaRotatoria(int capacidad);

    int getCapacidad() const;
    bool estaLlena() const;
    bool estaVacia() const;

    // nullptr si la posicion de embarque esta vacia.
    const CPasajero* verPasajeroEnEmbarque() const;

    // Si hay una posicion vacia, saca el primero de 'filaEstatica' y lo coloca ahi.
    // Devuelve false si no rellano nada (fila llena o filaEstatica vacia).
    bool intentarRellenar(CFilaEstatica& filaEstatica);

    // Quita al pasajero de la posicion de embarque. false si ya estaba vacia.
    bool sacarPasajeroEnEmbarque();

    // Rota todas las posiciones una celda.
    void girar();
};

#endif
