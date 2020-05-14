#include <stdio.h>
#include <locale.h> //Essa biblioteca possui funушes de regionalizaусo
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <conio.h>
#include <iostream>
#include <new>
#define TAM 3
using namespace std;

int main(){
    setlocale(LC_ALL,"");
    int cont;
    int tamanhoDaLista;

    cout << "Qual o tamanho da lista?\n";
    cin >> tamanhoDaLista;
    int *vetorEmCPlusPlus = new int[tamanhoDaLista];
    //Lendo novos valores
    for(cont=0;cont<tamanhoDaLista;cont++)
        cin >> vetorEmCPlusPlus[cont];
    
    imprimeSequencial(vetorEmCPlusPlus,tamanhoDaLista);
    
    return 0;
}


