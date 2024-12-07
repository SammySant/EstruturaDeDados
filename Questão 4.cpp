#include <stdio.h>  // Biblioteca padrão de entrada e saída
#include <locale.h> //Para mudar o idioma

// Definição de constantes para facilitar manutenção do código
// Número de cidades que terão índices pluviométricos registrados
#define NUM_CIDADES 7
// Número de meses que serão analisados
#define NUM_MESES 6

int main() {
	setlocale(LC_ALL,"Portuguese");
	
    // Declaração da matriz para armazenar índices pluviométricos
    // Estrutura: [cidades][meses] 
    // Cada linha representa uma cidade
    // Cada coluna representa um mês
    float indices_pluviometricos[NUM_CIDADES][NUM_MESES];
    
    // Vetor para armazenar a média de índices pluviométricos para cada cidade
    // Terá um valor para cada cidade
    float medias_cidades[NUM_CIDADES];
    
    // Vetor para armazenar a média de índices pluviométricos para cada mês na região
    // Terá um valor para cada mês
    float medias_meses[NUM_MESES];
    
    // Variáveis auxiliares para iteração e cálculos
    // i: iterador para cidades
    // j: iterador para meses
    int i, j;
    
    // Variáveis para armazenar somas temporárias durante os cálculos
    float soma_cidade,  // Soma dos índices de uma cidade
           soma_mes;    // Soma dos índices de um mês em todas as cidades

    // Vetor com nomes dos meses para impressão mais amigável
    // Permite exibir o nome do mês ao invés de apenas números
    char *nomes_meses[] = {
        "Janeiro", "Fevereiro", "Março", 
        "Abril", "Maio", "Junho"
    };

    // Início da entrada de dados
    printf("=== REGISTRO DE ÍNDICES PLUVIOMÉTRICOS ===\n");
    
    // Laço externo: percorre cada cidade
    for (i = 0; i < NUM_CIDADES; i++) {
        // Imprime identificação da cidade atual
        printf("\nCidade %d:\n", i + 1);
        
        // Inicializa soma da cidade como zero antes de acumular valores
        soma_cidade = 0.0;
        
        // Laço interno: percorre cada mês para a cidade atual
        for (j = 0; j < NUM_MESES; j++) {
            // Solicita entrada do índice pluviométrico para o mês específico
            printf("Índice pluviométrico de %s: ", nomes_meses[j]);
            // Lê o valor digitado pelo usuário e armazena na matriz
            scanf("%f", &indices_pluviometricos[i][j]);
            
            // Adiciona o valor do mês à soma total da cidade
            soma_cidade += indices_pluviometricos[i][j];
        }
        
        // Calcula a média da cidade dividindo a soma total pelo número de meses
        medias_cidades[i] = soma_cidade / NUM_MESES;
    }

    // Preparação para cálculo das médias por mês
    printf("\n=== MÉDIAS POR MÊS NA REGIÃO ===\n");
    
    // Inicializa vetor de médias dos meses com zeros
    // Garante que não haverá valores residuais de execuções anteriores
    for (j = 0; j < NUM_MESES; j++) {
        medias_meses[j] = 0.0;
    }
    
    // Cálculo das médias por mês
    // Laço externo: percorre cada mês
    for (j = 0; j < NUM_MESES; j++) {
        // Zera soma do mês antes de acumular valores de todas as cidades
        soma_mes = 0.0;
        
        // Laço interno: percorre todas as cidades para o mês atual
        for (i = 0; i < NUM_CIDADES; i++) {
            // Adiciona o índice pluviométrico da cidade no mês à soma
            soma_mes += indices_pluviometricos[i][j];
        }
        
        // Calcula média do mês dividindo soma total pelo número de cidades
        medias_meses[j] = soma_mes / NUM_CIDADES;
    }

    // Impressão dos resultados

    // a) Imprime índice de pluviosidade médio de cada cidade
    printf("\n=== MÉDIAS POR CIDADE ===\n");
    // Percorre todas as cidades
    for (i = 0; i < NUM_CIDADES; i++) {
        // Imprime número da cidade e sua média com 2 casas decimais
        printf("Cidade %d: %.2f mm\n", i + 1, medias_cidades[i]);
    }

    // b) Imprime índice de pluviosidade média de cada mês na região
    printf("\n=== MÉDIAS POR MÊS ===\n");
    // Percorre todos os meses
    for (j = 0; j < NUM_MESES; j++) {
        // Imprime nome do mês e sua média com 2 casas decimais
        printf("%s: %.2f mm\n", nomes_meses[j], medias_meses[j]);
    }

    // Indica que o programa terminou com sucesso
    return 0;
}
