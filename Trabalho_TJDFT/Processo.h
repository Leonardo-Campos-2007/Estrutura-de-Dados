#ifndef PROCESSO_H
#define PROCESSO_H

typedef struct
{
    int id_processo;
    int numero_sigilo;
    char sigla_grau[20];
    char procedimento[50];
    char ramo_justiça[50];
    char sigla_tribunal[10];
    int id_tribunal;
    int recurso;
    int id_ultimo_oj;
    char dt_recebimento[11];
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

} Processos;

FILE *LerDados(const char *arquivo);
int numeroProcessos(char *arquivo);
int id_ultimo_oj(char *arquivo, int id_processo);
int processoAntigo(char *arquivo);
int violenciaDomestica(char *arquivo);
int feminicidio(char *arquivo);
int ambiental(char *arquivo);
int quilombolas(char *arquivo);
int indigenas(char *arquivo);
int infancia(char *arquivo);
int dias_totais(int a, int m, int d);
int numeroDias(char *arquivo, int id_processo);
float percentualCumprimentoMeta1(char *arquivo);
void gerarCSV(char *entrada, char *saida);

#endif