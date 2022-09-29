#include <stdio.h>

int potencia(int base, int ep){  //fun��o recursiva

	if(ep==1){  //se o expoente for igual a 1
		return base;  //retornando a base
	}
	return base*potencia(base,ep-1);  //retorna o resultado do c�lculo
}

int main(){
	
	int v = potencia(2,4); //vari�vel que recebe a fun��o para fazer o c�lculo
	
	printf("%d", v);  //imprimindo
	
	return 0;
}