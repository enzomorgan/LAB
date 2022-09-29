#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define TAM 10

void imprime_vetor(int vetor[TAM]){
	int cont;
								//fun��o para imprimir o vetor
	printf("\n");
	
	for(cont = 0; cont < TAM; cont++){
		printf("|%d|", vetor[cont]);
	}
}

void selection_sort(int vetor[TAM]){
	int i, j, aux, posicaoMenorValor;
									//fun��o para selecionar e posicionar os elementos 
	for(i = 0; i < TAM; i++){
		posicaoMenorValor = i; //recebe a posi��o inicial para o menor valor
		
		for(j + 1; j < TAM; j++){ //analisa os elementos na frente
			if(vetor[j] < vetor[posicaoMenorValor]){
				posicaoMenorValor = j;
			}  //caso encontre um valor menor na frente dos analisados
		}
		
		if(posicaoMenorValor != 1){ //verifica se houve mudan�a e troca de valores
			aux = vetor[i];
			vetor[i] = vetor[posicaoMenorValor];
			vetor[posicaoMenorValor] = aux;
		}
		
			imprime_vetor(vetor);  //lista de elementos atualizada
	}
}

int main(){
	setlocale(LC_ALL, "");
	
	int vetor[TAM] = {10,9,8,7,6,5,4,3,2,1};  //declara��o de vari�vel vetor
	
	selection_sort(vetor);   //fun��o dos elementos
	
	imprime_vetor(vetor);    //chamando a fun��o para imprimir  
	
	return 0;
}