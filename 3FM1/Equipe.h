#ifndef EQUIPE_H
#define EQUIPE_H

#define ERRO -999

typedef struct 
{
    int posicao;
    char estado[30];
    char equipe[30]; // Nome do Time
    int pts; // Pontos = Vitoria * 3 + Empate
    int j; // Jogos
    int v; // Vitoria
    int e; // Empate
    int d; // Derrota
    int gp; // Gols Pró
    int gc; // Gols sofridos
    int sg; // Saldo de Gols = Gols Pró - Gols sofridos
    float aproveitamento;
} Time;

Time* LerDados(char* Arquivo);
int getPontos(Time* T, int posicao);
float getAproveitamento(Time* T, char* equipe);

#endif