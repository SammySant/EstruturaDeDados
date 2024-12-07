#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Definição da estrutura de voo
typedef struct Voo {
    int numero_voo;           // Número do voo
    int data_voo;             // Dia da semana (1-seg, 2-ter, 3-qua, 4-qui, 5-sex, 6-sab, 7-dom, 8-diario)
    int hora;                 // Hora do voo
    int min;                  // Minuto do voo
    int aeroporto_saida;      // ID do aeroporto de saída
    int aeroporto_chegada;    // ID do aeroporto de chegada
    int rota;                 // ID da rota
    float tempo_estimado;     // Tempo estimado de voo
    int passageiros_bordo;    // Número de passageiros a bordo

    // Ponteiro para o próximo voo (para implementação de lista dinâmica)
    struct Voo* proximo;
} Voo;

// Função para criar um novo voo (função interna)
Voo* criarVoo() {
    Voo* novoVoo = (Voo*)malloc(sizeof(Voo));
    
    if (novoVoo == NULL) {
        printf("Erro: Não foi possível alocar memória para o voo.\n");
        return NULL;
    }

    // Solicitar informações do voo
    printf("Digite o número do voo: ");
    scanf("%d", &novoVoo->numero_voo);

    printf("Digite o dia do voo (1-seg, 2-ter, 3-qua, 4-qui, 5-sex, 6-sab, 7-dom, 8-diario): ");
    scanf("%d", &novoVoo->data_voo);

    printf("Digite a hora do voo: ");
    scanf("%d", &novoVoo->hora);

    printf("Digite os minutos do voo: ");
    scanf("%d", &novoVoo->min);

    printf("Digite o ID do aeroporto de saída: ");
    scanf("%d", &novoVoo->aeroporto_saida);

    printf("Digite o ID do aeroporto de chegada: ");
    scanf("%d", &novoVoo->aeroporto_chegada);

    printf("Digite o ID da rota: ");
    scanf("%d", &novoVoo->rota);

    printf("Digite o tempo estimado de voo (em horas): ");
    scanf("%f", &novoVoo->tempo_estimado);

    printf("Digite o número de passageiros a bordo: ");
    scanf("%d", &novoVoo->passageiros_bordo);

    // Inicializa o próximo voo como NULL
    novoVoo->proximo = NULL;

    return novoVoo;
}

// Função para cadastrar um novo voo
void cadastrarVoo(Voo** lista) {
    Voo* novoVoo = criarVoo();
    
    if (novoVoo == NULL) {
        return;
    }

    // Se a lista estiver vazia
    if (*lista == NULL) {
        *lista = novoVoo;
        printf("Voo cadastrado com sucesso!\n");
        return;
    }

    // Encontrar o último voo da lista
    Voo* atual = *lista;
    while (atual->proximo != NULL) {
        // Verificar se já existe um voo com o mesmo número
        if (atual->numero_voo == novoVoo->numero_voo) {
            printf("Erro: Já existe um voo com este número.\n");
            free(novoVoo);
            return;
        }
        atual = atual->proximo;
    }

    // Verificar o último voo
    if (atual->numero_voo == novoVoo->numero_voo) {
        printf("Erro: Já existe um voo com este número.\n");
        free(novoVoo);
        return;
    }

    // Inserir o novo voo no final
    atual->proximo = novoVoo;
    printf("Voo cadastrado com sucesso!\n");
}

