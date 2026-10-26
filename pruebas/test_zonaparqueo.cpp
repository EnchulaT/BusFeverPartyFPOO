#include "minitest.h"
#include "modelo/CZonaParqueo.h"
#include "modelo/CCarro.h"

int main() {
    SECCION("CZonaParqueo - asignar y liberar");
    CZonaParqueo zona(0);
    CHECK(zona.estaLibre());

    CCarro carro(1, Color::VERDE, Orientacion::HORIZONTAL, 1, 2, CPosicion{0, 0});
    CHECK(zona.asignarVehiculo(&carro));
    // TODO: verificar que estaLibre() sea false despues de asignar.
    // TODO: verificar que asignarVehiculo() devuelva false si la zona ya estaba ocupada.
    // TODO: verificar que liberar() deje la zona libre otra vez.

    return RESUMEN();
}
