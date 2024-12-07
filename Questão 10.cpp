#include <stdio.h>  // Biblioteca padrão de entrada e saída
#include <locale.h> // Para definir a biblioteca

// Função recursiva para calcular a somatória de 1 a N
int somatoria_recursiva(int n) {
    // CASO BASE: Condição de parada da recursão
    // Quando n chega a 1, retorna 1 (primeiro número da sequência)
    // Esta é a condição fundamental que interrompe a chamada recursiva
    if (n == 1) {
        return 1;
    }
    
    // CASO RECURSIVO: 
    // Lógica de soma do número atual com a somatória dos números anteriores
    // n + somatoria_recursiva(n-1) realiza:
    // 1. Soma o número atual (n)
    // 2. Chama a função novamente com n-1
    // 3. Continua até chegar ao caso base (n == 1)
    return n + somatoria_recursiva(n - 1);
}

int main() {
	setlocale(LC_ALL,"Portuguese");
	
	
    // Declaração da variável para armazenar o número digitado pelo usuário
    int n;

    // Mensagem e entrada de dados do usuário
    // Solicita um número inteiro para calcular a somatória
    printf("Digite um número inteiro positivo N: ");
    scanf("%d", &n);  // Lê o número digitado pelo usuário

    // Validação de entrada
    // Verifica se o número digitado é positivo
    if (n <= 0) {
        // Mensagem de erro caso o número não seja válido
        printf("Por favor, digite um número inteiro positivo.\n");
        return 1;  // Encerra o programa com código de erro
    }

    // Chama a função recursiva para calcular a somatória
    // Armazena o resultado em uma variável
    int resultado = somatoria_recursiva(n);
    
    // Exibe o resultado da somatória para o usuário
    // Mostra o número original e a soma de todos os números até ele
    printf("A somatória dos números de 1 a %d é: %d\n", n, resultado);

    // Retorna 0 para indicar execução bem-sucedida do programa
    return 0;
}

/* 
Explicação:

Exemplo com N = 5:
1. somatoria_recursiva(5) é chamado
   - Retorna 5 + somatoria_recursiva(4)
2. somatoria_recursiva(4) é chamado
   - Retorna 4 + somatoria_recursiva(3)
3. somatoria_recursiva(3) é chamado
   - Retorna 3 + somatoria_recursiva(2)
4. somatoria_recursiva(2) é chamado
   - Retorna 2 + somatoria_recursiva(1)
5. somatoria_recursiva(1) é chamado
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
