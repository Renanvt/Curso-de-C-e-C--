#include <stdio.h>
#include <locale.h> //Essa biblioteca possui fun��es de regionaliza��o
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <conio.h>
#include <new>
#include <iostream>
#define TAM 10
using namespace std;
int buscaSimples(int vetor[TAM],int valorProcurado,int *posicaoEncontrada);
int buscaBinaria(int vetor[TAM],int valorProcurado,int *posicaoEncontrada);
void imprime_vetor(int vetor[TAM]);

int main(){
	setlocale(LC_ALL, "Portuguese");

    int vetor[TAM] = {1,23,44,56,63,72,84,90,98};
    int valorProcurado;
    int posicao, posicaoEncontrada;
    int cont;
    bool valorFoiEncontrado; /*TRUE COMO PADR�O!*/


    imprime_vetor(vetor);

    printf("\nQual número deseja encontrar?\n");
    scanf("%d",&valorProcurado);



    if(buscaSimples(vetor,valorProcurado,&posicaoEncontrada) == 1)
        printf("O valor foi encontrado na posição %d\n",posicaoEncontrada);
    else
        printf("Valor não encontrado\n");

    imprime_vetor(vetor);

    printf("\nQual número deseja encontrar?\n");
    scanf("%d",&valorProcurado);



    if(buscaBinaria(vetor,valorProcurado,&posicaoEncontrada) == 1)
        printf("O valor foi encontrado na posição %d",posicaoEncontrada);
    else
        printf("Valor não encontrado");


	return(0);
}


int buscaSimples(int vetor[TAM],int valorProcurado,int *posicaoEncontrada){
    int cont;
    bool valorFoiEncontrado=false;

    /*PESQUISAR SE O VALOR EXISTE*/
    for(cont=0;cont<TAM;cont++){
        if(vetor[cont] == valorProcurado){
            valorFoiEncontrado = true;
            *posicaoEncontrada = cont; /*Realiza uma passagem por referencia*/
        }
    }

    if(valorFoiEncontrado)
        return 1;
    else
        return -1;

}
void imprime_vetor(int vetor[TAM]){
    int cont;
    for(cont=0;cont<TAM;cont++)
        printf("%d - ",vetor[cont]);

}

int buscaBinaria(int vetor[TAM],int valorProcurado,int *posicaoEncontrada){
    int esquerda=0; /*Limite da esquerda*/
    int direita = TAM -1; /*Limite da direita*/
    int meio; /*Meio onde fica o cursor*/
    int i,j,troca;


    while(esquerda <= direita){
            /*[1] LAÇO -> 0<=10 -> TRUE*/
            /*[2] LAÇO -> 6<=10 -> TRUE*/
            /*[3] LAÇO -> 9<=10 -> TRUE*/
            /*[4] LAÇO -> 9<=8 -> FALSE -> SAI DO LA�O*/

        /*Encontra o meio da an�lise*/
        meio = (esquerda + direita)/2;
            /*[1] LAÇO -> meio -> (0 + 10 )/2 = 5*/
            /*[2] LAÇO -> meio -> (6 + 10 )/2 = 16/2 = 8*/
            /*[3] LAÇO -> meio -> (9 + 10 )/2 = 19/2 = 9,5 = 9*/

        /*Quando o valor do meio � encontrado*/
        if(valorProcurado == vetor[meio]){
            /*[1] LAÇO -> 100==vetor[5] -> 100==72 -> FALSE*/
            /*[2] LAÇO -> 100==vetor[8] -> 100==72 -> FALSE*/
            /*[2] LAÇO -> 100==vetor[9] -> 100==98 -> FALSE*/
            *posicaoEncontrada = meio;
            return 1;
        }

        /*Ajustando os limites laterais*/
        if(vetor[meio]<valorProcurado){
            esquerda = meio+1;
            /*[1] LAÇO -> vetor[5]<100;72 < 100; TRUE; esquerda=5+1 -> esquerda=6;*/
            /*[2] LAÇO -> vetor[8]<100; 98 < 100; TRUE esquerda = 9*/
            /*[3] LAÇO -> vetor[9]<100; FALSE*/

        }else{
            direita=meio-1;
            /*[3] LAÇO -> direita=9-1 -> direita=8*/
        }
    }

    return -1;/*Não foi achado nenhum valor*/
}
