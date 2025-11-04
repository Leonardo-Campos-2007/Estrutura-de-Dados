#ifndef MUSICA_H
#define MUSICA_H

typedef struct Item
{
    char Titulo[50];
    char Autor[200];
    int Ano;

    struct Item *Anterior;
    struct Item *Posterior;

} Item;

typedef struct
{

    int Tamanho;
    struct Item *Inicio;
    struct Item *Fim;

} Lista;

Item *criarItem(char *Titulo, char *Autor, int Ano);

void exibirInicio(Lista *L);

void exibirFinal(Lista *L);

void exibir78(Lista *L, int Ano);


#endif