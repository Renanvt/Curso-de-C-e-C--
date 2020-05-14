#include <stdio.h>
#include <locale.h> //Essa biblioteca possui funções de regionalização
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <conio.h>
#include <iostream>
#define TAM 3
using namespace std;

void imprimeVetor(int *v,int tamanho);
void adiciona1noVetor(int *v,int tamanho);
int main(){
	setlocale(LC_ALL, "Portuguese");
    int v[TAM] = {1,2,3};
    /*Quando o vetor é armazenado na memória a primeira variável
    dele é a primeira casa do vetor, por isso utiliza-se ponteiros no vetor

    A função altera diretamente na variável V porque é passado ponteiros
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
        cout << v[i] << "\n";
}
void adiciona1noVetor(int *v,int tamanho){
    int i;
    for(i=0;i<tamanho;i++)
        v[i] = v[i] + 1;

}

