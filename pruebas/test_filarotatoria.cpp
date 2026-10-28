#include <vector>
#include "minitest.h"
#include "CFilaRotatoria.h"
#include "CFilaEstatica.h"
using namespace std;

// true si hay un pasajero en la posicion de embarque y es del color indicado.
bool embarqueEs(const CFilaRotatoria& fila, Color color) {
    const CPasajero* pasajero = fila.verPasajeroEnEmbarque();
    return pasajero != nullptr && pasajero->getColor() == color;
}

int main() {
    SECCION("CFilaRotatoria - capacidad y estado inicial");
    CFilaRotatoria rotatoria(4);
    CHECK_EQ(rotatoria.getCapacidad(), 4);
    CHECK(rotatoria.estaVacia());
    CHECK(!rotatoria.estaLlena());
    CHECK(rotatoria.verPasajeroEnEmbarque() == nullptr);

    SECCION("intentarRellenar() desde la fila estatica");
    vector<CPasajero> secuencia = { CPasajero(Color::ROJO), CPasajero(Color::AZUL) };
    CFilaEstatica estatica(secuencia);
    CHECK(rotatoria.intentarRellenar(estatica));
    CHECK_EQ(estatica.cantidadRestante(), 1);       // rellena una sola posicion por llamada
    CHECK(!rotatoria.estaVacia());
    CHECK(embarqueEs(rotatoria, Color::ROJO));      // el primero de la estatica queda en embarque
    CHECK(rotatoria.intentarRellenar(estatica));
    CHECK_EQ(estatica.cantidadRestante(), 0);
    CHECK(embarqueEs(rotatoria, Color::ROJO));      // el segundo no le quita el puesto al primero
    CHECK(!rotatoria.intentarRellenar(estatica));   // la fila estatica ya esta vacia
    CHECK(!rotatoria.estaLlena());                  // quedaron 2 de 4 puestos ocupados

    SECCION("intentarRellenar() no pasa de la capacidad");
    vector<CPasajero> muchos = { CPasajero(Color::ROJO), CPasajero(Color::AZUL), CPasajero(Color::VERDE),
                                 CPasajero(Color::AMARILLO), CPasajero(Color::MORADO), CPasajero(Color::NARANJA) };
    CFilaEstatica estaticaLarga(muchos);
    CFilaRotatoria pequena(3);
    int rellenos = 0;
    while (pequena.intentarRellenar(estaticaLarga)) {
        rellenos++;
    }
    CHECK_EQ(rellenos, 3);
    CHECK(pequena.estaLlena());
    CHECK_EQ(estaticaLarga.cantidadRestante(), 3);
    CHECK(!pequena.intentarRellenar(estaticaLarga));
    CHECK_EQ(estaticaLarga.cantidadRestante(), 3);  // estando llena no saca a nadie de la estatica

    SECCION("girar() y sacarPasajeroEnEmbarque()");
    // pequena tiene [ROJO, AZUL, VERDE] con ROJO en embarque
    pequena.girar();
    CHECK(embarqueEs(pequena, Color::AZUL));        // el que estaba en embarque ya no esta
    pequena.girar();
    CHECK(embarqueEs(pequena, Color::VERDE));
    pequena.girar();
    CHECK(embarqueEs(pequena, Color::ROJO));        // tres giros = vuelta completa
    CHECK(pequena.estaLlena());                     // girar no pierde pasajeros

    CHECK(pequena.sacarPasajeroEnEmbarque());
    CHECK(pequena.verPasajeroEnEmbarque() == nullptr);
    CHECK(!pequena.estaLlena());
    CHECK(!pequena.sacarPasajeroEnEmbarque());      // la posicion de embarque ya estaba vacia

    // el puesto que quedo libre lo ocupa el primero de la fila estatica
    CHECK(pequena.intentarRellenar(estaticaLarga));
    CHECK(embarqueEs(pequena, Color::AMARILLO));
    CHECK(pequena.estaLlena());
    CHECK_EQ(estaticaLarga.cantidadRestante(), 2);

    SECCION("girar() tambien mueve los puestos vacios");
    CFilaRotatoria conHueco(3);
    CFilaEstatica dos(vector<CPasajero>{ CPasajero(Color::ROJO), CPasajero(Color::AZUL) });
    conHueco.intentarRellenar(dos);
    conHueco.intentarRellenar(dos);                 // [ROJO, AZUL, vacio]
    conHueco.girar();                               // [AZUL, vacio, ROJO]
    CHECK(embarqueEs(conHueco, Color::AZUL));
    conHueco.girar();                               // [vacio, ROJO, AZUL]
    CHECK(conHueco.verPasajeroEnEmbarque() == nullptr);
    CHECK(!conHueco.estaVacia());
    conHueco.girar();                               // [ROJO, AZUL, vacio]
    CHECK(embarqueEs(conHueco, Color::ROJO));

    SECCION("vaciar la fila rotatoria por completo");
    CHECK(conHueco.sacarPasajeroEnEmbarque());      // sale ROJO
    conHueco.girar();
    CHECK(conHueco.sacarPasajeroEnEmbarque());      // sale AZUL
    CHECK(conHueco.estaVacia());
    conHueco.girar();                               // girar vacia no falla
    CHECK(conHueco.estaVacia());

    return RESUMEN();
}
