#include <stdio.h>
#include <locale.h> //Essa biblioteca possui funções de regionalização
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <conio.h>
#include <iostream>

using namespace std;
int retornaComMaisDez(int numero){
    return numero + 10;
}
/*Funções com ponteiros:*/
void aumentaDez(int *num){
    *num = *num + 10;
}
int main(){
	setlocale(LC_ALL, "Portuguese");
    int a = 5;
    printf("o valor de a = %d\n",a);
    a = retornaComMaisDez(a);
    printf("o valor de a = %d\n",a);

    /*Trabalhando com ponteiros*/

    /*Função que aumenta 10 diretamente*/
    aumentaDez(&a);
     printf("o valor de a = %d\n",a);

	return(0);
}
