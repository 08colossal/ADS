void inserePosicao(No** headref, int valor, int pos){
	if(pos == 0){
		insereInicio(headRef, valor);
		return;
	}

	No* novo = criarNo(valor);
	No* aux = *headref;
	for (int i = 0; aux != NULL && i < pos-1; i++){
		aux = aux->prox;
	}

	if(aux == NULL){
		printf("posição invalida\n");
		free(novo);
		return;
	}

	novo->prox = aux->prox;
	aux->prox = novo;
}