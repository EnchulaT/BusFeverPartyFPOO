#include <vector>
#include "minitest.h"
#include "CFilaEstatica.h"
using namespace std;

int main() {
    SECCION("CFilaEstatica - vacia al crear sin elementos");
    CFilaEstatica vacia{vector<CPasajero>()};
    CHECK(vacia.estaVacia());
    CHECK_EQ(vacia.cantidadRestante(), 0);

    SECCION("CFilaEstatica - verPrimero no saca, sacarPrimero si");
    vector<CPasajero> secuencia = { CPasajero(Color::ROJO), CPasajero(Color::AZUL) };
    CFilaEstatica fila(secuencia);
    // TODO: verificar verPrimero() == ROJO y que cantidadRestante() siga en 2.
    // TODO: sacarPrimero() debe devolver true, dar ROJO, y dejar cantidadRestante() en 1.
    // TODO: sacar los dos restantes y verificar que sacarPrimero() devuelva false al final.

    return RESUMEN();
}
