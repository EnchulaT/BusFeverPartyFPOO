# Makefile del proyecto Bus Fever Party! FPOO-C++ Edition.
#
#   make                    compila el programa (ejecutable: busfeverparty)
#   make test               compila y corre TODAS las pruebas
#   make run-tablero        corre solo pruebas/test_tablero.cpp (cambie 'tablero' por su modulo)
#   make clean              borra lo compilado
#
# Funciona en Linux, macOS y Windows (con MinGW-w64/MSYS2 y make).
# Mismo esquema que el Makefile del Taller 5 (Drogueria): no se edita en principio,
# salvo que el equipo decida agregar una nueva carpeta de fuentes.

CXX      = g++
CXXFLAGS = -std=c++17 -Wall -Isrc -Isrc/modelo -Isrc/vista -Isrc/controlador -Ipruebas -MMD -MP

ifeq ($(OS),Windows_NT)
EXE = .exe
else
EXE =
endif

# Los .cpp se buscan en estas carpetas; todo lo compilado va a build/ (carpeta plana)
vpath %.cpp src src/modelo src/vista src/controlador pruebas

SRC_LIB    = $(filter-out src/main.cpp, $(wildcard src/*.cpp src/modelo/*.cpp src/vista/*.cpp src/controlador/*.cpp))
OBJ_LIB    = $(addprefix build/, $(notdir $(SRC_LIB:.cpp=.o)))
TEST_SRC   = $(wildcard pruebas/test_*.cpp)
TEST_NAMES = $(patsubst test_%,%,$(basename $(notdir $(TEST_SRC))))

all: busfeverparty$(EXE)

busfeverparty$(EXE): $(OBJ_LIB) build/main.o
	$(CXX) $(CXXFLAGS) $^ -o $@

build/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

build/test_%$(EXE): build/test_%.o $(OBJ_LIB)
	$(CXX) $(CXXFLAGS) $^ -o $@

run-%: build/test_%$(EXE)
	$(info === pruebas de $* ===)
	@build/test_$*$(EXE)

test: $(addprefix run-, $(TEST_NAMES))

clean:
ifeq ($(OS),Windows_NT)
	-@del /Q /F build\*.o build\*.d build\*.exe busfeverparty.exe
else
	@rm -f build/*.o build/*.d build/test_* busfeverparty
endif

-include $(wildcard build/*.d)

.PHONY: all test clean
.SECONDARY:
