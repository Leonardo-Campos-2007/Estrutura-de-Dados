#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO 150000

void InsertonSort(int *V, int N);

void ExibirVetor(int *V, int N);

int main()
{

    int Conjunto[TAMANHO];

    srand(time(NULL));

    for (int i = 0; i < TAMANHO; i++)
    {
        Conjunto[i] = rand() % 1000;
    }

    int Tamanho = sizeof(Conjunto) / sizeof(int);

    clock_t T0 = clock();
    InsertonSort(Conjunto, Tamanho);
    clock_t TF = clock();

    printf("Tempo de CPU: %f\n", (double)(TF - T0)/(CLOCKS_PER_SEC) );
    ExibirVetor(Conjunto, Tamanho);
}

void InsertonSort(int *V, int N)
{
    int Chave;
    int i;
    int j;

    for (int i = 1; i < N; i++)
    {
        Chave = V[i];
        j = i - 1;

        while (j >= 0 && V[j] > Chave)
        {
            V[j + 1] = V[j];
            j--;
        }

        V[j + 1] = Chave;

        ExibirVetor(V, N);
    }
}

void ExibirVetor(int *V, int N)
{

    for (int i = 0; i < N; i++)
    {
        printf("%d\t", V[i]);
    }

    printf("\n");
}
