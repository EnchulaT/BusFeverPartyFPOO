#include "minitest.h"
#include "modelo/CCarro.h"
#include "modelo/CBus.h"

int main() {
    SECCION("CCarro / CBus - construccion basica");
    CCarro carro(1, Color::ROJO, Orientacion::HORIZONTAL, 1, 2, CPosicion{0, 0});
    CHECK(carro.getTipo() == TipoVehiculo::CARRO);
    CHECK_EQ(carro.getId(), 1);

    CBus bus(2, Color::AZUL, Orientacion::VERTICAL, 2, 4, CPosicion{1, 1});
    CHECK(bus.getTipo() == TipoVehiculo::BUS);

    SECCION("celdasOcupadas() y subirPasajero()");
    // TODO: una vez implementado, verificar que celdasOcupadas() devuelva
    // exactamente 'largo' celdas en la direccion correcta segun 'orientacion'.
    // TODO: verificar que subirPasajero() devuelva false cuando el vehiculo ya esta lleno.

    return RESUMEN();
}
