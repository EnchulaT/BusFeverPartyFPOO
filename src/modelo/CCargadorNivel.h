/**
 * @file CCargadorNivel.h
 * @brief CONTRATO del modulo de Persistencia (lectura de niveles).
 *
 * ATENCION: ESTE ARCHIVO ES UN CONTRATO.
 *
 * Estandar CRC:
 *   Clase: CCargadorNivel
 *   Responsabilidades:
 *     - Leer un archivo plano (.txt) con el formato definido en el README y
 *       construir un CNivel a partir de su contenido.
 *     - Es la UNICA clase de persistencia del juego. Pertenece al Modelo: NO usa
 *       cin/cout (ni para mensajes de error), solo lee del archivo indicado.
 *   Colaboradores:
 *     - CNivel: la estructura que construye y devuelve.
 *
 * FORMATO DE ARCHIVO SUGERIDO (ver tambien niveles/nivel1.txt y el README):
 *   # las lineas que empiezan con # son comentarios y se ignoran
 *   TABLERO <filas> <columnas>
 *   VEHICULO <CARRO|BUS> <COLOR> <fila> <columna> <H|V> <largo> <capacidad>
 *   ... (una linea VEHICULO por cada vehiculo)
 *   PASAJEROS <COLOR> <cantidad> <COLOR> <cantidad> ...
 *
 * REGLAS DEL CONTRATO:
 *   - cargar() devuelve false (y NO modifica 'nivelResultado') si el archivo no
 *     existe o esta mal formado (por ejemplo, un color o tipo de vehiculo que no
 *     reconoce, o una linea TABLERO con valores invalidos).
 *   - Si cargar() devuelve true, 'nivelResultado' queda completamente lleno y listo
 *     para que CTablero y CFilaEstatica se construyan a partir de el.
 *   - La conversion de texto a Color/TipoVehiculo/Orientacion (y viceversa, si la
 *     necesitan para los mensajes de error) es responsabilidad de este modulo.
 */
#ifndef _CCARGADORNIVEL_H_
#define _CCARGADORNIVEL_H_
#include <string>
#include "CNivel.h"
using namespace std;

class CCargadorNivel
{
  public:
    // true si pudo leer y parsear el archivo correctamente (ver reglas arriba).
    bool cargar(const string& rutaArchivo, CNivel& nivelResultado) const;
};

#endif