// Função para consultar um voo específico
void consultaVoo(Voo* lista, int numero_voo) {
    // Percorrer a lista de voos
    Voo* atual = lista;
    
    while (atual != NULL) {
        // Verificar se encontrou o voo com o número desejado
        if (atual->numero_voo == numero_voo) {
            // Imprimir todas as informações do voo
            printf("\n--- Informações do Voo ---\n");
            printf("Número do Voo: %d\n", atual->numero_voo);
            printf("Dia do Voo: %d\n", atual->data_voo);
            printf("Horário: %02d:%02d\n", atual->hora, atual->min);
            printf("Aeroporto de Saída: %d\n", atual->aeroporto_saida);
            printf("Aeroporto de Chegada: %d\n", atual->aeroporto_chegada);
            printf("Rota: %d\n", atual->rota);
            printf("Tempo Estimado de Voo: %.2f horas\n", atual->tempo_estimado);
            printf("Passageiros a Bordo: %d\n", atual->passageiros_bordo);
            return;
        }
        atual = atual->proximo;
    }

    // Se chegar aqui, o voo não foi encontrado
    printf("Voo com número %d não encontrado.\n", numero_voo);
}

// Função para remover um voo
void removeVoo(Voo** lista, int numero_voo) {
    // Verificar se a lista está vazia
    if (*lista == NULL) {
        printf("Não há voos cadastrados.\n");
        return;
    }

    Voo* atual = *lista;
    Voo* anterior = NULL;

    // Percorrer a lista procurando o voo
    while (atual != NULL) {
        if (atual->numero_voo == numero_voo) {
            // Se for o primeiro voo da lista
            if (anterior == NULL) {
                *lista = atual->proximo;
            } else {
                // Conectar o voo anterior ao próximo voo
                anterior->proximo = atual->proximo;
            }

            // Liberar memória do voo removido
            free(atual);
            printf("Voo %d removido com sucesso!\n", numero_voo);
            return;
        }

        // Atualizar ponteiros para continuar a busca
        anterior = atual;
        atual = atual->proximo;
    }

    // Se chegar aqui, o voo não foi encontrado
    printf("Voo com número %d não encontrado.\n", numero_voo);
}

// Função para imprimir todos os voos
void imprimirVoos(Voo* lista) {
    if (lista == NULL) {
        printf("Não há voos cadastrados.\n");
        return;
    }

    Voo* atual = lista;
    while (atual != NULL) {
        printf("\n--- Informações do Voo ---\n");
        printf("Número do Voo: %d\n", atual->numero_voo);
        printf("Dia do Voo: %d\n", atual->data_voo);
        printf("Horário: %02d:%02d\n", atual->hora, atual->min);
        printf("Aeroporto de Saída: %d\n", atual->aeroporto_saida);
        printf("Aeroporto de Chegada: %d\n", atual->aeroporto_chegada);
        printf("Rota: %d\n", atual->rota);
        printf("Tempo Estimado de Voo: %.2f horas\n", atual->tempo_estimado);
        printf("Passageiros a Bordo: %d\n", atual->passageiros_bordo);
        
        atual = atual->proximo;
    }
}

// Função para liberar memória de todos os voos
void liberarVoos(Voo* lista) {
    Voo* atual = lista;
    while (atual != NULL) {
        Voo* temp = atual;
        atual = atual->proximo;
        free(temp);
    }
}

// Função principal para demonstração
int main() {
	setlocale(LC_ALL,"Portuguese");
	
    Voo* listaVoos = NULL;
    int opcao, numero_voo;

    do {
        printf("\n--- SISTEMA DE GERENCIAMENTO DE VOOS VOEBEM ---\n");
        printf("1. Cadastrar Novo Voo\n");
        printf("2. Consultar Voo\n");
        printf("3. Remover Voo\n");
        printf("4. Imprimir Todos os Voos\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarVoo(&listaVoos);
                break;
            case 2:
                printf("Digite o número do voo a consultar: ");
                scanf("%d", &numero_voo);
                consultaVoo(listaVoos, numero_voo);
                break;
            case 3:
                printf("Digite o número do voo a remover: ");
                scanf("%d", &numero_voo);
                removeVoo(&listaVoos, numero_voo);
                break;
            case 4:
                imprimirVoos(listaVoos);
                break;
            case 5:
                liberarVoos(listaVoos);
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 5);

    return 0;
}
