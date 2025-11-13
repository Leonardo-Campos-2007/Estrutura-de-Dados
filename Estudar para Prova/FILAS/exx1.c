/* fila_q03.c */
#include <stdio.h>
#include <stdlib.h>

/* Nó da lista encadeada */
typedef struct No {
    int valor;
    struct No *proximo;
} No;

/* Fila com ponteiros para frente e traseira */
typedef struct {
    No *frente;
    No *tras;
} Fila;

Fila *criarFila(void) {
    Fila *f = (Fila *)malloc(sizeof(Fila));
    if (!f) return NULL;
    f->frente = f->tras = NULL;
    return f;
}

int enfileirar(Fila *f, int valor) {
    if (!f) return 0;
    No *novo = (No *)malloc(sizeof(No));
    if (!novo) return 0;
    novo->valor = valor;
    novo->proximo = NULL;
    if (f->tras == NULL) {
        f->frente = f->tras = novo;
    } else {
        f->tras->proximo = novo;
        f->tras = novo;
    }
    return 1;
}

/* Desenfileira e coloca o valor em out; retorna 1 em sucesso, 0 se vazia */
int desenfileirar(Fila *f, int *out) {
    if (!f || f->frente == NULL) return 0;
    No *rem = f->frente;
    if (out) *out = rem->valor;
    f->frente = rem->proximo;
    if (f->frente == NULL) f->tras = NULL;
    free(rem);
    return 1;
}

/* Q01: conta elementos (percurso O(n)) */
int tamanhoFila(const Fila *f) {
    if (!f) return 0;
    int cont = 0;
    No *p = f->frente;
    while (p) {
        cont++;
        p = p->proximo;
    }
    return cont;
}

/* Q02: soma das chaves (percurso O(n)) */
int somaFila(const Fila *f) {
    if (!f) return 0;
    int soma = 0;
    No *p = f->frente;
    while (p) {
        soma += p->valor;
        p = p->proximo;
    }
    return soma;
}

/* === Q03: verifica se um elemento está na fila ===
   Retorna 1 se encontrar a chave, 0 caso contrário.
   Complexidade: O(n) no pior caso. */
int estaNaFila(const Fila *f, int chave) {
    if (!f) return 0;
    No *p = f->frente;
    while (p != NULL) {
        if (p->valor == chave) return 1; /* encontrado */
        p = p->proximo;
    }
    return 0; /* não encontrado */
}

/* libera toda a fila */
void liberarFila(Fila *f) {
    if (!f) return;
    No *p = f->frente;
    while (p) {
        No *tmp = p;
        p = p->proximo;
        free(tmp);
    }
    free(f);
}

/* Teste */
int main(void) {
    Fila *f = criarFila();
    enfileirar(f, 5);
    enfileirar(f, 10);
    enfileirar(f, 20);
    enfileirar(f, 42);

    printf("Tamanho: %d\n", tamanhoFila(f));
    printf("Soma: %d\n", somaFila(f));

    int chave = 20;
    printf("Chave %d %sna fila.\n", chave, estaNaFila(f, chave) ? "" : "não ");

    chave = 7;
    printf("Chave %d %sna fila.\n", chave, estaNaFila(f, chave) ? "" : "não ");

    liberarFila(f);
    return 0;
}
