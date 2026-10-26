#include "minitest.h"
#include "CCargadorNivel.h"

int main() {
    SECCION("cargar() - archivo inexistente");
    CCargadorNivel cargador;
    CNivel nivel;
    CHECK(!cargador.cargar("niveles/no_existe.txt", nivel));

    SECCION("cargar() - nivel1.txt valido");
    // TODO: cargar "niveles/nivel1.txt" (ajustar la ruta segun desde donde se corran
    // las pruebas) y verificar filas/columnas, cantidad de vehiculos y cantidad total
    // de pasajeros en secuenciaPasajeros.

    SECCION("cargar() - archivo mal formado");
    // TODO: crear un archivo de prueba con una linea invalida (color desconocido,
    // tipo de vehiculo desconocido, etc.) y verificar que cargar() devuelva false.

    return RESUMEN();
}
