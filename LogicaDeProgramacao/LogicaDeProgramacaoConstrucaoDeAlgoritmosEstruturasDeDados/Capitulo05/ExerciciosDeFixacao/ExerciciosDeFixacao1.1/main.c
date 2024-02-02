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

    Livro livro;

    FILE *arquivo;

    int opcao;

    if((arquivo=fopen("banco","a+b"))==NULL){
        printf("Problema na criação do arquivo!\n");
        system("pause");
        exit(0);
    }

    do{
        printf("Escolha uma opção\n\n");
        printf("1 Para buscar livros por assunto\n");
        printf("3 Para sair\n");
            scanf("%d",&opcao);

        switch(opcao){
            case 1:
                system("cls");


            break;
            case 3:
                system("cls");
                printf("Até logo!!!");
            break;
            default:
                system("cls");
                printf("Opção invalida!!!\n");
                system("pause");
                system("cls");
        }
    }while(opcao!=3);

    fclose(arquivo);
    return 0;
}
