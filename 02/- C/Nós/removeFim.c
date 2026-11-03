void removeFim(No** headRef){
	if(*headRef == NULL){
		printf("Lista vazia\n");
		return;
	}

	if((*headRef)->prox==NULL){
		free(*headRef);
		*headRef = NULL;
		return;
	}

	No* aux = *headRef;
	while(aux->prox->prox != NULL){
		aux = aux->prox;
	}

	free(aux->prox);
	aux->prox = NULL;
}