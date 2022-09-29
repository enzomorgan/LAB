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

void add(float x, float y){  //fun��o para adicionar novos elementos
	Ponto *p = (Ponto*) malloc(sizeof(Ponto));  //alocando na mem�ria
	
	p->x = x;  //apontando para o primeiro valor
	p->y = y;  //apontando para o segundo valor
	p->prox = listaPontos; //apontando para nulo
	listaPontos = p;  //apontando para os pr�ximos valores adicionados 
}

void imprime(){  //fun��o para imprimir os valores
	Ponto *auxLista = listaPontos; //ponteiro auxiliar
	
	while(auxLista != NULL){  //enquanto o ponteiro auxiliar for diferente de nulo
		printf("Ponto(%.1f, %.1f)\n", auxLista->x, auxLista->y);  //imprimindo os valores
		auxLista = auxLista ->prox;  //apontando para o pr�ximo
	}
}

int main(){
	setlocale(LC_ALL, "");
	
	//chamando a fun��o para adicionar valores
	add(1,5);
	add(2,7);
	add(5,3);
	
	imprime();  //chamando a fun��o para exibir os valores dos pontos
	
	system("pause\n");
	return 0;
}