#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
using namespace std;
//área de cabeçalho de definição de funcoes
void menuInicial();

   
    
void limpaTela(){
    system("CLS");
}
void iniciaTabuleiro(char tabuleiro[3][3]){
    //Navega por cada posição do tabuleiro e coloca o símbolo de '-'
    int i,j;
     for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            tabuleiro[i][j] = '-';
        } 
     }

}
void exibeTabuleiro(char tabuleiro[3][3]){
    //Exibe o tabuleiro com suas linhas e colunas quebrando a linha ao sair de um for
    char blue[] = { 0x1b, '[', '1', ';', '3', '4', 'm', 0 };
    char green[] = { 0x1b, '[', '1', ';', '3', '2', 'm', 0 };
    char normal[] = { 0x1b, '[', '1', ';', '3', '9', 'm', 0 };
    int i,j;
    cout << "\n";
     for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            cout << green << tabuleiro[i][j] << normal;
        }
        cout << "\n";
    }
   
}
//1 = x venceu, 2 = o venceu, 0 = velha
int confereTabuleiro(char tabuleiro[3][3]){
   
  
     //Confere se o jogador venceu nas linhas horizontais
       /* if(tabuleiro[0][0]== 'x' && tabuleiro[0][0] == tabuleiro[0][1] && tabuleiro[0][1] == tabuleiro[0][2]){
            cout << "O Jogador x venceu";
            estadoDeJogo=0;
        }
        if(tabuleiro[1][0]== 'x' && tabuleiro[1][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[1][2]){
            cout << "O Jogador x venceu";
            estadoDeJogo=0;
        }
        if(tabuleiro[2][0]== 'x' && tabuleiro[2][0] == tabuleiro[2][1] && tabuleiro[2][1] == tabuleiro[2][2]){
            cout << "O Jogador x venceu";
            estadoDeJogo=0;
        }
        
        */
        int i,j;
        //Confere linhas
        for(i=0;i<3;i++){
             if(tabuleiro[i][0]== 'x' && tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2]){
                return 1;
             }else if(tabuleiro[i][0]== 'o' && tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2]){
                return 2;           
             }
        }
        //Confere colunas
        for(j=0;j<3;j++){
             if(tabuleiro[0][j]== 'x' && tabuleiro[0][j] == tabuleiro[1][j] && tabuleiro[1][j] == tabuleiro[2][j]){
                return 1;
             }else if(tabuleiro[0][j]== 'o' && tabuleiro[0][j] == tabuleiro[1][j] && tabuleiro[1][j] == tabuleiro[2][j]){
                return 2;
             }
        }
        // Confere diagonal principal
        if(tabuleiro[0][0] != '-' && tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2]){

            if(tabuleiro[0][0] == 'x'){
               return 1;
            }else{
               return 2;
            }
        }
        // Confere diagonal secundária(invertida)
        if(tabuleiro[0][2] != '-' && tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0]){
            if(tabuleiro[0][2] == 'x'){
               return 1;
            }else{
                return 2;
            }
        }       
        return 0;
       
}
void exibeInstrucoes(){
    cout << "\nMapa de Posicoes: \n";
    cout << " 7 | 8 | 9\n";
    cout << " 4 | 5 | 6\n";
    cout << " 1 | 2 | 3\n";

}
void jogo(string nomeDoJogadorUm, string nomeDoJogadorDois, int pontuacaoJogadorUm, int pontuacaoJogadorDois){
 
  
    ///VARIAVEIS GERAIS
    string nomeDoJogadorAtual; // Nome dos jogadores;
    char tabuleiro[3][3]; //Tabuleiro do Jogo
     int i,j;
    int linhaJogada,colunaJogada,posicaoJogada;  // Posicção em que o jogador posiciona sua marca
   
    int estadoDeJogo = 1; // 0 = Sem jogo, 1 = Em jogo
    int turnoDoJogador = 1; // 1=x, 2=o
    int rodada = 0; // Quantas vezes os jogadores jogaram no total
    //Coloca os '-' no tabuleiro para indiciar o vazio
    
    int opcao; //Opcao de inicio
    bool posicionouJogada; //Verifica se o Jogador colocu um marcador no tabuleiro

    iniciaTabuleiro(tabuleiro);
   
    

    while(rodada < 9 && estadoDeJogo == 1){

        limpaTela();

        cout << "\nRodada: " << rodada <<"\n";
        cout << "Pontuacao: "<< nomeDoJogadorUm << " " << pontuacaoJogadorUm << " x "<< pontuacaoJogadorDois << " " << nomeDoJogadorDois;
       
        exibeTabuleiro(tabuleiro);
     
        //Exibe qual numero corresponde a qual posicao
        exibeInstrucoes();
     
       
        //Atualiza o nome do jogador atual
        if(turnoDoJogador == 1){
            nomeDoJogadorAtual = nomeDoJogadorUm;
        }else{
            nomeDoJogadorAtual = nomeDoJogadorDois;
        }
        posicionouJogada=false;
        //Matriz de posiceos possiveis
        int posicoes[9][2] = {{2,0},{2,1},{2,2},{1,0}, {1,1}, {1,2}, {0,0}, {0,1}, {0,2}};

        while(posicionouJogada == false){
            //Lê a jogada
            cout << "\n" << nomeDoJogadorAtual << ", Digite uma posicao conforme o mapa acima: ";
            cin >> posicaoJogada;
            //Passa a linha e coluna de acordo com a matriz de posicoes exibida no mapa
            linhaJogada=posicoes[posicaoJogada-1][0]; //posicoes[5-1][0] -> posicoes[4][0]
            colunaJogada=posicoes[posicaoJogada-1][1]; //posicoes[4][1];
       
            //Verifica se a posição é vazia
            if(tabuleiro[linhaJogada][colunaJogada] == '-'){
                //Conseguiu posicionar um marcador
                posicionouJogada=true;
            //Verifica de quem é a vez para posicionar o marcador
                if(turnoDoJogador==1){
                  char x[]={'x'};
                   tabuleiro[linhaJogada][colunaJogada] = x[0];
                    turnoDoJogador=2;
                }else{
                    
                     tabuleiro[linhaJogada][colunaJogada] = 'o';
                    turnoDoJogador=1;
             }
                       
        }
       
    }
       
        
        //Confere se o jogo acabou
        if(confereTabuleiro(tabuleiro) == 1){
            cout << "\nO jogador X venceu\n";
            pontuacaoJogadorUm++;
            estadoDeJogo=0;
        }else if(confereTabuleiro(tabuleiro) == 2){
             cout << "\nO jogador O venceu\n";
            pontuacaoJogadorDois++;
            estadoDeJogo=0;
        }
        //Aumenta uma rodada
        rodada++;
       
    }
    exibeTabuleiro(tabuleiro);
    cout << "Fim de jogo\n";
    cout << "Oque deseja fazer?\n";
    cout << "1-Continuar jogando\n";
    cout << "2-Menu inicial\n";
    cout << "3-Sair\n";
    cin >> opcao;
    if(opcao == 1){
        jogo(nomeDoJogadorUm,nomeDoJogadorDois,pontuacaoJogadorUm,pontuacaoJogadorDois);
    }else if(opcao == 2){
        menuInicial();
    }
   
}
   
void menuInicial(){

    //Nome dos jogadores
    string nomeDoJogadorUm, nomeDoJogadorDois;
    int opcao=0;
    while(opcao < 1 || opcao > 3){
        cout << "Bem vindo ao Jogo da Velha\n";
        cout << "1 - Jogar\n";
        cout << "2 - Sobre\n";
        cout << "3 - Sair\n";
        cout << "\nEscolha uma opcao e tecle ENTER\n";
        cin >> opcao;
        limpaTela();
        switch(opcao){
        case 1:
            cout << "Digite o nome do jogador 1:\n";
            cin >> nomeDoJogadorUm;
            cout << "Digite o nome do jogador 2:\n";
            cin >> nomeDoJogadorDois;
            jogo(nomeDoJogadorUm,nomeDoJogadorDois,0,0);
            break;
        case 2:
            cout << "Informacoes do jogo\n";
            break;
        case 3:
            cout << "Ate mais!";
            break;
        }

    }
}
int main(){
   
    menuInicial();
    return 0;
}