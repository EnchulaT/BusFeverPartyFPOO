#include <vector>
#include "minitest.h"
#include "CTablero.h"
#include "CFilaEstatica.h"
#include "CFilaRotatoria.h"
#include "CControladorJuego.h"
using namespace std;

int main() {
    SECCION("CControladorJuego - estado inicial EN_CURSO");
    CTablero tablero(6, 6);
    CFilaEstatica filaEstatica{vector<CPasajero>()};
    CFilaRotatoria filaRotatoria(4);
    CControladorJuego controlador(tablero, filaEstatica, filaRotatoria);
    CHECK(controlador.getEstado() == EstadoJuego::EN_CURSO);

    SECCION("verificarVictoria() con todas las filas vacias");
    // TODO: con fila estatica y fila rotatoria vacias desde el inicio, decidir si
    // eso cuenta como "ya gano" y verificarlo.

    SECCION("ejecutarCicloEmbarque() - caso basico");
    // TODO: armar un tablero con un vehiculo parqueado y un pasajero de su color en
    // la posicion de embarque, llamar a ejecutarCicloEmbarque() y verificar que el
    // pasajero aborde (el vehiculo tenga un pasajero mas) y la fila rotatoria se
    // rellene desde la estatica.

    SECCION("verificarDerrota() - 4 zonas ocupadas sin coincidencia de color");
    // TODO: simular las 4 zonas ocupadas con colores que no coinciden con el
    // pasajero en la posicion de embarque, y verificar que el estado pase a PERDIDO.

    return RESUMEN();
}
