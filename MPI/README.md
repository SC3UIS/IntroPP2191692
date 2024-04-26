# Evaluación 2 (25%) C/C++ Procesamiento Memoria Distribuída (En Parejas o Trios)

En esta evaluación, se busca realizar un seguimiento del uso de memoria distribuida a través del paso de mensajes utilizando MPI (Message Passing Interface), el cual es un estándar de comunicación utilizado en la programación paralela que permite a los procesos en un sistema distribuido intercambiar datos y coordinar sus acciones de manera eficiente.

![mpi communication](/MPI/images/mpi-point-to-point_communication.png)

**MPI** se utiliza comúnmente en aplicaciones de alto rendimiento donde es necesario procesar grandes cantidades de datos de manera simultánea. Permite a los desarrolladores crear programas paralelos que pueden ejecutarse en clústeres de computadoras, aprovechando al máximo los recursos disponibles y reduciendo el tiempo de procesamiento.

## Explicación de la solución

- En el algoritmo paralelizado con MPI, se inicializa el entorno MPI y se declaran las variables de rango, el tamaño, la clave a buscar, list, y variables para medir el tiempo de ejecución. 

``` mpicc -fopenmp hello.c -o hello ```

La lista se divide en sublistas para que cada proceso MPI pueda ordenar una porción de ella, utilizando MPI_Scatter para distribuir la lista entre los procesos. Luego, se inicia el temporizador y se ordena cada sublista utilizando el algoritmo de ordenamiento de burbuja en la función bubble_sort(). Posteriormente, se utiliza MPI_Gather para reunir las sublistas ordenadas en el proceso raíz. Los procesos MPI se sincronizan y se mide y muestra el tiempo tomado para ordenar la lista. Si el proceso es el raíz, se lee la clave de búsqueda. Utilizando MPI_Bcast, se transmite la clave de búsqueda a todos los procesos. Se inicia el temporizador y cada proceso realiza una búsqueda binaria en su sublista utilizando la función binary_search(). Se sincronizan los procesos MPI y se mide y muestra el tiempo tomado para realizar la búsqueda.

![uno](/MPI/images/uno.jpeg)

Compila el programa manualmente
``` mpicc -fopenmp mpi_binarySearch.c -o mpi_binarySearch ```

Ejecuta el archive compilado de MPI manualmente
``` mpirun ./mpi_binarySearch ```

Ejecuta con sbatch y da una salida en txt
``` sbatch mpi_binarySearch.sbatch ```

Revisar el output del sbatch
``` nano output_binarySearch_MPI.txt ```

Para paralelizar este algoritmo con MPI, en primer lugar, el proceso raíz inicializa el conjunto de datos y comienza la primera fase del algoritmo, que implica ordenar los elementos basándose en el número de dígitos. Luego, se comparten las variables necesarias para el algoritmo (como el tamaño del conjunto de datos) mediante un broadcast. Es crucial dividir equitativamente el conjunto de datos entre los procesos, y esto se logra gracias a la función MPI_Scatter. Una vez que cada proceso ha completado la segunda fase del ordenamiento en su subconjunto de datos, se reúnen estos subconjuntos con MPI_Gather, y se registra el tiempo del proceso que más tardó en ordenar su subconjunto como el tiempo total de ejecución.

![uno](/MPI/images/dos.jpeg)

Reserva
``` nano output_binarySearch_MPI.txt ```

Reserva interactiva
``` srun -n 4 --pty bash ```

*Nota:* Cuanto se está dentro de la reserva interactiva se pueden ejecutar los demás comandos.

**Aquí están el archivo output y el error.**

![output](/MPI/images/archivoOutput.png)

![Error](/MPI/images/archivoError.png)


## Conclusiones
En la paralelización que realizamos con MPI se logró distribuir la carga de trabajo entre los procesos, permitiendo un procesamiento más eficiente de la lista y una reducción interesante en el tiempo de ejecución en comparación con un enfoque secuencial, con el proceso realizado anteriormente. Teniendo en cuenta el sobrecosto de la comunicación MPI, que puede afectar el rendimiento en situaciones donde el tamaño de la lista es pequeño o el número de procesos es demasiado grande, en determinados casos puede ser muy utilies pero también hay que saber en cuales no lo es y distinguir las caracteriticas de cada procesos y algoritmo de paraleización para tomar la decisión adecuada.

**Esta evaluación fue realizada por Carlos SanJuan (2171998) & Valentina Galeano (2191692)**