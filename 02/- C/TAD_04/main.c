#include "aluno.h"
#include <stdio.h>
#include <string.h>

int main(void){
    char nome[100];
    float n1, n2;

    printf("Digite seu nome: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';
    
    printf("Digite suas notas: ");
    scanf("%f %f", &n1, &n2);

    aluno al = criarAluno(nome, n1, n2);
    exibeAluno(al);    
    printf("valor média: %.2f", calculoMedia(al));
    exibeSituacao(al);

    return 0;
}

/*
cd "c:/Users/Giovana/Documents/GITHUB/ADS/02/- C/TAD_04"
gcc main.c implement.c -o programa.exe 
./programa.exe
*/