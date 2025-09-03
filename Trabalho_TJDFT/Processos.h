#ifndef PROCESSOS_H
#define PROCESSOS_H

typedef struct {
    int id_processo;
    int numero_sigilo;
    char sigla_grau[20];
    char procedimento[50];
    char ramo_justiça[50];
    char sigla_tribunal[10];
    int id_tribunal;
    int recurso;
    int id_ultimo_oj;
    int dt_recebimento;
    int id_ultima_classe;
    int flag_violencia_domestica;
    int flag_feminicidio;
    int flag_ambiental;
    int flag_quilombolas;
    int flag_indigenas;
    int flag_infancia;
    int decisao;
    int dt_resolvido;
    int cnm1;
    int primeirasentm1;
    int baixm1;
    int decm1;
    int mpum1;
    int julgadom1;
    int desm1;
    int susm1;

    int numeroProcessos(int );
    int id_ultimo_oj();
    int id_processo();
    int violenciaDomestica();
    int feminicidio();
    int ambiental();
    int quilombolas();
    int indigenas();
    int infancia();
    int numeroDias();
    float percentualCumprimentoMeta1();
    char gerarCSV();


} Processos;

#endif
