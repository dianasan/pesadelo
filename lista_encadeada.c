#include<stdio.h>
#include<stdlib.h>

int main (){

typedef struct 			// tem um ponteiro pro primeiro elemento e campo prox aponta para o próximo elemento
{						//da lista
	int info;
	struct Lista* prox;
}Lista;

Lista* cria_lista(void){   //cria e retorna uma lista vazia
	return NULL;
}

Lista* insere_elemento(Lista* lista, int val){   //insere um novo elemento no começo da lista
	Lista* novo = (Lista*) malloc(sizeof(Lista));
	novo->info = val;
	novo->prox = lista;
	return novo;
}

void imprime_lista(Lista* lista){			//imprime a lista
	Lista* p;
	for(p = lista; p!= NULL; p = p->prox){
		printf("%d ", p->info);
	}
	printf("\n");
}

int lista_vazia(Lista* lista){	//retorna 0 se a lista não estiver vazia e 1 se ela estiver vazia
	if(lista == NULL){
		printf("lista vazia\n");
		return 1;
	}else{
		printf("a lista não está vazia\n");
		return 0;
	}

}

Lista* busca(Lista* lista, int val){
	Lista* p;

	/*p = lista;
	while(p != NULL){
		if(p->info == val){
			printf("achou\n");
			return p;}p=p->prox;}*/

	for(p=lista; p!=NULL; p=p->prox){    //nunca encontra
		if(p->info == val){
			printf("Achamos o elemento\n");
			return p;
		}
		printf("oq tá errado meu deus??\n");
	}
	printf("Não achou o elemento\n");
	return NULL;		//não achou o elemento da lista
}

Lista* retira_elemento(Lista* lista, int val){ //nunca retira elemento
	Lista*  ant = NULL; 	//ponteiro para elemento anterior
	Lista* p = lista;	
	imprime_lista(lista);	//ponteiro para percorrer a lista
	if (p ==NULL){
		return lista;
	}
	while(p->prox != NULL && p->info != val){		//procura elemento na lista guardando o anterior
		ant = p;
		p = p->prox;

}
	if(p->prox == NULL){
		printf("não achamos o elemento que você quer retirar\n");
		return lista;	//não achou e retorna lista original
	}

	if(ant == NULL){
		lista = p->prox;		//retira elemento do inicio
		printf("retiramos elemento do começo\n");
	}else{
		ant->prox = p->prox;	//retira elemento do meio da lista
		printf("retirmamos elemento do meio\n");
	}

	//imprime_lista(lista); //imprimindo a lista só pra melhor visualização
	free(p);
	return lista;
}

void libera_lista(Lista* lista){
	Lista* p = lista;

	while (p != NULL){
		Lista* t = p->prox;		//guarda referẽncia para o próximo elemento
		free(p);				//libera a memória apontada por p
		p = t;					//faz p apontar para o próximo
	}
	printf("liberamos a lista\n");
}

Lista* insere_ordenado(Lista* lista , int val){ //tá criando uma nova lista e não inserindo na lista existente 
	Lista* novo;
	Lista* ant = NULL;		//aponta o elemento anterior
	Lista* p = lista;		//percorre a lista

	while (p != NULL && p->info < val){
		ant = p;
		p = p->prox;
	}
	novo = (Lista*)malloc(sizeof(Lista));
	novo->info = val;

	if(ant == NULL){
		novo->prox = lista;
		lista = novo;
	}else{
		novo->prox = ant->prox;
		ant->prox = novo;
	}

	return lista;
}



Lista* lst;						//declaa uma lista não inicializada
lst = cria_lista();				//cria e inicializa a lista como vazia
lst = insere_elemento(lst, 1);		//insere na lista o elemento 12
lst = insere_elemento(lst, 2); 
lst = insere_elemento(lst, 4);
lst = insere_elemento(lst, 5);
lst = insere_elemento(lst, 6);
imprime_lista(lst);
lst = lista_vazia(lst);
//lst = insere_ordenado(lst, 3);
//lst = busca(lst, 3);
//lst = busca(lst, 2);
lst = retira_elemento(lst, 2);
imprime_lista(lst);
libera_lista(lst);


return 0;
}