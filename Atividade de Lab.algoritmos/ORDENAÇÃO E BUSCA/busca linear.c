#include <stdio.h>

struct estudante{  //estrutura para os estudantes
	int mat;
	char nome[50];
	float nota1;
	float nota2;
	float nota3;
};

//recebendo um ponteiro para estudante
void ler(struct estudante *pe){  //fun��o para imprimir os estudantes 
	scanf("%d %s %f %f %f", &pe->mat, pe->nome, &pe->nota1, &pe->nota2, &pe->nota3); //lendo os dados
}

void menu(){  //fun��o para imprimir o menu
	printf("====== digite a opcao: ======\n");
	printf("1 - pesquisar\n");
	printf("2 - sair\n");
	printf("=============================\n");
}

int pesquisa(int mat, int n, struct estudante v[]){  //fun��o para pesquisar
	int i;  //auxiliar
	for(i = 0; i < n; i++){  //percorrendo o vetor
		if(v[i].mat == mat){  //verificando a matr�cula
			return i;  //retornando o ind�ce do estudante
		}
	}
	return -1;  //se n�o encontrar a matr�cula, retorna -1
}

int main(){
	
	int n;  //vari�vel
	
	printf("Informe o valor de n: \n");
	scanf("%d", &n);  //lendo o valor de n
	
	struct estudante v[n]; //vetor de estudantes
	int i; //auxiliar
	for(i = 0; i < n; i++){ //percorrendo o vetor
		ler(&v[i]);  //chamando a fun��o ler
	}
	
	int op;  //vari�vel
	menu();  //chamando a fun��o do menu
	scanf("%d", &op);  //lendo a op��o digitada no menu
	
	while(op != 2){  //enquanto a op��o for diferente de 2(sair) ser� analisado
		if(op == 1){  //se op��o for igual a 1(pesquisar) 
			int mat;  //vari�vel para a matr�cula
			printf("informe a matricula: \n");
			scanf("%d", &mat);  //lendo a matr�cula digitada 
			int idx = pesquisa(mat, n, v);  //vari�vel que vai ser quem retorna na fun��o pesquisa
			if(idx != -1){  //se for diferente de -1, ser� feito o c�lculo da m�dia
				float media = (v[idx].nota1*2 + v[idx].nota2*3 + v[idx].nota3*4)/9;  //calculando m�dia
				printf("%s: %.2f\n", v[idx].nome, media);  //imprimindo os dados
			}
		}
		menu();  //fun��o do menu
		scanf("%d", &op);  //lendo a op��o digitada
	}
	
	printf("Fim do programa!!\n");
	
	return(0);
}