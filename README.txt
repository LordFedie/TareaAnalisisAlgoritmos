# Compilación y Ejecución en WSL

Este proyecto implementa distintos algoritmos para la comparación de puntos, incluyendo Fuerza Bruta, Dividir y Conquistar, y sus versiones mejoradas.

## Archivos Relevantes
- `DividirPorConquistar.h`
- `DividirPorConquistarMejoradoTrivialmente.h`
- `FuerzaBruta.h`
- `FuerzaBrutaTrivialmenteMejorada.h`
- `uhr.cpp` (Archivo principal)
- `utils.cpp`
- `quartiles_nth.cpp`

## Pasos para Ejecutar

1. **Abrir `uhr.cpp`**
   - Desplázese hasta la sección **"FUNCIONES"**.
   - Quite el comentario a la función que desee probar (`brute_force`, `DividirPorConquistar`, `better_brute_force` o `dividirPorConquistar2`).
   - **Solo una función debe estar sin comentar** para evitar conflictos.

2. **Guardar los cambios**  
   - Una vez haya seleccionado la función, guarde el archivo `uhr.cpp`.

3. **Compilar en WSL**  
   - Abra una terminal en WSL y navegue hasta la carpeta del proyecto.
   - Ejecute el siguiente comando para compilar:

     g++ -std=c++11 -O0 -o uhr uhr.cpp

4. **Ejecutar el programa**  
   - Una vez compilado, corra el siguiente comando para ejecutar:

     ./uhr "Nombre_archivo".csv 32 8 512 2
   - Puede poner cualquier nombre al archivo .csv según sea conveniente

## Notas
- Asegúrese de tener `g++` instalado en su WSL. Si no lo tiene, instálelo con:

  sudo apt update && sudo apt install g++
