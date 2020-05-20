#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <time.h>
using namespace std;

 
//Cabecalho de funcoes
void menuInicial();

void limpaTela(){
    system("cls");
}

void iniciaTabuleiro(char tabuleiro[10][10],char mascara[10][10]){
    int i,j;  //Variaveis auxiliares de navegação
    //Popula o tabuleiro com água
    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            tabuleiro[i][j] = 'A';
            mascara[i][j]= '*';
        }
    }
}
void exibeMapa(){
      //Mapa indicador de colunas
    int cont;
    for(cont=0;cont<10;cont++){
        if(cont == 0){
            cout << "     ";
        }
        cout << cont<< " ";
    }
    cout << "\n";
    for(cont=0;cont<10;cont++){
        if(cont == 0){
            cout << "     ";
        }
        cout << "| ";
    }
    cout << "\n";
}
void exibeTabuleiro(char tabuleiro[10][10],char mascara[10][10], bool mostraGabarito){
     //A 5. Posição do vetor corresponde a cor: 0 - Cinza ,1- Vermelho, 2 - Verde, 3 - Amarelo,4 - Azul, 5 - Rosa, 9 - Cor normal
     char blue[] = { 0x1b, '[', '1', ';', '3', '4', 'm', 0 };
    char green[] = { 0x1b, '[', '1', ';', '3', '2', 'm', 0 };
    char normal[] = { 0x1b, '[', '1', ';', '3', '9', 'm', 0 };
    
    //Exibi o tabuleiro
    int i,j;
    for(i=0;i<10;i++){
        cout << i << " - ";
        for(j=0;j<10;j++){
            switch(mascara[i][j]){
                case 'A':
                    cout << blue << " " <<mascara[j][j] << normal;
                    break;
                case 'P':
                    cout << green << " " <<mascara[i][j] << normal;
                    break;
                default:
                    cout << " " <<mascara[i][j];
                    break;
             }          
        }
        cout << "\n";     
    }
    if(mostraGabarito == true){
        for(i=0;i<10;i++){
            for(j=0;j<10;j++){
                cout << " "<<tabuleiro[i][j];
            }
            cout << "\n";
        }
    }

   
}
void posicionaBarcos(char tabuleiro[10][10]){
    //Coloca 10 barcos no tabuleiro
    int quantidade = 10;
    int quantidadePosicionada=0;
    //Verifica se já posicionou todos os barcos
    while(quantidadePosicionada < quantidade){
        int linhaArleatoria = rand() %10; //Gera um número arleatórios de 0 a 9
        int colunaArleatoria = rand() %10; // Gera numeros arleatórios de 0 a 9
        
        if(tabuleiro[linhaArleatoria][colunaArleatoria] == 'A'){

            //Posiciona 10 barcos arleatóriamente
            tabuleiro[linhaArleatoria][colunaArleatoria] = 'P';

            //Aumenta contador de barcos posicionados
            quantidadePosicionada++;
        }
        
    }
       
    
}
void verificaTiro(char tabuleiro[10][10], int linhaJogada, int colunaJogada, int *pontos, string *mensagem){
    //Verifica quantos pontos adicionar
        switch(tabuleiro[linhaJogada][colunaJogada]){
            case 'P':
                *pontos=*pontos+10;
                *mensagem="Voce acertou um barco pequeno! (10 pts)";
                break;
            case 'A':
                *mensagem = "Voce acertou a agua";
                break;
        }
}
void jogo(string nomeDoJogador){
    ///Variaveis Gerais
    char tabuleiro[10][10], mascara[10][10];  // Tabuleiro do jogo
    int linhaJogada, colunaJogada; // Posicao escolhida pelo jogador
   // int estadoDeJogo=1;  // 1 = Jogo aconteçendo, 0 = Fim de jogo
    int pontos=0; // Responsável pela pontuação
    string mensagem= "Bem vindo ao jogo!";  // Mensagem de feedback para o jogador
    int tentativas=0;  // Tentativas do jogador
    int maximoDeTentativas=5; // Maximo de tentativas do jogador
    int opcao;  //Opcoes de fim de jogo
   
     //Inicia o tabuleiro com água
    iniciaTabuleiro(tabuleiro,mascara);
    //Posiciona Barcos arleatoriamente
    posicionaBarcos(tabuleiro);   
 
    while(tentativas < maximoDeTentativas){
    
    
            limpaTela();
            //Exibe o mapa de indicações
            exibeMapa();
            //Exibe o tabuleiro
            exibeTabuleiro(tabuleiro, mascara, false);
            cout << "\nPontos: " << pontos << "\n";
            cout << "Tentativas restantes: "<<maximoDeTentativas-tentativas<<"\n";
            cout << mensagem << "\n";

            //Verificação de dados
            linhaJogada = -1;
            colunaJogada = -1;
            while( (linhaJogada < 0 || colunaJogada < 0) || (linhaJogada > 9 || colunaJogada > 9)){
                cout << nomeDoJogador <<", digite uma linha:\n";
                cin >> linhaJogada;
                cout << nomeDoJogador <<", digite uma coluna:\n";
                cin >> colunaJogada;
            }

           
            //Verifica oque aconteceu
            verificaTiro(tabuleiro,linhaJogada,colunaJogada, &pontos, &mensagem);

            //Revela oque está no tabuleiro
            mascara[linhaJogada][colunaJogada] = tabuleiro[linhaJogada][colunaJogada];

         tentativas++;
    }
        cout << "Fim de jogo, oque deseja fazer?\n";
        cout << "1 - Jogar Novamente\n";
        cout << "2 - Ir para o Menu\n";
        cout << "3 - Sair\n";
        cin >> opcao;
        switch (opcao)
        {
        case 1:
            jogo(nomeDoJogador);
            break;
        case 2:
            menuInicial();
            break;
        }  
}

void menuInicial(){
    int opcao=0;
    string nomeDoJogador;  //Nome do usuario
    while(opcao<1 || opcao>3){
        limpaTela();
        cout << "Bem vindo ao Jogo de Batalha Naval:\n";
        cout << "1 - Jogar\n";
        cout << "2 - Sobre\n";
        cout << "3 - Sair\n";
        cout << "Escolha uma opcao e tecle ENTER:";
        cin >> opcao;
        switch(opcao){
            case 1:
                //Inicia o jogo
                cout << "Qual seu nome?\n";
                cin >> nomeDoJogador;
                jogo(nomeDoJogador);
                break;
            case 2:
                //Informacoes do jogo
                cout << "informacoes do jogo";
                break;
            case 3:
                cout << "Ate mais";
                break;
        }
    }
}
int main(){
   
    //Gera números arleatorios
    srand( (unsigned)  time(NULL));
    menuInicial();
    return 0;
}