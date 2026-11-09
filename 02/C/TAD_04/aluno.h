#ifndef ALUNO_H
#define ALUNO_H

typedef struct{
    char nome[100];
    float nota1, nota2;
} aluno;

aluno criarAluno(char nome[], float n1, float n2);
void exibeAluno(aluno a);
float calculoMedia(aluno a);
void exibeSituacao(aluno a);
#endif