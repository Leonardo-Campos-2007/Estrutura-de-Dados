#include <stdio.h>
#include <string.h>
#include "expressao.h"

int main() {

    Expressao e;

    printf("Digite a expressao posfixa:\n");
    fgets(e.posFixa, 512, stdin);
    e.posFixa[strcspn(e.posFixa, "\n")] = '\0';

    strcpy(e.inFixa, getFormaInFixa(e.posFixa));
    e.Valor = getValorPosFixa(e.posFixa);

    printf("\nPosfixa: %s\n", e.posFixa);
    printf("Infixa:  %s\n", e.inFixa);
    printf("Valor:   %.4f\n", e.Valor);

    return 0;
}
