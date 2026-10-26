void imprime(const No* head){
	const No* aux = head;
	while (aux != NULL){
		printf("%d -> ", aux->dado);
		aux = aux->prox;
	}
	printf("NULL\n");
}