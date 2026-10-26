/**
 * @file CPasajero.h
 * @brief Definicion de la clase Pasajero.
 *
 * @details
 * Representa a un pasajero esperando en la fila estatica o en la fila rotatoria.
 * Un pasajero solo tiene un color: debe abordar un vehiculo de ese mismo color.
 *
 * -----------------------------------------------------------------------------
 * Estandar CRC (Clase - Responsabilidad - Colaboracion)
 * -----------------------------------------------------------------------------
 *
 * Clase:
 *   CPasajero
 *
 * Responsabilidades:
 *   - Representar a un pasajero y su color.
 *   - Exponer su color mediante un getter.
 *
 * Colaboradores:
 *   - CFilaEstatica: guarda la secuencia completa de pasajeros.
 *   - CFilaRotatoria: guarda a los pasajeros que ya pueden abordar.
 *   - CVehiculo: recibe pasajeros de su mismo color.
 *
 * -----------------------------------------------------------------------------
 *
 * Ya esta implementada por completo (igual que CMedicamento en el Taller 5): no es un
 * contrato de ningun modulo, se puede usar libremente.
 *
 * @author Equipo Bus Fever Party! FPOO-C++ Edition
 */
#ifndef _CPASAJERO_H_
#define _CPASAJERO_H_
#include "CTipos.h"

class CPasajero
{
  private:
    Color color;

  public:
    explicit CPasajero(Color color);
    Color getColor() const;
};

#endif
