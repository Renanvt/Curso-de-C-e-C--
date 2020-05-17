#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <conio.h>

#define TAM 3

void imprimeVetor(int *v,int tamanho);
void adiciona1noVetor(int *v,int tamanho);

int main(){
	setlocale(LC_ALL, "Portuguese");
    int v[TAM] = {1,2,3};
    /*Quando o vetor v armazenado na mem?ria, a primeira vari?vel dele ? a primeira casa do vetor, por isso utiliza-se ponteiros no vetor

    A fun??o altera diretamente na vari?vel v porque foi passado ponteiros
    */

    /*Mostrando o vetor*/
    imprimeVetor(v,TAM);

    /*Modificar o vetor*/
    adiciona1noVetor(v,TAM);
    imprimeVetor(v,TAM);
	return(0);
}


void imprimeVetor(int *v, int tamanho){
    int i;

    /*Percorrendo o vetor*/
    for(i=0;i<tamanho;i++)
        printf("%d \n",v[i]);
}
void adiciona1noVetor(int *v,int tamanho){
    int i;
    for(i=0;i<tamanho;i++)
        v[i] = v[i] + 1;
}

