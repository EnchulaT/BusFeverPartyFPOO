/*
    Proyecto: Bus Fever Party! FPOO-C++ Edition
    Modulo: Vista de consola

    ESTE ARCHIVO ES SUYO: reemplacen los STUB por la implementacion real.
*/
#include <iostream>
#include "CVistaConsola.h"
using namespace std;

void CVistaConsola::mostrarTablero(const CTablero& tablero) const {
    // STUB: implementar
}

void CVistaConsola::mostrarFilaRotatoria(const CFilaRotatoria& filaRotatoria) const {
    // STUB: implementar
}

void CVistaConsola::mostrarFilaEstatica(const CFilaEstatica& filaEstatica) const {
    // STUB: implementar
}

void CVistaConsola::mostrarZonasParqueo(const CTablero& tablero) const {
    // STUB: implementar
}

int CVistaConsola::pedirVehiculoAMover(const CTablero& tablero) const {
    // STUB: implementar (-1 si la entrada termina / EOF)
    cout << "Seleccione un vehiculo (id): ";
    int id;
    if (!(cin >> id)) return -1;
    return id;
}

void CVistaConsola::mostrarMensaje(const string& mensaje) const {
    cout << mensaje << endl;
}

void CVistaConsola::mostrarResultadoFinal(EstadoJuego estado) const {
    // STUB: implementar
}
