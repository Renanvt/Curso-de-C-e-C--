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

int main(){
 	  char nome[] = "Marcos";
	  char nome2[] = "Castro";
	  string txt("CFB Cursos - Curso de C++"); //Recebe o valor no construtor
	  string::iterator it;
	  string::iterator it2; //retorna um ponteiro de it2;
	  it= txt.begin(); //O iterator está apontando para o primeiro elemento da string txt 'c'
	  it2= txt.end()-1; //O iterator está apontando para o ultimo elemento da string txt 'c' menos o terminador \o
	  cout << txt << endl;
	  cout << *it << endl;
	  cout << *it2 << endl;

	///Funcoes de capacidade
	//Imprime o tamanho da string
	  cout << txt.size() << endl;
	  cout << txt.length() << endl;
	  cout << txt.max_size() <<endl;	//Retorna o tamanho máximo que a string pode ter
	  txt.resize(10);//Altera o tamanho da string
	  cout << txt.size() << endl; //O tamanho agora é 10
	  cout << txt << endl;
	  cout << txt.capacity()<< endl; //Retorna o tamanho do espaco que foi alocado inicialmente pra string = 
	  //25, será sempre o maior valor que foi utilizado para aquela string

	  //txt.clear();//Limpa a string
	  cout << txt << endl;
	  if(txt.empty()){
		  //Faz uma verificação, retornando true se a string estiver vazia e false se a sting não estiver vazia
	  	cout << "String vazia" << endl;
	  }else{
		  //Imprime o conteudo da string:
		  cout << txt << endl;
	  } 

	  cout << txt.capacity() << endl;
	  txt.resize(25);
	  cout << txt.capacity() << endl; //a string continua ocupando o espaço inicial mesmo após o resize para resolver utilizar a função
	  txt.shrink_to_fit();//Reduz a capacidade da string em caso de diminuição de conteúdo. Resultará em 25. obs: Essa função possui o valor mínimo de redução = 15
	  cout << txt.capacity() << endl;
	  
	  verificarSeSaoIguais(nome,nome2);
	  verificarSeEMaiuscula(nome);
	  verificarSeEMinuscula(nome);
	  verificarCaracter(nome);
	  verificarSeEDigito(nome);
	  verificarSeHaEspaco(nome);
	  inverte(nome);
	return 0;
}