#include <vector>
#include "minitest.h"
#include "CFilaRotatoria.h"
#include "CFilaEstatica.h"
using namespace std;

int main() {
    SECCION("CFilaRotatoria - capacidad y estado inicial");
    CFilaRotatoria rotatoria(4);
    CHECK_EQ(rotatoria.getCapacidad(), 4);
    CHECK(rotatoria.estaVacia());

    SECCION("intentarRellenar() desde la fila estatica");
    vector<CPasajero> secuencia = { CPasajero(Color::ROJO), CPasajero(Color::AZUL) };
    CFilaEstatica estatica(secuencia);
    // TODO: llamar intentarRellenar() repetidamente y verificar que:
    //   - rellena una posicion por llamada
    //   - deja de poder rellenar cuando la fila estatica se vacia (o la rotatoria se llena)

    SECCION("girar() y sacarPasajeroEnEmbarque()");
    // TODO: verificar que girar() rote las posiciones (el que estaba en embarque ya no esta).
    // TODO: verificar que sacarPasajeroEnEmbarque() devuelva false si la posicion de embarque esta vacia.

    return RESUMEN();
}
