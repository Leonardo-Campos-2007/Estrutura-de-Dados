#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "processos.h"

#include <stdio.h>

FILE *LerDados(const char *arquivo)
{
    FILE *fp = fopen(arquivo, "r");
    if (!fp)
    {
        perror("Erro ao abrir arquivo");
        return NULL; // retorna NULL se não conseguiu abrir
    }

    return fp; // retorna o ponteiro do arquivo
}
int numeroProcessos(char *arquivo)
{
    FILE *fp = LerDados(arquivo); // Abre o arquivo

    int i = 0;
    char linha[2048]; // tamanho que uma linha pode ter em caracteres
    Processos p;
    fgets(linha, sizeof(linha), fp); // Pula o cabeçalho.

    while (fgets(linha, sizeof(linha), fp))
    { // "While" fgets for verdadeiro (ele é verdadeiro até passar por todas as linhas)
        if (sscanf(linha, "%d;", &p.id_processo) == 1)
        {        // Lê apenas o id_processos de cada linha
            i++; // A cada id processo soma um
        }
    }

    fclose(fp);
    return i; // retorna o resultado
}

int id_ultimo_oj(char *arquivo, int id_processo)
{
    FILE *fp = LerDados(arquivo);

    char linha[2048];
    Processos p;
    fgets(linha, sizeof(linha), fp);

    while (fgets(linha, sizeof(linha), fp))
    {
        if (sscanf(linha, "%d;%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%d;",
                   &p.id_processo, &p.id_ultimo_oj) == 2)
        {
            if (p.id_processo == id_processo)
            {
                return p.id_ultimo_oj;
            }
        }
    }
    fclose(fp);
    return -1;
}

int processoAntigo(char *arquivo)
{
    FILE *fp = LerDados(arquivo);

    char linha[2048];
    Processos p;
    fgets(linha, sizeof(linha), fp);
    char data[11] = "9999-12-31"; // valor inicial bem "grande"
    int antigo = 0;

    while (fgets(linha, sizeof(linha), fp))
    {

        if (sscanf(linha,
                   "%d;%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%10[^;];",
                   &p.id_processo, p.dt_recebimento) == 2) // Pega o id do processo e a data de recebimento.
        {

            if (strcmp(p.dt_recebimento, data) < 0) // se a data atual for mais antiga que a armazenada.
            {
                strcpy(data, p.dt_recebimento); // atualiza a data mais antiga.
                antigo = p.id_processo;         // guarda o id do processo correspondente.
            }
        }
    }
    fclose(fp);
    return antigo;
}

int violenciaDomestica(char *arquivo)
{
    FILE *fp = LerDados(arquivo);

    int i = 0;
    char linha[3000];
    Processos p;
    fgets(linha, sizeof(linha), fp);

    while (fgets(linha, sizeof(linha), fp))
    {
        if (sscanf(linha, "%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%d;",
                   &p.flag_violencia_domestica) == 1)
        {
            if (p.flag_violencia_domestica == 1)
            {
                i++;
            }
        }
    }
    fclose(fp);
    return i;
}

int feminicidio(char *arquivo)
{
    FILE *fp = LerDados(arquivo);

    int i = 0;

    char linha[3000];
    Processos p;
    fgets(linha, sizeof(linha), fp);

    while (fgets(linha, sizeof(linha), fp))
    {
        if (sscanf(linha, "%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%d",
                   &p.flag_feminicidio) == 1)
        {
            if (p.flag_feminicidio == 1)
            {
                i++;
            }
        }
    }
    fclose(fp);
    return i;
}

int ambiental(char *arquivo)
{
    FILE *fp = LerDados(arquivo);

    int i = 0;

    char linha[3000];
    Processos p;
    fgets(linha, sizeof(linha), fp);

    while (fgets(linha, sizeof(linha), fp))
    {
        if (sscanf(linha, "%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%d",
                   &p.flag_ambiental) == 1)
        {
            if (p.flag_ambiental == 1)
            {
                i++;
            }
        }
    }
    fclose(fp);
    return i;
}

int quilombolas(char *arquivo)
{

    FILE *fp = LerDados(arquivo);

    int i = 0;

    char linha[3000];
    Processos p;
    fgets(linha, sizeof(linha), fp);

    while (fgets(linha, sizeof(linha), fp))
    {
        if (sscanf(linha, "%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%d",
                   &p.flag_quilombolas) == 1)
        {
            if (p.flag_quilombolas == 1)
            {
                i++;
            }
        }
    }
    fclose(fp);
    return i;
}

