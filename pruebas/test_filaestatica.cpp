#include <vector>
#include "minitest.h"
#include "CFilaEstatica.h"
using namespace std;

// true si la fila tiene un primer pasajero y es del color indicado.
bool primeroEs(const CFilaEstatica& fila, Color color) {
    const CPasajero* primero = fila.verPrimero();
    return primero != nullptr && primero->getColor() == color;
}

int main() {
    SECCION("CFilaEstatica - vacia al crear sin elementos");
    CFilaEstatica vacia{vector<CPasajero>()};
    CHECK(vacia.estaVacia());
    CHECK_EQ(vacia.cantidadRestante(), 0);
    CHECK(vacia.verPrimero() == nullptr);
    CPasajero sacado(Color::VERDE);
    CHECK(!vacia.sacarPrimero(sacado));
    CHECK(sacado.getColor() == Color::VERDE);   // no lo modifica si la fila esta vacia

    SECCION("CFilaEstatica - verPrimero no saca, sacarPrimero si");
    vector<CPasajero> secuencia = { CPasajero(Color::ROJO), CPasajero(Color::AZUL) };
    CFilaEstatica fila(secuencia);
    CHECK(!fila.estaVacia());
    CHECK(primeroEs(fila, Color::ROJO));
    CHECK(primeroEs(fila, Color::ROJO));        // consultar dos veces no lo saca
    CHECK_EQ(fila.cantidadRestante(), 2);

    CHECK(fila.sacarPrimero(sacado));
    CHECK(sacado.getColor() == Color::ROJO);
    CHECK_EQ(fila.cantidadRestante(), 1);
    CHECK(primeroEs(fila, Color::AZUL));        // el siguiente avanza al primer puesto

    CHECK(fila.sacarPrimero(sacado));
    CHECK(sacado.getColor() == Color::AZUL);
    CHECK(fila.estaVacia());
    CHECK_EQ(fila.cantidadRestante(), 0);
    CHECK(fila.verPrimero() == nullptr);

    CHECK(!fila.sacarPrimero(sacado));
    CHECK(sacado.getColor() == Color::AZUL);    // sigue siendo el ultimo que salio
    CHECK_EQ(fila.cantidadRestante(), 0);

    CHECK_EQ((int)secuencia.size(), 2);         // la fila trabaja con su propia copia

    SECCION("CFilaEstatica - respeta el orden exacto de grupos de colores");
    // como en un archivo de nivel: PASAJEROS ROJO 2 AZUL 2 VERDE 1
    vector<CPasajero> grupos = { CPasajero(Color::ROJO), CPasajero(Color::ROJO),
                                 CPasajero(Color::AZUL), CPasajero(Color::AZUL),
                                 CPasajero(Color::VERDE) };
    CFilaEstatica filaGrupos(grupos);
    vector<Color> esperado = { Color::ROJO, Color::ROJO, Color::AZUL, Color::AZUL, Color::VERDE };
    for (int i = 0; i < (int)esperado.size(); i++) {
        CHECK_EQ(filaGrupos.cantidadRestante(), (int)esperado.size() - i);
        CHECK(filaGrupos.sacarPrimero(sacado));
        CHECK(sacado.getColor() == esperado[i]);
    }
    CHECK(filaGrupos.estaVacia());

    return RESUMEN();
}
