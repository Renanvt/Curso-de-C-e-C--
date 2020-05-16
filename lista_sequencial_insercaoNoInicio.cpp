#include <iostream>
#include <new>
#include<string>
#include <stdlib.h>
#include <conio.h>
using namespace std;

struct pessoa{
    string nome;
    int rg;
};
void limpaTela();
void imprime_sequencial(pessoa *ponteiroSequencial, int tamanhoDaLista);
void adcComecoSequencial(pessoa *&ponteiroSequencial, int *tamanhoDaLista, string nome,int rg);
int main(){
    int funcaoDesejada=1;
    //Ponteiro para lista sequencial
    pessoa *ponteiroSequencial;
    //Tamanho da lista
    int tamanhoDaLista=0;

    //EXEMPLO
    pessoa *exemploListaSequencial = new pessoa[2];
    //Dois registros de exemplo:
    /*exemploListaSequencial[0].nome = "John";
    exemploListaSequencial[0].rg = 123;
    exemploListaSequencial[1].nome = "Maicon";
    exemploListaSequencial[1].rg = 321;*/

    //Faz o ponteiro principal apontar para o novo vetor
    //ponteiroSequencial = exemploListaSequencial;/*Coloca o primeiro elemento da lista sequencial em ponteiroSequencial*/
    

    while(funcaoDesejada<10 && funcaoDesejada>0){
        //Imprime a lista sequencial
        imprime_sequencial(ponteiroSequencial,tamanhoDaLista);//O tamanho da lista vai ser atualizado conforme for adicionando novos valores

        /*Mostrando  o menu*/
        funcaoDesejada=1;
        cout << "Operacoes \n";
        cout << "1 - Insercao de um node no inicio da lista\n";
        cout << "2 - Insercao de um node no fim da lista\n";
        cout << "3 - Insercao de um node na posicao N\n";
        cout << "4 - Retirar um node no inicio da lista\n";
        cout << "5 - Retirar um node no fim da lista\n";
        cout << "6 - Retirar um node na posicao N\n";
        cout << "7 - Procurar um nome com o campo RG \n";
        cout << "8 - Imprimir a Lista \n";
        cout << "9 - Sair do sistema\n";
        cout << "\nEscolha um numero e pressione ENTER: \n";
        //Lendo a opcao do usuario
        cin >> funcaoDesejada;
        limpaTela();

        /*Variáveis criadas nas operações*/
        string nome;
        int rg;
        //Chama a opcao desejada
        switch(funcaoDesejada){
                case 1:
                    cout << "Funcao escolhida: 1 - Insercao de um node no inicio da lista\n";
                    cout << "Digite um nome:\n";
                    cin >> nome;
                    cout << "Digite um RG:\n";
                    cin >> rg;
                    adcComecoSequencial(ponteiroSequencial,&tamanhoDaLista, nome, rg);
                    break;
                case 2:
                    cout << "Funcao escolhida: 2\n";
                    break;
                    
        }
        
    }
    return 0;
}
void limpaTela(){
    system("CLS");
}
void imprime_sequencial(pessoa *ponteiroSequencial, int tamanhoDaLista){
    int cont;
    for(cont=0;cont<tamanhoDaLista;cont++){
        cout << cont << " - " << ponteiroSequencial[cont].nome << "," << ponteiroSequencial[cont].rg << "\n";
    }
}

void adcComecoSequencial(pessoa *&ponteiroSequencial, int *tamanhoDaLista,string nome,int rg){
    //Se a lista for vazia, cria uma lista nova
    if(*tamanhoDaLista == 0){
        //Caso uma nova lista
        pessoa *novaListaSequencial = new pessoa[1];

        //Insere o primeiro novo elemento
        novaListaSequencial[0].nome = nome; 
        novaListaSequencial[0].rg = rg;

        //Atualiza o ponteiro para a lista nova
        ponteiroSequencial=novaListaSequencial;
    }else{
        //Caso a lista ja tenha membros
        pessoa *novaListaSequencial = new pessoa[*tamanhoDaLista + 1];
        //Insere o primeiro novo elemento
        novaListaSequencial[0].nome = nome; 
        novaListaSequencial[0].rg = rg;

        //Passa os elementos do vetor antigo para o novo
        int cont;
        for(cont=0;cont< *tamanhoDaLista;cont++){
            novaListaSequencial[cont + 1].nome=ponteiroSequencial[cont].nome; // Pega a minha lista antiga e passa os elementos para nova lista, 1 casa na frente
            novaListaSequencial[cont + 1].rg=ponteiroSequencial[cont].rg; 
        }
        //Atualiza o ponteiro para a lista nova
        ponteiroSequencial=novaListaSequencial;

    }
    
    //Aumenta o tamanho da lista
    *tamanhoDaLista = *tamanhoDaLista +1; //O Conteúdo apontado para o tamanho da lista recebe o conteúdo apontado para o tamanho da lista +1

}