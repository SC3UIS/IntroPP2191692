# Evaluación 2 (25%) C/C++ Procesamiento Memoria Distribuída (En Parejas o Trios)

En esta evaluación, se busca realizar un seguimiento del uso de memoria distribuida a través del paso de mensajes utilizando MPI (Message Passing Interface), el cual es un estándar de comunicación utilizado en la programación paralela que permite a los procesos en un sistema distribuido intercambiar datos y coordinar sus acciones de manera eficiente.

![mpi communication](/MPI/images/mpi-point-to-point_communication.png)

MPI se utiliza comúnmente en aplicaciones de alto rendimiento donde es necesario procesar grandes cantidades de datos de manera simultánea. Permite a los desarrolladores crear programas paralelos que pueden ejecutarse en clústeres de computadoras, aprovechando al máximo los recursos disponibles y reduciendo el tiempo de procesamiento.

mpicc -fopenmp hello.c -o hello

mpicc -fopenmp mpi_binarySearch.c -o mpi_binarySearch -> compila el programa manualmente
mpirun ./mpi_binarySearch -> ejecuta el archive compilado de MPI manualmente

sbatch mpi_binarySearch.sbatch -> ejecuta con sbatch y da una salida en txt

nano output_binarySearch_MPI.txt  -> revisar el output del sbatch

nano output_binarySearch_MPI.txt  -> reserva

srun -n 4 --pty bash -> reserva interactiva

Dentro de la reserva interactiva se pueden ejecutar los demás comandos.