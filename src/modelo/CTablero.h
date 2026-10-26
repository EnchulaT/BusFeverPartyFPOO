/**
 * @file CTablero.h
 * @brief CONTRATO del modulo Tablero.
 *
 * ATENCION: ESTE ARCHIVO ES UN CONTRATO.
 *
 * Estandar CRC:
 *   Clase: CTablero
 *   Responsabilidades:
 *     - Ser el duenio de la grilla (N x M), de TODOS los vehiculos colocados en
 *       ella y de las 4 zonas de parqueo.
 *     - Detectar colisiones entre vehiculos y con los bordes del tablero.
 *     - Ejecutar el movimiento de un vehiculo: avanzar en su eje mientras el
 *       camino este libre, hasta chocar, salir del tablero y parquear, o quedar
 *       bloqueado desde el primer paso.
 *   Colaboradores:
 *     - CVehiculo (y subclases CCarro/CBus): los administra.
 *     - CZonaParqueo: las 4 zonas, hijas del tablero.
 *     - CCargadorNivel / CNivel: a partir de ahi se construye el tablero inicial.
 *     - CControladorJuego: le pide mover vehiculos y consulta sus zonas de parqueo.
 *
 * REGLAS DEL CONTRATO:
 *   - El tablero es duenio de la memoria de los vehiculos (los recibe por
 *     unique_ptr en agregarVehiculo y los libera automaticamente al destruirse).
 *   - agregarVehiculo() devuelve nullptr si la posicion inicial del vehiculo choca
 *     con otro vehiculo ya colocado o se sale del tablero (y no lo agrega).
 *   - moverVehiculo(id) debe documentar en el .cpp exactamente que hace en cada
 *     caso (ver ResultadoMovimiento en CTipos.h): si no existe el id, si el
 *     primer paso ya esta bloqueado, si avanza y queda a mitad de camino (segun
 *     las reglas del enunciado los vehiculos avanzan "hasta alcanzar la zona de
 *     parqueo": el equipo decide y documenta si eso es en un solo llamado o si
 *     se detiene si se bloquea antes de salir), y si sale pero no hay zona de
 *     parqueo libre.
 *   - Al parquear un vehiculo exitosamente, moverVehiculo() debe marcarlo con
 *     setEnParqueadero(true) y asignarlo a una zona libre (via CZonaParqueo).
 */
#ifndef _CTABLERO_H_
#define _CTABLERO_H_
#include <array>
#include <memory>
#include <vector>
#include "CTipos.h"
#include "CVehiculo.h"
#include "CZonaParqueo.h"
using namespace std;

const int CANTIDAD_ZONAS_PARQUEO = 4;

class CTablero
{
  private:
    int filas;
    int columnas;
    vector<unique_ptr<CVehiculo>> vehiculos;
    array<CZonaParqueo, CANTIDAD_ZONAS_PARQUEO> zonasParqueo;

  public:
    CTablero(int filas, int columnas);

    int getFilas() const;
    int getColumnas() const;

    // Agrega el vehiculo al tablero y devuelve un puntero (no propietario) para usarlo.
    // nullptr si su posicion inicial choca con otro vehiculo o con el borde del tablero.
    CVehiculo* agregarVehiculo(unique_ptr<CVehiculo> vehiculo);

    CVehiculo* obtenerVehiculoPorId(int id) const;
    const vector<unique_ptr<CVehiculo>>& getVehiculos() const;

    // true si alguna celda ocupada en 'posicionesDestino' esta fuera del tablero o
    // coincide con una celda ocupada por OTRO vehiculo distinto de 'vehiculo'.
    bool hayColision(const CVehiculo& vehiculo, const vector<CPosicion>& posicionesDestino) const;

    // Intenta mover el vehiculo (ver reglas del contrato arriba).
    ResultadoMovimiento moverVehiculo(int idVehiculo);

    array<CZonaParqueo, CANTIDAD_ZONAS_PARQUEO>& getZonasParqueo();
    const array<CZonaParqueo, CANTIDAD_ZONAS_PARQUEO>& getZonasParqueo() const;
    bool todasLasZonasOcupadas() const;
};

#endif
