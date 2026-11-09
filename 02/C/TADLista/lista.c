#include <stdio.h>              // Disponibiliza printf() e perror().
#include <stdlib.h>             // Disponibiliza malloc(), free(), exit() e EXIT_FAILURE.
#include "lista.h"              // Importa a struct No e os prototipos do TAD.

// =============================================================
// CRIACAO DE NO
// =============================================================

No* criaNo(int valor) {             // Funcao recebe o valor que sera armazenado no novo no.
    No *novo = malloc(sizeof(No));  // Reserva memoria suficiente para um objeto No.

    if (novo == NULL) {                 // Verifica se a alocacao falhou.
        perror("malloc falhou");        // Exibe uma mensagem relacionada ao erro de sistema.
        exit(EXIT_FAILURE);             // Encerra o programa porque nao ha memoria para continuar.
    }                                   // Finaliza o teste de falha de malloc.

    novo->dado = valor;             // Copia o valor recebido para o campo dado do novo no.
    novo->prox = NULL;              // Inicialmente o novo no nao aponta para nenhum sucessor.

    return novo;                    // Devolve ao chamador o endereco do no recem-criado.
}                                   // Finaliza a funcao criaNo.

// =============================================================
// INSERCAO NO INICIO
// =============================================================

void insereInicio(No **headRef, int valor) {                // Recebe o endereco de head e o valor.
    No *novo = criaNo(valor);                               // Cria o no que sera colocado no inicio da lista.

    novo->prox = *headRef;                                  // Novo aponta para o antigo primeiro no da lista.
                                                            // Se a lista estiver vazia, *headRef vale NULL.

    *headRef = novo;                                        // Head original passa a apontar para o novo primeiro no.
}                                                           // Finaliza a insercao no inicio.

// =============================================================
// INSERCAO NO FIM
// =============================================================

void insereFim(No **headRef, int valor) {               // Recebe endereco de head e valor.
    No *novo = criaNo(valor);                           // Cria o no que sera colocado ao final.

    if (*headRef == NULL) {                                 // Caso especial: a lista ainda esta vazia.
        *headRef = novo;                                    // O novo no vira simultaneamente primeiro e ultimo no.
        return;                                             // Encerra a funcao porque a insercao ja terminou.
    }                                                       // Finaliza o tratamento da lista vazia.

    No *aux = *headRef;                                     // Aux comeca apontando para o primeiro no.

    while (aux->prox != NULL) {                             // Continua enquanto existir um proximo no.
        aux = aux->prox;                                    // Avanca aux exatamente um no na lista.
    }                                                       // Ao sair, aux aponta para o ultimo no.

    aux->prox = novo;                                   // O antigo ultimo no passa a apontar para o novo no.
}                                                       // Finaliza a insercao no fim.

// =============================================================
// INSERCAO EM POSICAO ESPECIFICA
// =============================================================

void inserePosicao(No **headRef, int valor, int pos) {              // Recebe head, valor e posicao.
    if (pos == 0) {                                                 // Posicao zero significa inserir antes do primeiro no.
        insereInicio(headRef, valor);                               // Reaproveita a funcao ja pronta para esse case.
        return;                                                     // Evita executar o restante da funcao desnecessariamente.
    }                                                               // Finaliza o caso especial da posicao zero.

    if (pos < 0) {                                                  // Impede o uso de indices negativos.
        printf("Posicao invalida!\n");                              // Informa o problema ao usuario.
        return;                                                     // Encerra sem criar no e sem alterar a lista.
    }                                                               // Finaliza a validacao de posicao negativa.

    No *novo = criaNo(valor);                                       // Cria o no que sera inserido.
    No *aux = *headRef;                                             // Aux inicia no primeiro no da lista.

    for (int i = 0; aux != NULL && i < pos - 1; i++) {              // Busca o antecessor.
        aux = aux->prox;                                            // Avanca um no a cada repeticao.
    }                                                               // Ao terminar, aux deve estar antes da posicao desejada.

    if (aux == NULL) {                                              // Se aux chegou a NULL, a posicao ultrapassa a lista.
        printf("Posicao invalida!\n");                              // Avisa que nao ha onde inserir.
        free(novo);                                                 // Libera o no criado, pois ele nao sera usado.
        return;                                                     // Encerra sem modificar a lista.
    }                                                               // Finaliza o tratamento da posicao invalida.

    novo->prox = aux->prox;                                     // Primeiro preserva a ligacao com o restante da lista.
    aux->prox = novo;                                           // Depois faz o no anterior apontar para o novo no.
}                                                               // Finaliza a insercao por posicao.

// =============================================================
// INSERCAO ORDENADA
// =============================================================

