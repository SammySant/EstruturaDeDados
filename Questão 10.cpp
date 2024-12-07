#include <stdio.h>  // Biblioteca padr�o de entrada e sa�da
#include <locale.h> // Para definir a biblioteca

// Fun��o recursiva para calcular a somat�ria de 1 a N
int somatoria_recursiva(int n) {
    // CASO BASE: Condi��o de parada da recurs�o
    // Quando n chega a 1, retorna 1 (primeiro n�mero da sequ�ncia)
    // Esta � a condi��o fundamental que interrompe a chamada recursiva
    if (n == 1) {
        return 1;
    }
    
    // CASO RECURSIVO: 
    // L�gica de soma do n�mero atual com a somat�ria dos n�meros anteriores
    // n + somatoria_recursiva(n-1) realiza:
    // 1. Soma o n�mero atual (n)
    // 2. Chama a fun��o novamente com n-1
    // 3. Continua at� chegar ao caso base (n == 1)
    return n + somatoria_recursiva(n - 1);
}

int main() {
	setlocale(LC_ALL,"Portuguese");
	
	
    // Declara��o da vari�vel para armazenar o n�mero digitado pelo usu�rio
    int n;

    // Mensagem e entrada de dados do usu�rio
    // Solicita um n�mero inteiro para calcular a somat�ria
    printf("Digite um n�mero inteiro positivo N: ");
    scanf("%d", &n);  // L� o n�mero digitado pelo usu�rio

    // Valida��o de entrada
    // Verifica se o n�mero digitado � positivo
    if (n <= 0) {
        // Mensagem de erro caso o n�mero n�o seja v�lido
        printf("Por favor, digite um n�mero inteiro positivo.\n");
        return 1;  // Encerra o programa com c�digo de erro
    }

    // Chama a fun��o recursiva para calcular a somat�ria
    // Armazena o resultado em uma vari�vel
    int resultado = somatoria_recursiva(n);
    
    // Exibe o resultado da somat�ria para o usu�rio
    // Mostra o n�mero original e a soma de todos os n�meros at� ele
    printf("A somat�ria dos n�meros de 1 a %d �: %d\n", n, resultado);

    // Retorna 0 para indicar execu��o bem-sucedida do programa
    return 0;
}

/* 
Explica��o:

Exemplo com N = 5:
1. somatoria_recursiva(5) � chamado
   - Retorna 5 + somatoria_recursiva(4)
2. somatoria_recursiva(4) � chamado
   - Retorna 4 + somatoria_recursiva(3)
3. somatoria_recursiva(3) � chamado
   - Retorna 3 + somatoria_recursiva(2)
4. somatoria_recursiva(2) � chamado
   - Retorna 2 + somatoria_recursiva(1)
5. somatoria_recursiva(1) � chamado
   - Retorna 1 (CASO BASE)

Desenvolvimento da pilha de chamadas:
5 + somatoria_recursiva(4)
5 + (4 + somatoria_recursiva(3))
5 + (4 + (3 + somatoria_recursiva(2)))
5 + (4 + (3 + (2 + somatoria_recursiva(1))))
5 + (4 + (3 + (2 + 1)))
5 + (4 + (3 + 3))
5 + (4 + 6)
5 + 10
15 (resultado final)
*/
