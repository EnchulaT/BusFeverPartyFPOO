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
7. **Trabajo en ramas:** cada quien (o cada pareja) trabaja en su propia rama
   (`feature/tablero`, `feature/controlador`, etc.) y abre un Pull Request hacia
   `main` para que el resto revise antes de mezclar, igual que hicimos en el Taller 5.
8. **Los modulos son independientes:** no esperen a que otro termine su parte.
   Programen contra el header (contrato) del modulo que necesiten; su STUB ya compila.
