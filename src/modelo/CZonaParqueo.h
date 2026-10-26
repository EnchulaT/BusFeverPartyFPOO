/**
 * @file CZonaParqueo.h
 * @brief CONTRATO del modulo Zona de Parqueo.
 *
 * ATENCION: ESTE ARCHIVO ES UN CONTRATO.
 *
 * Estandar CRC:
 *   Clase: CZonaParqueo
 *   Responsabilidades:
 *     - Representar una de las 4 zonas de parqueo del tablero: si esta libre
 *       o que vehiculo tiene estacionado.
 *     - NO decide cuando un vehiculo debe salir ni gestiona el embarque: eso es
 *       responsabilidad de CControladorJuego.
 *   Colaboradores:
 *     - CVehiculo: el vehiculo estacionado (si hay alguno).
 *     - CTablero: duenio de las 4 zonas de parqueo.
 *     - CControladorJuego: consulta y libera zonas durante el ciclo de embarque.
 *
 * REGLAS DEL CONTRATO:
 *   - asignarVehiculo() debe fallar (devolver false, no asignar nada) si la zona
 *     ya estaba ocupada.
 *   - liberar() deja la zona libre (vehiculoEstacionado = nullptr) sin importar
 *     si habia alguien o no.
 *   - CZonaParqueo NO es duenia de la memoria del vehiculo (no lo libera en su
 *     destructor): solo guarda un puntero de consulta.
 */
#ifndef _CZONAPARQUEO_H_
#define _CZONAPARQUEO_H_
#include "CVehiculo.h"

class CZonaParqueo
{
  private:
    int indice;
    CVehiculo* vehiculoEstacionado;

  public:
    explicit CZonaParqueo(int indice);

    int getIndice() const;
    bool estaLibre() const;
    CVehiculo* getVehiculoEstacionado() const;

    // Devuelve false si la zona ya estaba ocupada (no reemplaza al vehiculo existente).
    bool asignarVehiculo(CVehiculo* vehiculo);
    void liberar();
};

#endif
