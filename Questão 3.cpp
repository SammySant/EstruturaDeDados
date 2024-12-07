#include <stdio.h>  // Biblioteca padr�o de entrada e sa�da

// Defini��o de constantes para facilitar modifica��es futuras
#define NUM_ALUNOS 5   // N�mero total de alunos na turma
#define NUM_PROVAS 4   // N�mero de provas por aluno

int main() {
    // Declara��o da matriz de notas com valores pr�-definidos
    // Estrutura: [aluno][prova] - cada linha representa um aluno
    // Cada coluna representa as notas das diferentes provas
    float notas[NUM_ALUNOS][NUM_PROVAS] = {
        {7.5, 8.0, 6.5, 9.0},  // Notas do Aluno 1
        {6.0, 7.5, 8.5, 7.0},  // Notas do Aluno 2
        {8.5, 9.0, 7.5, 8.0},  // Notas do Aluno 3
        {5.5, 6.0, 7.0, 6.5},  // Notas do Aluno 4
        {9.0, 8.5, 8.0, 9.5}   // Notas do Aluno 5
    };
    
    // Vetor para armazenar as m�dias individuais de cada aluno
    float medias_alunos[NUM_ALUNOS];
    
    // Declara��o de vari�veis auxiliares para c�lculos
    float soma_notas_aluno,  // Soma das notas de um �nico aluno
          media_turma = 0.0; // Acumulador para c�lculo da m�dia geral
    
    // Vari�veis de itera��o para os la�os de repeti��o
    int i, j;

    // Cabe�alho do programa
    printf("=== SISTEMA DE NOTAS ===\n");
    
    // La�o externo: percorre cada aluno
    for (i = 0; i < NUM_ALUNOS; i++) {
        // Reinicia a soma de notas para cada novo aluno
        soma_notas_aluno = 0.0;
        
        // La�o interno: percorre as notas de cada prova do aluno atual
        for (j = 0; j < NUM_PROVAS; j++) {
            // Soma todas as notas do aluno atual
            soma_notas_aluno += notas[i][j];
        }
        
        // Calcula a m�dia do aluno dividindo a soma pelo n�mero de provas
        medias_alunos[i] = soma_notas_aluno / NUM_PROVAS;
        
        // Adiciona a m�dia do aluno � soma total das m�dias
        media_turma += medias_alunos[i];
    }

    // Calcula a m�dia final da turma dividindo a soma das m�dias pelo n�mero de alunos
    media_turma /= NUM_ALUNOS;

    // Se��o de apresenta��o dos resultados
    printf("\n=== RESULTADOS ===\n");
    
    // La�o para imprimir notas e m�dia de cada aluno
    for (i = 0; i < NUM_ALUNOS; i++) {
        // Imprime o n�mero do aluno
        printf("Aluno %d - Notas: ", i + 1);
        
        // Imprime todas as notas do aluno
        for (j = 0; j < NUM_PROVAS; j++) {
            printf("%.1f ", notas[i][j]);
        }
        
        // Imprime a m�dia do aluno
        printf("| M�dia: %.2f\n", medias_alunos[i]);
    }
    
    // Imprime a m�dia final de toda a turma
    printf("\nM�dia da Turma: %.2f\n", media_turma);

    // Indica que o programa terminou com sucesso
    return 0;
}