void insereOrdenado(No **headRef, int valor) {                      // Insere em uma lista crescente.
    No *novo = criaNo(valor);                                       // Cria o no que precisa ser encaixado na ordem correta.

    if (*headRef == NULL || valor < (*headRef)->dado) {                 // Vazia ou antes do primeiro.
        novo->prox = *headRef;                                          // Novo aponta para o antigo primeiro no.
        *headRef = novo;                                                // Head passa a apontar para o novo primeiro no.
        return;                                                         // Insercao concluida.
    }                                                                   // Finaliza o caso em que head precisa mudar.

    No *aux = *headRef;                                                 // Comeca a busca pelo primeiro no.

    while (aux->prox != NULL && aux->prox->dado < valor) {              // Procura ponto de insercao.
        aux = aux->prox;                                                // Avanca enquanto o proximo valor ainda for menor.
    }                                                                   // Aux fica no no que deve anteceder o novo.

    novo->prox = aux->prox;                                         // Novo aponta para o antigo sucessor de aux.
    aux->prox = novo;                                               // Aux passa a apontar para o novo no.
}                                                                   // Finaliza a insercao ordenada.

// =============================================================
// IMPRESSAO / PERCURSO
// =============================================================

void imprime(const No *head) {                                          // Recebe head apenas para leitura.
    const No *aux = head;                                               // Aux comeca apontando para o primeiro no.

    while (aux != NULL) {                                               // Repete enquanto existir um no valido.
        printf("%d -> ", aux->dado);                                    // Exibe o valor guardado no no atual.
        aux = aux->prox;                                                // Avanca para o proximo no da cadeia.
    }                                                                   // Termina quando aux recebe NULL.

    printf("NULL\n");                                                   // Mostra explicitamente o final da lista.
}                                                                       // Finaliza a funcao de impressao.

// =============================================================
// BUSCA LINEAR
// =============================================================

No* busca(No *head, int valor) {                                            // Recebe inicio da lista e valor procurado.
    No *aux = head;                                                         // Inicia a busca no primeiro no.

    while (aux != NULL) {                                                   // Continua enquanto ainda houver nos para verificar.
        if (aux->dado == valor) {                                           // Compara o dado do no atual com o valor procurado.
            return aux;                                                     // Encontrou: devolve o endereco desse no imediatamente.
        }                                                                   // Finaliza o teste de igualdade.

        aux = aux->prox;                                                    // Nao encontrou: avanca para o proximo no.
    }                                                                       // Termina ao chegar ao fim da lista.

    return NULL;                                                            // Informa que nenhum no continha o valor procurado.
}                                                                           // Finaliza a busca.

// =============================================================
// REMOCAO NO INICIO
// =============================================================

void removeInicio(No **headRef) {                                       // Recebe o endereco de head porque ele sera alterado.
    if (*headRef == NULL) {                                             // Verifica se existe algum no para remover.
        printf("Lista vazia!\n");                                        // Informa que a operacao nao pode ser realizada.
        return;                                                          // Encerra sem alterar nada.
    }                                                                   // Finaliza o teste de lista vazia.

    No *temp = *headRef;                                            // Guarda o endereco do primeiro no que sera removido.
    *headRef = (*headRef)->prox;                                    // Faz head avancar para o segundo no.
                                                                    // Se havia um unico no, head passa a ser NULL.
    free(temp);                                                     // Libera a memoria do antigo primeiro no.
}                                                                   // Finaliza a remocao no inicio.

// =============================================================
// REMOCAO NO FIM
// =============================================================

void removeFim(No **headRef) {                                          // Recebe o endereco de head.
    if (*headRef == NULL) {                                             // Caso 1: lista vazia.
        printf("Lista vazia!\n");                                        // Nao existe no para remover.
        return;                                                          // Encerra a funcao.
    }                                                                   // Finaliza o caso de lista vazia.

    if ((*headRef)->prox == NULL) {                                     // Caso 2: existe exatamente um no free(*headRef); // Libera o unico no existente.
        *headRef = NULL;                                                // Atualiza head para representar lista vazia.
        return;                                                         // Encerra porque a remocao foi concluida.
    }                                                                   // Finaliza o caso de um unico no.

    No *aux = *headRef;                                                 // Caso 3: comeca no primeiro no.

    while (aux->prox->prox != NULL) {                                   // Continua ate aux chegar ao penultimo no.
        aux = aux->prox;                                                // Avanca um no por vez.
    }                                                                   // Ao sair, aux->prox e o ultimo no.

    free(aux->prox);                                                // Libera o ultimo no da lista.
    aux->prox = NULL;                                               // O penultimo passa a ser o novo ultimo no.
}                                                                   // Finaliza a remocao no fim.

// =============================================================
// REMOCAO POR VALOR
// =============================================================

