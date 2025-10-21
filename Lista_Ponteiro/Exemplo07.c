#include <stdio.h>
#include <stdlib.h>

typedef struct Item
{

    int Chave;
    struct Item *Proximo;

} Item;

Item *CriarItem(int Chave);

void ExibirLista(Item *Inicio);

void InserirItem(Item *Inicio, Item *I, int Posicao);

void ExcluirItem(Item *Inicio, int Posicao);

int main()
{

    Item *A = CriarItem(17);
    Item *B = CriarItem(29);
    Item *C = CriarItem(41);
    Item *D = CriarItem(97);

    A->Proximo = B;
    B->Proximo = C;
    C->Proximo = D;

    ExibirLista(A);

    Item *P = CriarItem(67);
    P->Proximo = D;
    C->Proximo = P;
    ExibirLista(A);
    
    A->Proximo = C;
    free(B);
    ExibirLista(A);
}

Item *CriarItem(int Chave)
{
    Item *X = (Item *)malloc(sizeof(Item));

    X->Chave = Chave;

    X->Proximo = NULL;

    return X;
}

void ExibirLista(Item *Inicio)
{

    Item *X = Inicio;

    for (int i = 0; X != NULL; i++, X = X->Proximo)
    {
        printf("%d\t", X->Chave );
    }
    printf("\n");
}