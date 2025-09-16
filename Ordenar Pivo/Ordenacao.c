#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void TrocarElemento(int *A, int *B);

int Particao(int *V, int Inf, int Sup);

int main()
{

    int Vetor[] = {3, 6, 4, 5, 1, 7, 2};
    int Tamanho = sizeof(Vetor) / sizeof(int);
    Particao(Vetor, 1, 4);
}

void TrocarElemento(int *A, int *B)
{

    int temp = *A;
    *A = *B;
    *B = temp;
}

int Particao(int *V, int Inf, int Sup)
{
    int Pivot = V[(Inf + Sup) / 2];
    int i = Inf;
    int j = Sup;

    while (i <= j)
    {
        while (V[i] < Pivot)
        {
            i++;
        }

        while (V[j] > Pivot)
        {
            j--;
        }

        if (i <= j)
        {
            TrocarElemento(&V[i], &V[j]);
            i++;
            j--;
        }
    }

    return i;
}



