#include <stdio.h>          // Disponibiliza printf() e scanf().
#include <stdlib.h>         // Biblioteca padrao; mantida junto ao projeto.
#include "lista.h"          // Importa o tipo No e as funcoes da lista.

int main(void) {                // Ponto inicial de execucao do programa.
    No *head = NULL;            // Cria a cabeca da lista e inicia com lista vazia.

    int opcao;                  // Guardara a opcao escolhida no menu.
    int valor;                  // Guardara valores que serao inseridos/buscados/removidos.
    int pos;                    // Guardara a posicao usada na insercao por indice.

    do {                                        // Inicia um laco que repetira o menu ate opcao 0.
        printf("\n===== MENU =====\n");         // Exibe o titulo do menu.
        printf("1 - Inserir no inicio\n");      // Opcao que chama insereInicio.

        printf("2 - Inserir no fim\n");         // Opcao que chama insereFim.
        printf("3 - Inserir em posicao\n");     // Opcao que chama inserePosicao.
        printf("4 - Inserir ordenado\n");       // Opcao que chama insereOrdenado.
        printf("5 - Imprimir lista\n");         // Opcao que chama imprime.
        printf("6 - Buscar valor\n");           // Opcao que chama busca.
        printf("7 - Remover do inicio\n");      // Opcao que chama removeInicio.
        printf("8 - Remover do fim\n");         // Opcao que chama removeFim.
        printf("9 - Remover por valor\n");      // Opcao que chama removeValor.
        printf("10 - Destruir lista\n");        // Opcao que chama destroi.
        printf("11 - Tamanho da lista\n");      // Opcao que chama tamanho.
        printf("12 - Inverter lista\n");        // Opcao que chama inverte.
        printf("13 - Remover duplicatas\n");    // Opcao que chama removeDuplicadosOrdenada.
        printf("0 - Sair\n");                   // Opcao para encerrar o programa.
        printf("Escolha: ");                    // Solicita a escolha ao usuario.
        scanf("%d", &opcao);                    // Le a opcao e grava na variavel opcao.

        switch (opcao) {                        // Seleciona qual bloco sera executado.
            case 1:                                 // Usuario escolheu inserir no inicio.
                printf("Valor: ");                  // Solicita o valor a inserir.
                scanf("%d", &valor);                // Le o valor digitado.
                insereInicio(&head, valor);         // Passa &head porque head pode mudar.
                break;                              // Sai do switch e volta ao menu.

            case 2:                         // Usuario escolheu inserir no fim.
                printf("Valor: ");          // Solicita o valor a inserir.
                scanf("%d", &valor);        // Le o valor digitado.
                insereFim(&head, valor);    // Passa &head para tratar inclusive lista vazia.
                break;                      // Sai deste case.

            case 3:                                 // Usuario escolheu inserir em uma posicao.
                printf("Valor: ");                  // Solicita o valor.
                scanf("%d", &valor);                // Le o valor.
                printf("Posicao: ");                // Solicita o indice desejado.
                scanf("%d", &pos);                  // Le a posicao.
                inserePosicao(&head, valor, pos);   // Envia head, valor e posicao.
                break;                              // Sai deste case.

            case 4:                             // Usuario escolheu insercao ordenada.
                printf("Valor: ");              // Solicita o valor.
                scanf("%d", &valor);            // Le o valor.
                insereOrdenado(&head, valor);   // Insere tentando manter ordem crescente.
                break;                          // Sai deste case.

            case 5:                 // Usuario quer visualizar a lista.
                imprime(head);      // Passa head; a funcao apenas percorre e le os nos.
                break;              // Sai deste case.

            case 6: {                   // Abre um bloco proprio para declarar ’achado’.
                printf("Valor: ");      // Solicita o valor procurado.
                scanf("%d", &valor);    // Le o valor procurado.

                No *achado = busca(head, valor);    // Recebe endereco do no ou NULL.

                if (achado != NULL) {                                   // Testa se a busca realmente encontrou um no.
                    printf("Valor %d encontrado no endereco %p\n",      //Exibe dado e endereco.
                    achado->dado, (void*)achado);                       // %p exige um ponteiro void*.
                } 
                else {                                              // Executa quando busca devolve NULL.
                    printf("Valor nao encontrado!\n");               // Informa ausencia do valor.
                }                                                   // Finaliza o if/else da busca.
                break;                                              // Sai do case 6.
            }                                                       // Finaliza o bloco local do case 6.

            case 7:                                                 // Usuario escolheu remover o primeiro no.
                removeInicio(&head);                                /* &head porque o primeiro no sera alterado.*/
                break;                                              // Sai deste case.

            case 8:                                                     // Usuario escolheu remover o ultimo no.
                removeFim(&head);                                       /* &head porque lista com 1 no pode virar vazia.*/
                break;                                                  // Sai deste case.

            case 9:                                                     // Usuario escolheu remover um valor especifico.
                printf("Valor: ");                                      // Solicita o valor a remover.
                scanf("%d", &valor);                                    // Le o valor.
                removeValor(&head, valor);                              // Remove a primeira ocorrencia encontrada.
                break;                                                  // Sai deste case.   

            case 10:                                        // Usuario deseja liberar toda a lista sem sair.
                destroi(&head);                             // Libera todos os nos e faz head receber NULL.
                printf("Lista destruida!\n");               // Confirma a operacao.
                break;                                      // Sai deste case e o menu sera mostrado novamente.

            case 11:
                printf("Tamanho da lista: %d\n", tamanho(head));    // Chama a funcao que percorre a lista e devolve o tamanho.
                break;                                              // Sai deste case e o menu sera mostrado novamente.

            case 12:
                inverte(&head);                                     // Chama a funcao que inverte a lista.
                printf("Lista invertida!\n");                       // Confirma a operacao.
                break;                                              // Sai deste case e o menu sera mostrado novamente.

            case 13:
                removeDuplicadosOrdenada(&head);                    // Chama a funcao que remove duplicatas de uma lista ordenada.
                printf("Duplicatas removidas!\n");                  // Confirma a operacao.
                break;                                              // Sai deste case e o menu sera mostrado novamente.

            case 0:                             // Usuario escolheu encerrar o programa.
                destroi(&head);                 // Garante que nenhuma memoria alocadafique sem free.
                printf("Saindo...\n");          // Mensagem final.
                break;                          // Sai do switch.

            default:                                // Executa para qualquer opcao naoprevista acima.
                printf("Opcao invalida!\n");        // Solicita indiretamente nova tentativa.
        }                                           // Finaliza o switch.

        } while (opcao != 0);                       // Repete enquanto a opcao escolhida for diferente de zero.

    return 0;                                       // Informa ao sistema operacional que terminou com sucesso.
}                                                   // Finaliza a funcao main.