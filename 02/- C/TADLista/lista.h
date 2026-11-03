#ifndef LISTA_H                 // Se LISTA_H ainda nao foi definido...
#define LISTA_H                 // ...define LISTA_H e inicia a protecao do cabecalho.

// Define o formato de cada no da lista simplesmente encadeada.
typedef struct No {             // Inicia a declaracao da estrutura chamada struct No.
    int dado;                       // Campo que armazena o valor inteiro do no.
    struct No *prox;                // Ponteiro que guarda o endereco do proximo no.
} No;                           // Cria o apelido No para escrever menos codigo.

// Prototipo da funcao responsavel por alocar e inicializar um novo no
No* criaNo(int valor);          // Recebe um int e devolve o endereco do novo no.

// Prototipos das operacoes de insercao.
void insereInicio(No **headRef, int valor);             // Insere antes do primeiro no.
void insereFim(No **headRef, int valor);                // Insere depois do ultimo no.
void inserePosicao(No **headRef, int valor, int pos);   // Insere em um indice.
void insereOrdenado(No **headRef, int valor);            // Insere mantendo ordem crescente.

// Prototipos das operacoes de consulta/percurso.
void imprime(const No *head);                           // Percorre e exibe os valores sem alterar a lista.
No* busca(No *head, int valor);                         // Procura valor e devolve o endereco do no.

// Prototipos das operacoes de remocao.
void removeInicio(No **headRef);                        // Remove o primeiro no.
void removeFim(No **headRef);                           // Remove o ultimo no.
void removeValor(No **headRef, int valor);              // Remove a primeira ocorrencia do valor.
// Prototipo para liberar toda a memoria usada pela lista.
void destroi(No **headRef);                             // Libera todos os nos e deixa head igual a NULL.

//Protótipos atividade
int tamanho(const No* head);                            // Percorre a lista e devolve o tamanho.
void inverte(No** headRef);                             // Inverte a ordem dos ponteiros dos nos da lista.
void removeDuplicadosOrdenada(No** headRef);            // Remove duplicatas de uma lista ordenada.

#endif                                                  // Finaliza a protecao iniciada por #ifndef