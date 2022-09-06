#include <stdio.h>
#include <stdlib.h>

typedef struct aluno{ //estrutura para o aluno
	int matricula;
	char nome[80];
	char turma;
	float notas[3];
	float media;
} Aluno; //renomeando

void matricula(int n, Aluno* alunos){ //fun��o para adicionar os dados
	int i;  //vari�vel
	
	printf("Informe a quantidade de alunos que deseja matricular: \n");
	scanf("%d", &n);  //lendo a quantidade de alunos
	
	alunos = (Aluno*)malloc(n*sizeof(Aluno));  //alocando dinamicamente
	
	if(alunos == NULL){  //se for igual a nulo
		printf("memoria insuficiente!\n");  //imprimindo a mensagem
		exit(1);  //encerrando o programa
	}
	
	for(i = 0; i < n; i++){  //percorrendo o vetor
		if(n > 10){  //se for mais que 10 alunos
			printf("Nao temos mais vagas!\n");  //imprimindo a mensagem
			system("pause\n");  //pausando o programa para visualizar o erro
			exit(1); //encerrando o programa
		}
		printf("Matricula do aluno: \n");
		scanf("%d", &alunos->matricula[i]);  //lendo o n�mero da matricula
		printf("Nome: \n");
		scanf("%s", alunos->nome[i]);  //lendo o nome do aluno
		printf("Turma: \n");
		scanf("%s", alunos->turma[i]);  //lendo a turma
	}
	
	free(alunos);  //liberando a mem�ria
}

void lanca_notas(int n, Aluno* alunos){  //fun��o para lan�ar as notas
	int i;  //vari�vel
	
	for(i = 0; i < n, i++){ //percorrendo o vetor
		printf("Digite as notas: \n"); 
		scanf("%f", &alunos->notas[i]); //lendo as notas
		alunos->media = (alunos->media + alunos->notas[i])/3  //calculando 
	}
	printf("Media: %.1f\n", alunos); //imprimindo a m�dia
}

void imprime_tudo(int n, Aluno* alunos){  //fun��o para imprimir os dados
	int i; //vari�vel
	
	for(i = 0; i < n; i++){ //percorrendo o vetor
		printf("Matricula: %d\n", alunos->matricula); //imprimindo a matricula
		printf("Nome: %s\n", alunos->nome); //imprimindo o nome
	}
}

void imprime_turma(int n, Aluno* alunos, char turma){  //fun��o para imprimir turma
	int i; //vari�vel
	
	for(i = 0; i < n; i++){ //percorrendo o vetor
		printf("Matricula: %d\n", alunos->matricula); //imprimindo a matricula
		printf("Nome: %s\n", alunos->nome); //imprimindo o nome
		printf("Turma: %s\n", alunos->turma); //imprimindo a turma
	}
}

void imprime_turma_aprovados(int n, Aluno* alunos, char turma){ //fun��o para imprimir os aprovados
	int i; //vari�vel
	
	for(i = 0; i < n; i++){ //percorrendo o vetor
		printf("Turma: %s\n", alunos->turma);  //lendo a turma
		
		if(alunos->media >= 7){  //se m�dia for maior ou igual a 7
			printf("Aluno aprovado!\n"); //imprimindo a mensagem 
			printf("Turma: %s\n", alunos->turma);  //imprimindo a turma
		}
		else{ //se a m�dia n�o for maior ou igual a 7
			printf("Aluno reprovado!\n"); //imprimindo a mensagem
			printf("Turma: %s\n", alunos->turma); //imprimindo a turma
		}
	}
}
int main(){
	//declara��o de vari�veis
	Aluno* a;
	int n;
	char t;
	
	matricula(n, &a);  //chamando a fun��o para adicionar os dados
	printf("\n");
	lanca_notas(n, &a); //chamando a fun��o para adicionar as notas e a m�dia
	printf("\n");
	imprime_tudo(n, &a); //chamando a fun��o para imprimir a matricula e nome
	printf("\n"); 
	imprime_turma(n, &a, t); //chamando a fun��o para imprimir os dados da turma
	printf("\n");
	imprime_turma_aprovados(n, &a, t);  //chamando a fun��o para imprimir os aprovados
	
	return 0;
}