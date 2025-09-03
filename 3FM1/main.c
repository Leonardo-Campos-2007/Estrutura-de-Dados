#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "equipe.h"

int main() {

    Equipe * tabela = LerDados("tabela.csv");

printf("Posição: %d\n", tabela[0].Posicao);
printf("Estado: %s\n", tabela[1].Estado);

}
