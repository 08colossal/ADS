No* busca(No* head, int valor){
	No* aux = head;
	while(aux != NULL){
		if(aux->dado == valor){
			return aux;
		}
		aux = aux->prox;
	}
	return NULL;
}