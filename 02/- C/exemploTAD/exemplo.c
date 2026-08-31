#include "exemplo.h"
#include <math.h>

Ponto criarPonto (float x, float y) {
    Ponto p = {x, y};
    return p;
}

float distancia(Ponto p1, Ponto p2) {
    float dx = p2.x - p1.x;
    float dy = p2.y - p1.y;
    return sqrt(dx * dx + dy * dy);
}