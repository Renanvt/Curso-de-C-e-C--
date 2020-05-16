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
void adcFimSequencial(pessoa *&ponteiroSequencial,int *tamanhoDaLista, string nome,int rg);
void adcPosicaoSequencial(pessoa *&ponteiroSequencial,int *tamanhoDaLista, string nome,int rg, int posicao);
void removeInicioSequencial(pessoa *&ponteiroSequencial,int *tamanhoDaLista);
void removeFimSequencial(pessoa *&ponteiroSequencial,int *tamanhoDaLista);
void removePosicaoSequencial(pessoa *&ponteiroSequencial, int *tamanhoDaLista, int posicao);
int main(){
    int funcaoDesejada=1;
    //Ponteiro para lista sequencial
    pessoa *ponteiroSequencial;
    //Tamanho da lista
    int tamanhoDaLista=0;

    //EXEMPLO
   // pessoa *exemploListaSequencial = new pessoa[2];
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
        int rg, posicao;
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
                   cout << "Funcao escolhida: 2 - Insercao de um node no fim da lista\n";
                    cout << "Digite um nome:\n";
                    cin >> nome;
                    cout << "Digite um RG:\n";
                    cin >> rg;

                    //Se a lista for vazia, usamos a função de criar no inicio
                    if(tamanhoDaLista==0){
                        adcComecoSequencial(ponteiroSequencial,&tamanhoDaLista, nome, rg);
                    }else{
                        adcFimSequencial(ponteiroSequencial,&tamanhoDaLista,nome,rg);
                    }
                    break;
                case 3:
                    cout << "Funcao escolhida: 3 - Insercao de um node na posicao N\n";
                    cout << "Digite uma posicao\n";
                    cin >> posicao;
                    cout << "Digite um nome:\n";
                    cin >> nome;
                    cout << "Digite um RG:\n";
                    cin >> rg;
                   

                    
                    if(posicao == 0){
                        //Se estiver que adc no começo
                         adcComecoSequencial(ponteiroSequencial,&tamanhoDaLista, nome, rg);
                    }else if(posicao==tamanhoDaLista){
                        //Se estiver que adc no fim
                        adcFimSequencial(ponteiroSequencial,&tamanhoDaLista,nome,rg);
                    }else if(posicao>tamanhoDaLista){
                        cout << "Digite uma posicao valida\n";
                    }else{
                        //Adiciona em uma posição específica
                        adcPosicaoSequencial(ponteiroSequencial,&tamanhoDaLista,nome,rg,posicao);
                    }
                    break;
                case 4:
                     cout << "Funcao escolhida: 4- Retirar um node no início da lista \n";
                    //Se a lista for vazia
                    if(tamanhoDaLista==0){
                        cout << "\nLista Vazia!\n";
                    }else{
                        removeInicioSequencial(ponteiroSequencial,&tamanhoDaLista);
                    }
                    break;
                case 5:
                      cout << "Funcao escolhida: 5- Retirar um node no final da lista \n";
                       //Se a lista for vazia
                    if(tamanhoDaLista==0){
                        cout << "\nLista Vazia!\n";
                    }else{
                        removeFimSequencial(ponteiroSequencial,&tamanhoDaLista);
                    }
                    break;
                case 6:
                    cout << "Funcao escolhida: 5- Retirar um node na posicao N\n";
                   
                       //Se a lista for vazia
                    if(tamanhoDaLista==0){
                        cout << "\nLista Vazia!\n";
                    }else{
                        cout << "Digite uma posicao\n";
                        cin >> posicao;
                        if(posicao==0){
                            removeInicioSequencial(ponteiroSequencial,&tamanhoDaLista);
                        }else if(posicao==tamanhoDaLista-1){
                            removeFimSequencial(ponteiroSequencial,&tamanhoDaLista);
                        }else if(posicao>tamanhoDaLista-1){
                            cout << "Posicao nao existe\n";
                        }else{
                             removePosicaoSequencial(ponteiroSequencial,&tamanhoDaLista,posicao);
                        }
                    }
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
void adcFimSequencial(pessoa *&ponteiroSequencial,int *tamanhoDaLista, string nome,int rg){
        //Criar uma lista com um tamanho maior
         pessoa *novaListaSequencial = new pessoa[*tamanhoDaLista + 1];

        //Passa os elementos do vetor antigo para o novo
        //Essa nova lista é uma casa maior
        int cont;
        for(cont=0;cont< *tamanhoDaLista;cont++){
            novaListaSequencial[cont].nome=ponteiroSequencial[cont].nome; 
            novaListaSequencial[cont].rg=ponteiroSequencial[cont].rg; 
        }

        //Posiciona o último elemento
        novaListaSequencial[*tamanhoDaLista].nome=nome;
        novaListaSequencial[*tamanhoDaLista].rg=rg;

         //Atualiza o ponteiro para a lista nova
        ponteiroSequencial=novaListaSequencial;

        //Aumenta o tamanho da lista
        *tamanhoDaLista = *tamanhoDaLista +1;
}

void adcPosicaoSequencial(pessoa *&ponteiroSequencial,int *tamanhoDaLista, string nome,int rg, int posicao){
        //Criar uma lista com um tamanho maior
        pessoa *novaListaSequencial = new pessoa[*tamanhoDaLista + 1];

        //Passa os elementos do vetor antigo para o novo até 1 antes da posição que se quer modificar
        int cont;
        for(cont=0;cont< posicao;cont++){
            novaListaSequencial[cont].nome=ponteiroSequencial[cont].nome; 
            novaListaSequencial[cont].rg=ponteiroSequencial[cont].rg; 
        }

        //Adiciona o novo registro na posição correta
        novaListaSequencial[posicao].nome=nome;
        novaListaSequencial[posicao].rg=rg;

        //Coloca o resto dos valores antigos
        for(cont=posicao+1;cont< *tamanhoDaLista+1;cont++){
            novaListaSequencial[cont].nome=ponteiroSequencial[cont-1].nome; 
            novaListaSequencial[cont].rg=ponteiroSequencial[cont-1].rg; 
        }

         //Atualiza o ponteiro para a lista nova
        ponteiroSequencial=novaListaSequencial;

        //Aumenta o tamanho da lista
        *tamanhoDaLista = *tamanhoDaLista +1;
}
void removeInicioSequencial(pessoa *&ponteiroSequencial,int *tamanhoDaLista){

    //Cria um vetor com uma posição a menos
    pessoa *novaListaSequencial = new pessoa[*tamanhoDaLista -1];

    //Passa os elementos do vetor antigo para o novo
    int cont;
    for(cont=1;cont< *tamanhoDaLista;cont++){
            novaListaSequencial[cont-1].nome=ponteiroSequencial[cont].nome; 
            novaListaSequencial[cont-1].rg=ponteiroSequencial[cont].rg; 
    }
     //Atualiza o ponteiro para a lista nova
        ponteiroSequencial=novaListaSequencial;

        //Reduz o tamanho da lista
        *tamanhoDaLista = *tamanhoDaLista -1;
}
void removeFimSequencial(pessoa *&ponteiroSequencial,int *tamanhoDaLista){
    //Cria um vetor com uma posição a menos
    pessoa *novaListaSequencial = new pessoa [*tamanhoDaLista-1];
    //Passa os elementos do vetor antigo para o novo menos o último
    int cont;
    for(cont=0;cont<*tamanhoDaLista-1;cont++){
        novaListaSequencial[cont].nome=ponteiroSequencial[cont].nome;
        novaListaSequencial[cont].rg=ponteiroSequencial[cont].rg;
    }
    //Atualiza o ponteiro para a lista nova
    ponteiroSequencial=novaListaSequencial;

    //Reduz o tamanho da lista
    *tamanhoDaLista=*tamanhoDaLista-1;
}
void removePosicaoSequencial(pessoa *&ponteiroSequencial, int *tamanhoDaLista, int posicao){
    //Cria um vetor com uma posicao a menos
    pessoa *novaListaSequencial = new pessoa[*tamanhoDaLista-1];
    //Passa os valores de acordo com o contador
    int cont;
    for(cont=0;cont< *tamanhoDaLista-1;cont++){
        if(cont<posicao){
            //Se estiver antes da posicao passa normalmente
            novaListaSequencial[cont].nome=ponteiroSequencial[cont].nome;
            novaListaSequencial[cont].rg=ponteiroSequencial[cont].rg;
        }else{
            //Se estiver antes da posicao passa normalmente
            novaListaSequencial[cont].nome=ponteiroSequencial[cont+1].nome;
            novaListaSequencial[cont].rg=ponteiroSequencial[cont+1].rg;
        }
    }
     //Atualiza o ponteiro para a lista nova
    ponteiroSequencial=novaListaSequencial;

    //Reduz o tamanho da lista
    *tamanhoDaLista=*tamanhoDaLista-1;
}
