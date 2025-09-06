#include <stdio.h>
#include <stdlib.h>

#include "processos.h"

int main(){

    int QtdProcessos = numeroProcessos("TJDFT_filtrado.csv");
    if (QtdProcessos >= 0) {
        printf("Quantidade De Processos: %d\n\n", QtdProcessos);
    }

    int ultimo_oj = id_ultimo_oj("TJDFT_filtrado.csv", 323961063);
    printf("Codigo do ultimo orgao julgador: %d\n\n", ultimo_oj);

    int antigo = processoAntigo("TJDFT_filtrado.csv");
    printf("Codigo do processo mais antigo: %d\n\n", antigo);
    return 0;

    int qtddomestico = violenciaDomestica("TJDFT_filtrado.csv");
    printf("Quantidade de violencia Domestica: %d\n\n", qtddomestico);
    return 0;

    int qtdfeminicidio = feminicidio("TJDFT_filtrado.csv");
    printf("Quantidade de feminicidio: %d\n\n", qtdfeminicidio);
    return 0;

    int qtdambiental = ambiental("TJDFT_filtrado.csv");
    printf("Quantidade de crimes ambientais: %d\n\n", qtdambiental);
    return 0;

    int qtdquilombolas = quilombolas("TJDFT_filtrado.csv");
    printf("Quantidade de crimes com quilombolas %d\n\n", qtdquilombolas);
    return 0;

    int qtdindigenas = indigenas("TJDFT_filtrado.csv");
    printf("Quantidade de crimes com indigenas %d\n\n", qtdindigenas);
    return 0;

    int qtdinfancia = infancia("TJDFT_filtrado.csv");
    printf("Quantidade de crimes com menores de idade: %d\n\n", qtdinfancia);
    return 0;

    









}

