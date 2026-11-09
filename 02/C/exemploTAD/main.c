#include <stdio.h>
#include "exemplo.h"

int main(void) {
    Ponto p1 = criarPonto(0.0f, 0.0f);
    Ponto p2 = criarPonto(3.0f, 4.0f);
    printf("Distância: %.2f\n", distancia(p1, p2));

    return 0;
}

//me when it doesnt work