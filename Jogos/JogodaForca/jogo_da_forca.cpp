#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <time.h>
using namespace std;
void limpaTela(){
    system("cls");
}
string retornaPalavraArleatoria(){
    //Vetor com palavras disponiveis
    string palavras[3] = {"abacaxi", "manga", "morango"};
    //Indice gerado no intervalor {0,1,2}
    int indiceArleatorio = rand() % 3;
    //Exibi a palavra arleatória
    //cout << palavras[indiceArleatorio];
    return palavras[indiceArleatorio];
}
string retornaPalavraComMascara(string palavra, int tamanhoDaPalavra){
    int cont=0;
    string palavraComMascara;

    //Coloca uma máscara
    while(cont < tamanhoDaPalavra){
        palavraComMascara += "_";
        cont++;
    }
    return palavraComMascara;
}
void exibeStatus(string palavraComMascara, int tamanhoDaPalavra,int tentativasRestantes, string LetrasJaArriscadas, string mensagem){
    cout << mensagem << "\n";
    cout << "Palavra:  "<< palavraComMascara << ", Tamanho: "<<tamanhoDaPalavra<<"\n";
    cout << "Tentativas Restantes: " << tentativasRestantes<< "\n";

    //Exibi as letras arriscadas
    int cont;
    cout << "Letras arriscadas: ";
    for(cont=0;cont<LetrasJaArriscadas.size();cont++){
        cout << LetrasJaArriscadas[cont] << ", ";
    } 
    cout <<"\n";

       
}
int jogarSozinho(){
    
    //Palavra a ser adivinhada
    string palavra = retornaPalavraArleatoria();
    //Tamanho da palavra
    int tamanhoDaPalavra = palavra.size();
    
    //Palavra mascarada
    string palavraComMascara = retornaPalavraComMascara(palavra,tamanhoDaPalavra);
   
    ///Variáveis Gerais
    int tentativas=0,maximoDeTentativas=5; //Numero de tentativas e erros
    char letra; //Letra arriscada pelo usuario
    int cont=0; //Auxiliar contadora
    int opcao;  //Opcoes finais
    string letrasJaArriscadas; //Acumula as tentativas do jogador
    string palavraArriscada;
    bool jaDigitouLetra=false, acertouLetra=false;  //Auxiliar para saber se a letra ja foi digitada
    string mensagem = "Bem vindo ao jogo!";  //Feedback do jogador
  

    while(palavra != palavraComMascara && maximoDeTentativas - tentativas > 0){
        limpaTela();
        //Exibe o status atual do jogo
        exibeStatus(palavraComMascara,tamanhoDaPalavra,maximoDeTentativas-tentativas,letrasJaArriscadas,mensagem);
        //Le um palpite
        cout << "Digite uma letra (Ou digite 1 para arriscar a palavra):\n";
        cin >> letra;

        //Se digitar 1 deixa o usuário arriscar a palavra inteira
        if(letra=='1'){
            cin >> palavraArriscada;
            if(palavraArriscada == palavra){
                palavraComMascara = palavraArriscada;
            }else{
                tentativas=maximoDeTentativas;
            }
        }

        //Percorre as letras já arriscadas
        for(cont=0;cont<tentativas;cont++){
            //Se encontrar a letra
            if(letrasJaArriscadas[cont] == letra){
                mensagem = "Essa letra ja foi digitada!";
                jaDigitouLetra=true;
            }
        }
        //Se for uma letra nova
        if(jaDigitouLetra==false){
            //Incrementa as letras já arriscadas
            letrasJaArriscadas+= tolower(letra);
            //Percorre a palavra real e se a letra existir muda a palavraComMascara
            for(cont=0;cont<tamanhoDaPalavra;cont++){
                //Se a letra existir na palavra escondida
                if(palavra[cont] == tolower(letra)){
                    //Letra apareçe na palavraComMascara
                    palavraComMascara[cont] = palavra[cont];
                    acertouLetra=true;   
                }
            } 
            if(acertouLetra==false){
                mensagem = "Voce errou uma letra!";
            }else{
                mensagem = "Voce acertou uma letra!";
                acertouLetra=false;
            }
            //Aumenta uma tentativa realizada
            tentativas++;
        }
        //Reinicia auxiliares
        jaDigitouLetra=false;
        acertouLetra=false;

    }
    
    if(palavra == palavraComMascara){
        limpaTela();
        cout << "Parabens voce venceu!\n";
        cout << "Deseja reiniciar?\n";
        cout << "1-Sim\n";
        cout << "2-Nao\n";
        cin >> opcao;
        return opcao;
    }else{
        limpaTela();
        cout << "Bleh, voce perdeu!\n"; 
        cout << "Deseja Reiniciar?\n";
        cout << "1-Sim\n";
        cout << "2-Nao\n";
        cin >> opcao;
        return opcao;
    }
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
                if(jogarSozinho() == 1){
                    menuInicial();    
                }
                break;
            case 2:
                //Informacoes do jogo
                limpaTela();
                cout << "Jogo desenvolvido por Jonatan Renan em 2020\n";
                cout << "Creditos: Curso de C e C++ no Iniciante ao Avancado - Udemy\n";
                cout << "1 - Voltar\n";
                cout << "2 - Sair\n";
                cin >> opcao;
                if(opcao == 1){
                    menuInicial();
                }
                break;
        }
    }
}

int main(){
    //Para gerar números arleatórios
    srand ( (unsigned) time(NULL));
    menuInicial();
    return 0;
}