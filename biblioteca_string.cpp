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
	
	cout << endl;

	//FUNCOES PARA REFERENCIAR ACESSO A ELEMENTOS
	  string txt2("CFB Cursos - Curso de C++ - www.youtube.com/cfbcursos");
	  int tam=txt2.size(); // Retorna o elemento na posicao indicada
	  cout << txt2.at(2);
	  for(int i=0;i<tam;i++){
		  cout << txt2.at(i); //retorna o elemento indicado na posicao é o mesmo que se fazer txt[i];
	  }
	  cout << endl;
	  cout << txt2.back() << endl;;//Retorna a referencia para o ultimo elemento da string. =s
	  txt2.back()= 'B'; // substiui o s pelo b no final da string
	  cout << txt2 << endl;
	  txt2.front()='F';//Retorna a referencia para o primeiro elemento da string. Nesse caso mudando de C para F
	  
	///FUNCOES MODIFICADORAS
	string txt3("CFB Cursos");
	txt3+= "Curso de c++"; // Contatena txt em txt3
	txt3.append(" - Curso de c++"); // Contatena txt em txt3, o mesmo que +=
	txt3.assign("Curso de C++");//Substitui o conteudo da string. O mesmo que txt3=("Curso de C++");
	txt3.insert(10," - "); //Insere o novo conteudo da string em uma posicao especificada. Na posicao 10 vai inserir " - "
	txt3.erase(10,5);//Remove determinado conteudo da string, passando dois parametros, o ponto inicial e a quantidade de elementos que quero remover. Nesse caso irá remover 5 elementos a partir da posicao 10

	string txt4("CFB Cursos - Curso de C++");
	string txt5="Javascript";
	txt4.replace(22,4,txt5);//Substitui parte da string. Precisa informar 3 parâmetros, o ponto inicial, a quantidade de elementos e o que eu quero substituir. Nesse caso a partir da posicao 22, substituir todos os 4 elementos restantes, pelo conteudo de txt2
	cout << txt4 << endl;
	string txt6("Curso");
	string txt7="Aula";
	txt6.swap(txt7);//Faz uma troca de uma string pela outra
	cout << txt6 << endl; //Exibe Aula
	cout << txt7 << endl; // Exibe Curso

	txt3.push_back('B');//Adiciona um caracter no final da string. obs; essa funcao não contatena string
	cout << txt3 << endl;
	txt3.pop_back();//Remove o ultimo caracter da string

	//FUNCOES PARA OPERAÇÕES EM STRING
	string txt8("Curso de C++ - Biblioteca string");
	string txt9;
	size_t encontrado = txt8.find("de");//find() -> Encontra uma determinada ocorrencia dentro da string, passando oque quero encontrar dentro da string. sempre que n encontrar a ocorrencia dentro da string, irá retornar o valor maximo de size_t
	if(encontrado!=string::npos){//npos é uma constante estática que contem o valor maximo possivel de size_t
		cout << "Encontrado na posicao " << encontrado <<endl; 
	}else{
		cout << "NAO encontrado" << endl;	
	}
	cout << encontrado << endl;
	string txt10("Curso de c++ - Biblioteca string");
	string txt11;
	txt11=txt10.substr(15,10);//retorna uma nova string de acordo de uma posicao indicada de uma string ja existente, informando 2 parametros, o ponto inicial, e quantos caracteres a patir deste ponto eu quero retornar para a variavel que ira receber a nova string
	cout << txt11 << endl; //Exibe biblioteca
	string texto("Curso de c++");
	string texto2("CFB Cursos");
	if(texto.compare(txt2)==0){
		cout << "Strings iguais" << endl;
	}else{
		cout << "Strings diferentes" << endl;
	}
	//Compara duas strings, se as strings forem iguais, retorna 0, se a primeira string for maior do que a segunda, retorna um numero maior do que 0, se a segunda for maior do que a primeira, retorna um numero menor do que 0

	///FUNCOES PARA CONVERSAO
	string texto3("18"),texto4;
	int ano=2020,res;
	res=ano-stoi(texto3); //Converte a string para numeral
	cout << res <<endl; //Exibe 2002
	texto4=to_string(res);//Conversao de inteiro para string
	cout << texto4 << endl;
	//stol // Conversao de string pra long int
	//stoll // Conversao de string para long long int
	//stoul // Conversao de string para unsigned long int
	//stoull // Conversao de string para unsigned long long int
	//stof // Conversao de String para float
	// stod // Conversao de String para double
	// stold // Conversao de string para long double
	  verificarSeSaoIguais(nome,nome2);
	  verificarSeEMaiuscula(nome);
	  verificarSeEMinuscula(nome);
	  verificarCaracter(nome);
	  verificarSeEDigito(nome);
	  verificarSeHaEspaco(nome);
	  inverte(nome);
	return 0;
}