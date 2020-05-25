#include <iostream>
#include <cstring> // Evolução da biblioteca string.h.
//a biblioteca implementa a classe string

using namespace std;
struct {
	char nome[40];
}pessoa1,pessoa2;
int main(){
	  char meunome[] = "Bruno";
 	  
	
	  char txt1[50] = "Curso de programacao";
	  char txt2[50]="c++";
      char * txt3;
      char txt4[] = "CFB Cursos";
      char pesquisa= 'B';
      char *c;
      char pesquisa2= 'C';
      char txt5[] = "CBF Cursos - Curso de C++ - www.youtube.com/cfbcursos";
      char *c2;
      char key[]= "yt+w";
      char key2= 'o';
      int i;

	  strcpy(txt2,txt1);
	  strncpy(txt2,txt1,3); // Indica quantos caracteres quero copiar para o meu destino
	  cout << txt2 << endl;
	  memcpy(txt2,txt1,sizeof(txt1)+1);//Faz a copia do bloco de memoria ao inves da string. Nesse caso copia o bloco inteiro. +1 indica 
	  // que quero copiar até o terminador
	  
	  memcpy(pessoa1.nome,meunome,strlen(meunome)+1);
	  memcpy(pessoa2.nome,pessoa1.nome,sizeof(pessoa1.nome)+1); //pessoa2.nome -> pessoa1.nome
	  memcmp(txt1,txt2,sizeof(txt1));//Compara os blocos de memória, enquanto strcmp compara diretamente a string
      cout << pessoa1.nome << endl;
	  cout << pessoa2.nome << endl;

      txt3= (char*)memchr(txt4,pesquisa,strlen(txt4));
      if(txt3!=NULL){
          cout << "Letra " << pesquisa << " encontrada na posicao: " << txt3-txt4+1 << endl;
      }else{
          cout << "Letra " << pesquisa << " nao encontrada" <<endl;
      }

      c=strchr(txt4,pesquisa2);
      cout << "Pos: " << c-txt4+1<<endl;

      i = strcspn(txt5,key);
      cout << "Pos: " << i << endl;
      //Imprimir o elemento encontrado
      cout << "Pos: " << i <<  " - " << txt5[i] << endl;

      c2 = strrchr(txt5,key2);
      cout << "pos: " << c2-txt5 << endl;

      c2 = strtok(txt5,",-");
      while(c2!=NULL){
          cout << c2 << endl;
          c2 = strtok(NULL, ",-");
      }
	  return 0;
}