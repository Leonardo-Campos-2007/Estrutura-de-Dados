#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO 200

int main() {
    int Soma = 0;
    int V[TAMANHO];  // vetor para armazenar os números

    srand(time(NULL));

    // Geração dos números aleatórios
    for (int i = 0; i < TAMANHO; i++) {
        V[i] = rand() % 1000;
        printf("%d\n", V[i]);
        Soma += V[i];
    }

    // Medir tempo para imprimir os números
    clock_t T0 = clock();

    for (int i = 0; i < TAMANHO; i++) {
        printf("%d\t", V[i]);
    }

    clock_t TF = clock();

    double TempoCPU = (double)(TF - T0) / CLOCKS_PER_SEC;

    printf("\nTEMPO DE CPU %.6f segundos\n", TempoCPU);
    printf("Soma dos numeros: %d\n", Soma);

    return 0;
}
