/**
 * @file CVistaConsola.h
 * @brief CONTRATO del modulo Vista (interfaz de consola).
 *
 * ATENCION: ESTE ARCHIVO ES UN CONTRATO.
 *
 * Estandar CRC:
 *   Clase: CVistaConsola
 *   Responsabilidades:
 *     - TODA la interaccion por consola: mostrar el tablero, las filas de
 *       pasajeros, las zonas de parqueo; pedir al usuario que vehiculo mover;
 *       mostrar mensajes y el resultado final (ganaste / perdiste).
 *     - NUNCA calcula logica de negocio: solo lee datos del Modelo/Controlador
 *       (via getters) y los imprime, o lee datos del usuario con cin.
 *   Colaboradores:
 *     - CTablero, CFilaEstatica, CFilaRotatoria, CControladorJuego: de ahi lee
 *       todo lo que muestra.
 *
 * REGLAS DEL CONTRATO:
 *   - No se exige una representacion grafica elaborada: puede ser tan simple
 *     como imprimir ids/colores en texto. La prioridad (ver enunciado) es que
 *     la logica funcione, no la estetica.
 *   - pedirVehiculoAMover() debe devolver -1 si la entrada se termina (EOF),
 *     para que el programa pueda terminar en vez de quedarse esperando para
 *     siempre (importante para poder probar con stringstream/pruebas).
 *   - La conversion de Color a texto (para mostrarlo) es responsabilidad de
 *     este modulo (puede ser un metodo privado, no esta en el contrato publico).
 */
#ifndef _CVISTACONSOLA_H_
#define _CVISTACONSOLA_H_
#include <string>
#include "CTipos.h"
#include "CTablero.h"
#include "CFilaEstatica.h"
#include "CFilaRotatoria.h"
using namespace std;

class CVistaConsola
{
  public:
    void mostrarTablero(const CTablero& tablero) const;
    void mostrarFilaRotatoria(const CFilaRotatoria& filaRotatoria) const;
    void mostrarFilaEstatica(const CFilaEstatica& filaEstatica) const;
    void mostrarZonasParqueo(const CTablero& tablero) const;

    // Pide un id de vehiculo por cin. -1 si la entrada termino (EOF).
    int pedirVehiculoAMover(const CTablero& tablero) const;

    void mostrarMensaje(const string& mensaje) const;
    void mostrarResultadoFinal(EstadoJuego estado) const;
};

#endif
