#include <stdio.h>
#include <omp.h> 

void arrange(int, int);
int array[100], array1[100];
int i, j, temp, max, count, maxdigits = 0, c = 0;

int main() {
    int t1, t2, k, t, n = 1;

    printf("Enter size of array :");
    scanf("%d", &count);
    printf("Enter elements into array :");
    for (i = 0; i < count; i++) {
        scanf("%d", &array[i]);
        array1[i] = array[i];
    }

    // Paralelizando o cálculo do número de dígitos mais significativos
#pragma omp parallel for private(i, c) shared(maxdigits)
    for (i = 0; i < count; i++) {
        t = array[i]; /*first element in t */
        while (t > 0) {
            c++;
            t = t / 10; /* Find MSB */
        }
#pragma omp critical
        {
            if (maxdigits < c)
                maxdigits = c; /* number of digits of each number */
        }
        c = 0;
    }
    while (--maxdigits)
        n = n * 10;

    // Ordenando com base no dígito mais significativo
    for (i = 0; i < count; i++) {
        max = array[i] / n; /* MSB - Dividing by particular base */
        t = i;
        for (j = i + 1; j < count; j++) {
            if (max > (array[j] / n)) {
                max = array[j] / n; /* greatest MSB */
                t = j;
            }
        }
        temp = array1[t];
        array1[t] = array1[i];
        array1[i] = temp;
        temp = array[t];
        array[t] = array[i];
        array[i] = temp;
    }

    // Ordenando os números com o mesmo dígito mais significativo
    while (n >= 1) {
#pragma omp parallel for private(i, j, t1) shared(n)
        for (i = 0; i < count;) {
            t1 = array[i] / n;
            int start = i;
            for (j = i + 1; t1 == (array[j] / n); j++)
                ;
#pragma omp task // Executando a função arrange como uma tarefa OpenMP
            arrange(start, j);
            i = j;
        }
        n = n / 10;
    }

    // Imprimindo o array ordenado
    printf("\nSorted Array (Postman sort) :");
    for (i = 0; i < count; i++)
        printf("%d ", array1[i]);
    printf("\n");

    return 0;
}

/* Function to arrange the sequence having same base */
void arrange(int k, int n) {
    for (i = k; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (array1[i] > array1[j]) {
                temp = array1[i];
                array1[i] = array1[j];
                array1[j] = temp;
                temp = (array[i] % 10);
                array[i] = (array[j] % 10);
                array[j] = temp;
            }
        }
    }
}
