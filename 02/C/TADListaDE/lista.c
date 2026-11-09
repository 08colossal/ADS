#include "lista.h" // Importa os tipos e prototipos do TAD.

// Cria e inicializa uma nova lista vazia.
Lista* criaLista(void) { // Funcao que devolve um ponteiro para Lista.
    Lista* L = malloc(sizeof(Lista)); // Reserva memoria para a estrutura Lista.

    if (L == NULL) { // Testa se a alocacao falhou.
        perror("Falha ao criar lista"); // Exibe mensagem de erro do sistema.
        exit(EXIT_FAILURE); // Encerra o programa em caso de falha.
    } // Finaliza o teste de malloc.

    L->ini = NULL; // Lista vazia nao possui primeiro no.
    L->fim = NULL; // Lista vazia nao possui ultimo no .
    L->n = 0; // Lista vazia possui zero nos.

    return L; // Retorna o endereco da lista criada.
} // Finaliza criaLista.

// Verifica se a lista esta vazia.
int listaVazia(Lista* L) { // Recebe o endereco da lista.
    return (L == NULL || L->n == 0); // Retorna verdadeiro se nao existir ou tiver zero nos.
} // Finaliza listaVazia.

// Libera toda a memoria alocada pela lista.
void destroiLista(Lista* L) { // Recebe a lista que sera destruida.
    if (L == NULL) // Se a propria estrutura e NULL...
        return; // ...nao existe nada para liberar.

    No* p = L->ini; // Comeca pelo primeiro no.

    while (p != NULL) { // Continua enquanto houver no.
        No* aux = p->prox; // Guarda o proximo no antes do free.
        free(p); // Libera o no atual.
        p = aux; // Avanca para o endereco salvo.
    } // Termina quando todos os nos forem liberados.

        free(L); // Libera a estrutura principal da lista.
} // Finaliza destroiLista.

// Insere elemento no inicio da lista.
void insereInicio(Lista* L, int valor) { // Recebe a lista e o valor.
    No* novo = malloc(sizeof(No)); // Reserva memoria para um novo no.

    if (novo == NULL) { // Verifica se a alocacao falhou.
        perror("malloc falhou"); // Exibe mensagem de erro.
        exit(EXIT_FAILURE); // Encerra o programa.
    } // Finaliza o teste.

    novo->dado = valor; // Armazena o valor no novo no.
    novo->ant = NULL; // Primeiro no nao possui anterior.
    novo->prox = L->ini; // Aponta para o antigo primeiro no

    if (L->ini != NULL) // Se a lista ja tinha um primeiro ...
        L->ini->ant = novo; // ...o anterior dele passa a ser novo.
    else // Caso a lista estivesse vazia...
        L->fim = novo; // ...novo tambem e o ultimo.

    L->ini = novo; // Atualiza o primeiro no.
    L->n++; // Incrementa a quantidade de nos.
} // Finaliza insereInicio.

// Insere elemento no fim da lista.
void insereFim(Lista* L, int valor) { // Recebe a lista e o valor.
    No* novo = malloc(sizeof(No)); // Reserva memoria para o novo no.

    if (novo == NULL) { // Verifica se malloc falhou.
        perror("malloc falhou"); // Exibe mensagem de erro.
        exit(EXIT_FAILURE); // Encerra o programa.
    } // Finaliza o teste.

    novo->dado = valor; // Armazena o valor.
    novo->prox = NULL; // Ultimo no nao possui proximo.
    novo->ant = L->fim; // Novo aponta para o antigo ultimo.

    if (L->fim != NULL) // Se ja existia ultimo no...
        L->fim->prox = novo; // ...ele passa a apontar para novo .
    else // Se a lista estava vazia...
        L->ini = novo; // ...novo tambem vira o primeiro.

    L->fim = novo; // Atualiza o ultimo no.
    L->n++; // Incrementa a quantidade.
} // Finaliza insereFim.

// Imprime a lista do inicio ao fim.
void imprime(const Lista* L) { // Recebe a lista apenas para leitura.
    const No* p = L->ini; // Comeca no primeiro no.

    printf("[ "); // Inicia a representacao visual.

    while (p != NULL) { // Continua enquanto houver no.
        printf("%d ", p->dado); // Exibe o dado do no atual.
        p = p->prox; // Avanca para o proximo.
    } // Termina em NULL.

    printf("]\n"); // Fecha a representacao.
} // Finaliza imprime.

