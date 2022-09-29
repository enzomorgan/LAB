#include <stdio.h>
#include <stdlib.h>
#include <locale.h> 
#include <stdbool.h>
#define TAM 10


int main(){
	setlocale(LC_ALL, "");
	
	//declarando vari�veis
	int vetor[TAM] = {1,23,44,56,63,72,84,90,98};
	int valorProcurado, i, posicaoEncontrada;
	bool valorEncontrado;
	
	//la�o de repeti��o para imprimir o vetor
	for(i = 0; i < TAM; i++){
		printf("%d\n", vetor[i]);
	}
	
	//lendo o valor que deseja ser procurado
	printf("Qual n�mero deseja encontrar?\n");
	scanf("%d", &valorProcurado);
	
	//la�o para pesquisar se o valor digitado existe
	for(i = 0; i < TAM; i++){
		if(vetor[i] == valorProcurado){
			valorEncontrado = true; //valor encontrado � verdadeiro
			posicaoEncontrada = i;
		}   	
	}
	
	//estrutura para apresentar a posi��o, se o valor digitado for verdadeiro
	if(valorEncontrado){
		printf("O valor foi encontrado na posi��o: %d\n", posicaoEncontrada);
	}
	else{
		printf("Valor n�o encontrado\n");
	}
	
	system("pause\n\n");
	return 0;
}