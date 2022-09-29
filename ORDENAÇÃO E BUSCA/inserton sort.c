#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define TAM 10

void imprime_vetor(int vetor[TAM]){
	int cont;
	
	printf("\n");
							//fun��o para imprimir o vetor					
	for(cont = 0; cont < TAM; cont++){
		printf("|%d|", vetor[cont]);
	}
}

void inserton_sort(int vetor[TAM]){
	int i, j, atual;
                   	   	   	   	   //fun��o para posicionar os elementos 	
	for(i = 1; i < TAM; i++){
		atual = vetor[i];    //elemento atual em an�lise
		j = i - 1;      //elemento anterior ao analisado
		
		while((j >= 0) && (atual < vetor[j])){  //analisando membros anteriores
			vetor[j + 1] = vetor[j];   //posiciona os elementos uma posi��o para frente
			j = j - 1;  //faz o "j" andar para tr�s
		}
		
			
	//agora que o espa�o foi aberto, colocamos o atual (menor n�mero) na posi��o correta
		vetor[j + 1] = atual;
	
		imprime_vetor(vetor);  //mostra a lista atualizada      
	}

}

int main(){
	setlocale(LC_ALL, "");
	
	//declara��o de vari�veis
	int vetor[TAM] = {10,9,8,7,6,5,4,3,2,1};
	
	inserton_sort(vetor);  //chamando a fun��o dos elementos
	
	imprime_vetor(vetor);  //chamando a fun��o para imprimir o vetor
	
	return 0;
}