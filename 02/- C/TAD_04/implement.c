#include "aluno.h"
#include <math.h>
#include <string.h>
#include <stdio.h>

//criar aluno e retorná-lo
aluno criarAluno(char nome[], float nota1, float nota2){
    aluno a;
    strcpy(a.nome, nome);
    a.nota1 = nota1;
    a.nota2 = nota2;
    return a;
}

//media
float calculoMedia(aluno a){
    float media = ( a.nota1 + a.nota2 ) / 2;
    return media;
}

//exibe aluno
void exibeAluno(aluno a){
    printf("Aluno: %s\n", a.nome);
    printf("Nota 1: %.2f\n", a.nota1);
    printf("Nota 2: %.2f\n", a.nota2);
}

//exibe situação
void exibeSituacao(aluno a){
    float media = calculoMedia(a);
    if(media >= 6.0){
        printf("\nAprovado!!!");
    }
    else{
        printf("\nReprovado.");
    }
}