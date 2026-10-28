# Bus Fever Party! FPOO-C++ Edition

Proyecto de curso de Fundamentos de Programacion Orientada a Objetos (Univalle).
Implementa el juego "Bus Fever Party!" en C++ con arquitectura MVC y principios SOLID.

Enunciado completo: ver el PDF del proyecto que subio el profesor.

## Integrantes

- Alan Fernando Garcia Rodriguez
- Maximiliano Díaz Zapata
- Cristhian Felipe Morales Tovar
- Juan Camilo Oliveros Fernandez
- Juan Manuel Arboleda Benavidez

Repositorio del proyecto: https://github.com/EnchulaT/BusFeverPartyFPOO

## Como esta organizado

Mismo esquema de "contratos" que usamos en el Taller 5 (Drogueria con GitHub), pero
aqui con un solo equipo: cada quien puede tomar uno o varios modulos y trabajar en
paralelo sin bloquear a los demas, porque todos programan contra un header (.h) que
ya define que recibe y que devuelve cada metodo, y un .cpp con un STUB que ya compila.

- Un header `.h` = el CONTRATO del modulo: dice que metodos tiene la clase, que
  recibe, que devuelve y que reglas debe cumplir (comentario al inicio del archivo,
  formato CRC: Clase - Responsabilidad - Colaboracion).
- El `.cpp` de cada modulo trae un STUB (compila, pero los metodos no hacen nada
  util todavia, o devuelven un valor por defecto): hay que reemplazarlo por la
  implementacion real.
- `pruebas/test_<modulo>.cpp`: pruebas iniciales + comentarios TODO con ideas de
  casos para agregar. Usan el mismo `minitest.h` del Taller 5.

## Estructura del repositorio

```
src/
  CTipos.h            enums compartidos (Color, Orientacion, TipoVehiculo, EstadoJuego...)
  CPosicion.h         struct (fila, columna) - ya implementado
  CPasajero.*          clase simple (color) - ya implementada
  main.cpp             arma el juego y corre el ciclo de turnos
  modelo/
    CVehiculo.*         clase base abstracta (CONTRATO)
    CCarro.* CBus.*     subclases de CVehiculo (CONTRATO)
    CZonaParqueo.*      una de las 4 zonas de parqueo (CONTRATO)
    CFilaEstatica.*     cola completa de pasajeros (CONTRATO)
    CFilaRotatoria.*    cola circular de embarque (CONTRATO)
    CNivel.h             DTO con los datos de un nivel ya leido - ya implementado
    CCargadorNivel.*    lee el archivo .txt de un nivel (CONTRATO, persistencia)
    CTablero.*          grid, vehiculos y zonas de parqueo (CONTRATO)
  controlador/
    CControladorJuego.* logica de negocio: mover, ciclo de embarque, victoria/derrota (CONTRATO)
  vista/
    CVistaConsola.*     interfaz de consola (CONTRATO)
pruebas/                minitest.h + un test_<modulo>.cpp por modulo
niveles/                archivos .txt de nivel (nivel1, nivel2, nivel3: dificultad creciente)
docs/                   diagrama de clases UML y plantilla para fragmentos
```

## Compilar y correr

```bash
mkdir -p build
make              # compila el programa completo (ejecutable: busfeverparty)
make test         # corre las pruebas de todos los modulos
make run-tablero  # corre solo pruebas/test_tablero.cpp (cambie 'tablero' por su modulo)
./busfeverparty niveles/nivel1.txt
```

Requieren `g++` (C++17) y `make`.

## Formato del archivo de nivel (.txt)

```
# las lineas que empiezan con # son comentarios
TABLERO <filas> <columnas>
VEHICULO <CARRO|BUS> <COLOR> <fila> <columna> <H|V> <largo> <capacidad>
... (una linea VEHICULO por cada vehiculo)
PASAJEROS <COLOR> <cantidad> <COLOR> <cantidad> ...
```

Colores validos: ROJO, AZUL, AMARILLO, VERDE, MORADO, NARANJA, ROSA, CYAN (ver `CTipos.h`).
Orientacion: `H` (horizontal) o `V` (vertical).
Ver `niveles/nivel1.txt`, `nivel2.txt` y `nivel3.txt` como ejemplos.

## Quien hace que

Esto es trabajo nuestro, no esta repartido por el profesor como en el Taller 5: nos
toca repartirnos los modulos entre nosotros. Sugerencia de division (igual de
independiente que en el taller, por eso cada modulo tiene su propio header):

| Area                       | Clases                                            |
|-----------------------------|----------------------------------------------------|
| Vehiculos y colisiones      | CVehiculo, CCarro, CBus                            |
| Tablero y zonas de parqueo  | CTablero, CZonaParqueo                             |
| Pasajeros y filas           | CFilaEstatica, CFilaRotatoria                      |
| Persistencia (niveles)      | CCargadorNivel, CNivel                             |
| Logica de negocio           | CControladorJuego                                  |
| Interfaz de consola         | CVistaConsola                                      |

Vean `REGLAS.md` para la forma de trabajo con Git/GitHub.
