#include <stdio.h>
#include <stdlib.h>

#include "pilha.h"

Item *criarItem(int Chave)
{
    Item *I = (Item *)malloc(sizeof(Item));

    if (I == NULL)
    {
        printf("ERRO NÃO FOI POSSIVEL ALOCAR MEMORIA");
        return NULL;
    }

    I->Chave = Chave;
    I->Anterior = NULL;
}

Pilha *criarPilha()
{

    Pilha *P = (Pilha *)malloc(sizeof(Pilha));

    if (P == NULL)
    {
        printf("ERRO NÃO FOI POSSIVEL ALOCAR MEMORIA");
        return NULL;
    }

    P->Tamanho = 0;
    P->Topo = NULL;

    return P;
}

void empilhar(Pilha *P, Item *I)
{
    I->Anterior = P->Topo;
    P->Topo = I;
    P->Tamanho++;
}

void desempilhar(Pilha * P){

    if(P-> Tamanho == 0){
        printf("ERRO");
        return;
    }

    Item * I = P -> Topo;
    P -> Topo = I -> Anterior;
    free(I);
    P -> Tamanho--;
}