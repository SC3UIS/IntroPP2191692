#include <stdio.h>
#include <omp.h>

// Función para ordenar la lista utilizando el algoritmo de ordenamiento de burbuja
void bubble_sort(int [], int);

// Función para realizar la búsqueda binaria en la lista ordenada
void binary_search(int [], int, int, int);

int main() {
    int key, size, i;
    int list[25];

    // Solicitar al usuario el tamaño de la lista y los elementos
    printf("Enter size of a list: ");
    scanf("%d", &size);
    printf("Enter elements\n");
    for(i = 0; i < size; i++) {
        scanf("%d", &list[i]);
    }

    // Paralelizar la ordenación de la lista utilizando OpenMP
    #pragma omp parallel
    {
        // La directiva single asegura que la ordenación sea realizada una sola vez por el hilo maestro
        #pragma omp single
        bubble_sort(list, size);
    }

    // Solicitar al usuario la clave a buscar en la lista
    printf("\nEnter key to search\n");
    scanf("%d", &key);

    // Realizar la búsqueda binaria en la lista ordenada
    binary_search(list, 0, size, key);

    return 0;
}

// Función para ordenar la lista utilizando el algoritmo de ordenamiento de burbuja
void bubble_sort(int list[], int size) {
    int temp, i, j;

    for (i = 0; i < size; i++) {
        // La directiva for paraleliza el bucle interno de ordenamiento
        #pragma omp for
        for (j = 0; j < size - 1; j++) {
            if (list[j] > list[j + 1]) {
                // Intercambiar los elementos si están en orden incorrecto
                temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }
}

// Función para realizar la búsqueda binaria en la lista ordenada
void binary_search(int list[], int lo, int hi, int key) {
    int mid;

    // Verificar si el índice bajo supera al índice alto, lo que indica que la clave no está presente
    if (lo > hi) {
        printf("Key not found\n");
        return;
    }
    // Calcular el índice medio de la lista
    mid = (lo + hi) / 2;
    // Verificar si la clave está presente en el índice medio
    if (list[mid] == key) {
        printf("Key found\n");
    } else if (list[mid] > key) {
        // Realizar la búsqueda en la mitad inferior de la lista
        binary_search(list, lo, mid - 1, key);
    } else if (list[mid] < key) {
        // Realizar la búsqueda en la mitad superior de la lista
        binary_search(list, mid + 1, hi, key);
    }
}
