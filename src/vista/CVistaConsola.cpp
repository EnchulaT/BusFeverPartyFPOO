/**
 * @file CVistaConsola.cpp
 * @brief Implementacion de la vista de consola de Bus Fever Party!
 *
 * @details
 * La vista solo MUESTRA datos y LEE lo que escribe el usuario. No decide nada
 * del juego: toda la informacion sale de los getters del Modelo (CTablero,
 * las filas de pasajeros y los vehiculos). El contrato de la clase esta en
 * CVistaConsola.h.
 *
 * @author Equipo Bus Fever Party! FPOO-C++ Edition
 */
#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
#include <vector>
#include "CVistaConsola.h"
using namespace std;

/// Ancho (en caracteres) de cada celda al dibujar el tablero.
const int ANCHO_CELDA = 5;

/// Ancho de la columna donde se escribe el numero de cada fila.
const int ANCHO_NUMERO_FILA = 3;

// -----------------------------------------------------------------------------
// Funciones auxiliares. Son "static": solo existen dentro de este archivo y no
// forman parte del contrato publico de CVistaConsola.
// -----------------------------------------------------------------------------

/**
 * @brief Convierte un color a su nombre completo.
 * @param color Color a convertir.
 * @return El nombre en mayusculas, por ejemplo "ROJO".
 */
static string colorATexto(Color color) {
    if (color == Color::ROJO) return "ROJO";
    if (color == Color::AZUL) return "AZUL";
    if (color == Color::AMARILLO) return "AMARILLO";
    if (color == Color::VERDE) return "VERDE";
    if (color == Color::MORADO) return "MORADO";
    if (color == Color::NARANJA) return "NARANJA";
    if (color == Color::ROSA) return "ROSA";
    if (color == Color::CYAN) return "CYAN";
    return "?";
}

/**
 * @brief Convierte un color a un codigo corto de 2 letras.
 * @details No se usa solo la primera letra porque varios colores empiezan
 *          igual (AZUL y AMARILLO, ROJO y ROSA).
 * @param color Color a convertir.
 * @return El codigo, por ejemplo "RO" para ROJO.
 */
static string colorACodigo(Color color) {
    if (color == Color::ROJO) return "RO";
    if (color == Color::AZUL) return "AZ";
    if (color == Color::AMARILLO) return "AM";
    if (color == Color::VERDE) return "VE";
    if (color == Color::MORADO) return "MO";
    if (color == Color::NARANJA) return "NA";
    if (color == Color::ROSA) return "RS";
    if (color == Color::CYAN) return "CY";
    return "??";
}

/**
 * @brief Convierte el tipo de vehiculo a texto.
 * @param tipo Tipo de vehiculo.
 * @return "CARRO" o "BUS".
 */
static string tipoATexto(TipoVehiculo tipo) {
    if (tipo == TipoVehiculo::CARRO) return "CARRO";
    return "BUS";
}

/**
 * @brief Convierte la orientacion a texto.
 * @param orientacion Orientacion del vehiculo.
 * @return "horizontal" o "vertical".
 */
static string orientacionATexto(Orientacion orientacion) {
    if (orientacion == Orientacion::HORIZONTAL) return "horizontal";
    return "vertical";
}

/**
 * @brief Imprime en una sola linea los datos de un vehiculo (sin salto de linea).
 * @details Ejemplo de salida: "3 - BUS VERDE (vertical), pasajeros 0/4".
 * @param vehiculo Vehiculo a imprimir (no puede ser nullptr).
 */
static void imprimirVehiculo(const CVehiculo* vehiculo) {
    cout << vehiculo->getId() << " - "
         << tipoATexto(vehiculo->getTipo()) << " "
         << colorATexto(vehiculo->getColor())
         << " (" << orientacionATexto(vehiculo->getOrientacion()) << "), "
         << "pasajeros " << vehiculo->getPasajerosActuales()
         << "/" << vehiculo->getCapacidadMaxima();
}

/**
 * @brief Busca que vehiculo ocupa una celda del tablero.
 * @details Revisa las celdas de cada vehiculo que siga en el tablero. Los
 *          vehiculos parqueados ya salieron, asi que se ignoran.
 * @param tablero Tablero donde buscar.
 * @param fila Fila de la celda.
 * @param columna Columna de la celda.
 * @return La etiqueta del vehiculo (su id seguido del codigo de color, por
 *         ejemplo "1RO"), o "." si la celda esta libre.
 */
static string etiquetaDeCelda(const CTablero& tablero, int fila, int columna) {
    CPosicion buscada{fila, columna};

    // Los vehiculos se guardan en unique_ptr, que se usa como un puntero normal (con ->).
    const vector<unique_ptr<CVehiculo>>& vehiculos = tablero.getVehiculos();
    int cantidadVehiculos = vehiculos.size();

    for (int i = 0; i < cantidadVehiculos; i++) {
        if (vehiculos[i]->estaEnParqueadero()) {
            continue; // este vehiculo ya no esta en el tablero
        }
        vector<CPosicion> celdas = vehiculos[i]->celdasOcupadas();
        int cantidadCeldas = celdas.size();
        for (int j = 0; j < cantidadCeldas; j++) {
            if (celdas[j] == buscada) {
                return to_string(vehiculos[i]->getId()) + colorACodigo(vehiculos[i]->getColor());
            }
        }
    }
    return ".";
}

// -----------------------------------------------------------------------------
// Metodos de CVistaConsola (su documentacion general esta en CVistaConsola.h)
// -----------------------------------------------------------------------------

