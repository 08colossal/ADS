void removeInicio(No** headref){
	if(*headRef == NULL){
		printf("Lista vazia\n");
		return;
	}
	No* temp = *headRef;
	*headRef = (*headRef) -> prox;
	free(temp);
}