#include <stdio.h>  // Biblioteca padr�o de entrada e sa�da
#include <locale.h>

// Fun��o para encontrar o menor e o maior n�mero em um vetor 3x3
// Par�metros:
// - matrix: matriz de inteiros 3x3 a ser analisada
// - min: ponteiro para armazenar o menor n�mero encontrado
// - max: ponteiro para armazenar o maior n�mero encontrado
void encontrarMaiorMenor(int matrix[3][3], int *min, int *max) {
    // Inicializar os valores de min e max com o primeiro elemento da matriz
    // Isso garante que temos um ponto de partida para compara��o
    *min = matrix[0][0];  // Assume que o primeiro elemento � o menor
    *max = matrix[0][0];  // Assume que o primeiro elemento � o maior
    
    // Percorrer todos os elementos da matriz
    // La�o externo (i) percorre as linhas da matriz
    for (int i = 0; i < 3; i++) {
        // La�o interno (j) percorre as colunas da matriz
        for (int j = 0; j < 3; j++) {
            // Verifica��o para encontrar o menor n�mero
            // Se o elemento atual for menor que o valor m�nimo atual
            if (matrix[i][j] < *min) {
                // Atualiza o valor m�nimo com o elemento atual
                *min = matrix[i][j];
            }
            
            // Verifica��o para encontrar o maior n�mero
            // Se o elemento atual for maior que o valor m�ximo atual
            if (matrix[i][j] > *max) {
                // Atualiza o valor m�ximo com o elemento atual
                *max = matrix[i][j];
            }
        }
    }
}

int main(void) {
	setlocale(LC_ALL,"Portuguese");
	
    // Declara��o de vari�veis para armazenar o menor e o maior n�mero
    int min, max;
    
    // Declara��o e inicializa��o de matriz 3x3 com valores pr�-definidos
    // A matriz � organizada em 3 linhas, cada linha com 3 colunas
    int matriz[3][3] = {
        {1, 3, 7},    // Primeira linha
        {4, 9, 2},    // Segunda linha
        {11, 6, 5}    // Terceira linha
    };
    
    // Chamada da fun��o encontrarMaiorMenor
    // Passagem da matriz e endere�os de min e max
    // Uso de & para passar o endere�o de mem�ria das vari�veis
    encontrarMaiorMenor(matriz, &min, &max);
    
    // Exibi��o dos resultados encontrados
    // Imprime o menor n�mero da matriz
    printf("Menor n�mero: %d\n", min);
    
    // Imprime o maior n�mero da matriz
    printf("Maior n�mero: %d\n", max);
    
    // Indica que o programa terminou com sucesso
    return 0;
}