/**
 * @details Dibuja una grilla con el numero de cada fila y columna. Cada celda
 *          muestra la etiqueta del vehiculo que la ocupa ("." si esta libre).
 *          Debajo imprime una leyenda que explica que es cada id.
 */
void CVistaConsola::mostrarTablero(const CTablero& tablero) const {
    int filas = tablero.getFilas();
    int columnas = tablero.getColumnas();

    // Encabezado: numero de cada columna.
    cout << endl << setw(ANCHO_NUMERO_FILA) << " ";
    for (int c = 0; c < columnas; c++) {
        cout << setw(ANCHO_CELDA) << c;
    }
    cout << endl;

    // Una linea por fila, empezando con su numero.
    for (int f = 0; f < filas; f++) {
        cout << setw(ANCHO_NUMERO_FILA) << f;
        for (int c = 0; c < columnas; c++) {
            cout << setw(ANCHO_CELDA) << etiquetaDeCelda(tablero, f, c);
        }
        cout << endl;
    }

    // Leyenda: que es cada id.
    cout << endl << "Vehiculos en el tablero:" << endl;
    const vector<unique_ptr<CVehiculo>>& vehiculos = tablero.getVehiculos();
    int cantidadVehiculos = vehiculos.size();
    for (int i = 0; i < cantidadVehiculos; i++) {
        if (!vehiculos[i]->estaEnParqueadero()) {
            cout << "  ";
            imprimirVehiculo(vehiculos[i].get());
            cout << endl;
        }
    }
}

/**
 * @details Solo se puede consultar al pasajero que esta en la posicion de
 *          embarque, porque CFilaRotatoria no expone las demas posiciones.
 */
void CVistaConsola::mostrarFilaRotatoria(const CFilaRotatoria& filaRotatoria) const {
    cout << endl << "Fila rotatoria (capacidad " << filaRotatoria.getCapacidad() << "): ";

    if (filaRotatoria.estaVacia()) {
        cout << "vacia" << endl;
        return;
    }

    const CPasajero* enEmbarque = filaRotatoria.verPasajeroEnEmbarque();
    if (enEmbarque != nullptr) {
        cout << "en embarque: " << colorATexto(enEmbarque->getColor());
    } else {
        cout << "la posicion de embarque esta vacia";
    }
    if (filaRotatoria.estaLlena()) {
        cout << " (llena)";
    }
    cout << endl;
}

/**
 * @details Muestra cuantos pasajeros quedan y el color del siguiente en salir.
 *          CFilaEstatica solo permite consultar al primero de la fila.
 */
void CVistaConsola::mostrarFilaEstatica(const CFilaEstatica& filaEstatica) const {
    cout << endl << "Fila estatica: ";

    if (filaEstatica.estaVacia()) {
        cout << "vacia" << endl;
        return;
    }

    cout << filaEstatica.cantidadRestante() << " pasajeros esperando";
    const CPasajero* siguiente = filaEstatica.verPrimero();
    if (siguiente != nullptr) {
        cout << " (siguiente: " << colorATexto(siguiente->getColor()) << ")";
    }
    cout << endl;
}

/**
 * @details Muestra las 4 zonas numeradas desde 1: "[libre]" si no hay nadie, o
 *          los datos del vehiculo estacionado.
 */
void CVistaConsola::mostrarZonasParqueo(const CTablero& tablero) const {
    cout << endl << "Zonas de parqueo:" << endl;

    const array<CZonaParqueo, CANTIDAD_ZONAS_PARQUEO>& zonas = tablero.getZonasParqueo();
    for (int i = 0; i < CANTIDAD_ZONAS_PARQUEO; i++) {
        cout << "  Zona " << i + 1 << ": ";
        if (zonas[i].estaLibre()) {
            cout << "[libre]";
        } else {
            cout << "[";
            imprimirVehiculo(zonas[i].getVehiculoEstacionado());
            cout << "]";
        }
        cout << endl;
    }
}

/**
 * @details Repite la pregunta mientras el usuario escriba algo que no sea un
 *          numero. Si la entrada se termina (EOF) devuelve -1, como pide el contrato.
 * @return El id escrito por el usuario, o -1 si la entrada termino.
 */
int CVistaConsola::pedirVehiculoAMover(const CTablero& tablero) const {
    int id;
    cout << "Seleccione un vehiculo (id): ";

    // Si cin no pudo leer un numero, entra al ciclo.
    while (!(cin >> id)) {
        if (cin.eof()) {
            return -1; // no hay mas entrada
        }
        cin.clear(); // quita el estado de error para poder volver a leer
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // descarta la linea mala
        cout << "Entrada no valida: escriba el numero del vehiculo." << endl;
        cout << "Seleccione un vehiculo (id): ";
    }
    return id;
}

/**
 * @details Imprime el mensaje tal cual, seguido de un salto de linea.
 */
void CVistaConsola::mostrarMensaje(const string& mensaje) const {
    cout << mensaje << endl;
}

/**
 * @details Imprime un mensaje distinto segun el estado final de la partida.
 */
void CVistaConsola::mostrarResultadoFinal(EstadoJuego estado) const {
    cout << endl;
    if (estado == EstadoJuego::GANADO) {
        cout << "*** GANASTE! Todos los pasajeros lograron abordar. ***" << endl;
    } else if (estado == EstadoJuego::PERDIDO) {
        cout << "*** PERDISTE: las zonas de parqueo estan llenas y nadie puede abordar. ***" << endl;
    } else {
        cout << "La partida sigue en curso." << endl;
    }
}
