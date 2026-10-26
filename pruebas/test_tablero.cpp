#include "minitest.h"
#include "CTablero.h"
#include "CCarro.h"
#include <memory>
using namespace std;

int main() {
    SECCION("CTablero - dimensiones");
    CTablero tablero(6, 6);
    CHECK_EQ(tablero.getFilas(), 6);
    CHECK_EQ(tablero.getColumnas(), 6);

    SECCION("agregarVehiculo() - posicion valida vs colision");
    auto carro1 = make_unique<CCarro>(1, Color::ROJO, Orientacion::HORIZONTAL, 1, 2, CPosicion{0, 0});
    CVehiculo* ptr1 = tablero.agregarVehiculo(move(carro1));
    CHECK(ptr1 != nullptr);
    // TODO: agregar otro vehiculo en la MISMA posicion y verificar que agregarVehiculo()
    // devuelva nullptr (colision).
    // TODO: agregar un vehiculo con una celda fuera del tablero (p.ej. columna = 100) y
    // verificar que tambien devuelva nullptr.

    SECCION("moverVehiculo() y zonas de parqueo");
    // TODO: una vez implementado, mover un vehiculo hasta que salga del tablero y
    // verificar que quede marcado estaEnParqueadero() == true y ocupando una CZonaParqueo.
    // TODO: verificar todasLasZonasOcupadas() con las 4 zonas llenas.

    return RESUMEN();
}
