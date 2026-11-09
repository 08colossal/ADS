#include <stdio.h>
#include <stdlib.h>

No* criarNo(int valor){
	No* novo = malloc(sizeof(no));
	if (novo == NULL){
		print("falhou");
		exit(EXIT_FAILURE);
	}
	novo->dado = valor;
	novo->prox = NULL;
	return novo;
}