#ifndef LISTA_H // Evita inclusao duplicada do cabecalho.
#define LISTA_H // Define a macro de protecao.
#include <stdio.h> // Disponibiliza printf() e perror ().
#include <stdlib.h> // Disponibiliza malloc(), free(), exit() e EXIT_FAILURE.

// Estrutura do no da lista duplamente ligada.
typedef struct No { // Inicia a definicao de um no.
    int dado; // Valor armazenado no no.
    struct No* ant; // Ponteiro para o no anterior.
    struct No* prox; // Ponteiro para o proximo no.
} No; // Finaliza e cria o tipo No.

// Estrutura principal da lista.
typedef struct { // Inicia a estrutura de controle.
    No* ini; // Ponteiro para o primeiro no.
    No* fim; // Ponteiro para o ultimo no.
    int n; // Quantidade de nos na lista.
} Lista; // Finaliza e cria o tipo Lista.

// Funcoes do TAD.
Lista* criaLista(void); // Cria e retorna uma lista vazia.
int listaVazia(Lista* L); // Verifica se a lista esta vazia.
void destroiLista(Lista* L); // Libera todos os nos e a estrutura Lista.

void insereInicio(Lista* L, int valor); // Insere no inicio.
void insereFim(Lista* L, int valor); // Insere no fim.

No* busca(Lista* L, int valor); // Procura um valor e retorna o no.
void imprime(const Lista* L); // Percorre do inicio ao fim.
void imprimeReverso(const Lista* L); // Percorre do fim ao inicio.

void removeInicio(Lista* L); // Remove o primeiro no.
void removeFim(Lista* L); // Remove o ultimo no.
void removeValor(Lista* L, int valor); // Remove a primeira ocorrencia

// Funções atividade
void insereDepois(Lista* L, No* p, int valor);
void insereAntes(Lista* L, No* p, int valor);
void insereOrdenado(Lista* L, int valor);

#endif // Finaliza a protecao do cabecalho