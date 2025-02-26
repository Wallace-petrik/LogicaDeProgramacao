#include <stdio.h>
#include <locale.h>

struct{
    char nome[50];
    int notas[4];
    float media;
}typedef Alunos;

int main(){

    setlocale(LC_ALL,"");

    int opcao;

    do{
        system("cls");
        fflush(stdin);
        printf("\n1 para cadastrar");
        printf("\n2 para corrigir");
        printf("\n3 para pesquisar");
        printf("\n4 para listar Ap");
        printf("\n5 para listar Rp");
        printf("\n6 para sair\n:");
            scanf("%d%*c",&opcao);
            fflush(stdin);

        switch(opcao){
            case 1:{

            break;}

            case 2:{

            break;}

            case 3:{

            break;}

            case 4:{

            break;}

            case 5:{

            break;}

            case 6:{
                printf("\nAté logo !!!");
                getchar();
            break;}

            default:{
                printf("\n Opção invalida !!!");
                getchar();
            break;}
        }

    }while(opcao != 6);

    return 0;
}
