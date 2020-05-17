#include <stdio.h>
#include <stdlib.h>
#include <new>
struct estrutura{
    int valorNumerico;
    //Ponteiro que aponta para onde está minha próxima estrutura
    struct estrutura *proximo; /*Estrutura- Se torna um tipo de variável que é um ponteiro para o proximo*/
};
int main(){
    //Cria o início da lista
    estrutura *ponteiroEncadeada;

    //Cria um novo valor
    estrutura *novoPrimeiroValor = new estrutura;
    novoPrimeiroValor->valorNumerico=13;//Utiliza a seta para poder navegar na estrutura

    novoPrimeiroValor->proximo=NULL;/*Coloca como nulo porque é o primeiro valor e também o último*/
   
    //Faz o ponteiro da encadeada apontar para o primeiro valor
    ponteiroEncadeada = novoPrimeiroValor;//Vai receber a posicao na memoria para saber onde começa a lista encadeada

    //Cria um novo segundo valor
    estrutura *novoSegundoValor = new estrutura;
    novoSegundoValor->valorNumerico=20;
    novoSegundoValor->proximo=NULL;

    //Justa os valores com um encadeamento
    ponteiroEncadeada->proximo=novoSegundoValor;//Retorna o endereço na memória do meu novo segundo valor
   
   //Imprime a lista encadeada
    while(ponteiroEncadeada != NULL){ //Enquanto não estiver em uma posição na memória nula
        //Imprime o valor atual
        printf("\nValor: %d",ponteiroEncadeada->valorNumerico);
        //Cursor recebe a posicao de memória do proximo valor

        ponteiroEncadeada = ponteiroEncadeada->proximo;
    }
    return 0;
}