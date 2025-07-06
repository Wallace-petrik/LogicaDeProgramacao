#include <stdio.h>
#include <locale.h>

typedef struct{
    int codigoDoLivro;
    char titulo[30];
    char autor[30];
    char assunto[30];
    char editora[30];
    int ano;
    int edicao;
}Livro;

int main(){

    setlocale(LC_ALL,"");

    menu();

return 0;}

void menu(){
    int opcao;
    do{
        printf("1/p Cadastrar livro\n");
        printf("2/p Buscar livros por assunto\n");
        printf("3/p sair\n");
            scanf("%d",&opcao);
            fflush(stdin);
        switch(opcao){
            case 1:{

            break;}
            case 2:{

            break;}
            case 3:{
                printf("Até logo !!!");
                getchar();
            break;}
            default:{
                printf("Opção invalida !!!");
                getchar();
                system("cls");}
        }
    }while(opcao!=3);
}

