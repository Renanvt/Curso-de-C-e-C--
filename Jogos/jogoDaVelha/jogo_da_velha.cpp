#include <iostream>
#include <new>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
void limpaTela(){
    system("cls");
}
void iniciaTabuleiro(char tabuleiro[3][3]){
    int i,j;
     for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            tabuleiro[i][j] = '-';
        } 
     }

}
void exibeTabuleiro(char tabuleiro[3][3]){
    int i,j;
     for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            cout << tabuleiro[i][j];
        }
        cout << "\n";
    }
}
void jogo(){
    ///VARIAVEIS GERAIS
    char tabuleiro[3][3]; //Tabuleiro do Jogo
    int i,j;
    //Coloca os '-' no tabuleiro para indiciar o vazio
    iniciaTabuleiro(tabuleiro);
    //Exibe o tabuleiro com suas linhas e colunas
    exibeTabuleiro(tabuleiro);

    
}

void menuInicial(){

    int opcao=0;
    while(opcao<1 || opcao>3){
        cout << "Bem vindo ao Jogo da Velha\n";
        cout << "1 - Jogar\n";
        cout << "2 - Sobre\n";
        cout << "3 - Sair\n";
        cout << "\nEscolha uma opcao e tecle ENTER\n";
        cin >> opcao;
        limpaTela();
        switch (opcao)
        {
        case 1:
            jogo();
            break;
        case 2:
            cout << "Informacoes do jogo\n";
            break;
        default:
            break;
        }

    }
}
int main(){
    menuInicial();
    return 0;
}