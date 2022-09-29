#include <stdio.h>
#include <stdlib.h>

struct prato{  //estrutura para a pilha
	char cor;
	struct prato *prox;   	//ponteiro
};

typedef struct prato Prato; //renomeando

Prato *pilha;  //ponteiro

void push(char cor){  //fun��o para adicionar
	Prato *p = (Prato*) malloc(sizeof(Prato));  //alocando na mem�ria
	p->cor = cor;  //aponta para a cor do prato
	p->prox = pilha;  //novo elemento aponta para o primeiro elemento
	pilha = p; //novo primeiro elemento
}

void pop(){  //fun��o para remover 
	if(pilha == NULL){  //se a vari�vel for igual a nulo
		printf("Pilha vazia!!\n");
	}
	else{
		pilha = pilha->prox; //removendo o elemento que est� no topo
	}
}


void imprime(Prato *p){   //fun��o para imprimir os elementos
	if(p!=NULL){  //se a vari�vel for diferente de nulo
		printf("Cor do prato: %c\n", p->cor); //imprimindo
		imprime(p->prox);  //verificando o pr�ximo elemento
	}
}

int main(){
	
	//chamando a fun��o e adicionando as cores
	push('b');
	push('v');
	push('g');
	push('y');
	
	pop();  //chamando a fun��o para remover
	
	Prato *pilhaAux = pilha; //ponteiro auxiliar
	imprime(pilhaAux);  //chamando a fun��o para imprimir as cores adicionadas
	   	
	return 0;
}