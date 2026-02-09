#include <stdio.h>
#include "heap.c"

typedef struct Paciente {
    int idade;      // Idade do paciente
    char cpf[12];   // CPF do cliente (apenas números)
    char nome[101]; // Nome completo do paciente
} PACIENTE;

void visualizaFila(HEAP* fila) {
    if (heapVazia(fila)) {      // verifica se a fila está vazia antes de iniciar a função
        printf("\nA fila esta vazia.\n\n");
        return;
    }
    ELEMENTO* paciente;         // variável irá conter a prioridade e os dados de um paciente (no formato void*) 
    PACIENTE* paciente_dados;   // dados do cliente no formato correto (definidos no struct PACIENTE)
    printf("\nA fila esta com %d paciente(s):\n\n", fila->quantidade);
    for (int i = 0; i < fila->quantidade; i++) {
        printf("Paciente %d: ", i + 1);
        paciente = fila->vetor[i];                   
        paciente_dados = (PACIENTE*) paciente->info; // conversão do tipo dos dados (void* -> PACIENTE*)
        puts(paciente_dados->nome);       
        printf("Idade: %d\nCPF: %s\nPrioridade: %d\n\n", paciente_dados->idade, paciente_dados->cpf, paciente->prioridade);
    }
}

void atendePaciente(HEAP* fila) {
    if (heapVazia(fila)){   // verifica se a fila está vazia antes de iniciar a função
        printf("A fila esta vazia!\n\n");    
        return;
    }
    ELEMENTO* paciente_atendido = heapRemove(fila);     // variável obtém o paciente removido, pois a função heapRemove() retorna o paciente do início da fila - ver fila.c
    PACIENTE* paciente_atendido_dados = (PACIENTE*) paciente_atendido->info;    // dados do paciente são convertidos de void* para PACIENTE* - dessa forma, conseguimos acessá-los em seu formato original
    printf("\n%sfoi atendido(a)!\n", paciente_atendido_dados->nome);   // imprime o nome do paciente que foi atendido
    getchar();
}

void adicionaPaciente(HEAP* fila) {
    if (fila->quantidade < TAMANHO_MAX) {
        PACIENTE* paciente_dados = (PACIENTE*) malloc(sizeof(PACIENTE));    // aloca a memória dos dados do paciente
        getchar();

        // coleta de dados
        printf("\nNome do paciente: ");
        fgets(paciente_dados->nome, 101, stdin);
        printf("Idade do paciente: "); 
        scanf("%d", &paciente_dados->idade);
        printf("CPF do paciente (apenas numeros): ");
        scanf("%s", paciente_dados->cpf);

        ELEMENTO* paciente = (ELEMENTO*) malloc(sizeof(ELEMENTO));  // aloca a memória para o novo elemento da heap
        paciente->info = (void*) paciente_dados;    // dados do struct PACIENTE são convertidos para o tipo void* - assim, eles serão armazenados corretamente no vetor da heap
        printf("Prioridade de atendimento (3: mais urgente | 2: urgencia media | 1: pouco urgente): ");
        scanf("%d", &paciente->prioridade);
        heapInsere(fila, paciente); // função da biblioteca heap.c
    } 
    printf("A fila esta cheia!\n\n");
}

void menu() {   // imprime a tela principal do programa
    printf("-----------------------------------------------\n=============== HOSPITAL HEALTH ===============\n-----------------------------------------------\n");
    printf("1 - adicionar paciente | 2 - atender paciente | 3 - visualizar fila | 0 - Sair\n");
    printf("\nOperacao: ");
}

int main () {
    system("cls");
    HEAP* fila_hospital = heapCria();
    int operacao;
    while (1) {
        menu();
        if (scanf("%d", &operacao)) { // condição para tratamento de exceções - se a entrada for um número, scanf retorna 1. Caso contrário, retorna 0.
            switch (operacao) {
                case 0:
                    heapLibera(fila_hospital);
                    printf("Fim do programa.\n");
                    exit(1);
                case 1:
                    adicionaPaciente(fila_hospital);
                    break;
                case 2:
                    atendePaciente(fila_hospital);
                    break;
                case 3:
                    visualizaFila(fila_hospital);
                    break;
                default:
                    printf("Entrada invalida, digite um numero entre 0 a 3.");
                    break;
            }
        }
        else {  // Mensagem é exibida quando a entrada não é um número
            printf("Entrada invalida, digite um numero entre 0 a 3.\n\n------------------------------------");
            getchar();
        }
    }
}
