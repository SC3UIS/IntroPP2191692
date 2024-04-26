# Evaluación 1 | C/C++ Procesamiento Memoria Compartida

Descripción:

Este trabajo se enfoca en desarrollar una búsqueda binaria paralelizada utilizando OpenMP. El código se divide en varias secciones, que incluyen el archivo principal encargado de la búsqueda, una versión paralela de la función de búsqueda, y scripts para la compilación y la ejecución del programa.

Los demás arhcivos dentro de esta carpeta abordan la complejidad de ordenamiento. Se presenta una variante del Bucket Sort que aprovecha la estructura jerárquica de los elementos. Esta variante permite agrupar los elementos en subconjuntos según similitudes, como dígitos similares en este caso, y luego reorganiza estos subgrupos para obtener una lista ordenada.

----- Implementación de Ordenamiento Paralelo con OpenMP -----

Esta implementación presenta dos algoritmos de ordenamiento paralelizados utilizando OpenMP: BinarySort y PostmanSort. El código se divide en varias partes, incluyendo archivos de código fuente para cada algoritmo de ordenamiento, archivos de encabezado que contienen las declaraciones de funciones y las definiciones de estructuras necesarias, y archivos de secuencia de comandos para la compilación y ejecución en un entorno de clúster.

####  BinarySearch

![alt text](/OpenMP/images/image.png)

####  RadixSort

![alt text](/OpenMP/images/psotrm.png)

Archivos añadidos además de los base:

1. omp_BinarySearch.c: El código fuente de la implementación paralela del algoritmo busqueda binaria (BinarySerch) utilizando OpenMP.
2. omp_PostmanSort.c: La implementación paralela del algoritmo "Bucket Sort" utilizando OpenMP.
4. BinarySearch.sbatch: Archivos de secuencia de comandos SLURM que se utilizan para compilar y ejecutar los programas en el entorno.
5. PostmanSort.sbatch: Archivos de secuencia de comandos SLURM que se utilizan para compilar y ejecutar los programas en el entorno. 
6. output_BinarySearch.txt: Incluye detalles sobre la lista ordenada y el tiempo de ejecución.
7. output_PostmanSort.txt: Archivo de salida que contiene los resultados generados por la ejecución del algoritmo.


#### Compilación

Se puede utilizar el siguiente comando para compilar.
``` gcc -fopenmp omp_BinarySearch.c -o omp_BinarySearch ```

Este comando es para compilar el programa.
``` ./omp_BinarySearch ```

Lo mismo para PostmanSort:
``` gcc -fopenmp omp_PostmanSort.c -o omp_PostmanSort ```
``` ./omp_PostmanSort ```


