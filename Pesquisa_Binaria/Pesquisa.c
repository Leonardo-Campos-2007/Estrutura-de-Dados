#include <stdio.h>
#include <stdlib.h>

#define ERRO -1

int PB(int *V, int n, int Chave);

int main()
{
    int Numeros[] = {1, 2, 4, 5, 6, 7, 8, 10, 12, 14, 16, 18, 20, 21, 22};

    int Tamanho = sizeof(Numeros) / sizeof(int);

    int Elemento = 12;

    int Posicao = PB(Numeros, Tamanho, Elemento);

    if (Posicao != ERRO)
    {
        printf("A posicao eh %d. \n", Posicao);
    }
}