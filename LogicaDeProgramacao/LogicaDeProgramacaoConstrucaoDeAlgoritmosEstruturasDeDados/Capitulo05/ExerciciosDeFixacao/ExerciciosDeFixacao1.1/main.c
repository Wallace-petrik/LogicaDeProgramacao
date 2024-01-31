#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct{
    int codLivro;
    char titulo[30];
    char autor[30];
    char assunto[30];
    char editora[30];
    int ano;
    int edicao;
}Livro;

int main(){
    setlocale(LC_ALL,"");

    FILE *arq;

    arq = fopen("acervo.txt","a+");

    if(arq==NULL){
        printf("Problema na criação do arquivo!\n");
    }else{
        printf("O arquivo foi criado com sucesso!\n");
    }
    fclose(arq);
    return 0;
}
