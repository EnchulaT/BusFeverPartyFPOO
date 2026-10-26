/**
 * @file CBus.h
 * @brief CONTRATO del modulo Bus (subclase de CVehiculo).
 *
 * ATENCION: ESTE ARCHIVO ES UN CONTRATO.
 *
 * Estandar CRC:
 *   Clase: CBus (hereda de CVehiculo)
 *   Responsabilidades:
 *     - Representar un vehiculo mediano/grande. Segun el enunciado ocupa 2 o mas
 *       celdas y tiene mayor capacidad de pasajeros que un carro.
 *   Colaboradores:
 *     - CVehiculo: clase base.
 *
 * REGLAS DEL CONTRATO:
 *   - getTipo() siempre debe devolver TipoVehiculo::BUS.
 *   - Mismo criterio que CCarro: 'largo' y 'capacidad' llegan desde el archivo
 *     de nivel (via CCargadorNivel), no se fuerzan valores fijos aqui.
 */
#ifndef _CBUS_H_
#define _CBUS_H_
#include "CVehiculo.h"

class CBus : public CVehiculo
{
  public:
    CBus(int id, Color color, Orientacion orientacion, int largo, int capacidadMaxima, CPosicion posicion);
    TipoVehiculo getTipo() const override;
};

#endif