// Imprime a lista do fim ao inicio.
void imprimeReverso(const Lista* L) { // Recebe a lista apenas para leitura.
    const No* p = L->fim; // Comeca no ultimo no.

    printf("[ "); // Inicia a representacao.

    while (p != NULL) { // Continua enquanto houver no.
        printf("%d ", p->dado); // Exibe o dado atual.
        p = p->ant; // Volta para o no anterior.
    } // Termina quando chegar antes do primeiro.

    printf("]\n"); // Fecha a representacao.
} // Finaliza imprimeReverso.

// Busca um no com determinado valor.
No* busca(Lista* L, int valor) { // Recebe a lista e o valor;
    No* p = L->ini; // Comeca pelo primeiro no.

    while (p != NULL) { // Percorre a lista.
        if (p->dado == valor) // Compara o valor do no atual.
            return p; // Retorna o endereco se encontrar.

        p = p->prox; // Avanca para o proximo.
    } // Termina no fim da lista.

    return NULL; // Indica que o valor nao foi encontrado.
} // Finaliza busca.

// Remove o primeiro no da lista.
void removeInicio(Lista* L) { // Recebe a lista.
    if (listaVazia(L)) { // Verifica se existe no para remover.
        printf("Lista vazia!\n"); // Informa o caso.
        return; // Encerra sem alterar.
    } // Finaliza o teste.

    No* p = L->ini; // Guarda o antigo primeiro no.
    L->ini = p->prox; // Faz o inicio avancar.

    if (L->ini != NULL) // Se ainda existe primeiro no...
        L->ini->ant = NULL; // ...ele nao possui anterior.
    else // Se a lista ficou vazia...
        L->fim = NULL; // ...o fim tambem deve ser NULL.

    free(p); // Libera o antigo primeiro.
    L->n--; // Decrementa a quantidade.
} // Finaliza removeInicio.

// Remove o ultimo no da lista.
void removeFim(Lista* L) { // Recebe a lista.
    if (listaVazia(L)) { // Verifica se existe algo para remover.
        printf("Lista vazia!\n"); // Informa o caso.
        return; // Encerra sem alterar.
    } // Finaliza o teste.
    No* p = L->fim; // Guarda o antigo ultimo no.
    L->fim = p->ant; // Faz fim voltar para o anterior.

    if (L->fim != NULL) // Se ainda existe ultimo no...
        L->fim->prox = NULL; // ...ele nao possui proximo.
    else // Se a lista ficou vazia...
        L->ini = NULL; // ...o inicio tambem deve ser NULL

    free(p); // Libera o antigo ultimo.
    L->n--; // Decrementa a quantidade.
} // Finaliza removeFim.

// Remove um no com o valor especificado.
void removeValor(Lista* L, int valor) { // Recebe lista e valor a remover.
    if (listaVazia(L)) { // Verifica se ha elementos.
        printf("Lista vazia!\n"); // Informa que nada pode ser removido.
        return; // Encerra a funcao.
    } // Finaliza o caso vazio.

    No* p = busca(L, valor); // Procura a primeira ocorrencia.

    if (p == NULL) { // Se nenhum no foi encontrado...
        printf("Valor nao encontrado!\n"); // Informa o resultado.
        return; // Encerra sem alterar a lista.
    } // Finaliza o caso de valor inexistente.

    if (p->ant != NULL) // Se existe no anterior...
        p->ant->prox = p->prox; // ...ele passa a apontar para o sucessor.
    else // Se nao existe anterior...
        L->ini = p->prox; // ...p era o primeiro, entao atualiza ini.

    if (p->prox != NULL) // Se existe no seguinte...
        p->prox->ant = p->ant; // ...ele passa a apontar para o anterior.
    else // Se nao existe seguinte...
        L->fim = p->ant; // ...p era o ultimo, entao atualiza fim.

    free(p); // Libera o no removido.
    L->n--; // Decrementa a quantidade de nos.
} // Finaliza removeValor.

