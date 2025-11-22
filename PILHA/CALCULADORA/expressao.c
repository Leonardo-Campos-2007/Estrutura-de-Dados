#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "expressao.h"

typedef struct Item
{
    int Chave;
    struct Item *Anterior;
    

} Item;

typedef struct Pilha
{
    int Tamanho;
     Item *Topo;



}Pilha;

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


char * getFormaInFixa(char *Str)
{

    Pilha *P = criarPilha();

    P->Topo = NULL;
    P->Tamanho = 0;
   
    
    

    return Str;


}
