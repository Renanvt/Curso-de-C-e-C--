#include <stdio.h>
#include <locale.h> //Essa biblioteca possui funушes de regionalizaусo
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <conio.h>
#include <iostream>
#define TAM 3
using namespace std;

void imprimeSequencial(int *vetor, int tamanhoDaListaSequencial);

int main(){
    setlocale(LC_ALL,"");
    int cont;
    int vetor[TAM]={1,2,3}, tamanhoDaLista;

    imprimeSequencial(vetor,3);
    return 0;
}
/*Imprime a lista sequencial*/
void imprimeSequencial(int *vetor, int tamanhoDaListaSequencial){
    int cont;
    /*Imprime os valores*/
    for(cont=0;cont<tamanhoDaListaSequencial;cont++)
        printf("\nValor %d: %d",cont,vetor[cont]);
}
