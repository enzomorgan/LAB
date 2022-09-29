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

void imprime(Ponto *p){  //fun��o para imprimir os valores
	if(p!=NULL){  //se "p" for diferente de nulo
		printf("Ponto(%.1f,%.1f)\n", p->x, p->y); //imprimindo
		imprime(p->prox);  //chamando a fun��o para exibir o pr�ximo
	}
}

int length = 0; //vari�vel que � o tamanho da lista com in�co em zero

void addIndex(float x, float y, int index){  //fun��o para adicionar valores em determinados ind�ces
	Ponto *p = (Ponto*) malloc(sizeof(Ponto)); //alocando na mem�ria
	
	p->x = x; //apontando para o primeiro valor
	p->y = y; //apontando para o segundo valor
	   	
	if(index > length){  //se for maior que o tamanho da lista 
		printf("Posi��o inv�lida!!\n");
	}
	else{
		if(index == 0){  //se a vari�vel for igual a zero
			p->prox = listaPontos; //primeiro elemento
			listaPontos = p; //novo primeiro elemento
		}
		else{
			Ponto *listaAux = listaPontos; //ponteiro apontando para o primeiro elemento
			int i=0; //auxiliar contador
			
			while(i!=index-1){  //enquanto o contador for diferente da vari�vel menos um
				listaAux = listaAux->prox; //pulando os elementos
				i++; //incrementa��o
			}
			p->prox = listaAux->prox; //apontando
			listaAux->prox = p; //apontando para um novo local
		}
		length++; //incrementa��o
	}
}

int main(){
	setlocale(LC_ALL, "");
	
	//adicionando valores e chamando a fun��o
	addIndex(1,1,0);
	addIndex(2,4,1);
	
	Ponto *auxLista = listaPontos; //ponteiro auxiliar
	
	imprime(auxLista);  //chamando a fun��o para exibir os valores dos pontos
	
	system("pause\n");
	return 0;
}