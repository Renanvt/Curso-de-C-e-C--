#include <stdio.h>
#include <locale.h> //Essa biblioteca possui funções de regionalização
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <conio.h>
#include <iostream>
#define TAM 4
using namespace std;
bool pilha_vazia(int topo);
bool pilha_cheia(int topo);
void pilha_push(int pilha[TAM],int valor, int *topo);
void pilha_pop(int pilha[TAM], int *topo);
void imprime_vetor(int vetor[TAM],int topo);
void pilha_construtor(int pilha[TAM],int *topo);
int pilha_tamanho(int topo);
int pilha_get(int pilha[TAM],int *topo);
int main(){
	setlocale(LC_ALL, "Portuguese");
	int pilha[TAM];
	int topo;
    pilha_construtor(pilha,&topo);
    printf("\nTamanho da Pilha: %d",pilha_tamanho(topo));
    printf("\nÚltimo valor da Pilha: %d",pilha_get(pilha,&topo));


    if(pilha_vazia(topo))
        printf("\nA pilha está vazia");

    if(pilha_cheia(topo))
        printf("\nA pilha está cheia");

	return(0);
}
/*Cria a pilha e limpa ela*/
void pilha_construtor(int pilha[TAM],int *topo){
    /*Coloca o topo negativo para indicar uma pilha vazia*/
    *topo = -1;
    int cont;
    putchar('\n');
    for(cont=0;cont<TAM;cont++){
        pilha[cont] = 0;
    }
}
/*Retorna o ultimo valor da pilha*/
int pilha_get(int pilha[TAM],int *topo){
    if(pilha_vazia(*topo)){
        printf("\nA pilha está vazia\n");
        return 0;
    }else{
        return pilha[*topo];
    }
}

int pilha_tamanho(int topo){
    return topo + 1;
    }

/*Caso a pilha esteja vazia*/
bool pilha_vazia(int topo){
    if(topo == -1)
        return true;
    else
        return false;
}
/*Caso a pilha esteja cheia*/
bool pilha_cheia(int topo){
    if(topo == TAM-1)
        return true;
    else
        return false;
}
void imprime_vetor(int vetor[TAM],int topo){
    int cont;
    putchar('\n');
    for(cont=0;cont<TAM;cont++)
        printf("%d - ",vetor[cont]);

    printf("\nTopo: %d",vetor[topo]);


}
/*Adiciona uma valor no topo da pilha*/
void pilha_push(int pilha[TAM],int valor, int *topo){
/*Caso não possa colocar mais valores*/
	if(pilha_cheia(*topo))
        cout << "Pilha cheia!";
    else{
        *topo += 1;
        pilha[*topo] = valor;
    }
}
/*Remove um valor no topo da pilha*/
void pilha_pop(int pilha[TAM], int *topo){
    if(pilha_vazia(*topo))
        cout << "\nA pilha ja esta vazia\n";
    else{
        printf("\nValor Removido: %d\n",pilha[*topo]);
        pilha[*topo] = 0;
        *topo = *topo -1;
    }
}
