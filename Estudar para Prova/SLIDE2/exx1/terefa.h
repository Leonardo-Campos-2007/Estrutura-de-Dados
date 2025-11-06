#define TAM_TITULO 96
#define TAM_NOME 48

#define A_FAZER 0
#define FEITO 1
#define EM_ANDAMENTO 2

typedef struct {

    char Titulo[TAM_TITULO];
    char Responsavel[TAM_NOME];
    int Status;
    float Progresso;
    int Avaliação;


}Tarefa;

typedef struct 
{
    Tarefa *Dados;
    int Tamanho;
    int Capacidade;
}ListaTarefas;


/* --- Cabeçalhos das Funções --- */
ListaTarefas *CriarLista(int CapacidadeInicial);
void DestruirLista(ListaTarefas *Lista);
int AdicionarTarefa(ListaTarefas *Lista, Tarefa *T);
int RemoverTarefa(ListaTarefas *Lista, int Indice);
Tarefa *ObterTarefa(ListaTarefas *Lista, int Indice);
int AtualizarStatus(ListaTarefas *Lista, int Indice, int NovoStatus);
int AtualizarProgresso(ListaTarefas *Lista, int Indice, float NovoProgresso);
int AtualizarAvaliacao(ListaTarefas *Lista, int Indice, int NovaAvaliacao);
int ContarPorStatus(const ListaTarefas *Lista, int Status);
float MediaAvaliacao(const ListaTarefas *Lista);
char *TextoStatus(int Status);
void ImprimirLista(const ListaTarefas *Lista);