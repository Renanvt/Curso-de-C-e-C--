#include <stdio.h>
#include <locale.h> //Essa biblioteca possui fun��es de regionaliza��o
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <conio.h>
#include <iostream>
#define TAM 10
using namespace std;
void imprime_vetor(int vetor[TAM]);
void bubble_sort(int vetor[TAM]);
void selection_sort(int vetor[TAM]);
void quick_sort(int vetor[TAM],int inicio, int fim);
void insertion_sort(int vetor[TAM]);
void shell_sort(int vetor[TAM]);
void merge_sort(int vetor[TAM], int indiceEsquerdo, int indiceDireito);
void merge(int vetor[TAM], int indiceEsquerdo,int meio, int indiceDireito);

int main(){
    int vetor[TAM] = {10,9,8,7,6,5,4,3,2,1};

    bubble_sort(vetor);
    selection_sort(vetor);
    quick_sort(vetor,0,TAM);
    insertion_sort(vetor);
    shell_sort(vetor);
    merge_sort(vetor,0,TAM-1);
    imprime_vetor(vetor);


    return 0;
}
void imprime_vetor(int vetor[TAM]){
    int cont;
    putchar('\n');
    for(cont=0;cont<TAM;cont++)
        printf("%d - ",vetor[cont]);

}
void bubble_sort(int vetor[TAM]){
int x, y,troca;
  for(x=0;x<TAM;x++){
        for(y=x+1;y<TAM;y++){
            if(vetor[x]>vetor[y]){
                troca = vetor[x];
                vetor[x] = vetor[y];
                vetor[y]=troca;
            }
        }
  }
}
void selection_sort(int vetor[TAM]){
    int posicaoDoMenorValor,aux;
    int i,j;
    for(i=0;i<TAM;i++){
    /*Recebe a posi�� inicial para o menor valor*/
        posicaoDoMenorValor=i;
        /*Analisa os elementos na frente*/
        for(j=i+1;j<TAM;j++){
            /*Caso encontre um valor menor na frente dos analisados*/
            if(vetor[j]<vetor[posicaoDoMenorValor])
                posicaoDoMenorValor=j;
        }
        /*Verifica se houve mudan�a e troca os valores*/
        if(posicaoDoMenorValor != i){
            aux = vetor[i];
            vetor[i] = vetor[posicaoDoMenorValor];
            vetor[posicaoDoMenorValor]=aux;
        }
    }
}
void quick_sort(int vetor[TAM],int inicio, int fim){
    int esq,dir,pivo,meio,aux;

    /*Limites da esquerda e direita da regi�o analisada*/
    esq=inicio;
    dir=fim-1;
    /*Ajustando auxiliares do centro*/
    meio=(int) ((esq+dir)/2);
    pivo=vetor[meio];
    while(esq<=dir){
        while(vetor[esq]<pivo && esq<fim){
            esq++;
        }
        while(vetor[dir]>pivo && dir>inicio){
            dir--;
        }
        if(esq<=dir){
            /*Realiza uma troca*/
            aux=vetor[esq];
            vetor[esq]=vetor[dir];
            vetor[dir]=aux;
            /*Faz os limites laterais caminharem para o centro*/
            esq++;
            dir--;
        }
    }
    /*Recurs�o para continuar ordenando*/
    if(inicio<dir){
        quick_sort(vetor,inicio,dir+1);

    }
    /*Recurs�o para continuar ordenando*/
    if(esq<fim){
        quick_sort(vetor,esq,fim);
    }
}
void insertion_sort(int vetor[TAM]){
    int i, j, atual;

    for(i=1;i<TAM;i++){
        /*Elemento atual em an�lise*/
        atual = vetor[i];
        /*Elemento anterior ao analisado*/
        j=i-1;
        /*Analisando membros anteriores*/
        while(j >=0 &&(atual<vetor[j])){
            /*Posiciona os elementos uma posi��o para frente*/
            vetor[j+1]=vetor[j];
            /*Faz o j andar para tras*/
            j=j-1;
        }
        /*Agora que o espa�o foi aberto, colocamos o atual(menor numero) na posi��o correta*/
        vetor[j+1]=atual;
    }
}
void shell_sort(int vetor[TAM]){
    int i, j, atual;
    int h=1;

    /*De quantos em quantos ser� o pulo entre an�lises*/
    while(h<TAM){
        h=3*h+1;
    }
    while(h>1){
        /*Reduz a dist�ncia entre as analises*/
        h=h/3;
       int i, j, atual;

        for(i=h;i<TAM;i++){
            /*Elemento atual em an�lise*/
            atual = vetor[i];
            /*Elemento anterior ao analisado*/
            j=i-h;

            /*Analisando membros anteriores*/
            while(j >=0 &&(atual<vetor[j])){

                /*Posiciona os elementos uma posi��o para frente*/
                vetor[j+h]=vetor[j];

                /*Faz o j andar para tras*/
                j=j-h;
            }
        /*Agora que o espa�o foi aberto, colocamos o atual(menor numero) na posi��o correta*/
        vetor[j+h]=atual;
        }
    }
}
void merge_sort(int vetor[TAM], int indiceEsquerdo, int indiceDireito){

    if(indiceEsquerdo<indiceDireito){

        /*Encontra o meio*/
        int meio = indiceEsquerdo + (indiceDireito-indiceEsquerdo)/2;

        /*Da metade para tr�s*/
        merge_sort(vetor,indiceEsquerdo,meio);

        /*Da metade para frente*/
        merge_sort(vetor,meio+1,indiceDireito);

        /*Para visualizar o processo deve inserir a fun��o imprime vetor aqui*/
        /*imprime_vetor(vetor);*/
        /*Uni os dois subarrays que foram criados*/
        merge(vetor,indiceEsquerdo,meio,indiceDireito);
    }
}

