#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct ponto{
	float x;
	float y;
	struct ponto *prox;  //ponteiro que aponta para o pr�ximo   	
};

typedef struct ponto Ponto;  //renomeando

Ponto *listaPontos;  //ponteiro que aponta para o primeiro elemento da lista	 

void addFirst(float x, float y){  //fun��o para adicionar novos elementos no in�cio
	Ponto *p = (Ponto*) malloc(sizeof(Ponto));  //alocando na mem�ria
	
	p->x = x;  //apontando para o primeiro valor
	p->y = y;  //apontando para o segundo valor
	p->prox = listaPontos; //apontando para nulo
	listaPontos = p;  //apontando para os pr�ximos valores adicionados 
}

void addLast(float x, float y){ //fun��o para adicionar novos elementos no fim
	Ponto *p = (Ponto*) malloc(sizeof(Ponto));  //alocando na mem�ria
	
	p->x = x;  //apontando para o primeiro valor
	p->y = y;  //apontando para o segundo valor
	p->prox = NULL; //apontando para nulo
	if(listaPontos==NULL){  //se o in�cio da lista for nulo
		listaPontos = p;  //�ltimo tamb�m � o primeiro
	}
	else{  //se ele n�o for nulo
		Ponto *listaAux = listaPontos;  //ponteiro auxiliar 
		while(listaAux->prox!=NULL){  //enquanto o ponteiro auxilar que aponta para o pr�ximo for nulo 
			listaAux = listaAux->prox;  //indo para o pr�ximo elemento
		}
		listaAux->prox = p; //apontando para o novo �ltimo elemento
	}
}

void imprime(Ponto *p){  //fun��o para imprimir os valores
	if(p!=NULL){  //se "p" for diferente de nulo
		printf("Ponto(%.1f,%.1f)\n", p->x, p->y); //imprimindo
		imprime(p->prox);  //chamando a fun��o para exibir o pr�ximo
	}
}

int main(){
	setlocale(LC_ALL, "");
	
	//chamando a fun��o para adicionar valores
	addFirst(1,5);
	addFirst(2,7);
	addFirst(5,3);
	addLast(1,1);
	addLast(8,8);
	
	Ponto *auxLista = listaPontos; //ponteiro auxiliar
	
	imprime(auxLista);  //chamando a fun��o para exibir os valores dos pontos
	
	system("pause\n");
	return 0;
}