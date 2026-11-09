#include "lista.h" // Importa o TAD Lista Dupla.

int main(void) { // Ponto inicial da execucao.
    Lista* L = criaLista(); // Cria uma lista vazia.

    int opcao, valor; // Guarda a opcao e valores digitados.

    do { // Repete o menu ate escolher 0.
        printf("\n===== MENU =====\n"); // Titulo do menu.
        printf("1 - Inserir no inicio\n"); // Opcao 1.
        printf("2 - Inserir no fim\n"); // Opcao 2.
        printf("3 - Imprimir lista\n"); // Opcao 3.
        printf("4 - Imprimir reverso\n"); // Opcao 4.
        printf("5 - Buscar valor\n"); // Opcao 5.
        printf("6 - Remover do inicio\n"); // Opcao 6.
        printf("7 - Remover do fim\n"); // Opcao 7.
        printf("8 - Remover por valor\n"); // Opcao 8.
        printf("9 - Destruir lista\n"); // Opcao 9.
        printf("10 - Insere depois de um nó\n"); // Opcao 10.
        printf("11 - Insere antes de um nó\n"); // Opcao 11.
        printf("12 - Insere de forma ordenada\n"); // Opcao 12.
        printf("0 - Sair\n"); // Opcao 0.
        printf("Escolha: "); // Solicita a opcao.

        scanf("%d", &opcao); // Le a opcao.

        switch (opcao) { // Escolhe a operacao.
            case 1: // Inserir no inicio.
                printf("Valor: "); // Solicita o valor.
                scanf("%d", &valor); // Le o valor.
                insereInicio(L, valor); // Chama a funcao.
                break; // Retorna ao menu.

            case 2: // Inserir no fim.
                printf("Valor: "); // Solicita o valor.
                scanf("%d", &valor); // Le o valor.
                insereFim(L, valor); // Chama a funcao.
                break; // Retorna ao menu.

            case 3: // Imprimir do inicio ao fim.
                imprime(L); // Executa o percurso normal.
                break; // Retorna ao menu.

            case 4: // Imprimir do fim ao inicio.
                imprimeReverso(L); // Executa o percurso reverso.
                break; // Retorna ao menu.

            case 5: // Buscar um valor.
                printf("Valor: "); // Solicita o valor.
                scanf("%d", &valor); // Le o valor.

                { // Cria um bloco local.
                    No* p = busca(L, valor); // Recebe o no encontrado ou NULL.

                    if (p != NULL) // Se encontrou...
                        printf("Encontrado! Valor=%d Endereco=%p\n",
                        p->dado, (void*)p); // Exibe dado e endereco.
                    else // Caso contrario...
                        printf("Valor nao encontrado.\n"); // Informa ausencia.
                } // Finaliza o bloco.
                break; // Retorna ao menu.

            case 6: // Remover primeiro no.
                removeInicio(L); // Chama a funcao.
                break; // Retorna ao menu.

            case 7: // Remover ultimo no.
                removeFim(L); // Chama a funcao.
                break; // Retorna ao menu.

            case 8: // Remover por valor.
                printf("Valor: "); // Solicita o valor.
                scanf("%d", &valor); // Le o valor.
                removeValor(L, valor); // Chama a funcao.
                break; // Retorna ao menu.

            case 9: // Destruir a lista atual.
                destroiLista(L); // Libera nos e estrutura.
                printf("Lista destruida!\n"); // Confirma a operacao.
                L = criaLista(); // Recria a lista para continuar.
                break; // Retorna ao menu.

            case 10: { // Adicionar novo vó depois de um nó existente
                int d;
                printf("\nValor: ");
                scanf("%d", &valor); //Que valor será adicionado
                printf("\nAdicionar depois de: ");
                scanf("%d", &d); //Depois de qual nó
                No* p = busca(L, d); 
                if(p != NULL){
                    insereDepois(L, p, valor); //Insere 'valor' depois do nó 'd'
                    printf("Adicionado após %d", d); //Confere que foi adicionado
                } else{
                    printf("Erro: O valor %d nao foi encontrado na lista.\n", d); //caso 'd' não exista na lista
                }
                break;
            }

            case 11:{ // Adicionar novo vó antes de um nó existente
                int d;
                printf("\nValor: ");
                scanf("%d", &valor); //Que valor será adicionado
                printf("\nAdicionar antes de: ");
                scanf("%d", &d); //Antes de qual nó
                No* p = busca(L, d);
                if(p != NULL){
                    insereAntes(L, p, valor); //Insere 'valor' antes do nó 'd'
                    printf("Adicionado antes de %d", d); //Confere que foi adicionado
                } else{
                    printf("Erro: O valor %d nao foi encontrado na lista.\n", d); //caso 'd' não exista na lista
                }
                break;
            }

            case 12:
                printf("\nValor: ");
                scanf("%d", &valor); //Que valor será adicionado
                insereOrdenado(L, valor); //Adiciona o nó na lista
                printf("Adicionado %d em ordem.", valor); //Confere que foi adicionado
                break;

            case 0: // Encerrar.
                destroiLista(L); // Libera toda memoria.
                printf("Saindo...\n"); // Mensagem final.
                break; // Sai do switch.

            default: // Opcao nao prevista.
            printf("Opcao invalida!\n"); // Informa o erro.
        } // Finaliza o switch.

    } while (opcao != 0); // Repete ate a opcao 0.

    destroiLista(minhaLista); //garante integridade do uso de memória
    return 0; // Encerra com sucesso.
}