int indigenas(char *arquivo)
{

    FILE *fp = LerDados(arquivo);

    int i = 0;

    char linha[3000];
    Processos p;
    fgets(linha, sizeof(linha), fp);

    while (fgets(linha, sizeof(linha), fp))
    {
        if (sscanf(linha, "%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%d",
                   &p.flag_indigenas) == 1)
        {
            if (p.flag_indigenas == 1)
            {
                i++;
            }
        }
    }
    fclose(fp);
    return i;
}

int infancia(char *arquivo)
{

    FILE *fp = LerDados(arquivo);

    int i = 0;

    char linha[3000];
    Processos p;
    fgets(linha, sizeof(linha), fp);

    while (fgets(linha, sizeof(linha), fp))
    {
        if (sscanf(linha, "%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%d",
                   &p.flag_infancia) == 1)
        {
            if (p.flag_infancia == 1)
            {
                i++;
            }
        }
    }
    fclose(fp);
    return i;
}

int dias_totais(int ano, int mes, int dia)
{
    static int dias_por_mes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int i, dias = 0;

    for (i = 1; i < ano; i++)
        dias += 365 + ((i % 4 == 0 && (i % 100 != 0 || i % 400 == 0)) ? 1 : 0);

    for (i = 1; i < mes; i++)
        dias += dias_por_mes[i - 1];

    if (mes > 2 && (ano % 4 == 0 && (ano % 100 != 0 || ano % 400 == 0)))
        dias += 1;

    dias += dia;
    return dias;
}

int numeroDias(char *arquivo, int id_processo)
{
    FILE *fp = LerDados(arquivo);

    char linha[3000];
    Processos p;

    fgets(linha, sizeof(linha), fp); // pula cabeçalho

    while (fgets(linha, sizeof(linha), fp))
    {
        // lê id_processo da struct e as datas
        if (sscanf(linha,
                   "%d;%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%10[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%10[^;]",
                   &p.id_processo, p.dt_recebimento, p.dt_resolvido) == 3)
        {
            if (p.id_processo == id_processo)
            {
                int a1, m1, d1, a2, m2, d2;

                // converte datas para inteiros
                if (sscanf(p.dt_recebimento, "%d-%d-%d", &a1, &m1, &d1) != 3)
                    continue;
                if (sscanf(p.dt_resolvido, "%d-%d-%d", &a2, &m2, &d2) != 3)
                    continue;

                fclose(fp);

                return dias_totais(a2, m2, d2) - dias_totais(a1, m1, d1);
            }
        }
    }

    fclose(fp);
}

float percentualCumprimentoMeta1(char *arquivo)
{
    FILE *fp = LerDados(arquivo);

    char linha[3000];
    int cnm1 = 0;
    int julgadom1 = 0;
    int desm1 = 0;
    int susm1 = 0;
    Processos p;

    fgets(linha, sizeof(linha), fp); // pula cabeçalho

    while (fgets(linha, sizeof(linha), fp))
    {
        if (sscanf(linha,
                   "%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];"
                   "%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%d;%*[^;];%*[^;];%*[^;];%*[^;];%d;%d;%d",
                   &p.cnm1, &p.julgadom1, &p.desm1, &p.susm1) == 4)
        {
            if (p.cnm1 == 1)
            {
                cnm1++;
            }
            if (p.julgadom1 == 1)
            {
                julgadom1++;
            }
            if (p.desm1 == 1)
            {
                desm1++;
            }
            if (p.susm1 == 1)
            {
                susm1++;
            }
        }
    }
    if (cnm1 + desm1 - susm1 == 0)
        return 0.0f;

    float meta1 = ((float)julgadom1 / (cnm1 + desm1 - susm1)) * 100.0f;
    return meta1;
}
void gerarCSV(char *entrada, char *saida)
{

    FILE *fpIn = fopen(entrada, "r");
    FILE *fpOut = fopen(saida, "w");

    if (!fpIn || !fpOut)
    {
        printf("Erro ao abrir o arquivo!");
        exit(1);
    }

    char linha[3000];
    Processos p;

    if (fgets(linha, sizeof(linha), fpIn))
    {
        fprintf(fpOut, "%s", linha);
    }

    while (fgets(linha, sizeof(linha), fpIn))
    {
        if (sscanf(linha, "%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%d",
                   &p.julgadom1) == 1)
        {
            if (p.julgadom1 == 1)
            {

                fprintf(fpOut, "%s", linha);
            }
        }
    }
    fclose(fpIn);
    fclose(fpOut);

    printf("Arquivo gerado com sucesso!!!\n");
}