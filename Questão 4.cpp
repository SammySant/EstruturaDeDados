#include <stdio.h>  // Biblioteca padr�o de entrada e sa�da
#include <locale.h> //Para mudar o idioma

// Defini��o de constantes para facilitar manuten��o do c�digo
// N�mero de cidades que ter�o �ndices pluviom�tricos registrados
#define NUM_CIDADES 7
// N�mero de meses que ser�o analisados
#define NUM_MESES 6

int main() {
	setlocale(LC_ALL,"Portuguese");
	
    // Declara��o da matriz para armazenar �ndices pluviom�tricos
    // Estrutura: [cidades][meses] 
    // Cada linha representa uma cidade
    // Cada coluna representa um m�s
    float indices_pluviometricos[NUM_CIDADES][NUM_MESES];
    
    // Vetor para armazenar a m�dia de �ndices pluviom�tricos para cada cidade
    // Ter� um valor para cada cidade
    float medias_cidades[NUM_CIDADES];
    
    // Vetor para armazenar a m�dia de �ndices pluviom�tricos para cada m�s na regi�o
    // Ter� um valor para cada m�s
    float medias_meses[NUM_MESES];
    
    // Vari�veis auxiliares para itera��o e c�lculos
    // i: iterador para cidades
    // j: iterador para meses
    int i, j;
    
    // Vari�veis para armazenar somas tempor�rias durante os c�lculos
    float soma_cidade,  // Soma dos �ndices de uma cidade
           soma_mes;    // Soma dos �ndices de um m�s em todas as cidades

    // Vetor com nomes dos meses para impress�o mais amig�vel
    // Permite exibir o nome do m�s ao inv�s de apenas n�meros
    char *nomes_meses[] = {
        "Janeiro", "Fevereiro", "Mar�o", 
        "Abril", "Maio", "Junho"
    };

    // In�cio da entrada de dados
    printf("=== REGISTRO DE �NDICES PLUVIOM�TRICOS ===\n");
    
    // La�o externo: percorre cada cidade
    for (i = 0; i < NUM_CIDADES; i++) {
        // Imprime identifica��o da cidade atual
        printf("\nCidade %d:\n", i + 1);
        
        // Inicializa soma da cidade como zero antes de acumular valores
        soma_cidade = 0.0;
        
        // La�o interno: percorre cada m�s para a cidade atual
        for (j = 0; j < NUM_MESES; j++) {
            // Solicita entrada do �ndice pluviom�trico para o m�s espec�fico
            printf("�ndice pluviom�trico de %s: ", nomes_meses[j]);
            // L� o valor digitado pelo usu�rio e armazena na matriz
            scanf("%f", &indices_pluviometricos[i][j]);
            
            // Adiciona o valor do m�s � soma total da cidade
            soma_cidade += indices_pluviometricos[i][j];
        }
        
        // Calcula a m�dia da cidade dividindo a soma total pelo n�mero de meses
        medias_cidades[i] = soma_cidade / NUM_MESES;
    }

    // Prepara��o para c�lculo das m�dias por m�s
    printf("\n=== M�DIAS POR M�S NA REGI�O ===\n");
    
    // Inicializa vetor de m�dias dos meses com zeros
    // Garante que n�o haver� valores residuais de execu��es anteriores
    for (j = 0; j < NUM_MESES; j++) {
        medias_meses[j] = 0.0;
    }
    
    // C�lculo das m�dias por m�s
    // La�o externo: percorre cada m�s
    for (j = 0; j < NUM_MESES; j++) {
        // Zera soma do m�s antes de acumular valores de todas as cidades
        soma_mes = 0.0;
        
        // La�o interno: percorre todas as cidades para o m�s atual
        for (i = 0; i < NUM_CIDADES; i++) {
            // Adiciona o �ndice pluviom�trico da cidade no m�s � soma
            soma_mes += indices_pluviometricos[i][j];
        }
        
        // Calcula m�dia do m�s dividindo soma total pelo n�mero de cidades
        medias_meses[j] = soma_mes / NUM_CIDADES;
    }

    // Impress�o dos resultados

    // a) Imprime �ndice de pluviosidade m�dio de cada cidade
    printf("\n=== M�DIAS POR CIDADE ===\n");
    // Percorre todas as cidades
    for (i = 0; i < NUM_CIDADES; i++) {
        // Imprime n�mero da cidade e sua m�dia com 2 casas decimais
        printf("Cidade %d: %.2f mm\n", i + 1, medias_cidades[i]);
    }

    // b) Imprime �ndice de pluviosidade m�dia de cada m�s na regi�o
    printf("\n=== M�DIAS POR M�S ===\n");
    // Percorre todos os meses
    for (j = 0; j < NUM_MESES; j++) {
        // Imprime nome do m�s e sua m�dia com 2 casas decimais
        printf("%s: %.2f mm\n", nomes_meses[j], medias_meses[j]);
    }

    // Indica que o programa terminou com sucesso
    return 0;
}
