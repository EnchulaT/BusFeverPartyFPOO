# Reglas de trabajo (equipo propio, basado en el Taller 5)

Como aqui NO hay 8 grupos ni un monitor que arbitre, estas reglas son una guia que
nos pusimos nosotros mismos para poder trabajar en paralelo sin pisarnos, tomando
lo que nos sirvio del Taller 5 de la Drogueria.

1. **Antes de tocar codigo, pongannse de acuerdo en quien toma que modulo** (ver
   la tabla en `README.md`). Evita que dos personas reescriban lo mismo.
2. **Los headers `.h` son el contrato del modulo.** Si alguien cree que falta un
   metodo o hay un error de diseno, se discute en el equipo (chat, en persona, o un
   issue en GitHub) ANTES de cambiarlo, para que no se rompa el codigo de otro que
   ya este usando ese header.
3. **Modelo y vista no se mezclan:** las clases de `src/modelo/` y `src/controlador/`
   nunca usan `cin`/`cout`; `src/vista/CVistaConsola` nunca calcula logica de negocio.
4. **Cada modulo que implementen debe traer sus pruebas** en verde (las iniciales +
   las que agreguen cubriendo los TODO).
5. **Commits pequenios y con mensajes claros** (ej: `CTablero: implementa moverVehiculo`).
6. **Antes de hacer push:** `git pull` de la rama, `make` sin errores y `make test`
   revisando que las pruebas de su modulo pasen.
7. **Trabajo en ramas:** cada quien (o cada pareja) trabaja en su propia rama y abre
   un Pull Request hacia `main` para que el resto revise antes de mezclar, igual que
   hicimos en el Taller 5 (ver la seccion de comandos mas abajo).
8. **Los modulos son independientes:** no esperen a que otro termine su parte.
   Programen contra el header (contrato) del modulo que necesiten; su STUB ya compila.

## Flujo de trabajo con Git, paso a paso

Esta seccion trae los comandos exactos para trabajar su modulo sin chocar con los
de los demas. Reemplacen `<modulo>` por el nombre corto de su modulo en minusculas
(por ejemplo: `tablero`, `vehiculo`, `filaestatica`, `filarotatoria`, `zonaparqueo`,
`cargadornivel`, `controlador`, `vista`) y `<NombreModulo>` por el nombre real de la
clase que estan implementando (ej. `CTablero`, `CControladorJuego`).

### Paso 1. Clonar el repositorio (una sola vez, si aun no lo tienen)

```bash
git clone https://github.com/EnchulaT/BusFeverPartyFPOO.git
cd BusFeverPartyFPOO
```

### Paso 2. Actualizar `main` antes de empezar

Siempre que vayan a arrancar o retomar trabajo, primero traigan lo ultimo de `main`:

```bash
git checkout main
git pull origin main
```

### Paso 3. Crear (o retomar) la rama de su modulo

La primera vez que alguien del equipo trabaja ese modulo, crea la rama:

```bash
git checkout -b feature/<modulo>
git push -u origin feature/<modulo>
```

Si la rama ya existe (otro compañero la creo, o ustedes mismos antes), solo traiganla:

```bash
git fetch origin
git checkout feature/<modulo>
git pull origin feature/<modulo>
```

### Paso 4. Compilar y ver sus pruebas (probablemente en rojo al inicio)

```bash
mkdir -p build          # si no existe
make                     # compila el programa completo
make run-<modulo>        # corre solo las pruebas de su modulo
```

Necesitan `g++` (con soporte C++17) y `make` instalados.

### Paso 5. Implementar y probar

Editen SOLO los archivos de su modulo (el `.h` no se toca salvo acuerdo del equipo,
ver regla 2):

```bash
# ejemplo con el modulo tablero:
# - src/modelo/CTablero.cpp         <- aqui reemplazan los STUB
# - pruebas/test_tablero.cpp        <- aqui agregan sus propias pruebas (los TODO)

make run-<modulo>        # verifiquen sus pruebas cada vez que cambien algo
```

### Paso 6. Guardar sus cambios (commits pequeños)

```bash
git status                                    # revisen que solo esten sus archivos
git add src/modelo/C<NombreModulo>.cpp pruebas/test_<modulo>.cpp
git commit -m "<NombreModulo>: implementa <que hicieron>"
```

Repitan el Paso 5 y el Paso 6 las veces que necesiten (commits chiquitos > un commit gigante).

### Paso 7. Mantenerse al dia con `main`

Antes de abrir el Pull Request, y cada vez que se integre el trabajo de otro
compañero a `main`, traigan esos cambios a su rama:

```bash
git fetch origin
git merge origin/main
# si hay conflicto, resuelvanlo (ver abajo "Si Git marca un conflicto"),
# luego: git add <archivo-en-conflicto>  &&  git commit
```

### Paso 8. Subir y abrir el Pull Request

```bash
git push origin feature/<modulo>
```

Luego, desde GitHub (en el repo, boton "Compare & pull request"), abran el PR de
`feature/<modulo>` hacia `main`. El titulo sugerido: `<NombreModulo>: <resumen corto>`
(ej. `CTablero: implementa movimiento y colisiones`). Se llena solo con la plantilla
de `.github/pull_request_template.md`: completenla antes de pedir revision.

### Paso 9. Revision y fusion

Alguien del equipo (no el autor) revisa el PR en GitHub. Si piden cambios, hagan
nuevos commits y `git push` sobre la MISMA rama (`feature/<modulo>`): el PR se
actualiza solo. Cuando este aprobado, se mezcla a `main` desde GitHub ("Merge pull
request" o "Squash and merge", lo que el equipo prefiera).

### Si Git marca un conflicto

No borren cosas al azar. Abran el archivo en conflicto, busquen las marcas
`<<<<<<<`, `=======` y `>>>>>>>`, decidan en equipo que version debe quedar
(o combinen ambas a mano), borren las marcas, y luego:

```bash
git add <archivo-que-tenia-el-conflicto>
git commit
```

(o `git merge --continue` si estaban en medio de un `git merge`). Si no estan
seguros, pregunten al equipo antes de seguir.
