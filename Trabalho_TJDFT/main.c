#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "processos.h"

int main(){
    clock_t T0 = clock();
    int QtdProcessos = numeroProcessos("TJDFT_filtrado.csv");
    if (QtdProcessos >= 0) {
        printf("Quantidade De Processos: %d\n\n", QtdProcessos);
    }

    int ultimo_oj = id_ultimo_oj("TJDFT_filtrado.csv", 323961063);
    printf("Codigo do ultimo orgao julgador: %d\n\n", ultimo_oj);

    int antigo = processoAntigo("TJDFT_filtrado.csv");
    printf("Codigo do processo mais antigo: %d\n\n", antigo);
    

    int qtddomestico = violenciaDomestica("TJDFT_filtrado.csv");
    printf("Quantidade de violencia Domestica: %d\n\n", qtddomestico);
   

    int qtdfeminicidio = feminicidio("TJDFT_filtrado.csv");
    printf("Quantidade de feminicidio: %d\n\n", qtdfeminicidio);
    

    int qtdambiental = ambiental("TJDFT_filtrado.csv");
    printf("Quantidade de crimes ambientais: %d\n\n", qtdambiental);
    

    int qtdquilombolas = quilombolas("TJDFT_filtrado.csv");
    printf("Quantidade de crimes com quilombolas: %d\n\n", qtdquilombolas);
    

    int qtdindigenas = indigenas("TJDFT_filtrado.csv");
    printf("Quantidade de crimes com indigenas: %d\n\n", qtdindigenas);
    

    int qtdinfancia = infancia("TJDFT_filtrado.csv");
    printf("Quantidade de crimes com menores de idade: %d\n\n", qtdinfancia);

    printf("A diferenca de dias eh: %d\n\n", numeroDias("TJDFT_filtrado.csv", 323961063));

    float meta1 = percentualCumprimentoMeta1("TJDFT_filtrado.csv");
    printf("Porcentagem da meta1: %.2f\n\n", meta1);

    gerarCSV("TJDFT_filtrado.csv", "processos_meta1.csv");
    clock_t TF = clock();
    printf("\n\nTempo de Execucao: %.2f segundos\n", (double)(TF - T0)/CLOCKS_PER_SEC);
    return 0;

}
    