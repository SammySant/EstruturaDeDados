#include <stdio.h>  // Biblioteca padrão de entrada e saída
#include <locale.h>

// Função para encontrar o menor e o maior número em um vetor 3x3
// Parâmetros:
// - matrix: matriz de inteiros 3x3 a ser analisada
// - min: ponteiro para armazenar o menor número encontrado
// - max: ponteiro para armazenar o maior número encontrado
void encontrarMaiorMenor(int matrix[3][3], int *min, int *max) {
    // Inicializar os valores de min e max com o primeiro elemento da matriz
    // Isso garante que temos um ponto de partida para comparação
    *min = matrix[0][0];  // Assume que o primeiro elemento é o menor
    *max = matrix[0][0];  // Assume que o primeiro elemento é o maior
    
    // Percorrer todos os elementos da matriz
    // Laço externo (i) percorre as linhas da matriz
    for (int i = 0; i < 3; i++) {
        // Laço interno (j) percorre as colunas da matriz
        for (int j = 0; j < 3; j++) {
            // Verificação para encontrar o menor número
            // Se o elemento atual for menor que o valor mínimo atual
            if (matrix[i][j] < *min) {
                // Atualiza o valor mínimo com o elemento atual
                *min = matrix[i][j];
            }
            
            // Verificação para encontrar o maior número
            // Se o elemento atual for maior que o valor máximo atual
            if (matrix[i][j] > *max) {
                // Atualiza o valor máximo com o elemento atual
                *max = matrix[i][j];
            }
        }
    }
}

int main(void) {
	setlocale(LC_ALL,"Portuguese");
	
    // Declaração de variáveis para armazenar o menor e o maior número
    int min, max;
    
    // Declaração e inicialização de matriz 3x3 com valores pré-definidos
    // A matriz é organizada em 3 linhas, cada linha com 3 colunas
    int matriz[3][3] = {
        {1, 3, 7},    // Primeira linha
        {4, 9, 2},    // Segunda linha
        {11, 6, 5}    // Terceira linha
    };
    
    // Chamada da função encontrarMaiorMenor
    // Passagem da matriz e endereços de min e max
    // Uso de & para passar o endereço de memória das variáveis
    encontrarMaiorMenor(matriz, &min, &max);
    
    // Exibição dos resultados encontrados
    // Imprime o menor número da matriz
    printf("Menor número: %d\n", min);
    
    // Imprime o maior número da matriz
    printf("Maior número: %d\n", max);
    
    // Indica que o programa terminou com sucesso
    return 0;
}
