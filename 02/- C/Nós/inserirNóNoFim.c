void insereFim(No** headRef, int valor){
	No* novo = criarVo(valor);
	if (*headRef == NULL){
		*headRef = novo;
	}	
	No* aux = *headRef;
	while (aux->prox != NULL){
		aux = aux->prox;
	}
	aux->prox = novo;
}