void insereDepois(Lista* L, No* p, int valor){ // Recebe lista, nó e valor a adicionar após o nó;
    if (p == NULL || L == NULL) { // Se nenhum no foi encontrado...
        printf("Valores vazios.\n");
        return;
    }

    No* novo = malloc(sizeof(No)); // Aloca memória
    if (novo == NULL) { //Se o malloc falhou
        perror("malloc falhou");
        exit(EXIT_FAILURE);
    }

    novo->dado = valor; //O dado do nó a ser inserido
    novo->ant = p; //o ponteiro anterior desse nó
    novo->prox = p->prox; //o ponteiro próximo desse nó
    
    if(p->prox != NULL){ //se existe um valor depois de p
        p->prox->ant = novo; //o ponteiro anterior desse valor passa a ser o novo nó
    }else{
        L->fim = novo; //ou o fim da lista vira o novo nó
    }

    p->prox = novo; // o ponteiro próximo do nó será o novo nó
    L->n++; //soma um novo nó na contagem de nós
}
        
void insereAntes(Lista* L, No* p, int valor){
    if (p == NULL || L == NULL) { // Se nenhum no foi encontrado...
        printf("Valores vazios.\n");
        return;
    }

    No* novo = malloc(sizeof(No)); // Aloca memória
    if (novo == NULL) { //Se o malloc falhou
        perror("malloc falhou");
        exit(EXIT_FAILURE);
    }

    novo->dado = valor; //O dado do nó a ser inserido
    novo->prox = p; //o ponteiro próximo desse nó
    novo->ant = p->ant; //o ponteiro anterior desse nó
    
    if(p->ant != NULL){ //se existe um valor antes de p
        p->ant->prox = novo; //o ponteiro próximo desse valor passa a ser o novo nó
    }else{
        L->ini = novo; //ou o inicio da lista vira o novo nó
    }

    p->ant = novo; // o ponteiro anterior do nó será o novo nó
    L->n++; //soma um novo nó na contagem de nós
};

void insereOrdenado(Lista* L, int valor){
    No *novo = malloc(sizeof(No));                                   // Cria o no que precisa ser encaixado na ordem correta.
    if (novo == NULL) {                                             // Verifica se a alocacao falhou.
        perror("malloc falhou");                                    // Exibe uma mensagem relacionada ao erro de sistema.
        exit(EXIT_FAILURE);                                         // Encerra o programa
    }
    novo->dado = valor;
    novo->prox = NULL; //inicializa
    novo->ant = NULL; //inicializa
    
    if (L->ini == NULL) {                                           // Em uma lista vazia o novo valor é o primeiro e o ultimo
        L->ini = novo;
        L->fim = novo;
    } 
    
    else if (valor < (L->ini)->dado) {                              // se antes do primeiro.
        novo->prox = L->ini;                                         // Novo próximo aponta para o antigo primeiro no.
        L->ini->ant = novo;                                         // O antigo head anterior aponta para o novo
        L->ini = novo;                                               // Head passa a ser o novo no.
    }                                                                // Finaliza o caso em que head precisa mudar.
    
    else if(valor > (L->fim)->dado){                                 // se depois do ultimo
        novo->ant = L->fim;                                         // Novo anterior aponta para o antigo fim
        L->fim->prox = novo;                                        // O próximo do antigo final da lista agora é o novo nó
        L->fim = novo;                                              // O fim da lista passa a ser o novo nó
    }

    else{
        No *aux = L->ini;                                                 // Comeca a busca pelo primeiro no.
    
        while (aux->prox != NULL && aux->prox->dado < valor) {              // Procura ponto de insercao.
            aux = aux->prox;                                                // Avanca enquanto o proximo valor ainda for menor.
        }                                                                   // Aux fica no no que deve anteceder o novo.

        novo->prox = aux->prox;                                         // Novo proximo aponta para o antigo sucessor de aux.
        novo->ant = aux;                                                //novo anterior aponta para o auxiliar
        aux->prox->ant = novo;                                          // o anterior do próximo ponto de inserção é o novo;
        aux->prox = novo;                                               // o próximo do ponto de inserção é o novo;
        
        }                                                                   // Finaliza a insercao ordenada.
    L->n++;                                                             // conta o novo nó
};