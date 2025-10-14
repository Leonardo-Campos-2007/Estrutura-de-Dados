#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tarefa.h"

int main()
{

    Tarefa T1 = {"Preparar relatorio da diciplina RT", "Ana Maria", EM_ANDAMENTO, 0.75, 5};
    Tarefa T2 = {"Estudo diario", "Leonardo", EM_ANDAMENTO, 0.100, 5};
    Tarefa T3 = {"Pedido da Empresa", "Miguel", EM_ANDAMENTO, 0.86, 4};
    Tarefa T4 = {"Projeto Pessoal", "Caze", EM_ANDAMENTO, 0.53, 1};
    Tarefa T5 = {"Metas da Academia", "Bressan", EM_ANDAMENTO, 0.90, 3};
    Tarefa T6 = {"Dever da Facudade", "Laura", EM_ANDAMENTO, 0.50, 5};
    Tarefa T7 = {"Trabalho da Facudade", "Layssa", EM_ANDAMENTO, 0.40, 2};
    Tarefa T8 = {"Curso de ESD", "Julia", EM_ANDAMENTO, 0.45, 4};
    Tarefa T9 = {"Obrigações diarias", "Gabriel", EM_ANDAMENTO, 0.10, 1};
    Tarefa T10 = {"Trabalho da Facudade", "Gustavo", EM_ANDAMENTO, 0.87, 4};

    Lista *Planner = CriarLista(200);

    AdicionarTarefa(Planner, T1);
    AdicionarTarefa(Planner, T2);
    AdicionarTarefa(Planner, T3);
    AdicionarTarefa(Planner, T4);
    AdicionarTarefa(Planner, T5);
    AdicionarTarefa(Planner, T6);
    AdicionarTarefa(Planner, T7);
    AdicionarTarefa(Planner, T8);
    AdicionarTarefa(Planner, T9);
    AdicionarTarefa(Planner, T10);

    for (int i = 0; i < Planner->Tamanho; i++)
    {
        printf("%d\t", i);
        printf("%s\n", Planner->Dados[i].Titulo);
    }

    DestruirLista(Planner);

    printf("%X\n", Planner);
}