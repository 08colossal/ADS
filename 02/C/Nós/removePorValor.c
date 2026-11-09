void removeValor(No** headRef, int valor){
	if(*headRef == NULL){
		printf("Lista vazia\n");
		return;	
	}

	if((*headRef)->dado == valor){
		removeInicio(headRef);
		return;
	}

	No* aux = *headRef;
	while (aux->prox !== NULL && aux->prox->dado != valor){
		aux = aux->prox;
	}

	if(aux-> prox == NULL){
		printf("valor não encontrado\n");
		return;
	}

	No* tempo = aux->prox;
	aux-> prox = temp->prox;
	free(temp);
}