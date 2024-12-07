#include <stdio.h>

int main() {
    // Declara��o das vari�veis
    int x, y, *p;

    // Inicializa��o de y com 0
    y = 0;

    // p recebe o endere�o de y
    p = &y;

    // x recebe o valor apontado por p (que � y, atualmente 0)
    x = *p;

    // x recebe o valor 4
    x = 4;

    // Incrementa o valor apontado por p (y)
    // y ser� incrementado de 0 para 1
    (*p)++;

    // Decrementa x
    // x ser� decrementado de 4 para 3
    --x;

    // Adiciona o valor de x ao valor apontado por p
    // y = y + x
    // y = 1 + 3 = 4
    (*p) += x;

    // Impress�o dos valores finais para verifica��o
    printf("Valores finais:\n");
    printf("x = %d\n", x);
    printf("y = %d\n", y);
    printf("*p = %d\n", *p);
    printf("Endere�o de p: %p\n", (void*)p);

    return 0;
}
