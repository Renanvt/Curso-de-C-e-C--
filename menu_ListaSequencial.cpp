#include <iostream>
#include <new>
#include <string>
#include <stdlib.h>
using namespace std;
struct pessoa{
    string nome;
    int rg;
    struct pessoa *proximo;
};
void limpaTela();
int retornaTamanho(pessoa *ponteiroEncadeada);
void imprimeEncadeada(pessoa *ponteiroEncadeada);
void adcComecoEncadeada(pessoa *&ponteiroEncadeada, string nome, int rg);
void adcFimEncadeada(pessoa *&ponteiroEncadeada, string nome, int rg);

int main(){
    int funcaoDesejada;
    //Cria o inicio da lista encadeada
    pessoa *ponteiroEncadeada=new pessoa;
    ponteiroEncadeada->nome="";
    ponteiroEncadeada->rg=0;
    ponteiroEncadeada->proximo=NULL;
    /*
    //Cria o primeiro valor
    pessoa *novoPrimeiroValor = new pessoa;
    novoPrimeiroValor->nome = "John";
    novoPrimeiroValor->rg = 123;
    novoPrimeiroValor->proximo=NULL;

    //Transforma o ponteiro do inicio da lista em novo valor
    ponteiroEncadeada = novoPrimeiroValor; //Cria uma lista de tamanho 1

    //Cria o segundo valor
    pessoa *novoSegundoValor = new pessoa;
    novoSegundoValor->nome = "Jorge";
    novoSegundoValor->rg = 321;
    novoSegundoValor->proximo=NULL;

    //Encadeamento de valores
    novoPrimeiroValor->proximo=novoSegundoValor;
    */
    funcaoDesejada=1;
    while(funcaoDesejada<9 && funcaoDesejada>0){
        
        cout << "Operacoes\n";
        cout << "1 - Insercao de um node no inicio da lista\n";
        cout << "2 - Insercao de um node no fim da lista\n";
        cout << "3 - Insercao de um node na posicao N\n";
        cout << "4 - Retirar um node no inicio da lista\n";
        cout << "5 - Retirar um node no fim da lista\n";
        cout << "6 - Retirar um node na posicao N\n";
        cout << "7 - Procurar um nome com o campo RG \n";
        cout << "8 - Imprimir a Lista \n";
        cout << "9 - Sair do sistema\n\n";
        //Imprime a lista
        if(retornaTamanho(ponteiroEncadeada)==0){
            cout << "Lista Vazia\n";
        }else{
            imprimeEncadeada(ponteiroEncadeada);
        }
       
        //Retorna o tamanho
        cout << "Tamanho atual: "<< retornaTamanho(ponteiroEncadeada) << "\n";

        cout << "\nEscolha um numero e pressione ENTER: \n";
        cin >> funcaoDesejada;
        //Variavéis para valores novos
        string nome;
        int rg;
        limpaTela();
        switch(funcaoDesejada){
            case 1:
                cout << "Funcao escolhida: 1 - Insercao de um node no inicio da lista\n";
                cout << "Digite o nome:\n";
                cin >> nome;
                cout << "Digite o RG:\n";
                cin >> rg;
                adcComecoEncadeada(ponteiroEncadeada,nome,rg);
                break;
            case 2:
                cout << "Funcao escolhida: 2 - Insercao de um node no fim da lista\n";
                cout << "Digite o nome:\n";
                cin >> nome;
                cout << "Digite o RG:\n";
                cin >> rg;
                if(retornaTamanho(ponteiroEncadeada)==0){
                    adcComecoEncadeada(ponteiroEncadeada,nome,rg);
                }else{
                    adcFimEncadeada(ponteiroEncadeada,nome,rg);
                }
                break;
            case 3:
                cout << "Funcao escolhida: 3\n";
                break;
            case 4:
                cout << "Funcao escolhida: 4\n";
                break;
            case 5:
                cout << "Funcao escolhida: 5\n";
                break;
            case 6:
                cout << "Funcao escolhida: 6\n";
                break;
        }
    }
    return 0;
}
void limpaTela(){
    system("CLS");
}
int retornaTamanho(pessoa *ponteiroEncadeada){
    //Se a lista estiver vazia
     if(ponteiroEncadeada->nome==""){
        return 0;
    }

    //Tamanho da lista
    int tamanho=0;
    //Ponteiro cursor auxiliar
    pessoa *p= ponteiroEncadeada; //Joga o cursor no primeiro membro da lista
   
    while(p != NULL){
        //Atualiza o cursor
        p = p->proximo;
        //Contador de tamanho aumenta
        tamanho++;
    }
    return tamanho;
}
void imprimeEncadeada(pessoa *ponteiroEncadeada){
    //Ponteiro cursor auxiliar
    pessoa *p= ponteiroEncadeada;
    while(p != NULL){
        //Imprime a lista
        cout << p->nome << "," << p->rg << "\n";
        p=p->proximo;//Atualiza o cursor
        
    }
}
void adcComecoEncadeada(pessoa *&ponteiroEncadeada, string nome, int rg){
    //Cria uma nova estrutura
    pessoa *novoValor = new pessoa;
    novoValor->nome=nome;
    novoValor->rg=rg;
    //Verifica se a lista está vazia
    if(ponteiroEncadeada->nome == ""){
        //O valor antigo é desencadeado,cortado pra fora
        novoValor->proximo=NULL;
    }else{
         novoValor->proximo=ponteiroEncadeada;
    }
    //Redireciona o ponteiro
    ponteiroEncadeada = novoValor;
}
void adcFimEncadeada(pessoa *&ponteiroEncadeada, string nome, int rg){
    //Cria uma nova estrutura
    pessoa *novoValor = new pessoa;
    novoValor->nome=nome;
    novoValor->rg=rg;
    novoValor->proximo=NULL;

    //Ponteiro cursor auxiliar
    pessoa *p= ponteiroEncadeada;
    while(p != NULL){
        //Quando chega no último elemento, faz ele apontar para o novo valor
        if(p->proximo==NULL){
            p->proximo=novoValor;
            return; //Sai do while e termina o código antes de atualizar o cursor
        }
        p=p->proximo;//Atualiza o cursor
        
    }
}