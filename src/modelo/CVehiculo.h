/**
 * @file CVehiculo.h
 * @brief CONTRATO del modulo Vehiculo (clase base abstracta).
 *
 * ATENCION: ESTE ARCHIVO ES UN CONTRATO. En principio no se edita; si el equipo
 * decide que falta o sobra un metodo, se discute entre todos antes de cambiarlo
 * (aqui no hay 'profesor' que arbitre, asi que el acuerdo lo toman ustedes).
 *
 * Estandar CRC:
 *   Clase: CVehiculo (abstracta)
 *   Responsabilidades:
 *     - Representar un vehiculo del tablero: id, color, orientacion fija,
 *       tamanio (cuantas celdas ocupa), capacidad de pasajeros y posicion actual.
 *     - Calcular que celdas ocupa segun su posicion, orientacion y largo.
 *     - Llevar la cuenta de pasajeros que ha recogido (sin superar su capacidad).
 *     - NO decide si puede moverse (eso es responsabilidad de CTablero, que conoce
 *       a TODOS los vehiculos y puede detectar colisiones entre ellos).
 *   Colaboradores:
 *     - CTablero: pregunta la posicion/celdas ocupadas para detectar colisiones,
 *       y es quien actualiza la posicion del vehiculo al moverlo.
 *     - CZonaParqueo: guarda un puntero al vehiculo que esta estacionado.
 *     - CPasajero / CControladorJuego: usan getColor() y subirPasajero() para el
 *       ciclo de embarque.
 *
 * REGLAS DEL CONTRATO:
 *   - El vehiculo es abstracto: no se puede instanciar directamente, solo a traves
 *     de CCarro o CBus (ver getTipo()).
 *   - 'posicion' representa la celda de referencia del vehiculo (por convencion: la
 *     celda "de atras", desde la que avanza). celdasOcupadas() debe devolver esa
 *     celda mas las siguientes 'largo - 1' celdas en la direccion de 'orientacion'.
 *   - subirPasajero() debe fallar (devolver false) si el vehiculo ya esta lleno.
 *   - Documenten en el .cpp cualquier decision de diseno que tomen (p.ej. si
 *     'orientacion' + 'largo' se interpreta creciendo en fila o en columna).
 */
#ifndef _CVEHICULO_H_
#define _CVEHICULO_H_
#include <vector>
#include "CTipos.h"
#include "CPosicion.h"
using namespace std;

class CVehiculo
{
  protected:
    int id;
    Color color;
    Orientacion orientacion;
    int largo;              // cuantas celdas ocupa (1 para un carro pequenio, 2 o mas para un bus)
    int capacidadMaxima;
    int pasajerosActuales;
    CPosicion posicion;      // celda de referencia (ver nota en el contrato)
    bool enParqueadero;

  public:
    CVehiculo(int id, Color color, Orientacion orientacion, int largo, int capacidadMaxima, CPosicion posicion);
    virtual ~CVehiculo() = default;

    // Cada subclase indica que tipo de vehiculo es.
    virtual TipoVehiculo getTipo() const = 0;

    int getId() const;
    Color getColor() const;
    Orientacion getOrientacion() const;
    int getLargo() const;
    int getCapacidadMaxima() const;
    int getPasajerosActuales() const;
    bool estaLleno() const;

    CPosicion getPosicion() const;
    void setPosicion(const CPosicion& nuevaPosicion);

    // Todas las celdas que ocupa el vehiculo en el tablero (ver nota del contrato).
    vector<CPosicion> celdasOcupadas() const;

    bool estaEnParqueadero() const;
    void setEnParqueadero(bool valor);

    // Sube un pasajero si hay cupo. Devuelve false si el vehiculo ya estaba lleno.
    bool subirPasajero();
};

#endif
