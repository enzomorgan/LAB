#include <stdio.h>
#include <stdlib.h>
#define TAM 10

void imprime_vetor(int vetor[TAM]){
	int cont;
									//fun��o para imprimir o vetor
	printf("\n");
	
	for(cont = 0; cont < TAM; cont++){
		printf("|%d|", vetor[cont]);
	}
}

void shell_sort(int vetor[TAM]){	//ordena valores longe um dos outros	
	int i, j, valor;
	int h = 1;
	
	//de quantos em quantos ser� o pulo entre an�lises
	while(h < TAM){
		h = 3 * h + 1;
	} 	
	
	while(h > 1){
		//reduz a dist�ncia entre as an�lises
		h = h / 3;
	}
	
		for(i = h; i < TAM; i++){
			valor = vetor[i];    //elemento atual em an�lise
			j = i - h;      //elemento anterior ao analisado
		
 			while((j >= 0) && (valor < vetor[j])){  //analisando membros anteriores
				vetor[j + h] = vetor[j];   //posiciona os elementos uma posi��o para frente
				j = j - h;  //faz o "j" andar para tr�s
		}
			
		//agora que o espa�o foi aberto, colocamos o atual (menor n�mero) na posi��o correta
			vetor[j + h] = valor;
		
			imprime_vetor(vetor); //lista atualizada
		 }		

}

int main(){
	int vetor[TAM] = {10,9,8,7,6,5,4,3,2,1};
	
	shell_sort(vetor);
	
	imprime_vetor(vetor);
	
	return 0;
}