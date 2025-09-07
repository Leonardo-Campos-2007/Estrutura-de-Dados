#ifndef PROCESSO_H
#define PROCESSO_H

typedef struct
{
    int id_processo;
    int numero_sigilo;
    char sigla_grau[20];
    char procedimento[50];
    char ramo_justica[50];
    char sigla_tribunal[10];
    int id_tribunal;
    int recurso;
    int id_ultimo_oj;
    char dt_recebimento[11];    // YYYY-MM-DD + '\0'
    int id_ultima_classe;
    int flag_violencia_domestica;
    int flag_feminicidio;
    int flag_ambiental;
    int flag_quilombolas;
    int flag_indigenas;
    int flag_infancia;
    int decisao;
    char dt_resolvido[11];     
    int cnm1;
    int primeirasentm1;
    int baixm1;
    int decm1;
    int mpum1;
    int julgadom1;
    int desm1;
    int susm1;
} Processo;

// Funções de manipulação
FILE *LerDados(const char *TJDFT_filtrado);
int numeroProcessos(const char *TJDFT_filtrado);
int id_ultimo_oj(const char *TJDFT_filtrado, int id_processo);
int processoAntigo(const char *TJDFT_filtrado);
int violenciaDomestica(const char *TJDFT_filtrado);
int feminicidio(const char *TJDFT_filtrado);
int ambiental(const char *TJDFT_filtrado);
int quilombolas(const char *TJDFT_filtrado);
int indigenas(const char *TJDFT_filtrado);
int infancia(const char *TJDFT_filtrado);


void gerarCSV(const char *entrada, const char *saida);


#endif
