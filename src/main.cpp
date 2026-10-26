/*
    Proyecto: Bus Fever Party! FPOO-C++ Edition
    main.cpp - arma el juego a partir de los contratos y corre el ciclo de turnos.

    EN PRINCIPIO NO SE EDITA (como en el Taller 5), pero como aqui solo hay un
    equipo, si necesitan ajustar el 'cableado' (por ejemplo la ruta del nivel por
    defecto) esta bien que lo modifiquen y avisen al resto.

    Mientras los modulos sigan siendo STUB esto COMPILA pero el juego no hace
    nada util todavia: es normal, es el punto de partida.
*/
#include <iostream>
#include <memory>
#include <vector>
#include "CTipos.h"
#include "CPasajero.h"
#include "modelo/CNivel.h"
#include "modelo/CCargadorNivel.h"
#include "modelo/CVehiculo.h"
#include "modelo/CCarro.h"
#include "modelo/CBus.h"
#include "modelo/CTablero.h"
#include "modelo/CFilaEstatica.h"
#include "modelo/CFilaRotatoria.h"
#include "controlador/CControladorJuego.h"
#include "vista/CVistaConsola.h"
using namespace std;

// Crea el vehiculo concreto (CCarro o CBus) a partir de los datos leidos del nivel.
static unique_ptr<CVehiculo> crearVehiculo(int id, const CVehiculoDatos& datos) {
    if (datos.tipo == TipoVehiculo::BUS) {
        return make_unique<CBus>(id, datos.color, datos.orientacion, datos.largo, datos.capacidad, datos.posicion);
    }
    return make_unique<CCarro>(id, datos.color, datos.orientacion, datos.largo, datos.capacidad, datos.posicion);
}

// Capacidad de la fila rotatoria. El equipo puede ajustarla o leerla del nivel
// si decide agregar esa opcion al formato de archivo.
static const int CAPACIDAD_FILA_ROTATORIA = 6;

int main(int argc, char* argv[]) {
    string rutaNivel = (argc > 1) ? argv[1] : "niveles/nivel1.txt";

    CCargadorNivel cargador;
    CNivel nivel;
    if (!cargador.cargar(rutaNivel, nivel)) {
        cerr << "No se pudo cargar el nivel: " << rutaNivel << endl;
        return 1;
    }

    CTablero tablero(nivel.filas, nivel.columnas);
    int siguienteId = 1;
    for (const CVehiculoDatos& datos : nivel.vehiculos) {
        tablero.agregarVehiculo(crearVehiculo(siguienteId, datos));
        siguienteId++;
    }

    vector<CPasajero> secuencia;
    for (Color color : nivel.secuenciaPasajeros) {
        secuencia.push_back(CPasajero(color));
    }
    CFilaEstatica filaEstatica(secuencia);
    CFilaRotatoria filaRotatoria(CAPACIDAD_FILA_ROTATORIA);

    // Llenado inicial de la fila rotatoria desde la fila estatica.
    while (filaRotatoria.intentarRellenar(filaEstatica)) {
        // sigue rellenando hasta que no haya mas espacio o pasajeros
    }

    CControladorJuego controlador(tablero, filaEstatica, filaRotatoria);
    CVistaConsola vista;

    vista.mostrarMensaje("Bus Fever Party! FPOO-C++ Edition");
    while (controlador.getEstado() == EstadoJuego::EN_CURSO) {
        vista.mostrarTablero(tablero);
        vista.mostrarZonasParqueo(tablero);
        vista.mostrarFilaRotatoria(filaRotatoria);
        vista.mostrarFilaEstatica(filaEstatica);

        int idVehiculo = vista.pedirVehiculoAMover(tablero);
        if (idVehiculo == -1) break;  // entrada terminada (EOF)

        controlador.jugarTurno(idVehiculo);
    }

    vista.mostrarResultadoFinal(controlador.getEstado());
    return 0;
}
