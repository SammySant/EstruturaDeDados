#include <stdio.h>   // Biblioteca padrão para entrada e saída
#include <stdbool.h> // Biblioteca para usar o tipo booleano (true/false)

#define TAMANHO 3 // Define o tamanho do tabuleiro como 3x3

// Função para inicializar o tabuleiro
void inicializarTabuleiro(char tabuleiro[TAMANHO][TAMANHO]) {
    // Preenche todas as posições da matriz com espaços (' ')
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = ' ';
        }
    }
}

// Função para exibir o tabuleiro
void exibirTabuleiro(char tabuleiro[TAMANHO][TAMANHO]) {
    // Exibe a matriz em formato visual, com linhas e colunas separadas por "|"
    printf("\n");
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf(" %c ", tabuleiro[i][j]); // Exibe o conteúdo de cada célula
            if (j < TAMANHO - 1) printf("|"); // Adiciona separadores verticais
        }
        printf("\n");
        if (i < TAMANHO - 1) {
            printf("---|---|---\n"); // Adiciona linhas horizontais entre as fileiras
        }
    }
    printf("\n");
}

// Função para verificar se há um vencedor
char verificarVencedor(char tabuleiro[TAMANHO][TAMANHO]) {
    // Verifica todas as linhas
    for (int i = 0; i < TAMANHO; i++) {
        if (tabuleiro[i][0] != ' ' && tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2]) {
            return tabuleiro[i][0]; // Retorna o símbolo ('X' ou 'O') do vencedor
        }
    }

    // Verifica todas as colunas
    for (int j = 0; j < TAMANHO; j++) {
        if (tabuleiro[0][j] != ' ' && tabuleiro[0][j] == tabuleiro[1][j] && tabuleiro[1][j] == tabuleiro[2][j]) {
            return tabuleiro[0][j]; // Retorna o vencedor
        }
    }

    // Verifica a diagonal principal (canto superior esquerdo até canto inferior direito)
    if (tabuleiro[0][0] != ' ' && tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2]) {
        return tabuleiro[0][0];
    }

    // Verifica a diagonal secundária (canto superior direito até canto inferior esquerdo)
    if (tabuleiro[0][2] != ' ' && tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0]) {
        return tabuleiro[0][2];
    }

    // Retorna um espaço vazio (' ') caso não haja vencedor
    return ' ';
}

// Função para verificar se o tabuleiro está cheio (empate)
bool tabuleiroCheio(char tabuleiro[TAMANHO][TAMANHO]) {
    // Percorre todas as células do tabuleiro
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            if (tabuleiro[i][j] == ' ') {
                return false; // Retorna false se encontrar uma célula vazia
            }
        }
    }
    return true; // Retorna true se todas as células estiverem preenchidas
}

// Função principal
int main() {
    char tabuleiro[TAMANHO][TAMANHO]; // Matriz que representa o tabuleiro
    char jogadorAtual = 'X';         // Define o jogador que começa ('X')
    char vencedor = ' ';             // Variável para armazenar o vencedor
    int linha, coluna;               // Variáveis para guardar as jogadas

    inicializarTabuleiro(tabuleiro); // Inicializa o tabuleiro com espaços vazios

    printf("Bem-vindo ao Jogo da Velha!\n");
    exibirTabuleiro(tabuleiro); // Mostra o tabuleiro vazio no início do jogo

    while (true) { // Loop principal do jogo
        // Solicita a jogada do jogador atual
        printf("Jogador %c, escolha sua jogada (linha e coluna, 0-2): ", jogadorAtual);
        scanf("%d %d", &linha, &coluna); // Lê a linha e coluna digitadas pelo jogador

        // Verifica se a jogada é válida
        if (linha >= 0 && linha < TAMANHO && coluna >= 0 && coluna < TAMANHO && tabuleiro[linha][coluna] == ' ') {
            tabuleiro[linha][coluna] = jogadorAtual; // Atualiza o tabuleiro com a jogada
            exibirTabuleiro(tabuleiro);             // Exibe o tabuleiro atualizado

            // Verifica se há um vencedor
            vencedor = verificarVencedor(tabuleiro);
            if (vencedor != ' ') {
                printf("Parabéns, jogador %c! Você venceu!\n", vencedor);
                break; // Encerra o loop se houver um vencedor
            }

            // Verifica se o tabuleiro está cheio (empate)
            if (tabuleiroCheio(tabuleiro)) {
                printf("O jogo terminou em empate!\n");
                break; // Encerra o loop se houver empate
            }

            // Alterna o jogador (troca entre 'X' e 'O')
            jogadorAtual = (jogadorAtual == 'X') ? 'O' : 'X';
        } else {
            printf("Jogada inválida. Tente novamente.\n"); // Mensagem para jogada inválida
        }
    }

    printf("Obrigado por jogar!\n");
    return 0; // Finaliza o programa
}

