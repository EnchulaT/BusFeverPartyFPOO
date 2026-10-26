/**
 * @file CCarro.h
 * @brief CONTRATO del modulo Carro (subclase de CVehiculo).
 *
 * ATENCION: ESTE ARCHIVO ES UN CONTRATO.
 *
 * Estandar CRC:
 *   Clase: CCarro (hereda de CVehiculo)
 *   Responsabilidades:
 *     - Representar un vehiculo pequenio. Segun el enunciado ocupa normalmente
 *       1 o 2 celdas y tiene menor capacidad de pasajeros que un bus.
 *   Colaboradores:
 *     - CVehiculo: clase base, de ahi hereda posicion/orientacion/color/etc.
 *
 * REGLAS DEL CONTRATO:
 *   - getTipo() siempre debe devolver TipoVehiculo::CARRO.
 *   - El constructor recibe los mismos datos que CVehiculo (le llega desde
 *     CCargadorNivel, que lee 'largo' y 'capacidad' del archivo de nivel: no se
 *     fuerzan valores fijos aqui para poder representar distintos niveles).
 */
#ifndef _CCARRO_H_
#define _CCARRO_H_
#include "CVehiculo.h"

class CCarro : public CVehiculo
{
  public:
    CCarro(int id, Color color, Orientacion orientacion, int largo, int capacidadMaxima, CPosicion posicion);
    TipoVehiculo getTipo() const override;
};

#endif
