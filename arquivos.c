#include <stdio.h>
typedef struct ficha{ //Estrutura chamada ficha
  char nome[50]; 
  char telefone[15];
}FICHA;
int main(){
  //Variavel ponteiro file para arquivos em disco:
  //FILE *arq, *pont;
  //Pra abrir um arquivo utilizamos a funcao FOPEN:
  //FILE *p;
  //p = fopen(nome_do_arquivo, modo_de_abertura);
  /*
  R -> ABRE UM ARQUIVO PARA LEITURA APENAS
  W -> CRIA UM NOVO ARQUIVO PARA GRAVAÇÃO
  A -> ABRE UM ARQUIVO PARA EDIÇÃO DE DADOS
  R+ -> ABRE UM ARQUIVO PARA LEITURA E ESCRITA
  W+ -> CRIA UM ARQUIVO PARA LEITURA E ESCRITA
  A+ -> ADICIONA DADOS EM ARQUIVO OU CRIA NOVO

  fclose(arq) FUNCAO PARA FECHAR ARQUIVO
  fputc(carac., *arq) FUNCAO PARA ESCREVER CARACTERE
  fgetc(*arq) FUNCAO PARA LER CARACTERE
  fputs(*cadeira, *arq) FUNCAO PARA ESCREVER STRING
  fgets(*cadeia, *arq) FUNCAO PARA LER STRING
  fwrite e fread DADOS DIVERSOS
  */
  FILE *pont_arq; //ponteiro pra um arquivo qualquer
  FICHA cadastro; //Declaracao da estrutura
  char registro[65]; //Vetor de armazenamento de dados para guardar no arquivo
  char n1[2], n2[2];
  char *arquivo = "dados.txt"; // caminho do arquivo
  int i;
  pont_arq = fopen("dados.txt", "w"); //Cria o arquivo e abre, sobreescrevendo se existir
    if(pont_arq==NULL){
      printf("Erro!");
      return 1; //Sai fora do programa
    }
  printf("Cadastro de dados em arquivo:");
  for(i=1;i<=3;i++){
    printf("\n\nNome: ");
    scanf("%s", &cadastro.nome);
    printf("\nTelefone: ");
    scanf("%s", &cadastro.telefone);
    //fprintf é uma outra alternativa equivalente ao fputs
    //Escreve no arquivo 
    
    fprintf(pont_arq, "%s", &cadastro.nome); //Joga o cadastr.nome dentro de pont_arq
    fprintf(pont_arq, "%s", "-"); // Grava um traco em pont_arq
    fprintf(pont_arq, "%s", &cadastro.telefone); // Grava cadastro.telefone em pont_arq
    fprintf(pont_arq, "%s", "\n");// \n faz o registro de fim de linha ENDOFLINE
  }
  fclose(pont_arq);
  printf("Dados gravados com sucesso!");
  return 0;
}