/*Justa os dois sub-arrays criados ao dividir o vetor principal*/
void merge(int vetor[TAM], int indiceEsquerdo,int meio, int indiceDireito){

    int i,j,k; /*Auxiliares contadoras*/
    int n1 = meio - indiceEsquerdo+1; /*Tamanho do primeiro vetor auxiliar*/
    int n2 = indiceDireito - meio; /*Tamanho do segundo vetor auxiliar*/

    /*Cria dois Arrays Tempor�rios*/
    int vetorEsquerdo[n1],vetorDireito[n2];

    /*Passa os elementos do vetor principal para o primeiro vetor auxiliar(esquerda)*/
    for(i=0;i<n1;i++){
        vetorEsquerdo[i] = vetor[indiceEsquerdo + i];
    }

    /*Passa os elementos do vetor principal para o segundo vetor auxiliar(direita)*/
    for(j=0;j<n2;j++){
        vetorDireito[j] = vetor[meio + 1 + j];
    }

    /*Reseta as vari�veis*/
    i=0;
    j=0;
    k=indiceEsquerdo;
    while(i<n1 && j < n2){
        /*Caso o valor na esquerda seja menor*/
        if(vetorEsquerdo[i] <= vetorDireito[j]){
            /*Passo para o meu vetor principal o valor menor*/
            vetor[k] = vetorEsquerdo[i];
            /*Incrementa o auxiliar para passar a an�lise para os proximos valores do vetor auxiliar*/
            i++;
        }else{
            vetor[k]=vetorDireito[j];
            j++;
        }
        /*Aumenta o indice de posicionamento do vetor*/
        k++;
    }
    /*Se faltarem alguns elementos do vetor ESQUERDO, passa ele para o array principal*/
    while(i<n1){
        vetor[k]=vetorEsquerdo[i];
        i++;
        k++;
    }
    /*Se faltarem alguns elementos do vetor DIREITO, passa ele para o array principal*/
    while(j<n2){
        vetor[k]=vetorDireito[j];
        j++;
        k++;
    }
}



