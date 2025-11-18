#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    char Chave;
    struct No *Esquerda;
    struct No *Direita;

    struct No *F[3];

} No;

No *criarNO(int Chave)
{

    No *N = (No *)malloc(sizeof(No));
    if (N == NULL)
    {
        printf("ERRO, não a memoria para o No\n");
        return NULL;
    }

    N->Chave = Chave;
    N->Esquerda = NULL;
    N->Direita = NULL;

    for (int i = 0; i < 3; i++)
    {
        N->F[i] = NULL;
    }

    return N;
}

int contarNos(No * N){
    if(N == NULL){
        return 0;

        return 1 + contarNos(N->Direita) + contarNos(N->Esquerda);


    }
}

int main()
{

    // Nivel 1

    No *Raiz = criarNO(10);

    // Nivel 2

    Raiz->Esquerda = criarNO(12);
    Raiz->Direita = criarNO(15);

    //Nivel 3

    Raiz->Esquerda->Esquerda = criarNO(16);
    Raiz->Esquerda->Direita = criarNO(18);

    Raiz->Direita->Direita = criarNO(20);

    //Nivel 4

    Raiz->Direita->Direita->Esquerda = criarNO(17);
    Raiz->Direita->Direita->Direita = criarNO(19);
}