void removeValor(No **headRef, int valor) {                             // Remove a primeira ocorrencia do valor.
    if (*headRef == NULL) {                                             // Caso 1: lista vazia.
        printf("Lista vazia!\n");                                        // Nao existe valor algum para procurar.
        return;                                                          // Encerra sem alterar a lista.
    }                                                                   // Finaliza o caso de lista vazia.

    if ((*headRef)->dado == valor) {                                    // Caso 2: valor esta no primeiro no.
        removeInicio(headRef);                                          // Reutiliza a funcao correta para remover o inicio.
        return;                                                          // Encerra porque a remocao ja ocorreu.
    }                                                                   // Finaliza o caso do primeiro no.

    No *aux = *headRef;                                                 // Aux aponta para o no ANTERIOR ao candidato.

    while (aux->prox != NULL && aux->prox->dado != valor) {             // Procura o antecessor.
        aux = aux->prox;                                                // Avanca enquanto o proximo no nao tiver o valor.
    }                                                                   // Sai ao encontrar o valor ou ao chegar ao final.

    if (aux->prox == NULL) {                                            // Se nao existe proximo no, o valor nao foi encontrado.
        printf("Valor nao encontrado!\n");                              // Informa o resultado da busca.
        return;                                                         // Encerra sem modificar a lista.
    }                                                                   // Finaliza o caso de valor inexistente.

    No *temp = aux->prox;                                           // Temp guarda o endereco exato do no a remover.
    aux->prox = temp->prox;                                         // Religa o antecessor diretamente ao sucessor.
    free(temp);                                                     // Libera a memoria do no que saiu da cadeia.
}                                                                   // Finaliza a remocao por valor.

// =============================================================
// DESTRUICAO COMPLETA DA LISTA
// =============================================================

void destroi(No **headRef) {                                            // Recebe endereco de head para esvaziar a lista.
    No *atual = *headRef;                                               // Atual comeca apontando para o primeiro no.

    while (atual != NULL) {                                             // Continua enquanto ainda houver no alocado.
        No *proximo = atual->prox;                                      // SALVA o proximo endereco antes de liberar atual.
        free(atual);                                                    // Libera a memoria do no atual.
        atual = proximo;                                                // Avanca usando o endereco salvo anteriormente.
    }                                                                   // Termina depois que todos os nos foram liberados.

    *headRef = NULL;                                                    // Garante que head represente uma lista vazia.
}                                                                       // Finaliza a destruicao completa da lista.

//-------------------------------
//
//-------------------------------
int tamanho(const No* head){            // Recebe head apenas para leitura.
    int count = 0;                      // Inicializa o contador de nos.
    const No* Head = head;              // Auxiliar para percorrer a lista sem alterar head.
    while (Head != NULL){               // Continua enquanto houver no valido.
        count++;                        // Incrementa o contador para cada no encontrado.
        Head = Head->prox;              // Avanca para o proximo no da lista.
    }
    return count;                       // Devolve o total de nós contados.
}; 

void inverte(No** headRef) {            // Recebe o endereco de head para alterar a lista.
    No* atual = *headRef;               // Ponteiro para percorrer a lista.
    No* ante = NULL;                    // Ponteiro para armazenar o no anterior.
    No* prox = NULL;                    // Ponteiro para armazenar o proximo no.

    if(atual == NULL || atual->prox == NULL){   // Lista vazia ou com um unico no, nao ha necessidade de inverter.
        return;                                 // Encerra a funcao sem alterar nada.
    }           

    while (atual != NULL) {  // Continua enquanto houver nos para processar.
        prox = atual->prox;  // o próximo será o a.próximo na 'fila'
        atual->prox = ante;  // o a.p se tornará o anterior
        ante = atual;        // o anterior se tornará o atual
        atual = prox;        // o atual será o próximo
    }

    /*
        [ 1 ] [ 2 ] [ 3 ] [ 4 ]
         At->  Pr...
         At1 <-At2   Pr...
               At2 <-At3   Pr...

        O atual de agora aponta para o atual anterior e segue para o próximo na 'fila'
    */
    
    *headRef = ante; //Head aponta para o último nó (armazenado em anterior, pois atual agora é o null) 
};

void removeDuplicadosOrdenada(No** headRef){        // Recebe o head para leitura 
    No* Head = *headRef;                            // Cria um auxiliar que aponta para o head
    No* aux = Head;                                 // Cria um ponteiro para o próximo nó
    No* proximo = NULL;

    if(Head == NULL || Head->prox == NULL){
        return;                                     // Retorna caso a lista seja vazia ou de um número
    }

    while(aux != NULL && aux->prox != NULL){        
        if(aux->dado == aux->prox->dado){           // Verifica se o dado do nó atual é igual ao dado do próximo nó          
            proximo = aux->prox->prox;              // Salva o número que vem depois do próximo para não perder o ponteiro
            free(aux->prox);                        // Libera o duplicado
            aux->prox = proximo;                    // Redireciona o ponteiro
        }
        else{
            aux = aux->prox;                        //Continua lendo a lista
        }
    }
};