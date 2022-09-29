#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


int main(){
	setlocale(LC_ALL, "");
	
	int n;   //vari�vel inteira
	int *pn;   //ponteiro criado para vari�vel
	
	pn = &n;   //endere�o onde "n" est� declarado
	
	printf("Informe um valor: \n");   //informando um valor para linhas e colunas
	scanf("%d", pn);   //lendo o valor informado
	
	//criando uma matriz para armazenar os valores
	int matriz[n][n];
	int i, j;  //auxiliares contadoras
	
	//caminhando sobre as linhas e colunas da matriz
	for(i = 0; i < n; i++){  //linhas
		for(j = 0; j < n; j++){  //colunas
			scanf("%d", &matriz[i][j]); //lendo valores
		}
	}
	
	//verificando se o n�mero pesquisado existe na matriz
	int num;  //vari�vel
	scanf("%d", &num); //lendo o n�mero digitado
	
	//pesquisando
	for(i = 0; i < n; i++){  //linhas
		for(j = 0; j < n; j++){  //colunas
			if(matriz[i][j] == num){  //analisando o n�mero digitado
				printf("linha: %d, coluna: %d", i , j);  //imprimindo a linha e coluna que o n�mero est�			}
			}
		}
	}
	
	return 0;
}