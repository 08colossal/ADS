#ifndef EXEMPLO_H
#define EXEMPLO_H

typedef struct {
    float x, y;
} Ponto;

Ponto criarPonto(float x, float y);
float distancia(Ponto p1, Ponto p2);

#endif