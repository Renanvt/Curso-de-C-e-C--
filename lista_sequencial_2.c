#include <stdio.h>
#include <locale.h> //Essa biblioteca possui funушes de regionalizaусo
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <conio.h>

void imprime_sequencial(int *vetor, int tamanhoDaLista);
int* aloca_vetor(int tam);
int main(){

    int cont,tamanhoDaLista;
    int *vetorAlocado;

    printf("Qual o tamanho da lista?\n");
    scanf("%d",&tamanhoDaLista);

    vetorAlocado=aloca_vetor(tamanhoDaLista);

    printf("Digite os valores:\n");
    for(cont=0;cont<tamanhoDaLista;cont++)
        scanf("%d",&vetorAlocado[cont]);

    imprime_sequencial(vetorAlocado,tamanhoDaLista);
    return 0;
}
void imprime_sequencial(int *vetor, int tamanhoDaLista){
    int cont=0;
    for(cont=0;cont<tamanhoDaLista;cont++){
            printf("%d",vetor[cont]);
            if(cont!=tamanhoDaLista-1)
                printf(" - ");
    }
    
}

int* aloca_vetor(int tam){
    int *v;
    v = (int*) malloc(tam * sizeof(int));
    return v;
}
    