#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "equipe.h"

int main(){
    Time* Tabela = LerDados("tabela.csv");
        printf("%d\n", getPontos(Tabela, 20));
        printf("%.2f%%\n", getAproveitamento(Tabela, "Palmeiras"));
    return 0;
}