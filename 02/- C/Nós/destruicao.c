void destrói(No** headRef){
	No* atual = *headRef;
	while (atual != NULL){
		No* próximo = atual->prox;
		free(atual);
		atual = próximo;
	}
	*headRef = NULL;
}