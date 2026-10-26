void insereInicio(No* headRef, int valor){
	No* novo = criaNo(valor);
	novo->prox = headRef;
	*headRef = novo;
}