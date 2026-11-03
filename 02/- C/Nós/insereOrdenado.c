void insereOrdenado(No** headRef, int valor){
	No* novo = criaNo(valor);
	if(*headRef == NULL || valor < (*headRef)->dado){
		novo->prox = *headRef;
		*headRef = novo;
		return;
	}

	No* aux = *headRef;
	while (aux->prox != NULL && aux->prox->dado < valor){
		aux = aux->prox;
	}

	novo->prox = aux->prox;
	aux->prox = novo;
}