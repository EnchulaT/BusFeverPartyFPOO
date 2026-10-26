/**
 * @file CFilaEstatica.h
 * @brief CONTRATO del modulo Fila Estatica de pasajeros.
 *
 * ATENCION: ESTE ARCHIVO ES UN CONTRATO.
 *
 * Estandar CRC:
 *   Clase: CFilaEstatica
 *   Responsabilidades:
 *     - Contener la secuencia COMPLETA y en orden de los pasajeros que aun no
 *       han pasado a la fila rotatoria.
 *     - Solo el primer pasajero de la fila puede salir (no rota, no se puede
 *       acceder a los demas).
 *   Colaboradores:
 *     - CPasajero: lo que contiene.
 *     - CFilaRotatoria: le pide pasajeros (sacarPrimero) para rellenarse.
 *     - CCargadorNivel / CNivel: a partir de ahi se construye la secuencia inicial.
 *
 * REGLAS DEL CONTRATO:
 *   - El constructor recibe la secuencia YA ORDENADA tal como debe salir.
 *   - verPrimero() NO saca al pasajero, solo permite consultarlo (nullptr si vacia).
 *   - sacarPrimero() SI lo quita de la fila. Devuelve false (y no modifica nada)
 *     si la fila ya estaba vacia.
 */
#ifndef _CFILAESTATICA_H_
#define _CFILAESTATICA_H_
#include <vector>
#include "CPasajero.h"
using namespace std;

class CFilaEstatica
{
  private:
    vector<CPasajero> pasajeros;

  public:
    explicit CFilaEstatica(const vector<CPasajero>& secuencia);

    bool estaVacia() const;
    int cantidadRestante() const;

    // No saca al pasajero, solo lo consulta. nullptr si la fila esta vacia.
    const CPasajero* verPrimero() const;

    // Saca al primer pasajero y lo copia en 'pasajeroSacado'. false si la fila estaba vacia.
    bool sacarPrimero(CPasajero& pasajeroSacado);
};

#endif
