#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "processos.h"

#include <stdio.h>

FILE *LerDados(const char *TJDFT_filtrado)
{
    FILE *fp = fopen(TJDFT_filtrado, "r");
    if (!fp)
    {
        perror("Erro ao abrir arquivo");
        return NULL; // retorna NULL se não conseguiu abrir
    }

    return fp; // retorna o ponteiro do arquivo
}

int numeroProcessos(const char *TJDFT_filtrado)
{
    FILE *fp = LerDados(TJDFT_filtrado); // Abre o arquivo

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

int id_ultimo_oj(const char *TJDFT_filtrado, int id_processo)
{
    FILE *fp = LerDados(TJDFT_filtrado);

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

int processoAntigo(const char *TJDFT_filtrado)
{
    FILE *fp = LerDados(TJDFT_filtrado);

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

int violenciaDomestica(const char *TJDFT_filtrado)
{

    FILE *fp = LerDados(TJDFT_filtrado);

    int i = 0;
    char linha[3000];
    Processos p;
    fgets(linha, sizeof(linha), fp);

    while (fgets(linha, sizeof(linha), fp))
    {
        if (sscanf(linha, "%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%d;",
                   &p.flag_violencia_domestica) == 1)
        {
            if(p.flag_violencia_domestica == 1){
                i++;
            }
        }
    }
    fclose(fp);
    return i;
}

int feminicidio(const char *TJDFT_filtrado)
{

    FILE *fp = LerDados(TJDFT_filtrado);

    int i = 0;

    char linha[3000];
    Processos p;
    fgets(linha, sizeof(linha), fp);

    while (fgets(linha, sizeof(linha), fp))
    {
        if (sscanf(linha, "%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%d",
                   &p.flag_feminicidio) == 1)
        {
            if(p.flag_feminicidio == 1){
                i++;
            }
        }
    }
    fclose(fp);
    return i;
}

int ambiental(const char *TJDFT_filtrado)
{

    FILE *fp = LerDados(TJDFT_filtrado);

    int i = 0;

    char linha[3000];
    Processos p;
    fgets(linha, sizeof(linha), fp);

    while (fgets(linha, sizeof(linha), fp))
    {
        if (sscanf(linha, "%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%d",
                   &p.flag_ambiental) == 1)
        {
            if(p.flag_ambiental == 1){
                i++;
            }
        }
    }
    fclose(fp);
    return i;
}

int quilombolas(const char *TJDFT_filtrado)
{

    FILE *fp = LerDados(TJDFT_filtrado);

    int i = 0;

    char linha[3000];
    Processos p;
    fgets(linha, sizeof(linha), fp);

    while (fgets(linha, sizeof(linha), fp))
    {
        if (sscanf(linha, "%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%d",
                   &p.flag_quilombolas) == 1)
        {
            if(p.flag_quilombolas == 1){
                i++;
            }
        }
    }
    fclose(fp);
    return i;
}

int indigenas(const char *TJDFT_filtrado)
{

    FILE *fp = LerDados(TJDFT_filtrado);

    int i = 0;

    char linha[3000];
    Processos p;
    fgets(linha, sizeof(linha), fp);

    while (fgets(linha, sizeof(linha), fp))
    {
        if (sscanf(linha, "%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%d",
                   &p.flag_indigenas) == 1)
        {
            if(p.flag_indigenas == 1){
                i++;
            }
        }
    }
    fclose(fp);
    return i;
}

int infancia(const char *TJDFT_filtrado)
{

    FILE *fp = LerDados(TJDFT_filtrado);

    int i = 0;

    char linha[3000];
    Processos p;
    fgets(linha, sizeof(linha), fp);

    while (fgets(linha, sizeof(linha), fp))
    {
        if (sscanf(linha, "%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%d",
                   &p.flag_infancia) == 1)
        {
            if(p.flag_infancia == 1){
                i++;
            }
        }
    }
    fclose(fp);
    return i;
}

