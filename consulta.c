#include <stdio.h>
int main(){
    FILE *arq;
    char frase[100];
    arq = fopen("dados.txt","r"); //Abre arquivo pra leitura

    if(arq==NULL)
        printf("\nErro na abertura!");
    else
    {
        while(!feof(arq)){ //feof -> file end of file
            fgets(frase,100,arq); //Pega a string
            if(ferror(arq)) //ferror -> file error
            {
                printf("Erro na leitura!");
            }
            else{
                printf("\nDados: %s",frase);
            }
        }
    }
          fclose(arq);//Fecha o arquivo
    
    return 0;
}