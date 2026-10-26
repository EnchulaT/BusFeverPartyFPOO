/**
 * minitest.h - Mini framework de pruebas para el proyecto Bus Fever Party!
 * (identico al usado en el Taller 5 - Drogueria). ATENCION: este archivo NO se edita.
 *
 * Uso:
 *   CHECK(condicion);             -> pasa si la condicion es true
 *   CHECK_EQ(obtenido, esperado); -> pasa si son iguales (deben poder imprimirse con <<)
 *   CHECK_NEAR(a, b, tolerancia); -> para numeros reales (float/double)
 *   CHECK_CONTIENE(texto, trozo); -> pasa si "texto" contiene "trozo"
 *   SECCION("titulo");            -> imprime un titulo para agrupar pruebas
 *   return RESUMEN();             -> al final del main
 *
 * Para comparar enum class u otros tipos no imprimibles use CHECK(a == b).
 * Para comparar tamanios use un cast: CHECK_EQ((int)v.size(), 2);
 */
#ifndef _MINITEST_H_
#define _MINITEST_H_
#include <iostream>
#include <sstream>
#include <string>
#include <cmath>

namespace minitest {
    inline int& pasaron()  { static int n = 0; return n; }
    inline int& fallaron() { static int n = 0; return n; }

    inline void registrar(bool ok, const std::string& descripcion, const char* archivo, int linea) {
        if (ok) {
            pasaron()++;
        } else {
            fallaron()++;
            std::cout << "  [FALLO] " << descripcion << "   (" << archivo << ":" << linea << ")" << std::endl;
        }
    }

    inline bool contiene(const std::string& texto, const std::string& trozo) {
        return texto.find(trozo) != std::string::npos;
    }

    inline int resumen(const char* archivo) {
        std::cout << "  -> " << pasaron() << " pruebas OK, " << fallaron() << " fallidas  (" << archivo << ")" << std::endl;
        return 0;   // el resultado se lee en la salida; 0 evita que make muestre "Error" por pruebas fallidas
    }
}

#define SECCION(titulo) std::cout << "- " << titulo << std::endl

#define CHECK(cond) minitest::registrar((cond), #cond, __FILE__, __LINE__)

#define CHECK_EQ(a, b) do { \
    auto _obtenido = (a); auto _esperado = (b); \
    bool _ok = (_obtenido == _esperado); \
    std::ostringstream _os; \
    _os << #a << " == " << #b; \
    if (!_ok) _os << "   [obtenido: " << _obtenido << " | esperado: " << _esperado << "]"; \
    minitest::registrar(_ok, _os.str(), __FILE__, __LINE__); \
} while (0)

#define CHECK_NEAR(a, b, tol) minitest::registrar( \
    std::fabs((double)(a) - (double)(b)) <= (tol), \
    std::string(#a) + " ~= " + #b, __FILE__, __LINE__)

#define CHECK_CONTIENE(texto, trozo) minitest::registrar( \
    minitest::contiene((texto), (trozo)), \
    std::string("el texto contiene ") + #trozo, __FILE__, __LINE__)

#define RESUMEN() minitest::resumen(__FILE__)

#endif
