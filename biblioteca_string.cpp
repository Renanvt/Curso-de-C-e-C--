#include <iostream>
#include <string.h>
#include <cstring> // Evolução da biblioteca string.h.
//a biblioteca implementa a classe string

using namespace std;
void inverte(char nome[]){
	//Obtendo o tamanho da string
	int tam;
	for(tam=0;nome[tam];tam++);
	//Invertendo a string
	for(int i = tam -1; i>=0; i--)
		cout << nome[i];
}
void verificarCaracter(char nome[]){
	if(isalpha(nome[0])){
		//Retorna true se o caractere for alfabetico
	  	cout << "caractere alfabetico" << endl;
	  }else{
	  	cout << "caractere numerico" << endl;
	  }
}
void verificarSeEDigito(char nome[]){
	if(isdigit(nome[0])){
		//Retorna true se o caractere for um digito (0 - 9)
	  	cout << "numero" << endl;
	  }else{
	  	cout << "letra" << endl;
	  }
}
void verificarSeEMaiuscula(char nome[]){
	if(isupper(nome[0])){
		//Retorna true se o caractere for Maiusculo
		cout << "Maiuscula" << endl;
	}else{
		cout << "Minuscula" << endl;
	}
}
void verificarSeEMinuscula(char nome[]){
	if(islower(nome[0])){
		//Retorna true se o caractere for Minusculo
		cout << "Maiuscula" << endl;
	}else{
		cout << "Maiuscula" << endl;
	}
}
void verificarSeHaEspaco(char nome[]){
	if(isspace(nome[0])){
		//Retorna true se o caractere for um espaco em branco
		cout << "espaco em branco" << endl;
	}else{
		cout << "nao eh espaco em branco" << endl;
	}
}
void verificarSeSaoIguais(char nome[], char nome2[]){
	if(strcmp(nome, nome2) == 0){
	  	cout << "strings iguais!" <<endl;
	  }else{
	  	cout << "strings diferentes!"<<endl;
	  }
}
struct {
	char nome[40];
}pessoa1,pessoa2;
int main(){
	char meunome[] = "Bruno";
 	  char nome[] = "Marcos";
	  char nome2[] = "Castro";
	  char txt1[50] = "Curso de programacao";
	  char txt2[50]="c++";
	  strcpy(txt2,txt1);
	  strncpy(txt2,txt1,3); // Indica quantos caracteres quero copiar para o meu destino
	  cout << txt2 << endl;
	  memcpy(txt2,txt1,sizeof(txt1)+1);//Faz a copia do bloco de memoria ao inves da string. Nesse caso copia o bloco inteiro. +1 indica 
	  // que quero copiar até o terminador
	  
	  memcpy(pessoa1.nome,meunome,strlen(meunome)+1);
	  memcpy(pessoa2.nome,pessoa1.nome,sizeof(pessoa1.nome)+1); //pessoa2.nome -> pessoa1.nome
	  memcmp(txt1,txt2,sizeof(txt1)//Compara os blocos de memória, enquanto strcmp compara diretamente a string
	  
	  cout << pessoa1.nome << endl;
	  cout << pessoa2.nome << endl;
	  verificarSeSaoIguais(nome,nome2);
	  verificarSeEMaiuscula(nome);
	  verificarSeEMinuscula(nome);
	  verificarCaracter(nome);
	  verificarSeEDigito(nome);
	  verificarSeHaEspaco(nome);
	  inverte(nome);
	return 0;
}