#include <stdio.h>

int main() {
    // Declaração das variáveis
    int x, y, *p;

    // Inicialização de y com 0
    y = 0;

    // p recebe o endereço de y
    p = &y;

    // x recebe o valor apontado por p (que é y, atualmente 0)
    x = *p;

    // x recebe o valor 4
    x = 4;

    // Incrementa o valor apontado por p (y)
    // y será incrementado de 0 para 1
    (*p)++;

    // Decrementa x
    // x será decrementado de 4 para 3
    --x;

    // Adiciona o valor de x ao valor apontado por p
    // y = y + x
    // y = 1 + 3 = 4
    (*p) += x;

    // Impressão dos valores finais para verificação
    printf("Valores finais:\n");
    printf("x = %d\n", x);
    printf("y = %d\n", y);
    printf("*p = %d\n", *p);
    printf("Endereço de p: %p\n", (void*)p);

    return 0;
}
