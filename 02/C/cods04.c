#include <stdio.h>
#include <stdlib.h>

int main(){

    float soma = 0;
    int n;
    printf("Quantos valores deseja armazenar?");
    scanf("%d", &n);
    float *alloc = malloc(n * sizeof *alloc);
    for (int i = 0; i < n; i++){
        printf("Digite o %dº número: ", i);
        scanf("%f", &alloc[i]);
        soma += alloc[i];
    }
    printf("A média dos valores é: %.2f", soma/n);
    free(alloc);
    alloc = NULL;
    return 0;
}