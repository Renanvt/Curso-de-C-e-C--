#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;
void limpaTela(){
    system("cls");
}
void menuInicial(){
    //Opcao escolhida pelo usuário
    int opcao=0;
    //Enquanto o jogador não digita uma opcao válida mostra o menu novamento
    while(opcao<1 || opcao>3){
        cout << "Bem vindo ao Jogo\n";
        cout << "1 - Jogar\n";
        cout << "2 - Sobre\n";
        cout << "3 - Sair\n";
        cout << "\nEscolha uma opcao e tecle ENTER:\n";
        cin >> opcao;
        limpaTela();
        //Faz algo de acordo com a posicao escolhida
        switch(opcao){
            case 1:
                //Inicia o jogo
                cout << "Jogo iniciado";
                break;
            case 2:
                //Sobre
                cout << "Informacoes do jogo";
                break;
        }
    }
}
