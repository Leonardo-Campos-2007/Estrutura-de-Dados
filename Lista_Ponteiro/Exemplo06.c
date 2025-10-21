#include <stdio.h>
#include <stdlib.h>

typedef struct Item
{

    int Chave;
    struct Item *Proximo;

} Item;

void ExibirLista(Item * Inicio);

void InserirItem(Item * Inicio, Item * I, int Posicao);

void ExcluirItem(Item * Inicio, int Posicao);

int main()
{

    Item *A = (Item *)malloc(sizeof(Item));
    Item *B = (Item *)malloc(sizeof(Item));
    Item *C = (Item *)malloc(sizeof(Item));
    Item *D = (Item *)malloc(sizeof(Item));
    Item *X = (Item *)malloc(sizeof(Item));

    A->Chave = 17;
    B->Chave = 29;
    C->Chave = 41;
    D->Chave = 97;
    X->Chave = 73;

    A->Proximo = NULL;
    B->Proximo = NULL;
    C->Proximo = NULL;
    D->Proximo = NULL;
    X->Proximo = NULL;

    printf("%X \t %d\n", A, A->Chave);
    printf("%X \t %d\n", B, B->Chave);
    printf("%X \t %d\n", C, C->Chave);
    printf("%X \t %d\n", D, D->Chave);

    A->Proximo = B;
    B->Proximo = C;
    C->Proximo = D;
    D->Proximo = A;

    printf("\nLISTA:\n");

    for (Item *X = A; X != NULL; X = X->Proximo)
    {

        printf("%X \t %d\n", X, X->Chave);
    }
}
