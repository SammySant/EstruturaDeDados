#include <stdio.h>  // Biblioteca padrão de entrada e saída

// Definição de constantes para facilitar modificações futuras
#define NUM_ALUNOS 5   // Número total de alunos na turma
#define NUM_PROVAS 4   // Número de provas por aluno

int main() {
    // Declaração da matriz de notas com valores pré-definidos
    // Estrutura: [aluno][prova] - cada linha representa um aluno
    // Cada coluna representa as notas das diferentes provas
    float notas[NUM_ALUNOS][NUM_PROVAS] = {
        {7.5, 8.0, 6.5, 9.0},  // Notas do Aluno 1
        {6.0, 7.5, 8.5, 7.0},  // Notas do Aluno 2
        {8.5, 9.0, 7.5, 8.0},  // Notas do Aluno 3
        {5.5, 6.0, 7.0, 6.5},  // Notas do Aluno 4
        {9.0, 8.5, 8.0, 9.5}   // Notas do Aluno 5
    };
    
    // Vetor para armazenar as médias individuais de cada aluno
    float medias_alunos[NUM_ALUNOS];
    
    // Declaração de variáveis auxiliares para cálculos
    float soma_notas_aluno,  // Soma das notas de um único aluno
          media_turma = 0.0; // Acumulador para cálculo da média geral
    
    // Variáveis de iteração para os laços de repetição
    int i, j;

    // Cabeçalho do programa
    printf("=== SISTEMA DE NOTAS ===\n");
    
    // Laço externo: percorre cada aluno
    for (i = 0; i < NUM_ALUNOS; i++) {
        // Reinicia a soma de notas para cada novo aluno
        soma_notas_aluno = 0.0;
        
        // Laço interno: percorre as notas de cada prova do aluno atual
        for (j = 0; j < NUM_PROVAS; j++) {
            // Soma todas as notas do aluno atual
            soma_notas_aluno += notas[i][j];
        }
        
        // Calcula a média do aluno dividindo a soma pelo número de provas
        medias_alunos[i] = soma_notas_aluno / NUM_PROVAS;
        
        // Adiciona a média do aluno à soma total das médias
        media_turma += medias_alunos[i];
    }

    // Calcula a média final da turma dividindo a soma das médias pelo número de alunos
    media_turma /= NUM_ALUNOS;

    // Seção de apresentação dos resultados
    printf("\n=== RESULTADOS ===\n");
    
    // Laço para imprimir notas e média de cada aluno
    for (i = 0; i < NUM_ALUNOS; i++) {
        // Imprime o número do aluno
        printf("Aluno %d - Notas: ", i + 1);
        
        // Imprime todas as notas do aluno
        for (j = 0; j < NUM_PROVAS; j++) {
            printf("%.1f ", notas[i][j]);
        }
        
        // Imprime a média do aluno
        printf("| Média: %.2f\n", medias_alunos[i]);
    }
    
    // Imprime a média final de toda a turma
    printf("\nMédia da Turma: %.2f\n", media_turma);

    // Indica que o programa terminou com sucesso
    return 0;
}
