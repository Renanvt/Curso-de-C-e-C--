#include <stdio.h>
#include <locale.h> //Essa biblioteca possui funушes de regionalizaусo
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <conio.h>

#define TAM 3
using namespace std;

void imprimeSequencial(int *vetor, int tamanhoDaListaSequencial);
int* alocaVetor(int tam);
int main(){
    setlocale(LC_ALL,"");
    int cont;
    int vetor[TAM]={1,2,3}, tamanhoDaLista;

    imprimeSequencial(vetor,3);
    putchar('\n');
    //Lendo novos valores
    for(cont=0;cont<TAM;cont++)
        scanf("%d", &vetor[cont]);
     imprimeSequencial(vetor,3);
    
    //Pedindo tamanho do vetor
    printf("\nDigite o tamanho do vetor: \n");
    scanf("%d",&tamanhoDaLista);

    /*Ponteiro para o novo vetor*/
    int *vetorLidoNaHora;
    //Passa o espaço da memória que foi criado para o vetor
    vetorLidoNaHora = alocaVetor(tamanhoDaLista);
    //Lendo novos valores
    for(cont=0;cont<tamanhoDaLista;cont++)
        scanf("%d", &vetorLidoNaHora[cont]);

    imprimeSequencial(vetorLidoNaHora,tamanhoDaLista);
    
    return 0;
}
/*Imprime a lista sequencial*/
void imprimeSequencial(int *vetor, int tamanhoDaListaSequencial){
    int cont;
    /*Imprime os valores*/
    for(cont=0;cont<tamanhoDaListaSequencial;cont++)
        printf("\nValor %d: %d",cont,vetor[cont]);
}
//Aloca um vetor do tamanho pedido
int* alocaVetor(int tam){
    //Cria um ponteiro auxiliar
    int *v;
    //Aloca memória para o novo vetor
    v=(int*) malloc(tam * sizeof(int));
    return v;
}
